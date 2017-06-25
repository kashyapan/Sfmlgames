# Sfmlgames
Practising sfml games from scratch 


To compile multifile programs :


g++ -std=c++11 -c main.cpp game.cpp window.cpp

g++ main.o game.o window.o  -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

./sfml-app
