#include "window.h"
#include "game.h"

window::window(const std::string& title , const sf::Vector2u& size){
    setup(title,size);
}




void window::setup(const std::string& title, const sf::Vector2u& size){
    m_window_title = title;
    m_window_size = size;
    m_window.setFramerateLimit(60);
    done = false;
    create_func();
    
}



void window::create_func(){
    m_window.create({m_window_size.x, m_window_size.y,32}, m_window_title);
}



void window::destroy(){
    done = true;
    m_window.close();

}



void window::begin_draw(){
    m_window.clear(sf::Color::White);

}



void window::end_draw(){
    m_window.display();
}


void window::draw_func(sf::Drawable& d_element){
    m_window.draw(d_element);
}

sf::Vector2u& window:: getwindowsize(){
    return m_window_size;
}



void window::update_func(){
    sf::Event event;
    while(m_window.pollEvent(event)){
        if(event.type ==sf::Event::Closed)
        destroy();
        switch(event.type ){
            case sf::Event::KeyPressed:
            game::handle_input(event.key.code,true);
            break;
            case sf::Event::KeyReleased:
            game::handle_input(event.key.code,false);
        }
    }
}

bool window::is_done() { return done ;}


    

