#pragma once 
#include "window.h"
#include "snake.h"
class Game{
    private:
    Window m_window;
    Snake m_snake; 
    sf::Vector2u size; 
    public:
    Window* GetWindow();
    Snake* GetSnake();
    Game();
     void Render();
    void Update();
     void Draw(sf::Drawable& delement);

};