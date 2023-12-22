#include "Message.hpp"

Message::Message(sf::String &strUsername, sf::String &strMsg, sf::Font &msgFont) {
    username.setString(strUsername);
    username.setFont(msgFont);
    username.setColor(sf::Color::Red);
    username.setCharacterSize(20);

    msg.setString(strMsg);
    msg.setFont(msgFont);
    msg.setColor(sf::Color::Blue);
    msg.setCharacterSize(20);

    int numOfLines = strMsg.getSize() / (MSG_CHAR_LINE_CAP + 1) + 1;
    msgHeight = numOfLines * (20 + 10) + 10;
    msgRect.setPosition(LEFT_X_INDENT, LOWEST_Y_POS - msgHeight);
    msgRect.setSize({float(std::max<int>(std::min<int>(strMsg.getSize() * 12 + 10 + 10, MSG_WIDTH), strUsername.getSize() * 12 + 10 + 10)), (float)msgHeight});
    msg.setPosition(LEFT_X_INDENT + 10, LOWEST_Y_POS - msgHeight + 10);
    msgRect.setFillColor(sf::Color::White);

    unHeight = 40;
    usernameRect.setPosition(LEFT_X_INDENT, LOWEST_Y_POS - msgHeight - unHeight);
    usernameRect.setSize({float(strUsername.getSize() * 12 + 10 + 10), (float)40});
    username.setPosition(LEFT_X_INDENT + 10, LOWEST_Y_POS - msgHeight - unHeight + 10);
    usernameRect.setFillColor(sf::Color::White);
}

void Message::update(sf::RenderWindow &w) {
    w.draw(usernameRect);
    w.draw(username);
    w.draw(msgRect);
    w.draw(msg);
}

void Message::updateDelta(float delta) {
    username.move(0, delta);
    usernameRect.move(0, delta);
    msg.move(0, delta);
    msgRect.move(0, delta);
}

std::string Message::serialize() {
    json j;
    j["username"] = username.getString().toAnsiString();
    j["message"] = msg.getString().toAnsiString();
    return j.dump();
}

void Message::deserialize(std::string jsonMessage, Message &into, sf::Font &useFont) {
    std::stringstream jsonStream(jsonMessage);
    json data = json::parse(jsonStream);

    std::string un = data.at("username");
    std::string m = data.at("message");

    sf::String username = sf::String(un);
    sf::String message = sf::String(m);
    into = Message(username, message, useFont);
}