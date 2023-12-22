#include "SFML/Graphics.hpp"
#include "Menu.hpp"
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 700), "LocalChat");
    window.setFramerateLimit(60);

    std::vector<Menu *> menus;
    initMenuCash(menus);

    int menuID = MAIN_MENU_ID;
    while (menuID != EXIT_ID) {
        menuID = menus[menuID]->display(window);
    }

    for (int i = 0; i < menus.size(); ++i) {
        delete menus[i];
    }

    return 0;
}

