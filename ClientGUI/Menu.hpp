#ifndef CLIENTGUI_MENU_HPP
#define CLIENTGUI_MENU_HPP

#include "TCPClient.hpp"
#include "Button.hpp"
#include "Messages.hpp"
#include "InputBox.hpp"
#include "SFML/Graphics.hpp"
#include <vector>
#include <fstream>

#define MAIN_MENU_CONFIG "/Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/config/MainMenu"
#define CHAT_OPTIONS_MENU_CONFIG "/Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/config/ChatMenu"
#define ABOUT_MENU_CONFIG "/Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/config/AboutMenu"
#define CLIENT_MENU_CONFIG "/Users/strCarne/Documents/Projects/C++/Networking/NetworkChat/ClientGUI/config/ClientMenu"

#define MENUS_NUMBER 3
#define EXIT_ID -1
#define MAIN_MENU_ID 0
#define ABOUT_MENU_ID 1
#define CLIENT_MENU_ID 2

#define UNICODE_ALERT "\t\t\t\t\tApologies!\nUnicode symbols are not available.\n\t Please, use ASCII characters."

class Menu {
public:
    virtual int display(sf::RenderWindow &w) = 0;

    void update(sf::RenderWindow &w);

    void contains(sf::Vector2<int> const &point);

    virtual ~Menu() {}

protected:
    Menu(std::string configFileName);
    std::vector<Button> buttons;
    sf::Font font;
};

class MainMenu: public Menu {
public:
    MainMenu(): Menu(MAIN_MENU_CONFIG) {}
    int display(sf::RenderWindow &w);
    ~MainMenu() {}
private:
    const char chat = 0;
    const char about = 1;
    const char exit = 2;
};

class AboutMenu: public Menu {
public:
    AboutMenu(): Menu(ABOUT_MENU_CONFIG) {}
    int display(sf::RenderWindow &w);
    ~AboutMenu() {}
private:
    const char back = 0;

    sf::String s;
};

class ChatOptionsMenu: public Menu {
public:
    ChatOptionsMenu(): Menu(CHAT_OPTIONS_MENU_CONFIG) {}
    int display(sf::RenderWindow &w);
    ~ChatOptionsMenu() {}
private:
    const char client = 0;
    const char server = 1;
    const char goBack = 2;
};

class ClientMenu: public Menu {
public:
    ClientMenu(): Menu(CLIENT_MENU_CONFIG) {}
    int display(sf::RenderWindow &w);
    ~ClientMenu() {}
private:
    const char back = 0;
};

void initMenuCash(std::vector<Menu *> &);

#endif