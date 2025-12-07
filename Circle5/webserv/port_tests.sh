#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

TESTS_PASSED=0
TESTS_FAILED=0
TESTS_TOTAL=0

CONFIG_DIR="./config"
TEST_CONFIG_DIR="./test_configs"
WEBSERV_BIN="./webserv"

mkdir -p "$TEST_CONFIG_DIR"


print_test_result() {
    local test_name="$1"
    local result="$2"
    local message="$3"
    
    TESTS_TOTAL=$((TESTS_TOTAL + 1))
    
    if [ "$result" == "PASS" ]; then
        echo -e "${GREEN}PASS${NC}: $test_name"
        [ -n "$message" ] && echo -e "  ${BLUE}Info${NC}: $message"
        TESTS_PASSED=$((TESTS_PASSED + 1))
    else
        echo -e "${RED}FAIL${NC}: $test_name"
        [ -n "$message" ] && echo -e "  ${RED}Error${NC}: $message"
        TESTS_FAILED=$((TESTS_FAILED + 1))
    fi
}

check_port() {
    local port=$1
    if command -v nc &> /dev/null; then
        nc -z localhost $port 2>/dev/null
        return $?
    elif command -v curl &> /dev/null; then
        curl -s -o /dev/null -w "%{http_code}" http://localhost:$port 2>/dev/null
        [ $? -eq 0 ] && return 0 || return 1
    else
        echo -e "${YELLOW}Warning: Neither nc nor curl available for port checking${NC}"
        return 1
    fi
}

start_server() {
    local config_file="$1"
    local pid_file="$2"
    
    $WEBSERV_BIN "$config_file" > /dev/null 2>&1 &
    local pid=$!
    echo $pid > "$pid_file"
    sleep 2
    

    if kill -0 $pid 2>/dev/null; then
        return 0
    else
        return 1
    fi
}

stop_server() {
    local pid_file="$1"
    
    if [ -f "$pid_file" ]; then
        local pid=$(cat "$pid_file")
        if kill -0 $pid 2>/dev/null; then
            kill $pid 2>/dev/null
            sleep 1
            kill -9 $pid 2>/dev/null
        fi
        rm -f "$pid_file"
    fi
}

cleanup() {
    echo -e "\n${YELLOW}Cleaning up...${NC}"
    pkill -f "$WEBSERV_BIN" 2>/dev/null
    rm -rf "$TEST_CONFIG_DIR"
    sleep 1
}

trap cleanup EXIT

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}   WEBSERV PORT CONFIGURATION TESTS${NC}"
echo -e "${BLUE}========================================${NC}\n"

if [ ! -f "$WEBSERV_BIN" ]; then
    echo -e "${YELLOW}Webserv binary not found. Compiling...${NC}"
    make
    if [ $? -ne 0 ]; then
        echo -e "${RED}Failed to compile webserv${NC}"
        exit 1
    fi
fi

echo -e "\n${BLUE}[TEST 1]${NC} Multiple ports with different websites"

cat > "$TEST_CONFIG_DIR/multi_port.conf" << 'EOF'
server {
    listen 9001;
    server_name localhost;
    host 127.0.0.1;
    root www;
    index index.html;
    error_page 404 /error_pages/404.html;

    location / {
        methods GET;
    }
}

server {
    listen 9002;
    server_name localhost;
    host 127.0.0.1;
    root www;
    index about.html;
    error_page 404 /error_pages/404.html;

    location / {
        methods GET;
    }
}

server {
    listen 9003;
    server_name localhost;
    host 127.0.0.1;
    root www;
    index contact.html;
    error_page 404 /error_pages/404.html;

    location / {
        methods GET;
    }
}
EOF

start_server "$TEST_CONFIG_DIR/multi_port.conf" "$TEST_CONFIG_DIR/test1.pid"
if [ $? -eq 0 ]; then
    sleep 1
    
    port_9001_ok=false
    port_9002_ok=false
    port_9003_ok=false
    
    if check_port 9001; then port_9001_ok=true; fi
    if check_port 9002; then port_9002_ok=true; fi
    if check_port 9003; then port_9003_ok=true; fi
    
    if $port_9001_ok && $port_9002_ok && $port_9003_ok; then
        if command -v curl &> /dev/null; then
            content1=$(curl -s http://localhost:9001/ 2>/dev/null)
            content2=$(curl -s http://localhost:9002/ 2>/dev/null)
            content3=$(curl -s http://localhost:9003/ 2>/dev/null)
            
            if [ ${#content1} -gt 0 ] && [ ${#content2} -gt 0 ] && [ ${#content3} -gt 0 ]; then
                print_test_result "Multiple ports serve content" "PASS" "Ports 9001, 9002, 9003 are accessible"
            else
                print_test_result "Multiple ports serve content" "FAIL" "Some ports returned empty content"
            fi
        else
            print_test_result "Multiple ports are listening" "PASS" "Ports 9001, 9002, 9003 are all listening"
        fi
    else
        print_test_result "Multiple ports configuration" "FAIL" "Not all ports are accessible (9001:$port_9001_ok, 9002:$port_9002_ok, 9003:$port_9003_ok)"
    fi
else
    print_test_result "Multiple ports configuration" "FAIL" "Server failed to start"
fi

stop_server "$TEST_CONFIG_DIR/test1.pid"
sleep 2

echo -e "\n${BLUE}[TEST 2]${NC} Duplicate port in same configuration file"

cat > "$TEST_CONFIG_DIR/duplicate_port.conf" << 'EOF'
server {
    listen 9010;
    server_name localhost;
    host 127.0.0.1;
    root www;
    index index.html;

    location / {
        methods GET;
    }
}

server {
    listen 9010;
    server_name localhost;
    host 127.0.0.1;
    root www;
    index about.html;

    location / {
        methods GET;
    }
}
EOF

start_server "$TEST_CONFIG_DIR/duplicate_port.conf" "$TEST_CONFIG_DIR/test2.pid"
result=$?
sleep 2

if [ $result -ne 0 ] || ! kill -0 $(cat "$TEST_CONFIG_DIR/test2.pid" 2>/dev/null) 2>/dev/null; then
    print_test_result "Duplicate port rejection" "PASS" "Server correctly rejected configuration with duplicate port 9010"
else
    if check_port 9010; then
        print_test_result "Duplicate port rejection" "FAIL" "Server started despite duplicate port configuration"
    else
        print_test_result "Duplicate port rejection" "PASS" "Server rejected duplicate port configuration"
    fi
fi

stop_server "$TEST_CONFIG_DIR/test2.pid"
sleep 2

echo -e "\n${BLUE}[TEST 3]${NC} Multiple servers with same port (triple duplicate)"

cat > "$TEST_CONFIG_DIR/triple_duplicate.conf" << 'EOF'
server {
    listen 9020;
    server_name server1;
    host 127.0.0.1;
    root www;
    index index.html;

    location / {
        methods GET;
    }
}

server {
    listen 9020;
    server_name server2;
    host 127.0.0.1;
    root www;
    index about.html;

    location / {
        methods GET;
    }
}

server {
    listen 9020;
    server_name server3;
    host 127.0.0.1;
    root www;
    index contact.html;

    location / {
        methods GET;
    }
}
EOF

start_server "$TEST_CONFIG_DIR/triple_duplicate.conf" "$TEST_CONFIG_DIR/test3.pid"
result=$?
sleep 2

if [ $result -ne 0 ] || ! kill -0 $(cat "$TEST_CONFIG_DIR/test3.pid" 2>/dev/null) 2>/dev/null; then
    print_test_result "Triple duplicate port rejection" "PASS" "Server rejected configuration with triple duplicate port"
else
    if check_port 9020; then
        print_test_result "Triple duplicate port rejection" "FAIL" "Server started despite triple duplicate port"
    else
        print_test_result "Triple duplicate port rejection" "PASS" "Server rejected triple duplicate port"
    fi
fi

stop_server "$TEST_CONFIG_DIR/test3.pid"
sleep 2

echo -e "\n${BLUE}[TEST 4]${NC} Two separate server instances with common port"

cat > "$TEST_CONFIG_DIR/server1_common.conf" << 'EOF'
server {
    listen 9030;
    server_name server1;
    host 127.0.0.1;
    root www;
    index index.html;

    location / {
        methods GET;
    }
}

server {
    listen 9031;
    server_name server1_alt;
    host 127.0.0.1;
    root www;
    index about.html;

    location / {
        methods GET;
    }
}
EOF

cat > "$TEST_CONFIG_DIR/server2_common.conf" << 'EOF'
server {
    listen 9030;
    server_name server2;
    host 127.0.0.1;
    root www;
    index contact.html;

    location / {
        methods GET;
    }
}

server {
    listen 9032;
    server_name server2_alt;
    host 127.0.0.1;
    root www;
    index index.html;

    location / {
        methods GET;
    }
}
EOF

start_server "$TEST_CONFIG_DIR/server1_common.conf" "$TEST_CONFIG_DIR/test4a.pid"
if [ $? -eq 0 ]; then
    sleep 1
    
    if check_port 9030 && check_port 9031; then
        start_server "$TEST_CONFIG_DIR/server2_common.conf" "$TEST_CONFIG_DIR/test4b.pid"
        result=$?
        sleep 2
        
        server2_running=false
        if [ -f "$TEST_CONFIG_DIR/test4b.pid" ]; then
            pid=$(cat "$TEST_CONFIG_DIR/test4b.pid")
            if kill -0 $pid 2>/dev/null; then
                server2_running=true
            fi
        fi
        
        if [ $result -ne 0 ] || [ "$server2_running" = false ]; then
            print_test_result "Common port between instances" "PASS" "Second server correctly failed to start due to port conflict"
        else
            if check_port 9030; then
                print_test_result "Common port between instances" "FAIL" "Second server started despite port 9030 conflict"
            else
                print_test_result "Common port between instances" "PASS" "Second server failed to bind to conflicting port"
            fi
        fi
        
        stop_server "$TEST_CONFIG_DIR/test4b.pid"
    else
        print_test_result "Common port between instances" "FAIL" "First server failed to start properly"
    fi
else
    print_test_result "Common port between instances" "FAIL" "First server failed to start"
fi

stop_server "$TEST_CONFIG_DIR/test4a.pid"
sleep 2

echo -e "\n${BLUE}[TEST 5]${NC} Three server instances, two sharing a port"

cat > "$TEST_CONFIG_DIR/server_a.conf" << 'EOF'
server {
    listen 9040;
    server_name server_a;
    host 127.0.0.1;
    root www;
    index index.html;

    location / {
        methods GET;
    }
}
EOF

cat > "$TEST_CONFIG_DIR/server_b.conf" << 'EOF'
server {
    listen 9041;
    server_name server_b;
    host 127.0.0.1;
    root www;
    index about.html;

    location / {
        methods GET;
    }
}
EOF

cat > "$TEST_CONFIG_DIR/server_c.conf" << 'EOF'
server {
    listen 9041;
    server_name server_c;
    host 127.0.0.1;
    root www;
    index contact.html;

    location / {
        methods GET;
    }
}
EOF

start_server "$TEST_CONFIG_DIR/server_a.conf" "$TEST_CONFIG_DIR/test5a.pid"
sleep 1
start_server "$TEST_CONFIG_DIR/server_b.conf" "$TEST_CONFIG_DIR/test5b.pid"
sleep 1
start_server "$TEST_CONFIG_DIR/server_c.conf" "$TEST_CONFIG_DIR/test5c.pid"
sleep 2

running_count=0
server_a_running=false
server_b_running=false
server_c_running=false

if [ -f "$TEST_CONFIG_DIR/test5a.pid" ] && kill -0 $(cat "$TEST_CONFIG_DIR/test5a.pid") 2>/dev/null; then
    server_a_running=true
    running_count=$((running_count + 1))
fi

if [ -f "$TEST_CONFIG_DIR/test5b.pid" ] && kill -0 $(cat "$TEST_CONFIG_DIR/test5b.pid") 2>/dev/null; then
    server_b_running=true
    running_count=$((running_count + 1))
fi

if [ -f "$TEST_CONFIG_DIR/test5c.pid" ] && kill -0 $(cat "$TEST_CONFIG_DIR/test5c.pid") 2>/dev/null; then
    server_c_running=true
    running_count=$((running_count + 1))
fi

port_9040_ok=false
port_9041_ok=false

if check_port 9040; then port_9040_ok=true; fi
if check_port 9041; then port_9041_ok=true; fi

if $server_a_running && $server_b_running && ! $server_c_running; then
    print_test_result "Three servers with port conflict" "PASS" "Only first two servers started, third correctly failed"
elif $server_a_running && ! $server_b_running && $server_c_running; then
    print_test_result "Three servers with port conflict" "PASS" "Server A and C started, B failed (race condition)"
elif $port_9040_ok && $port_9041_ok && [ $running_count -eq 2 ]; then
    print_test_result "Three servers with port conflict" "PASS" "Two servers running, one failed due to port conflict"
else
    print_test_result "Three servers with port conflict" "FAIL" "Unexpected server states (A:$server_a_running, B:$server_b_running, C:$server_c_running)"
fi

stop_server "$TEST_CONFIG_DIR/test5a.pid"
stop_server "$TEST_CONFIG_DIR/test5b.pid"
stop_server "$TEST_CONFIG_DIR/test5c.pid"
sleep 2

echo -e "\n${BLUE}[TEST 6]${NC} Valid port ranges"

cat > "$TEST_CONFIG_DIR/port_ranges.conf" << 'EOF'
server {
    listen 1024;
    server_name low_port;
    host 127.0.0.1;
    root www;
    index index.html;

    location / {
        methods GET;
    }
}

server {
    listen 32768;
    server_name mid_port;
    host 127.0.0.1;
    root www;
    index about.html;

    location / {
        methods GET;
    }
}

server {
    listen 65535;
    server_name high_port;
    host 127.0.0.1;
    root www;
    index contact.html;

    location / {
        methods GET;
    }
}
EOF

start_server "$TEST_CONFIG_DIR/port_ranges.conf" "$TEST_CONFIG_DIR/test6.pid"
if [ $? -eq 0 ]; then
    sleep 2
    
    low_ok=false
    mid_ok=false
    high_ok=false
    
    if check_port 1024; then low_ok=true; fi
    if check_port 32768; then mid_ok=true; fi
    if check_port 65535; then high_ok=true; fi
    
    if $low_ok && $mid_ok && $high_ok; then
        print_test_result "Port range validation" "PASS" "All ports (1024, 32768, 65535) are accessible"
    else
        print_test_result "Port range validation" "FAIL" "Some ports not accessible (1024:$low_ok, 32768:$mid_ok, 65535:$high_ok)"
    fi
else
    print_test_result "Port range validation" "FAIL" "Server failed to start with various port ranges"
fi

stop_server "$TEST_CONFIG_DIR/test6.pid"
sleep 2

echo -e "\n${BLUE}========================================${NC}"
echo -e "${BLUE}           TEST SUMMARY${NC}"
echo -e "${BLUE}========================================${NC}"
echo -e "Total tests:  $TESTS_TOTAL"
echo -e "${GREEN}Passed:       $TESTS_PASSED${NC}"
echo -e "${RED}Failed:       $TESTS_FAILED${NC}"

if [ $TESTS_FAILED -eq 0 ]; then
    echo -e "\n${GREEN}All tests passed!${NC}"
    exit 0
else
    echo -e "\n${RED}Some tests failed!${NC}"
    exit 1
fi
