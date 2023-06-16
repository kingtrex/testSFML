#ifndef CERCLE_H
#define CERCLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
class Cercle{
    public:
        Cercle();
        ~Cercle(){};
        void mouvement(int temps);
        sf::CircleShape &getShape(){return this->shape;}
    private:
        sf::CircleShape shape;
};
#endif