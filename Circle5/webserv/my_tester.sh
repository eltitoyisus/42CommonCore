#!/bin/bash

#Config

SERVER="localhost:8001"
HOST="localhost"
PORT="8001"
UPLOAD="upload"
DELETE="delete"

# WebServ
# Usage: ./my_tester.sh [test_name]
# Example: ./my_tester.sh get
#          ./my_tester.sh all

# Colores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[1;37m'
NC='\033[0m'
BOLD='\033[1m'

# Contadores
TOTAL=0
PASSED=0
FAILED=0

# Función para imprimir headers de sección
print_header() {
    echo -e "${CYAN}╔════════════════════════════════════════╗${NC}"
    echo -e "${CYAN}║${WHITE}${BOLD}  $1${NC}${CYAN}         ║${NC}"
    echo -e "${CYAN}╚════════════════════════════════════════╝${NC}"
    echo ""
}

# Función para imprimir test
print_test() {
    echo -e "${YELLOW}▶${NC} ${WHITE}$1${NC}"
}

# Función para verificar respuesta
check_response() {
    local expected="$1"
    local response="$2"
    TOTAL=$((TOTAL + 1))
    
    if echo "$response" | grep -q "$expected"; then
        echo -e "${GREEN}✓ PASS${NC} - Respuesta correcta: $expected"
        PASSED=$((PASSED + 1))
    else
        echo -e "${RED}✗ FAIL${NC} - Esperado: $expected"
        FAILED=$((FAILED + 1))
    fi
    echo ""
}

test_get() {
    print_header "PRUEBAS GET"

    # --- Pruebas de Éxito (2xx) ---
    print_test "GET / (should be 200 OK)"
    RESPONSE=$(curl -s -i "http://$SERVER/" | head -n 5)
    echo "$RESPONSE"
    check_response "200 OK" "$RESPONSE"
    
    print_test "GET /index.html (should be 200 OK)"
    RESPONSE=$(curl -s -i "http://$SERVER/index.html" | head -n 5)
    echo "$RESPONSE"
    check_response "200 OK" "$RESPONSE"

    # --- Pruebas de Redirección (3xx) ---
    print_test "GET /css (should be 301 Moved Permanently)"
    RESPONSE=$(curl -s -i "http://$SERVER/css" | head -n 5)
    echo "$RESPONSE"
    check_response "301" "$RESPONSE"

    # --- Pruebas de Error de Cliente (4xx) ---
    print_test "GET /fake.html (should be 404 Not Found)"
    RESPONSE=$(curl -s -i "http://$SERVER/fake.html" | head -n 5)
    echo "$RESPONSE"
    check_response "404" "$RESPONSE"

    print_test "GET / ruta con espacios (should be 400 Bad Request)"
    RESPONSE=$(printf "GET /   index.html HTTP/1.1\r\nHost: $HOST\r\nConnection: close\r\n\r\n" | nc $HOST $PORT | head -n 5)
    echo "$RESPONSE"
    check_response "400" "$RESPONSE"

    print_test "GET /../../etc/passwd (Path Traversal) (should be 400, 403, or 404)"
    RESPONSE=$(curl -s -i --path-as-is "http://$SERVER/../../etc/passwd" | head -n 5)
    echo "$RESPONSE"
    check_response "40" "$RESPONSE"  # Acepta 400, 403, 404
}

test_head() {
    print_header "PRUEBAS HEAD"

    print_test "HEAD /index.html (should be 200 OK)"
    RESPONSE=$(curl -s -I "http://$SERVER/" | head -n 10)
    echo "$RESPONSE"
    check_response "200 OK" "$RESPONSE"
    
    print_test "HEAD /css (should be 301 Moved Permanently)"
    RESPONSE=$(curl -s -I "http://$SERVER/css" | head -n 5)
    echo "$RESPONSE"
    check_response "301" "$RESPONSE"

    print_test "HEAD /fake.html (should be 404 Not Found)"
    RESPONSE=$(curl -s -I "http://$SERVER/fake.html" | head -n 5)
    echo "$RESPONSE"
    check_response "404" "$RESPONSE"

    print_test "HEAD /upload (should be 405 Method Not Allowed)"
    RESPONSE=$(curl -s -I "http://$SERVER/upload" | head -n 5)
    echo "$RESPONSE"
    check_response "405" "$RESPONSE"
}

test_post() {
    print_header "PRUEBAS POST"

    # --- Pruebas de Error de Cliente (4xx) ---
    print_test "POST /index.html (should be 405 Method Not Allowed)"
    RESPONSE=$(curl -s -i -X POST -d "" "http://$SERVER/index.html" | head -n 5)
    echo "$RESPONSE"
    check_response "405" "$RESPONSE"

    print_test "POST /$UPLOAD con JSON malformado (should be 400 Bad Request)"
    RESPONSE=$(curl -s -i -X POST -H "Content-Type: application/json" \
         -d '{"name":"test' "http://$SERVER/$UPLOAD" | head -n 5)
    echo "$RESPONSE"
    check_response "400" "$RESPONSE"
    
    print_test "POST /$UPLOAD con Content-Type inválido (should be 400 Bad Request)"
    RESPONSE=$(curl -s -i -X POST -H "Content-Type: application/json" \
         -d '{"email":"test@test.com"}' "http://$SERVER/$UPLOAD" | head -n 5)
    echo "$RESPONSE"
    check_response "400" "$RESPONSE"
    
    print_test "POST /upload con 4MB (should be 413 Payload Too Large)"
    dd if=/dev/zero of=temp_payload.bin bs=1M count=4 2>/dev/null
    RESPONSE=$(curl -s -i -X POST -F "file=@temp_payload.bin" "http://$SERVER/upload" | head -n 5)
    echo "$RESPONSE"
    check_response "413" "$RESPONSE"
    rm temp_payload.bin

    # --- Pruebas de Éxito (2xx) ---
    print_test "POST /$UPLOAD (Contact Form) ✅ (should be 201 Created)"
    RESPONSE=$(curl -s -i -X POST \
         -F "name=Luis Martin" \
         -F "email=luis@example.com" \
         -F "message=Test message" \
         "http://$SERVER/$UPLOAD" | head -n 5)
    echo "$RESPONSE"
    check_response "201" "$RESPONSE"
}

test_delete() {
    print_header "PRUEBAS DELETE"

    print_test "DELETE / (should be 405 Method Not Allowed)"
    RESPONSE=$(curl -s -i -X DELETE "http://$SERVER/" | head -n 5)
    echo "$RESPONSE"
    check_response "405" "$RESPONSE"

    print_test "DELETE /$DELETE?img=test_delete.txt (should be 200 OK)"
    echo "Test file for deletion" > www/file/test_delete.txt
    RESPONSE=$(curl -s -i -X DELETE "http://$SERVER/$DELETE?img=test_delete.txt" | head -n 5)
    echo "$RESPONSE"
    check_response "200" "$RESPONSE"

    print_test "DELETE /$DELETE sin query string (should be 404 Not Found)"
    RESPONSE=$(curl -s -i -X DELETE "http://$SERVER/$DELETE" | head -n 5)
    echo "$RESPONSE"
    check_response "404" "$RESPONSE"
}

test_methods() {
    print_header "PRUEBAS DE MÉTODOS NO PERMITIDOS"
    
    print_test "POST to / (GET only) (should be 405)"
    RESPONSE=$(curl -s -i -X POST "http://$SERVER/" | head -n 5)
    echo "$RESPONSE"
    check_response "405" "$RESPONSE"
    
    print_test "UNKNOWN method to / (should be 400 Bad Request)"
    RESPONSE=$(curl -s -i -X UNKNOWN "http://$SERVER/" | head -n 5)
    echo "$RESPONSE"
    check_response "400" "$RESPONSE"
}

test_payload_size() {
    print_header "PRUEBAS DE TAMAÑO DE PAYLOAD"
    
    print_test "POST 150 bytes to /post_body (limit 100 bytes) (should be 413)"
    PAYLOAD=$(printf 'A%.0s' {1..150})
    RESPONSE=$(curl -s -i -X POST -H "Content-Type: text/plain" -d "$PAYLOAD" "http://$SERVER/post_body" | head -n 5)
    echo "$RESPONSE"
    check_response "413" "$RESPONSE"
}

test_raw() {
    print_header "PRUEBAS CON RAW HTTP"
    
    print_test "Raw GET request to $HOST:$PORT"
    RESPONSE=$(printf "GET / HTTP/1.1\r\nHost: $HOST\r\nConnection: close\r\n\r\n" | nc $HOST $PORT | head -n 5)
    echo "$RESPONSE"
    check_response "200" "$RESPONSE"
    
    print_test "Raw HEAD request to $HOST:$PORT"
    RESPONSE=$(printf "HEAD / HTTP/1.1\r\nHost: $HOST\r\nConnection: close\r\n\r\n" | nc $HOST $PORT | head -n 5)
    echo "$RESPONSE"
    check_response "200" "$RESPONSE"
}

# Show usage
usage() {
    echo -e "${CYAN}════════════════════════════════════════${NC}"
    echo -e "${WHITE}${BOLD}  WebServ Tester - Usage${NC}"
    echo -e "${CYAN}════════════════════════════════════════${NC}"
    echo ""
    echo -e "${YELLOW}Available tests:${NC}"
    echo -e "  ${GREEN}get${NC}        - 🌐 Test GET requests"
    echo -e "  ${GREEN}head${NC}       - 👤 Test HEAD requests"
    echo -e "  ${GREEN}post${NC}       - 📮 Test POST requests"
    echo -e "  ${GREEN}delete${NC}     - 🗑️  Test DELETE requests"
    echo -e "  ${GREEN}methods${NC}    - ⚠️  Test method not allowed"
    echo -e "  ${GREEN}payload${NC}    - 📦 Test client_max_body_size"
    echo -e "  ${GREEN}raw${NC}        - 🔧 Test raw HTTP requests"
    echo -e "  ${GREEN}all${NC}        - 🎯 Run all tests"
    echo ""
    echo -e "${YELLOW}Example:${NC}"
    echo -e "  ${CYAN}$0 get${NC}"
    echo -e "  ${CYAN}$0 all${NC}"
    echo ""
}

# Función para mostrar resultados finales
print_summary() {
    echo ""
    echo -e "${CYAN}╔════════════════════════════════════════╗${NC}"
    echo -e "${CYAN}║${WHITE}${BOLD}          RESUMEN DE PRUEBAS            ${NC}${CYAN}║${NC}"
    echo -e "${CYAN}╚════════════════════════════════════════╝${NC}"
    echo ""
    echo -e "${WHITE}Total de pruebas:${NC} $TOTAL"
    echo -e "${GREEN}✓ Pasadas:${NC} $PASSED"
    echo -e "${RED}✗ Falladas:${NC} $FAILED"
    echo ""
    
    if [ $FAILED -eq 0 ]; then
        echo -e "${GREEN}${BOLD}🎉 ¡TODAS LAS PRUEBAS PASARON! 🎉${NC}"
    else
        PERCENTAGE=$((PASSED * 100 / TOTAL))
        echo -e "${YELLOW}Porcentaje de éxito: ${PERCENTAGE}%${NC}"
    fi
    echo ""
}

# --- Main ---
case "${1:-all}" in
    get)
        test_get
        print_summary
        ;;
    head)
        test_head
        print_summary
        ;;
    post)
        test_post
        print_summary
        ;;
    delete)
        test_delete
        print_summary
        ;;
    methods)
        test_methods
        print_summary
        ;;
    payload)
        test_payload_size
        print_summary
        ;;
    raw)
        test_raw
        print_summary
        ;;
    all)
        echo -e "${PURPLE}${BOLD}"
        echo "╔════════════════════════════════════════════════╗"
        echo "║                                                ║"
        echo "║      🚀 WEBSERV COMPREHENSIVE TESTER 🚀       ║"
        echo "║                                                ║"
        echo "╚════════════════════════════════════════════════╝"
        echo -e "${NC}"
        echo ""
        test_get
        test_head
        test_post
        test_delete
        test_methods
        test_payload_size
        test_raw
        print_summary
        ;;
    help|--help|-h)
        usage
        ;;
    *)
        echo -e "${RED}Unknown test: $1${NC}"
        usage
        exit 1
        ;;
esac