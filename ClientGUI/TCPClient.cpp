#include "TCPClient.hpp"

vsa::TCPClient::TCPClient(std::string const &ip, unsigned short port): errorState(false) {
    socketFD = createTCPIPv4Socket();
    address = createIPv4Address(ip, port);
    errorState = connect(socketFD, reinterpret_cast<const struct sockaddr *>(address), sizeof *address);
    session = 0;
}

bool vsa::TCPClient::alive() { return errorState == false; }

void vsa::TCPClient::send(std::string serializedMsg) {
    const char *buffer = serializedMsg.c_str();
    size_t amountWasSent = ::send(socketFD, buffer, strlen(buffer), 0);
    if (amountWasSent < serializedMsg.length()) {
        std::cout << "Server side error: server isn't working.\n";
        // break;
    }
}

void vsa::TCPClient::recvMessages(Messages &messages, std::mutex &mx) {
    session = new std::thread(&TCPClient::dial, this, std::ref<Messages>(messages), std::ref<std::mutex>(mx));
}

void vsa::TCPClient::dial(Messages &messages, std::mutex &mx) {
    char buffer[bufferCapacity];
    while (true) {
        ssize_t amountReceived = recv(socketFD, buffer, 2048, 0);
        if (amountReceived > 0) {
            buffer[amountReceived] = 0;
            Message msg;
            std::string serializedMsg(buffer);
            Message::deserialize(serializedMsg, msg, messages.getFont());

            std::lock_guard<std::mutex> lock(mx);
            messages.addMsg(msg);

        } else if (amountReceived == 0)  {
            // connection closed
            break;
        } else {
            // error
            break;
        }
    }
}

int vsa::TCPClient::createTCPIPv4Socket() { return socket(AF_INET, SOCK_STREAM, 0); }

sockaddr_in *vsa::TCPClient::createIPv4Address(std::string const &ip, unsigned short port) {
    sockaddr_in *address = new sockaddr_in();
    address->sin_family = AF_INET;
    address->sin_port = htons(port);

    if (ip.length() == 0) {
        address->sin_addr.s_addr = INADDR_ANY;
    } else {
        inet_pton(AF_INET, ip.c_str(), &address->sin_addr.s_addr);
    }

    return address;
}

vsa::TCPClient::~TCPClient() {
    delete address;
    close(socketFD);
    if (session != 0) {
        session->join();
        delete session;
    }
}