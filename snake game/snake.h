#pragma once 
#include <SFML/Graphics.hpp>


class Snake{
    private:

    sf::Texture t1, t2;
    sf::Sprite s1,s2;
    int  direction;
    int num;
    public:
    void runsnake();
    void Handle_Input(sf::Keyboard::Key key);

};