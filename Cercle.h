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
        /**
         * @brief 
         * 
         * @param plateforme ensemble des plateforme
         * @param axe 0: verifie la colision sur une plateforme, 1: verifie la colision sur les cotés
         * @return true s'il y a une colision
         * @return false s'il n'y a pas de colision
         */
        bool isCol(std::vector<Plateforme> plateforme, int axe);
    private:
        sf::CircleShape shape;
        float centreX, basY;
        int fall;
        int speed;
};
#endif