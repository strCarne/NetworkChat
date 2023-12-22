#ifndef INPUTBOX_HPP
#define INPUTBOX_HPP

#include "SFML/Graphics.hpp"

class InputBox {
public:
    InputBox(sf::String initialMessege, float x, float y, float w, float h, sf::Font &chatFont, int charCap, int charLineCap);

    void add(sf::String c);

    sf::String extract();

    void update(sf::RenderWindow &w);

    sf::String input;
private:
    sf::Text initMsg;
    sf::Text currText;
    sf::RectangleShape rect;
    int charCap, charLineCap;
};

#endif