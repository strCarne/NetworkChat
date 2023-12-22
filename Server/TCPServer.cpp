#include "TCPServer.hpp"

vsa::TCPServer::TCPServer(std::string const &ip, unsigned short port, unsigned maxBacklog) {
    socketFD = createTCPIPv4Socket();
    address = createIPv4Address(ip, port);

    int error = bind(socketFD, reinterpret_cast<const sockaddr *>(address), sizeof *address);
    if (error != 0) {
        throw std::domain_error("couldn't bind the server socket");
    }

    error = listen(socketFD, maxBacklog);
    if (error != 0) {
        throw std::domain_error("couldn't start listening on the socket");
    }
}

void vsa::TCPServer::startAcceptingConns() {
    std::cout << "Server started.\n";
    std::vector<std::thread> sessions;
    while (true) {
        AcceptedSocket *clientSocket = acceptConn();

        if (!clientSocket->acceptedSuccessfully) {
            std::cout << "fail\n";
            continue;
        }

        // Client accepted
        users.push_back(clientSocket);

        sessions.emplace_back(&TCPServer::recvData, this, clientSocket->acceptedSocketFD);
    }
    for (auto &t: sessions) {
        t.join();
    }
}

vsa::TCPServer::~TCPServer() {
    delete address;
    address = 0;
    for (auto &ptrToAS: users) {
        delete ptrToAS;
        ptrToAS = 0;
    }
}

int vsa::TCPServer::createTCPIPv4Socket() { return socket(AF_INET, SOCK_STREAM, 0); }

sockaddr_in *vsa::TCPServer::createIPv4Address(std::string const &ip, unsigned short port) {
    sockaddr_in *address = new sockaddr_in();
    address->sin_family = AF_INET;
    address->sin_port = htons(port);

    if (ip.empty()) {
        address->sin_addr.s_addr = INADDR_ANY;
    } else {
        inet_pton(AF_INET, ip.c_str(), &address->sin_addr.s_addr);
    }

    return address;
}

vsa::AcceptedSocket *vsa::TCPServer::acceptConn() {
    sockaddr_in address;
    socklen_t addressSize = sizeof address;
    int clientSocketFD = accept(socketFD, (struct sockaddr *) &address, &addressSize);

    AcceptedSocket *acceptedSocket = new AcceptedSocket;
    acceptedSocket->address = address;
    acceptedSocket->acceptedSocketFD = clientSocketFD;
    acceptedSocket->acceptedSuccessfully = clientSocketFD > 0;
    acceptedSocket->error = clientSocketFD > 0 ? NOT_AN_ERR : clientSocketFD;

    return acceptedSocket;
}

void vsa::TCPServer::recvData(int clientSocketFD) {
    // char buffer[bufferCapacity];
    std::array<char, bufferCapacity> buffer;
    while (true) {
        ssize_t amountReceived = recv(clientSocketFD, buffer.data(), bufferCapacity, 0);
        if (amountReceived > 0) {
            buffer[amountReceived] = 0;
            // printf("Client msg: %s", buffer);
            broadcastToOther(buffer, clientSocketFD);
        } else if (amountReceived == 0)  {
            printf("Connection closed.\n");
            break;
        } else {
            printf("ERR\n");
            break;
        }
    }
    killUserSession(clientSocketFD);
    close(clientSocketFD);
}

void vsa::TCPServer::broadcastToOther(std::array<char, 2048> buffer, int fromFD) {
    std::string log(buffer.data());
    std::cout << log << '\n';

    for (int i = 0; i < users.size(); ++i) {
        int userSocketFD = users[i]->acceptedSocketFD;
        if (userSocketFD == fromFD) {
            continue;
        }
        send(userSocketFD, buffer.data(), strlen(buffer.data()), 0);
    }
}

void vsa::TCPServer::killUserSession(int clientSocketFD) {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i]->acceptedSocketFD == clientSocketFD) {
            delete users[i];
            std::swap(users[i], users[users.size()-1]);
            users.pop_back();
            return;
        }
    }
}