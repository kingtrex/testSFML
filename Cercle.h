#ifndef CERCLE_H
#define CERCLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plateforme.h"
class Cercle{
    public:
        Cercle();
        ~Cercle(){};
        void mouvement(int temps, std::vector<Plateforme> rect);
        sf::CircleShape &getShape(){return this->shape;}
    private:
        sf::CircleShape shape;
        float centreX, basY;
};
#endif