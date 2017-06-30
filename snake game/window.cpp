#include "window.h"
#include <Clock.hpp>

sf::Clock clock ;
float timetaken =0;
const float delay = 0.2;
Window :: Window(std::string& title , sf::Vector2u& size){
  setup(title, size);
  }

void Window::setup(std::string title , sf::Vector2u size){
    m_size = size;
    m_window_title = title;
    done =false;
    create_func();
    }

Snake* Window::GetSnake(){
    return &m_snake;

}
void Window::create_func(){
    m_window.create({m_size.x,m_size.y,32}, title );
}    

void Window::BeginDraw(){
    m_window.clear(sf::Color::Black);

}

void Window::Draw(sf::Drawable& delement){
    m_window.draw(delement);
}



void Window:: End_Draw(){
    m_window.display();
}



void Window::destroy(){
    m_window.close();
}

void Window::Update_Func(){
    float time = clock.getElapsedTime().asSeconds;
    clock.restart();
    timetaken+=time;
    while(!done){
        sf::Event event;
        while(m_window.pollEvent(event){
            switch(event){
            case sf::Event::KeyPressed:
            m_snake.Handle_Input(event.key);
            break;
            case sf::Event::KeyReleased:
            m_snake.Handle_Input(event.key);
            break;
            case sf::Event::Closed:
            destroy();
        }

    }   
        if(timetaken>delay ){
            m_snake.runsnake();
        }
        
    }
}

bool Window::IsDone(){
    return done;
}