#ifndef CERCLE_H
#define CERCLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plateforme.h"
#include <cmath>
class Cercle{
    public:
        Cercle();
        ~Cercle(){};
        void mouvement(float temps, std::vector<Plateforme> rect);
        sf::CircleShape &getShape(){return this->shape;}
        void updateCo();
    private:
        sf::CircleShape shape;
        float centreX, basY;
        int fall;
        int speed;
};
#endif