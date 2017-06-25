#include "game.h"

const int width = 640;
const int height = 480;
const int border_size = 30;
game::game():m_window("Pong game",sf::Vector2u(width,height))
{ 
top.setPosition(border_size,0);
top.setFillColor(sf::Color(100,100,100));
top.setSize(sf::Vector2f(width-2*border_size,border_size));
top.setOutlineThickness(3);
top.setOutlineColor(sf::Color::Blue);

bottom.setPosition(border_size,height-border_size);
bottom.setFillColor(sf::Color(100,100,100));
bottom.setSize(sf::Vector2f(width-2*border_size,border_size));
bottom.setOutlineThickness(3);
bottom.setOutlineColor(sf::Color::Blue);



left.setPosition(0,0);
left.setFillColor(sf::Color(100,100,100));
left.setSize(sf::Vector2f(border_size,height));
left.setOutlineThickness(3);
left.setOutlineColor(sf::Color::Blue);


right.setPosition(600,0);
right.setFillColor(sf::Color(100,100,100));
right.setSize(sf::Vector2f(border_size,height));
right.setOutlineThickness(3);
right.setOutlineColor(sf::Color::Blue);


ball.setPosition(height/2,width/2);
ball.setFillColor(sf::Color(100,100,100));
ball.setSize(sf::Vector2f(20,20));
ball.setOutlineThickness(2);
ball.setOutlineColor(sf::Color::Cyan);



}
void game::handle_input(){

}
window* game::getwindow(){ return &m_window ;}


void game::render(){
    m_window.begin_draw();
    m_window.draw_func(top);
    m_window.draw_func(bottom);
    m_window.draw_func(left);
    m_window.draw_func(right);
    m_window.draw_func(ball);
    m_window.end_draw();
}

void game::Update(){
    m_window.update_func();
}