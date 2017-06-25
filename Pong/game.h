#pragma once

#include "window.h"


class game{

    window m_window;
    sf::RectangleShape top;

    public:
    game();
    void handle_input();
    void Update();
    void render();
    window* getwindow();

};