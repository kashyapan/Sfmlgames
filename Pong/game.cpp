#include "game.h"

const int width = 640;
const int height = 480;
const int border_size = 30;
bool game::is_moving_up = false;
bool game::is_moving_down = false;
 sf::Vector2f ballspeed(4.0,.40);
game::game():m_window("Pong game",sf::Vector2u(width,height))
{ 
top.setPosition(border_size,0);
top.setFillColor(sf::Color(100,100,100));
top.setSize(sf::Vector2f(width-2*border_size,border_size));
top.setOutlineThickness(3);
top.setOutlineColor(sf::Color::Red);

bottom.setPosition(border_size,height-border_size);
bottom.setFillColor(sf::Color(100,100,100));
bottom.setSize(sf::Vector2f(width-2*border_size,border_size));
bottom.setOutlineThickness(3);
bottom.setOutlineColor(sf::Color::Red);



left.setPosition(0,0);
left.setFillColor(sf::Color(100,100,100));
left.setSize(sf::Vector2f(border_size,height));
left.setOutlineThickness(3);
left.setOutlineColor(sf::Color::Red);

right.setPosition(600,0);
right.setFillColor(sf::Color(100,100,100));
right.setSize(sf::Vector2f(border_size,height));
right.setOutlineThickness(3);
right.setOutlineColor(sf::Color::Red);


ball.setRadius(12);
ball.setPosition(height/2,width/2);
ball.setFillColor(sf::Color(100,100,100));
ball.setOutlineThickness(2);
ball.setOutlineColor(sf::Color::Cyan);


line.setPosition(300,0);



line.setFillColor(sf::Color::Yellow);
line.setSize(sf::Vector2f(5,height));
line.setOutlineThickness(1);
line.setOutlineColor(sf::Color::Red);


player1.setFillColor(sf::Color::Blue);
player1.setSize(sf::Vector2f(10,height/7));
player1.setOutlineThickness(1);
player1.setOutlineColor(sf::Color::Blue);
player1.setPosition(border_size+20,height/3);

player2.setFillColor(sf::Color::Red);
player2.setSize(sf::Vector2f(10,height/7));
player2.setOutlineThickness(1);
player2.setOutlineColor(sf::Color::Red);
player2.setPosition(580,height/3);



}
 void game::handle_input(sf::Keyboard::Key key,bool ispressed){
    if(key == sf::Keyboard::W)
     is_moving_up = ispressed;
     if(key == sf::Keyboard::S)
    is_moving_down = ispressed;
    
}
window* game::getwindow(){ return &m_window ;}

bool game:: is_collision(sf::CircleShape & r1, sf::RectangleShape& r2){
    sf::FloatRect f1 = r1.getGlobalBounds();
    sf::FloatRect f2 = r2.getGlobalBounds();
    return f1.intersects(f2);
}

bool game:: is_collision(sf::RectangleShape & r1, sf::RectangleShape& r2){
    sf::FloatRect f1 = r1.getGlobalBounds();
    sf::FloatRect f2 = r2.getGlobalBounds();
    return f1.intersects(f2);
}

void game::render(){
    m_window.begin_draw();
    m_window.draw_func(top);
    m_window.draw_func(bottom);
    m_window.draw_func(left);
    m_window.draw_func(right);
    m_window.draw_func(ball);
    m_window.draw_func(line);
    m_window.draw_func(player1);
    m_window.draw_func(player2);
    m_window.end_draw();

    if(is_collision(ball,top))
    ballspeed.y =-ballspeed.y;
    if(is_collision(ball,left))
    ballspeed.x =-ballspeed.x;
    if(is_collision(ball,right))
    ballspeed.x =-ballspeed.x;
    if(is_collision(ball,bottom))
    {
    ballspeed.y =-ballspeed.y;
    }

 
    if(is_collision(ball,player1) || (is_collision(ball,player2)))
    {
        ballspeed.x=-ballspeed.x;
    
       
    }

    
    
    if(is_moving_up && !is_collision(player1,top))
  {
    player1.move(0,-20.0);
   } 
   if(is_moving_down && !is_collision(player1,bottom))
   { 
       player1.move(0,10.0);
   }
  if (ball.getPosition().y  + ball.getRadius()< player2.getPosition().y  )
            player2.move(0, -10.0);
        else if(ball.getPosition().y+ball.getRadius() > player2.getPosition().y+player2.getSize().y)
            player2.move(0, 10.0);
    ball.move(ballspeed);
}

void game::Update(){
    m_window.update_func();
}
