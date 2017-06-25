#include "game.h"

int main(){
    game g;
    while(!g.getwindow()->is_done()){
        g.Update();
        g.render();

    }
}