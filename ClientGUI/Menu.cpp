#include "Menu.hpp"
#include <iostream>

Menu::Menu(std::string configFileName) {
    std::ifstream in(configFileName);
    if (!in.good()) {
        return;
    }

    std::string fontPath;
    in >> fontPath;
        font.loadFromFile(fontPath);

    int n;
    for (in >> n; n > 0; --n) {
        std::string btnText;
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(in, btnText);
        int fontSize, x, y;
        in >> fontSize >> x >> y;
        buttons.emplace_back(btnText, font, fontSize, x, y);
    }
}

void Menu::update(sf::RenderWindow &w) {
    for (auto btn : buttons) {
        btn.update(w);
    }
}

int MainMenu::display(sf::RenderWindow &window) {
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                return EXIT_ID;
            case sf::Event::MouseButtonReleased:
                switch (event.mouseButton.button) {
                case sf::Mouse::Left:
                    if (buttons[chat].contains(sf::Mouse::getPosition(window))) {
                        return CLIENT_MENU_ID;
                    }
                    if (buttons[about].contains(sf::Mouse::getPosition(window))) {
                        return ABOUT_MENU_ID;
                    }
                    if (buttons[exit].contains(sf::Mouse::getPosition(window))) {
                        window.close();
                        return EXIT_ID;
                    }
                    break;
                }
            }
        }
        window.clear();
        update(window);
        window.display();
    }
}

int AboutMenu::display(sf::RenderWindow &window) {
    s = "The \"LocalChat\" application is a group chat\nfor users connected to a single LAN. It \nprovides messaging using the TCP/IP protocol. \nThis app is not a Telegram or WhatsApp killer,\nit's just trying to occupy its niche in local\nnetwork group chats. If you have any comments\nor suggestions, you can email me.\nvsa@gmail.com";
    
    sf::Text t;
    t.setString(s);
    t.setFont(font);
    t.setColor(sf::Color::Green);
    t.setCharacterSize(18);
    t.setPosition({50, 225});
    sf::IntRect rect = sf::IntRect(t.getGlobalBounds());
    // sf::RectangleShape rectShape();
    

    sf::Event event;
    while (window.isOpen()) {
        if (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                return EXIT_ID;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left &&
                    buttons[back].contains(sf::Mouse::getPosition(window))) {
                        return MAIN_MENU_ID;
                    }
            }
        }
        window.clear();
        update(window);
        window.draw(t);
        window.display();
    }

    return EXIT_ID;
}

void alert(sf::String s, sf::Font &f) {
    sf::Text t;
    t.setString(s);
    t.setFont(f);
    t.setColor(sf::Color::Green);
    t.setCharacterSize(36);
    t.setPosition({30, 30});
    sf::IntRect rect = sf::IntRect(t.getGlobalBounds());

    sf::Event event;
    sf::RenderWindow w(sf::VideoMode(rect.width + 60, rect.height + 60), "ALERT");
    while (w.isOpen()) {
        if (w.pollEvent(event)) {
            switch(event.type) {
            case sf::Event::TextEntered:
                if (event.text.unicode == '\n') {
                    w.close();
                    return;
                }
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Left && rect.contains(sf::Mouse::getPosition(w))) {
                    w.close();
                    return;
                }
                break;
            case sf::Event::Closed:
                w.close();
                return;
            }
        }
        w.clear();
        w.draw(t);
        w.display();
    }
}

int ClientMenu::display(sf::RenderWindow &window) {
    vsa::TCPClient client("", 2000);
    if (!client.alive()) {
        alert("ERROR: couldn't connect to\nthe server.\n\nPossible reasons:\n1) Server is not available.\n2) Your computer isn't\nconnected to the network.", font);
        return MAIN_MENU_ID;
    }

    sf::Event event;
    sf::Font chatFont;
    chatFont.loadFromFile("fonts/jetbrains/JetBrainsMono-Light.ttf");

    InputBox *unIB = new InputBox("Your username...", 195, 330, 210, 40, chatFont, 16, 16);
    sf::String strUserName;
    while (window.isOpen() && strUserName.isEmpty()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                return EXIT_ID;
            case sf::Event::MouseButtonReleased:
                switch (event.mouseButton.button) {
                case sf::Mouse::Left:
                    if (buttons[back].contains(sf::Mouse::getPosition(window))) {
                        return MAIN_MENU_ID;
                    }
                    break;
                }
                break;
            case sf::Event::TextEntered:
                if (event.text.unicode >= 128) {
                    alert(UNICODE_ALERT, font);
                } else if (event.text.unicode == '\n') {
                    strUserName = unIB->extract();
                    break;
                } else {
                    unIB->add(event.text.unicode);
                }
                break; 
            }
        }
        window.clear();
        unIB->update(window);
        update(window);
        window.display();
    }
    delete unIB;

    sf::String usernameTemplate = "Username: ";
    usernameTemplate += strUserName;

    sf::Text username;
    username.setString(usernameTemplate);
    username.setFont(font);
    username.setPosition(20, 655);
    username.setCharacterSize(25);
    username.setColor(sf::Color::Green);

    std::mutex mx;
    Messages storage(chatFont);
    client.recvMessages(storage, mx);

    InputBox ib("Enter your messege here...", LEFT_X_INDENT, 450, MSG_WIDTH, 200, chatFont, 315, MSG_CHAR_LINE_CAP);
    sf::RectangleShape panel({600, 700 - LOWEST_Y_POS});
    panel.setPosition({0, LOWEST_Y_POS});
    panel.setFillColor(sf::Color::Black);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                return EXIT_ID;
            case sf::Event::MouseButtonReleased:
                switch (event.mouseButton.button) {
                case sf::Mouse::Left:
                    if (buttons[back].contains(sf::Mouse::getPosition(window))) {
                        return MAIN_MENU_ID;
                    }
                    break;
                }
                break;

            case sf::Event::TextEntered:
                if (event.text.unicode >= 128) {
                    alert(UNICODE_ALERT, font);
                } else if (event.text.unicode == '\n') {
                    mx.lock();
                    std::string serializedMsg = storage.addMsg(strUserName, ib.extract());
                    mx.unlock();
                    client.send(serializedMsg);
                } else {
                    ib.add(event.text.unicode);
                }
                break; 

            case sf::Event::MouseWheelScrolled:
                // cout << event.mouseWheelScroll.delta << '\n';
                storage.updateDelta(event.mouseWheelScroll.delta);
                break;
            }
        }
        window.clear();
        storage.update(window);
        window.draw(panel);
        ib.update(window);
        update(window);
        window.draw(username);
        window.display();
    }
}

void initMenuCash(std::vector<Menu *> &menus) {
    menus.resize(MENUS_NUMBER, 0);
    menus[MAIN_MENU_ID] = new MainMenu();
    menus[ABOUT_MENU_ID] = new AboutMenu();
    menus[CLIENT_MENU_ID] = new ClientMenu();
}