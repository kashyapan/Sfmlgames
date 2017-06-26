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
    sf::RectangleShape player1;
    sf::RectangleShape player2;
    static bool is_moving_up;
    static bool is_moving_down;

    public:
    game();
   static void handle_input(sf::Keyboard::Key Key,bool ispressed);
    void Update();
    void render();
    window* getwindow();
    bool is_collision(sf::CircleShape& r1 , sf::RectangleShape& r2);

};