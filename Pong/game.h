#pragma once

#include "window.h"


class game{

    window m_window;
    sf::RectangleShape top;
    sf::RectangleShape bottom;
    sf::RectangleShape left;
    sf::RectangleShape right;
    sf::RectangleShape ball; 

    public:
    game();
    void handle_input();
    void Update();
    void render();
    window* getwindow();
    bool is_collision(sf::RectangleShape& r1 , sf::RectangleShape& r2);

};