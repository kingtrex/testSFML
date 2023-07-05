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
         * @brief Verifie si il y a une colision en Y
         * 
         * @param plateforme ensemble des plateformes
         * @return true s'il y a une colision
         * @return false s'il n'y a pas de colision
        */
        bool isCol(std::vector<Plateforme> plateforme);
        /**
         * @brief Verifie si il y a collision en X
         * 
         * @param plateforme ensemble des plateforme
         * @param dir 1: vers la gauche, -1: vers la droite
         * @return true s'il y a une colision
         * @return false s'il n'y a pas de colision
         */
        bool isCol(const std::vector<Plateforme> &plateforme, float dir);
        /**
         * @brief Verifie si il y a une collision avec les coordonnées données
         * 
         * @param x coordonnée en X
         * @param y coordonnée en Y
         * @param plateforme vecteur de toute les plateformes
         * @return true Il y a collision
         * @return false sinon
         */
        bool hasCollide(const float x, const float y, const std::vector<Plateforme> &plateforme);
        /**
         * @brief retourne le signe de x
         * 
         * @param x 
         * @return int -1 si x < 0,
         * 0 si x = 0,
         * 1 si x > 1
         */
        int sign(const float x);
    private:
        sf::CircleShape shape;
        sf::Vector2f pointLeft, pointRight, pointUp, pointDown;
        sf::Vector2f velocity;
        int fall;
        int speed;
};
#endif