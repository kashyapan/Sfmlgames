#pragma once
#include "snake.h"
#include<SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Window {
    private:
    Snake m_snake;
    sf::RenderWindow m_window;
    sf::Vector2u m_size;
    std::string m_window_title;
    bool done;
    void setup(std::string title, sf::Vector2f size);
    void create_func();
    void destroy();
    public:
    Window();
    Window(std::string& title , sf::Vector2f& size);
    void BeginDraw();
    void End_Draw();
    bool IsDone();
    
    void Draw(sf::Drawable& delement );
    void Update_Func();
};