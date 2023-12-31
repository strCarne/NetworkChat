#ifndef CLIENTGUI_BUTTON_HPP
#define CLIENTGUI_BUTTON_HPP

#include "SFML/Graphics.hpp"
#include <functional>
#include <string>

class Menu;

class Button {
public:
    Button(std::string caption, sf::Font &font, unsigned int fontSize, int x, int y);

    sf::Text &getCaption();
    sf::FloatRect &getRectangle();

    void setFontColor(sf::Color const &c);

    void setStyle(sf::Uint32 const &style);

    bool contains(sf::Vector2<int> const &point);

    virtual void update(sf::RenderWindow &w);

    virtual ~Button();

protected:
    sf::Text caption;
    sf::FloatRect rectangle;
};

#endif //CLIENTGUI_BUTTON_HPP
