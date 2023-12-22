#ifndef TCPCLIENT_HPP
#define TCPCLIENT_HPP

#include "SFML/Graphics.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <thread>
#include <stdexcept>
#include <mutex>
#include <string>
#include <memory>
#include <iostream>
#include "Messages.hpp"

namespace vsa {

    class TCPClient {
    public:
        TCPClient() {}

        TCPClient(std::string const &ip, unsigned short port);

        void send(std::string serializedMsg);

        void recvMessages(Messages &messages, std::mutex &m);

        ~TCPClient();

        void dial(Messages &messages, std::mutex &m);

        bool alive();
    private:

        int createTCPIPv4Socket();
        struct sockaddr_in *createIPv4Address(std::string const &ip, unsigned short port);

        int socketFD;
        sockaddr_in *address;
        std::thread *session;

        bool errorState;

        static const int bufferCapacity = 2048;

    };

}

#endif