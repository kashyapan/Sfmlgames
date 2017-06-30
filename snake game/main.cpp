#include "game.h"
int main(){
    Game g;
    while(!g.GetWindow()->IsDone()){
        g.Update();
    }
}