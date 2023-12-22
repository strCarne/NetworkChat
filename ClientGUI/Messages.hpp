#ifndef MESSAGES_HPP
#define MESSAGES_HPP

#include "Message.hpp"
#include "SFML/Graphics.hpp"
#include <vector>
#include <string>

class Messages {
public:
    Messages(sf::Font &msgFont);
    void updateDelta(float delta);
    void update(sf::RenderWindow &w);
    std::string addMsg(sf::String username, sf::String msg);
    
    void addMsg(Message &newMsg) {
        updatePosition(newMsg.username.getPosition().y - 20);
        msgs.push_back(newMsg);
    }

    void updatePosition(int start) {
        for (int i = msgs.size() - 1; i >= 0; i--) {
            auto yLow = msgs[i].msgRect.getPosition().y + msgs[i].msgHeight;
            auto delta =  start - yLow;
            msgs[i].updateDelta(delta);
            start = msgs[i].usernameRect.getPosition().y - 20;
        }
    }

    sf::Font &getFont() { return msgFont; }

private:
    std::vector<Message> msgs;
    sf::Font msgFont;
};

#endif