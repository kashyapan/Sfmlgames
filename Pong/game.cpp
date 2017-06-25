#include "game.h"

game::game():m_window("Pong game",sf::Vector2u(640,480))
{ 
top.setPosition(240,120);
top.setFillColor(sf::Color::Blue);
top.setSize(sf::Vector2f(30,120));
}
void game::handle_input(){

}
window* game::getwindow(){ return &m_window ;}


void game::render(){
    m_window.begin_draw();
    m_window.draw_func(top);
    m_window.end_draw();
}

void game::Update(){
    m_window.update_func();
}