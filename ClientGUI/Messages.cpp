#include "Messages.hpp"
#include <algorithm>
#include <vector>

Messages::Messages(sf::Font &msgFont): msgFont(msgFont) {}

void Messages::updateDelta(float delta) {
    if (msgs.size() == 0 || delta == 0) {
        return;
    }

    auto fmy = msgs[0].usernameRect.getPosition().y;
    auto lmy = msgs[msgs.size()-1].msgRect.getPosition().y + msgs[msgs.size()-1].msgHeight;

    if (delta > 0 && fmy > HIGHEST_Y_POS) {
        return;
    }

    if (delta < 0 && lmy < LOWEST_Y_POS) {
        return;
    }

    for (auto &msg: msgs) {
        msg.updateDelta(delta);
    }
    return;
}

void Messages::update(sf::RenderWindow &w) {
    for (auto &msg: msgs) {
        msg.update(w);
    }
}

std::string Messages::addMsg(sf::String username, sf::String msg) {
    Message newMsg(username, msg, msgFont);
    updatePosition(newMsg.username.getPosition().y - 20);
    msgs.emplace_back(username, msg, msgFont);
    return newMsg.serialize();
}