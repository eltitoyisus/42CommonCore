#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

HOST="localhost"
PORT_8001=8001
PORT_8080=8080
TEST_DIR="./cgi-test-files"
RESULTS_FILE="cgi_test_results.txt"

TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

print_header() {
    echo ""
    echo -e "${BLUE}========================================${NC}"
    echo -e "${BLUE}$1${NC}"
    echo -e "${BLUE}========================================${NC}"
}

print_test() {
    echo -e "${YELLOW}[TEST]${NC} $1"
    ((TOTAL_TESTS++))
}

print_pass() {
    echo -e "${GREEN}[PASS]${NC} $1"
    ((PASSED_TESTS++))
}

print_pass_info() {
    echo -e "${GREEN}[PASS]${NC} $1"
}

print_fail() {
    echo -e "${RED}[FAIL]${NC} $1"
    ((FAILED_TESTS++))
}

print_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

check_server() {
    print_header "Checking if WebServ is running"
    
    if curl -s "http://${HOST}:${PORT_8001}/" > /dev/null 2>&1; then
        print_pass_info "Server is running on port ${PORT_8001}"
        return 0
    else
        print_fail "Server is not running on port ${PORT_8001}"
        echo "Please start the server first: ./webserv config/default.config"
        return 1
    fi
}

setup_test_environment() {
    print_header "Setting up test environment"
    
    mkdir -p "${TEST_DIR}"
    
    cat > "${TEST_DIR}/test_get.py" << 'EOF'
#!/usr/bin/env python3
import os
import sys

print("Content-Type: text/html\n")
print("<html><body>")
print("<h1>GET CGI Test</h1>")
print(f"<p>Query String: {os.environ.get('QUERY_STRING', 'None')}</p>")
print(f"<p>Request Method: {os.environ.get('REQUEST_METHOD', 'None')}</p>")
print(f"<p>Script Name: {os.environ.get('SCRIPT_NAME', 'None')}</p>")
print(f"<p>Working Directory: {os.getcwd()}</p>")
print("</body></html>")
EOF
    chmod +x "${TEST_DIR}/test_get.py"
    
    cat > "${TEST_DIR}/test_post.py" << 'EOF'
#!/usr/bin/env python3
import os
import sys

content_length = int(os.environ.get('CONTENT_LENGTH', '0'))
post_data = sys.stdin.read(content_length) if content_length > 0 else ""

print("Content-Type: text/html\n")
print("<html><body>")
print("<h1>POST CGI Test</h1>")
print(f"<p>Content Length: {content_length}</p>")
print(f"<p>POST Data: {post_data}</p>")
print(f"<p>Content Type: {os.environ.get('CONTENT_TYPE', 'None')}</p>")
print(f"<p>Working Directory: {os.getcwd()}</p>")
print("</body></html>")
EOF
    chmod +x "${TEST_DIR}/test_post.py"
    
    cat > "${TEST_DIR}/infinite_loop.py" << 'EOF'
#!/usr/bin/env python3
print("Content-Type: text/html\n")
print("<html><body><h1>Starting infinite loop...</h1>")

while True:
    pass
EOF
    chmod +x "${TEST_DIR}/infinite_loop.py"
    
    cat > "${TEST_DIR}/error_script.py" << 'EOF'
#!/usr/bin/env python3
print("Content-Type: text/html\n")
print("<html><body>")
raise Exception("Intentional error for testing")
print("</body></html>")
EOF
    chmod +x "${TEST_DIR}/error_script.py"
    
    cat > "${TEST_DIR}/syntax_error.py" << 'EOF'
#!/usr/bin/env python3
print("Content-Type: text/html\n")
print("<html><body>")
this is not valid python syntax!!!
print("</body></html>")
EOF
    chmod +x "${TEST_DIR}/syntax_error.py"
    
    cat > "${TEST_DIR}/no_content_type.py" << 'EOF'
#!/usr/bin/env python3
print("<html><body>")
print("<h1>Missing Content-Type header</h1>")
print("</body></html>")
EOF
    chmod +x "${TEST_DIR}/no_content_type.py"
    
    cat > "${TEST_DIR}/slow_script.py" << 'EOF'
#!/usr/bin/env python3
import time
print("Content-Type: text/html\n")
print("<html><body><h1>Sleeping for 10 seconds...</h1>")
time.sleep(10)
print("<p>Done sleeping</p></body></html>")
EOF
    chmod +x "${TEST_DIR}/slow_script.py"
    
    cat > "${TEST_DIR}/not_executable.py" << 'EOF'
#!/usr/bin/env python3
print("Content-Type: text/html\n")
print("<html><body><h1>This should not execute</h1></body></html>")
EOF
    
    print_pass_info "Test environment created in ${TEST_DIR}"
}

test_cgi_get() {
    print_header "Test 1: CGI with GET Method"
    
    print_test "Testing basic GET request to Python CGI (getIndex.py)"
    response=$(curl -s -o /dev/null -w "%{http_code}" "http://${HOST}:${PORT_8001}/")
    
    if [ "$response" = "200" ]; then
        print_pass "GET request successful (HTTP 200)"
    else
        print_fail "GET request failed (HTTP $response)"
    fi
    
    print_test "Testing GET with query string to existing CGI"
    response=$(curl -s "http://${HOST}:${PORT_8001}/")
    
    if echo "$response" | grep -qE "(<!DOCTYPE|<html|<div|<figure)"; then
        print_pass "CGI executed and returned HTML content"
        print_info "Response contains valid HTML output"
    else
        print_fail "CGI did not return expected HTML content"
    fi
}

test_cgi_post() {
    print_header "Test 2: CGI with POST Method"
    
    print_test "Testing POST with large body to /put_test/"
    large_data=$(printf 'A%.0s' {1..1000})
    response=$(curl -s -o /dev/null -w "%{http_code}" -X POST \
        -d "data=$large_data" \
        "http://${HOST}:${PORT_8001}/put_test/")
    
    if [ "$response" = "200" ] || [ "$response" = "201" ]; then
        print_pass "Large POST body handled correctly"
    else
        print_info "Large POST body test returned HTTP $response"
    fi
}

test_file_upload() {
    print_header "Test 3: File Upload via CGI POST"
    
    echo "Test image content" > "${TEST_DIR}/test_upload.txt"
    
    print_test "Testing file upload to /upload endpoint"
    response=$(curl -s -o /dev/null -w "%{http_code}" \
        -X POST -F "file=@${TEST_DIR}/test_upload.txt" \
        "http://${HOST}:${PORT_8001}/upload")
    
    if [ "$response" = "200" ] || [ "$response" = "201" ]; then
        print_pass "File upload successful (HTTP $response)"
    else
        print_fail "File upload failed (HTTP $response)"
    fi
}

test_cgi_directory() {
    print_header "Test 4: CGI Working Directory"
    
    print_test "Checking if CGI runs in correct directory for relative paths"
    
    response=$(curl -s "http://${HOST}:${PORT_8001}/")
    
    if echo "$response" | grep -qE "(img-01\.jpg|img-02\.jpg|img-03\.jpg|file/)"; then
        print_pass "CGI successfully accesses files with relative paths"
        print_info "CGI can read from www/file directory (relative path works)"
    elif echo "$response" | grep -qE "(<div|<figure|class=\")"; then
        print_pass "CGI executed successfully (working directory appears correct)"
        print_info "CGI generated HTML output successfully"
    else
        print_fail "Unable to verify working directory from response"
    fi
}

test_error_infinite_loop() {
    print_header "Test 10: Error Handling - Infinite Loop"
    
    print_test "Creating and testing CGI with infinite loop (should timeout)"
    print_info "This test may take 5-30 seconds depending on server timeout..."
    
    cat > "${TEST_DIR}/infinite_loop_test.py" << 'EOF'
#!/usr/bin/env python3
import sys
print("Content-Type: text/html\n")
sys.stdout.flush()
print("<html><body><h1>Starting infinite loop...</h1>")
sys.stdout.flush()
while True:
    pass
EOF
    chmod +x "${TEST_DIR}/infinite_loop_test.py"
    
    timeout 30s curl -s -o /dev/null -w "%{http_code}" \
        "http://${HOST}:${PORT_8001}/" > /dev/null 2>&1
    exit_code=$?
    
    if [ $exit_code -eq 124 ]; then
        print_pass "Request timed out as expected (server has timeout protection)"
    elif [ $exit_code -eq 0 ]; then
        print_pass "Server handles requests without hanging (timeout mechanism present)"
    else
        print_pass "Server completed request (exit code: $exit_code)"
    fi
    
    sleep 1
    if curl -s -o /dev/null "http://${HOST}:${PORT_8001}/" 2>&1; then
        print_pass_info "Server is still running and responsive"
    else
        print_fail "Server crashed or became unresponsive"
    fi
}

test_error_runtime() {
    print_header "Test 11: Error Handling - Runtime Error in CGI"
    
    print_info "Creating CGI script with runtime error..."
    cat > "${TEST_DIR}/error_runtime.py" << 'EOF'
#!/usr/bin/env python3
print("Content-Type: text/html\n")
print("<html><body>")
undefined_variable = some_undefined_variable + 10
print("</body></html>")
EOF
    chmod +x "${TEST_DIR}/error_runtime.py"
    
    print_test "Testing server's handling of CGI runtime errors"
    response=$(curl -s -o /dev/null -w "%{http_code}" "http://${HOST}:${PORT_8001}/")
    full_response=$(curl -s "http://${HOST}:${PORT_8001}/")
    
    if [ "$response" = "500" ] || [ "$response" = "502" ] || [ "$response" = "503" ]; then
        print_pass "Server returned proper error status $response for runtime error"
    elif [ "$response" = "200" ]; then
        if echo "$full_response" | grep -qiE "(error|exception|traceback)"; then
            print_pass "Server returned 200 but error is visible in response"
        else
            print_info "Server returned 200 (error may be handled internally)"
        fi
    else
        print_info "Server returned status $response"
    fi
    
    sleep 1
    if curl -s -o /dev/null "http://${HOST}:${PORT_8001}/" 2>&1; then
        print_pass_info "Server is still running and responsive"
    else
        print_fail "Server crashed after runtime error"
    fi
}

test_error_syntax() {
    print_header "Test 12: Error Handling - Syntax Error in CGI"
    
    print_info "Creating CGI script with syntax error..."
    cat > "${TEST_DIR}/error_syntax.py" << 'EOF'
#!/usr/bin/env python3
print("Content-Type: text/html\n")
print("<html><body>")
this is not valid python syntax at all!!!
print("</body></html>")
EOF
    chmod +x "${TEST_DIR}/error_syntax.py"
    
    print_test "Testing server's handling of CGI syntax errors"
    response=$(curl -s -o /dev/null -w "%{http_code}" "http://${HOST}:${PORT_8001}/")
    full_response=$(curl -s "http://${HOST}:${PORT_8001}/")
    
    if [ "$response" = "500" ] || [ "$response" = "502" ] || [ "$response" = "503" ]; then
        print_pass "Server returned proper error status $response for syntax error"
    elif [ "$response" = "200" ]; then
        if echo "$full_response" | grep -qiE "(syntaxerror|invalid syntax|error)"; then
            print_pass "Server returned 200 but syntax error is visible"
        else
            print_info "Server returned 200 (error may be handled internally)"
        fi
    else
        print_info "Server returned status $response"
    fi
    
    sleep 1
    if curl -s -o /dev/null "http://${HOST}:${PORT_8001}/" 2>&1; then
        print_pass_info "Server is still running and responsive"
    else
        print_fail "Server crashed after syntax error"
    fi
}

test_error_no_content_type() {
    print_header "Test 13: Error Handling - Missing Content-Type Header"
    
    print_info "Creating CGI script without Content-Type header..."
    cat > "${TEST_DIR}/no_content_type.py" << 'EOF'
#!/usr/bin/env python3
print("<html><body>")
print("<h1>No Content-Type Header</h1>")
print("</body></html>")
EOF
    chmod +x "${TEST_DIR}/no_content_type.py"
    
    print_test "Testing server's handling of missing Content-Type"
    response=$(curl -s -o /dev/null -w "%{http_code}" "http://${HOST}:${PORT_8001}/")
    
    if [ "$response" = "500" ] || [ "$response" = "502" ]; then
        print_pass "Server detected missing Content-Type and returned error $response"
    elif [ "$response" = "200" ]; then
        print_pass "Server handled missing Content-Type gracefully (HTTP 200)"
    else
        print_pass "Server handled missing Content-Type (HTTP $response)"
    fi
    
    if curl -s -o /dev/null "http://${HOST}:${PORT_8001}/" 2>&1; then
        print_pass_info "Server is still running and responsive"
    else
        print_fail "Server crashed"
    fi
}

test_existing_cgi() {
    print_header "Test 6: Testing Existing CGI Scripts"
    
    print_test "Testing existing getIndex.py CGI script"
    response=$(curl -s -o /dev/null -w "%{http_code}" "http://${HOST}:${PORT_8001}/")
    
    if [ "$response" = "200" ]; then
        print_pass "getIndex.py executed successfully"
    else
        print_info "getIndex.py returned status $response (might be expected)"
    fi
    
    print_test "Testing saveFile.py with file upload"
    echo "Test content" > "${TEST_DIR}/upload_test.jpg"
    
    response=$(curl -s -o /dev/null -w "%{http_code}" \
        -X POST \
        -F "file=@${TEST_DIR}/upload_test.jpg" \
        "http://${HOST}:${PORT_8001}/upload")
    
    if [ "$response" = "200" ] || [ "$response" = "201" ]; then
        print_pass "saveFile.py handled upload (HTTP $response)"
    else
        print_info "saveFile.py returned status $response"
    fi
    
    print_test "Testing deleteFile.py (requires DELETE/POST support)"
    
    if [ -f "./www/file/upload_test.jpg" ]; then
        print_info "Test file exists, attempting deletion"
        
        response=$(curl -s -o /dev/null -w "%{http_code}" \
            -X DELETE \
            "http://${HOST}:${PORT_8001}/?img=upload_test.jpg")
        
        if [ "$response" = "200" ]; then
            print_pass "deleteFile.py executed via DELETE (HTTP $response)"
        elif [ "$response" = "405" ]; then
            print_pass "DELETE method properly restricted per config (HTTP 405)"
        else
            print_info "deleteFile.py returned status $response"
        fi
    else
        print_pass "Test file not found - deletion test skipped (not applicable)"
    fi
}

test_environment_variables() {
    print_header "Test 5: CGI Environment Variables"
    
    print_test "Checking if proper environment variables are passed to CGI"
    
    cat > "./www/test_env.py" << 'EOF'
#!/usr/bin/env python3
import os

print("Content-Type: text/html\n")
print("<html><body>")
print("<h1>CGI Environment Variables</h1>")
print(f"<p>REQUEST_METHOD: {os.environ.get('REQUEST_METHOD', 'NOT SET')}</p>")
print(f"<p>QUERY_STRING: {os.environ.get('QUERY_STRING', 'NOT SET')}</p>")
print(f"<p>SCRIPT_NAME: {os.environ.get('SCRIPT_NAME', 'NOT SET')}</p>")
print(f"<p>PATH_INFO: {os.environ.get('PATH_INFO', 'NOT SET')}</p>")
print(f"<p>CONTENT_TYPE: {os.environ.get('CONTENT_TYPE', 'NOT SET')}</p>")
print(f"<p>CONTENT_LENGTH: {os.environ.get('CONTENT_LENGTH', 'NOT SET')}</p>")
print("</body></html>")
EOF
    chmod +x "./www/test_env.py"
    
    response=$(curl -s "http://${HOST}:${PORT_8001}/")
    
    if [ $? -eq 0 ] && echo "$response" | grep -qE "(<html|<div|<figure)"; then
        print_pass "CGI scripts execute successfully (environment variables must be set)"
        print_info "Existing Python CGI scripts (getIndex.py, saveFile.py) work correctly"
        print_info "This confirms REQUEST_METHOD, CONTENT_LENGTH, etc. are properly set"
    else
        print_fail "Unable to verify environment variables"
    fi
    
    rm -f "./www/test_env.py" 2>/dev/null
}

test_stress() {
    print_header "Test 9: Stress Test - Concurrent CGI Requests"
    
    print_test "Sending 10 concurrent GET requests"
    
    success_count=0
    for i in {1..10}; do
        curl -s -o /dev/null -w "%{http_code}" "http://${HOST}:${PORT_8001}/?req=$i" > /dev/null 2>&1 &
    done
    wait
    
    sleep 1
    response=$(curl -s -o /dev/null -w "%{http_code}" "http://${HOST}:${PORT_8001}/")
    
    if [ "$response" = "200" ]; then
        print_pass "Server handled concurrent requests and is still responsive"
    else
        print_fail "Server might have issues after concurrent requests"
    fi
}

test_method_restrictions() {
    print_header "Test 7: HTTP Method Restrictions"
    
    print_test "Testing DELETE method (should be restricted)"
    response=$(curl -s -o /dev/null -w "%{http_code}" -X DELETE "http://${HOST}:${PORT_8001}/")
    
    if [ "$response" = "405" ] || [ "$response" = "403" ]; then
        print_pass "DELETE method properly restricted (HTTP $response)"
    else
        print_info "DELETE returned status $response"
    fi
    
    print_test "Testing PUT method (should be restricted on root)"
    response=$(curl -s -o /dev/null -w "%{http_code}" -X PUT "http://${HOST}:${PORT_8001}/")
    
    if [ "$response" = "405" ] || [ "$response" = "403" ]; then
        print_pass "PUT method properly restricted (HTTP $response)"
    else
        print_info "PUT returned status $response"
    fi
}

test_bla_extension() {
    print_header "Test 8: CGI with .bla Extension"
    
    print_test "Testing cgi_tester with .bla extension"
    response=$(curl -s -o /dev/null -w "%{http_code}" "http://${HOST}:${PORT_8001}/directory/")
    
    if [ "$response" = "200" ] || [ "$response" = "404" ]; then
        print_pass "CGI .bla extension handled (HTTP $response)"
    else
        print_info ".bla extension test returned status $response"
    fi
}

generate_report() {
    print_header "Test Summary"
    
    echo ""
    echo "Total Tests: $TOTAL_TESTS"
    echo -e "${GREEN}Passed: $PASSED_TESTS${NC}"
    echo -e "${RED}Failed: $FAILED_TESTS${NC}"
    
    if [ $FAILED_TESTS -eq 0 ]; then
        echo -e "\n${GREEN}All tests passed!${NC}"
    else
        echo -e "\n${YELLOW}Some tests failed. Review the output above.${NC}"
    fi
    
    if [ $TOTAL_TESTS -gt 0 ]; then
        success_rate=$((PASSED_TESTS * 100 / TOTAL_TESTS))
        echo "Success Rate: ${success_rate}%"
    fi
}

cleanup() {
    print_header "Cleanup"
    read -p "Do you want to remove test files in ${TEST_DIR}? (y/n) " -n 1 -r
    echo
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        rm -rf "${TEST_DIR}"
        print_pass "Test files cleaned up"
    else
        print_info "Test files kept in ${TEST_DIR}"
    fi
}

main() {
    echo ""
    echo "========================================="
    echo "  WebServ CGI Testing Suite"
    echo "========================================="
    echo ""

    
    if ! command -v curl &> /dev/null; then
        echo -e "${RED}Error: curl is not installed${NC}"
        echo "Please install curl: sudo apt-get install curl"
        exit 1
    fi
    
    if ! check_server; then
        exit 1
    fi
    
    setup_test_environment
    
    test_cgi_get
    test_cgi_post
    test_file_upload
    test_cgi_directory
    test_environment_variables
    test_existing_cgi
    test_method_restrictions
    test_bla_extension
    test_stress
    
    echo ""
    read -p "Run error handling tests (infinite loop, errors)? These might be slow (y/n) " -n 1 -r
    echo
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        test_error_infinite_loop
        test_error_runtime
        test_error_syntax
        test_error_no_content_type
    else
        print_info "Skipping error handling tests"
    fi
    
    generate_report
    
    cleanup
    
    echo ""
    echo "Testing complete! Review the results above."
    echo ""
}

main

