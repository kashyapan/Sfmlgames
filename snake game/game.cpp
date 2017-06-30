#include "game.h"


sf::Vector2u size= (640,480);
const std::string title = "Snake game -1 ";
Game::Game():m_window(title, size){}




Window* Game::GetWindow(){
    return &m_window;
}
Snake* Game::GetSnake(){
    return &m_snake;
}

void Game::Draw(sf::Drawable& delement){
    m_window.BeginDraw();
    m_window.Draw(delement);
    m_window.End_Draw();
}

void Game::Render(){



}

void Game::Update(){
    m_window.Update_Func();
}