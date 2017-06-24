#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Game{
    private:
        RenderWindow window;
        CircleShape player;
        bool mIsMovingDown;
        bool mIsMovingLeft;
        bool mIsMovingRight;
        bool mIsMovingUp;
        bool mIsColorChanged; 
        void update();
        void render();
        void process_events();
        void handlekeyboardactions(Keyboard::Key key ,bool ispressed);
    public:
        Game();
        void run();

};
int main(){
    Game g;
    g.run();
}
Game :: Game():window(VideoMode(400,600),"SFML APPLICATION"),
player(){
    player.setFillColor(sf::Color::Magenta);
    player.setRadius(40.f);
    player.setPosition(100.f,100.f);
}
void Game:: run(){
    while(window.isOpen()){
       process_events();
       update();
       render();
    }
}
void Game::handlekeyboardactions(Keyboard::Key key ,bool ispressed){
    if(key == Keyboard::W)
        mIsMovingUp = ispressed;
    if(key== Keyboard::D)
        mIsMovingRight = ispressed;
    if(key == Keyboard::S)
        mIsMovingDown = ispressed;
    if(key ==Keyboard::A)
        mIsMovingLeft = ispressed;
    if(key == Keyboard::C)
        mIsColorChanged =ispressed;



}
void Game::process_events(){
    Event event;
    while(window.pollEvent(event)){
        switch(event.type){
            case Event::KeyPressed:
            handlekeyboardactions(event.key.code,true);
            break;
            case Event::KeyReleased:
            handlekeyboardactions(event.key.code,false);
            break;
            case Event::Closed:
            window.close();
            break;
        }
    }
}

void Game::update()
{
    static int colorcount ;
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp)
    movement.y -= 1.f;
    if (mIsMovingDown)
    movement.y += 1.f;
    if (mIsMovingLeft)
    movement.x -= 1.f;
    if (mIsMovingRight)
    movement.x += 1.f;
    if( mIsColorChanged ){

        
        colorcount++;
        cout<<"current color "<<colorcount<<"\n";
        if(colorcount >4){ colorcount =0; }
        switch(colorcount){
            case 0: 
                player.setFillColor(Color::Red);
                break;
            case 1:
                player.setFillColor(Color::Blue);
                break;
            case 2:
                player.setFillColor(Color::Cyan);
                break;
            case 3:
                player.setFillColor(Color::Magenta);
                break;
            case 4:
                player.setFillColor(Color::White);
                break;
            }        
        }
        player.move(movement);
}



void Game ::render(){
    window.clear();
    window.draw(player);
    window.display();
}

