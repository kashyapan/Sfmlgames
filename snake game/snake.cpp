#include "snake.h"
#include "window.h"
#include <time.h>
struct snake{
    int x;
    int y;

}s[100];

struct food{
    int x;
    int y;
}f;
f.x = 15;
f.y =15;
int n = 32 , m =18;
int size= 16;
int w = size * n;
int h = size *m;
srand(time(0));
Snake::Snake(){
    t1.loadFromFile("images/green.png");
    t2.loadFromFile("images/red.png");
    s1(t1);
    s2(t2);
    num =4;
    
}
void Snake::runsnake(){
    for(int i=num;i>0;i--){
        s[i].x = s[i-1].x;
        s[i].y= s[i-1].y;
    }
    
}




void Snake::Handle_Input(sf::Keyboard::Key key){
    if(key==sf::Keyboard::Up)s[0].y-=1;
    if(key ==sf::Keyboard::Left )s[0].x-=1;
    if(key == sf::Keyboard::Right) s[0].x+=1;
    if(key == sf::Keyboard::Down)s[0].y+=1;


      if(s[0].x ==f.x && s[0].y==f.y)
    {
        num++;
        f.x = rand()%n;
        f.y = rand()%m;
        s2(f);
        Game::Draw(s2)
    }

    if(s[0].x > n) s[0].x =0; 
    if (s[0].x<0)  s[0].x =n;
    if(s[0].y<0)s[0].y= m;
    if(s[0].y>m)s[0].y =n;
    s1(s)
   Game:: Draw();
}

    
void Snake::Draw(){
    for(int i=0 ; i<num;i++){
        s1.setPosition(s[i].x*size,s[i].y*size);
        Game::Draw(s1);

    }
}




