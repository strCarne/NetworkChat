#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <memory>
#include <iostream>
#include <iostream>
#include <sstream>

#define HIGHEST_Y_POS 20
#define LOWEST_Y_POS 430
#define LEFT_X_INDENT 20
#define MSG_WIDTH 560
#define MSG_CHAR_LINE_CAP 45

using json = nlohmann::json;

class Message {
public:
    Message() {}
    Message(sf::String &strUsername, sf::String &strMsg, sf::Font &msgFont);
    
    void update(sf::RenderWindow &w);
    void updateDelta(float delta);

    std::string serialize();
    static void deserialize(std::string jsonMessage, Message &into, sf::Font &useFont);

    friend class Messages;

private:
    sf::Text username;
    sf::RectangleShape usernameRect;
    sf::Text msg;
    sf::RectangleShape msgRect;
    int unHeight, msgHeight;
};

#endif