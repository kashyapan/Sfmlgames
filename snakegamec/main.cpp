#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <iostream>
int num=4;
class snake{
    snake* next;
    int x;
    int y;
    snake* head;
    public:
    snake(){
        head =0;
        next=0;
    }
};
int dir;
struct snakecheck{
    int x;
    int y;
}s[100];

int prev;


struct food{
    int x;
    int y;
}f;
void run(){




   
    for(int i =num ;i>0;i--){
        s[i].x=s[i-1].x;
        s[i].y =s[i-1].y;
    }

        if(dir==3)
    s[0].y -=1;
    if(dir ==0)
    s[0].y +=1;
    if(dir == 1)
    s[0].x -=1;
    if(dir ==2)
    s[0].x +=1;
    if(s[0].x ==f.x && s[0].y ==f.y){ 
        num++;
        f.x =1+rand()%12;
        f.y=1+rand()%12;
    }
    


              
                  

for(int i =1;i<num;i++){
    if(s[0].x ==s[i].x&& s[0].y ==s[i].y ){
        num=4;
    }
}
    

}

bool iscollision(sf::RectangleShape& rect,sf::Sprite& s1){
    
    sf::FloatRect f1 = rect.getGlobalBounds();
    sf::FloatRect f2 = s1.getGlobalBounds();
    return f1.intersects(f2);

}
    


void restart(){
    s[0].x= 15;
    s[0].y=15;
    num=4;

}






int main(){


    float timer =0;
    float time=0;
    sf::Clock clock;
    sf::RectangleShape top;
    sf::RectangleShape bottom;
    sf::RectangleShape left;
    sf::RectangleShape right;
    int border_size =30;
    int height =800;
    int width =600;
    f.x=20;
    f.y=20;
    s[0].x =15;
    s[0].x=15;
top.setPosition(0,-8);
top.setFillColor(sf::Color(100,100,100));
top.setSize(sf::Vector2f(height,10));
top.setOutlineThickness(3);
top.setOutlineColor(sf::Color::Red);

bottom.setPosition(10,600);
bottom.setFillColor(sf::Color(100,100,100));
bottom.setSize(sf::Vector2f(height ,20));
bottom.setOutlineThickness(3);
bottom.setOutlineColor(sf::Color::Red);



left.setPosition(0,0);
left.setFillColor(sf::Color(100,100,100));
left.setSize(sf::Vector2f(0,height));
left.setOutlineThickness(3);
left.setOutlineColor(sf::Color::Red);

right.setPosition(800,0);
right.setFillColor(sf::Color(100,100,100));
right.setSize(sf::Vector2f(border_size,height));
right.setOutlineThickness(3);
right.setOutlineColor(sf::Color::Red);

    
    sf::RenderWindow m_window;
    m_window.create(sf::VideoMode(800,600),"Snake game without oops ");
    sf::Texture t1;
    sf::Texture t2;
    bool collision =false;

        t1.loadFromFile("images/red.png");
        t2.loadFromFile("images/green.png");
        sf::Sprite s2(t2);
        sf::Sprite s1(t1);
        s1.setPosition(100,25);
        s2.setPosition(f.x,f.y);
        m_window.setFramerateLimit(60);
    while(m_window.isOpen()){
 
      
        timer = clock.getElapsedTime().asSeconds();
        time +=timer;
        clock.restart();
          sf::Event event;
          while(m_window.pollEvent(event)){

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) dir=1;   
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  dir=2;    
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) dir=3;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) dir=0;
              }
                     m_window.clear(sf::Color::Black);

              for(int i=0;i<num;i++){
                  s1.setPosition(s[i].x*20,s[i].y*20);
               
                   m_window.draw(s1);
                    }

                
            

              s2.setPosition(f.x*20,f.y*20);
         
                m_window.draw(s2);
                
                if(iscollision(top,s1)){
                     collision = true;
                    restart();
                   
                }
                if(collision){
                    for(int i=0;i<num;i++){
                        s1.setPosition(s[i].x,s[i].y);
                        m_window.draw(s1);
                       

                    }
                    collision = false;
                }


              if(time>0.1)
              {
                   time =0;    run();
              }
                
              
 
        m_window.draw(top);
        m_window.draw(left);
        m_window.draw(bottom);
            
        m_window.draw(right);     
          m_window.display();
          


    }

}


