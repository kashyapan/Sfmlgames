#include "game.h"

const int width = 640;
const int height = 480;
const int border_size = 30;
game::game():m_window("Pong game",sf::Vector2u(width,height))
{ 
top.setPosition(border_size,20);
top.setFillColor(sf::Color(100,100,100));
top.setSize(sf::Vector2f(width-2*border_size,border_size));
top.setOutlineThickness(3);
top.setOutlineColor(sf::Color::Blue);

bottom.setPosition(border_size,420);
bottom.setFillColor(sf::Color(100,100,100));
bottom.setSize(sf::Vector2f(width-2*border_size,border_size));
bottom.setOutlineThickness(3);
bottom.setOutlineColor(sf::Color::Blue);
}
void game::handle_input(){

}
window* game::getwindow(){ return &m_window ;}


void game::render(){
    m_window.begin_draw();
    m_window.draw_func(top);
    m_window.draw_func(bottom);
    m_window.end_draw();
}

void game::Update(){
    m_window.update_func();
}