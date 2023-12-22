#include "InputBox.hpp"

InputBox::InputBox(sf::String initialMessage, float x, float y, float w, float h, sf::Font &chatFont, int charCap, int charLineCap) {
    initMsg.setPosition(x + 10, y + 10);
    initMsg.setColor(sf::Color::White);
    initMsg.setFont(chatFont);
    initMsg.setColor(sf::Color::Black);
    initMsg.setCharacterSize(20);
    initMsg.setString(initialMessage);

    currText.setPosition(x + 10, y + 10);
    currText.setColor(sf::Color::Black);
    currText.setCharacterSize(20);
    currText.setFont(chatFont);

    rect.setSize({w, h});
    rect.setPosition({x, y});
    rect.setFillColor(sf::Color::White);

    this->charCap = charCap;
    this->charLineCap = charLineCap;
}

void InputBox::add(sf::String c) {
    if (input.getSize() == charCap + (charCap / charLineCap - 1) && c != '\b') {
        return;
    }
    if (c == '\b') {
                if (input.getSize() > 0) {
                    input.erase(input.getSize()-1);
                    if (input.getSize() > 0 && input[input.getSize()-1] == '\n') {
                        input.erase(input.getSize()-1);
                    }
                }
    } else {

        int lineNum = input.getSize() / charLineCap;
        int elNum = input.getSize() % charLineCap;
        if (lineNum > 0 && elNum - lineNum == -1) {
            input += '\n';
        }
        input += c;

    }
}

sf::String InputBox::extract() {
    sf::String result = input;
    input.clear();
    return result;
}

void InputBox::update(sf::RenderWindow &w) {
    w.draw(rect);
    if (input.isEmpty()) {
        w.draw(initMsg);
    } else {
        currText.setString(input);
        w.draw(currText);
    }
}