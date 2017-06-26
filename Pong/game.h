#pragma once

#include "window.h"


class game{

    window m_window;
    sf::RectangleShape top;
    sf::RectangleShape bottom;
    sf::RectangleShape left;
    sf::RectangleShape right;
    sf::CircleShape ball;
    sf::RectangleShape line;

    public:
    game();
    void handle_input();
    void Update();
    void render();
    window* getwindow();
    bool is_collision(sf::CircleShape& r1 , sf::RectangleShape& r2);

};