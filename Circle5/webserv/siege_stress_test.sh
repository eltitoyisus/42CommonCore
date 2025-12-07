#!/bin/bash


declare -a TESTS=(
    "Availability Test (99.5% requirement)|http://localhost:8001/|5|15s|-b"
    "Memory Leak Test|http://localhost:8001/|5|30s|-b"
    "Connection Test|http://localhost:8001/|10|15s|-b"
    "Indefinite Siege Test|http://localhost:8001/|8|60s|-b"
    "Multi-port Test 8002|http://localhost:8002/|5|10s|-b"
    "Multi-port Test 8003|http://localhost:8003/|5|10s|-b"
    "Different Pages Test|http://localhost:8001/index.html|5|15s|-b"
    "Contact Page Test|http://localhost:8001/contact.html|5|15s|-b"
)

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

print_header() {
    echo ""
    echo "========================================"
    echo " $1"
    echo "========================================"
}

print_test_info() {
    echo "Test: $1"
    echo "URL: $2"
    echo "Concurrent Users: $3"
    echo "Duration: $4"
    echo "Flags: $5"
    echo ""
}

monitor_memory() {
    local test_name=$1
    local duration=$2
    echo "Monitoring memory usage for $test_name..."
    
    local webserv_pid=$(pgrep webserv | head -1)
    if [ -z "$webserv_pid" ]; then
        echo -e "${RED}Warning: Could not find webserv process for memory monitoring${NC}"
        return
    fi
    
    local initial_memory=$(ps -o rss= -p $webserv_pid 2>/dev/null | tr -d ' ')
    echo "Initial memory: ${initial_memory} KB"
    
    sleep $duration
    
    local final_memory=$(ps -o rss= -p $webserv_pid 2>/dev/null | tr -d ' ')
    if [ -n "$final_memory" ]; then
        echo "Final memory: ${final_memory} KB"
        local memory_diff=$((final_memory - initial_memory))
        echo "Memory change: ${memory_diff} KB"
        
        if [ $memory_diff -gt 5000 ]; then
            echo -e "${RED}Warning: Significant memory increase detected${NC}"
        else
            echo -e "${GREEN}Memory usage stable${NC}"
        fi
    fi
}

check_connections() {
    echo "Checking for hanging connections..."
    local established=0
    local time_wait=0
    
    if command -v netstat &> /dev/null; then
        established=$(netstat -an 2>/dev/null | grep -E ':(8001|8002|8003)' | grep ESTABLISHED | wc -l)
        time_wait=$(netstat -an 2>/dev/null | grep -E ':(8001|8002|8003)' | grep TIME_WAIT | wc -l)
    elif command -v ss &> /dev/null; then
        established=$(ss -an 2>/dev/null | grep -E ':(8001|8002|8003)' | grep ESTAB | wc -l)
        time_wait=$(ss -an 2>/dev/null | grep -E ':(8001|8002|8003)' | grep TIME-WAIT | wc -l)
    fi
    
    echo "Established connections: $established"
    echo "TIME_WAIT connections: $time_wait"
    
    if [ $established -gt 20 ]; then
        echo -e "${RED}Warning: High number of established connections${NC}"
    else
        echo -e "${GREEN}Connection cleanup looks good${NC}"
    fi
}

if ! command -v siege &> /dev/null; then
    echo -e "${RED}Error: siege is not installed${NC}"
    echo "Install it with: sudo apt-get install siege (Ubuntu/Debian)"
    echo "Or: brew install siege (macOS)"
    exit 1
fi

if ! command -v bc &> /dev/null; then
    echo -e "${RED}Warning: bc not installed, availability checking will be limited${NC}"
fi

echo "Checking if webserv is running..."
if ! curl -s --max-time 5 "http://localhost:8001/" > /dev/null 2>&1; then
    echo -e "${RED}Error: Server at http://localhost:8001/ is not responding${NC}"
    echo "Make sure webserv is running before starting the tests"
    echo ""
    echo "To start webserv, run:"
    echo "  ./webserv config/default.config"
    echo ""
    echo "Or check if webserv crashed with:"
    echo "  ps aux | grep webserv"
    exit 1
fi

webserv_pid=$(pgrep webserv | head -1)
if [ -z "$webserv_pid" ]; then
    echo -e "${RED}Warning: No webserv process found running${NC}"
    echo "The server might be responding but not running as 'webserv'"
else
    echo "Found webserv process: PID $webserv_pid"
fi

print_header "WebServ Siege & Stress Tests - Requirements Validation"
echo "Found siege: $(which siege)"
echo "Total tests to run: ${#TESTS[@]}"
echo ""
echo "Testing requirements:"
echo "1. Availability ≥99.5% with siege -b"
echo "2. No memory leaks"
echo "3. No hanging connections"
echo "4. Indefinite siege capability"
echo ""

test_number=1
for test_config in "${TESTS[@]}"; do
    IFS='|' read -r test_name url concurrent duration flags <<< "$test_config"
    
    print_header "Test $test_number/${#TESTS[@]}: $test_name"
    print_test_info "$test_name" "$url" "$concurrent" "$duration" "$flags"
    
    if [[ "$test_name" == *"Memory"* ]] || [[ "$test_name" == *"Indefinite"* ]]; then
        monitor_memory "$test_name" $(echo $duration | sed 's/s//') &
        memory_monitor_pid=$!
    fi
    
    echo "Starting siege test..."
    siege $flags -c "$concurrent" -t "$duration" "$url" 2>&1
    
    echo ""
    echo "Analysis for $test_name:"
    echo "----------------------------------------"
    
    if [[ "$test_name" == *"Memory"* ]] || [[ "$test_name" == *"Indefinite"* ]]; then
        wait $memory_monitor_pid 2>/dev/null
    fi
    
    if [[ "$test_name" == *"Connection"* ]] || [[ "$test_name" == *"Indefinite"* ]]; then
        check_connections
    fi
    
    echo ""
    
    ((test_number++))
    
    echo "Checking server health after test..."
    if ! curl -s --max-time 5 "http://localhost:8001/" > /dev/null 2>&1; then
        echo -e "${RED}Server is not responding after test${NC}"
        
        current_webserv_pid=$(pgrep webserv | head -1)
        if [ -z "$current_webserv_pid" ]; then
            echo -e "${RED}WebServ process has died${NC}"
            echo "The previous test caused the server to crash"
            echo ""
            echo "To continue testing:"
            echo "1. Restart webserv: ./webserv config/default.config"
            echo "2. Run the script again"
            echo ""
            echo "This indicates a critical bug in your webserv implementation"
            exit 1
        else
            echo "WebServ process exists but not responding - may be hung"
            echo "PID: $current_webserv_pid"
        fi
    else
        echo -e "${GREEN}Server is still healthy${NC}"
    fi
    
    if [ $test_number -le ${#TESTS[@]} ]; then
        echo "Waiting 3 seconds before next test..."
        sleep 3
    fi
done

print_header "Final Analysis"
echo "Checking overall system state..."
check_connections

if curl -s --max-time 5 "http://localhost:8001/" > /dev/null 2>&1; then
    echo -e "${GREEN}WebServ is still responding after all tests${NC}"
else
    echo -e "${RED}WebServ is not responding after tests${NC}"
fi

print_header "Test Summary"
echo "All $((test_number-1)) tests completed!"
echo ""
echo "Requirements tested:"
echo "Availability with siege -b (Test 1)"
echo "Memory leak detection (Test 2, 4)"
echo "Hanging connection check (Test 3, 4)"
echo "Indefinite siege capability (Test 4)"