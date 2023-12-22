#include "TCPServer.hpp"

int main() {
    vsa::TCPServer server("", 2000, 10);
    server.startAcceptingConns();
}