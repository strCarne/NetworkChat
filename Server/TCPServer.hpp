#ifndef VSACHAT_TCPSERVER_HPP
#define VSACHAT_TCPSERVER_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <thread>
#include <mutex>
#include <array>
#include <iostream>

#define NOT_AN_ERR 1

namespace vsa {

    struct AcceptedSocket {
        int acceptedSocketFD;
        sockaddr_in address;
        int error;
        bool acceptedSuccessfully;
    };
    
    class TCPServer {
    public:
        TCPServer(std::string const &ip, unsigned short port, unsigned maxBacklog);

        void startAcceptingConns();

        ~TCPServer();

    private:
        int createTCPIPv4Socket();

        sockaddr_in *createIPv4Address(std::string const &ip, unsigned short port);

        AcceptedSocket *acceptConn();

        void recvData(int clientSocketFD);

        void broadcastToOther(std::array<char, 2048> data, int fromFD);

        void killUserSession(int clientSocketFD);

        int socketFD;
        sockaddr_in *address;
        std::vector<AcceptedSocket *> users;

        static const int bufferCapacity = 2048;
    };
}

#endif