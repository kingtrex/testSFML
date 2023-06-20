#ifndef CERCLE_H
#define CERCLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plateforme.h"
class Cercle{
    public:
        Cercle();
        ~Cercle(){};
        /*
        gestion du mouvement du cercle
        temps: float: quand temps > 0.1, le cercle descend par la gravité
        rect: std::vector<Plateform>: ensemble des plateformes
        */
        void mouvement(float temps, std::vector<Plateforme> rect);
        /*
        obtenir la référence du cercle
        return: sf::CircleShape &
        */
        sf::CircleShape &getShape(){return this->shape;}
        void updateCo();
    private:
        sf::CircleShape shape;
        float centreX, basY;
};
#endif