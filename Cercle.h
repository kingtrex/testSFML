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
        /**
         * @brief déplacement des entités
         * 
         * @param temps 
         * @param rect 
         */
        void mouvement(float temps, const std::vector<Plateforme> &rect);
        /**
         * @brief Get the Shape object
         * 
         * @return sf::CircleShape& 
         */
        sf::CircleShape &getShape(){return this->shape;}
        /**
         * @brief mettre a jour les coordonnées importantes de l'entité
         * 
         */
        void updateCo();

        // /**
        //  * @brief Verifie si il y a une colision en Y
        //  * 
        //  * @param plateforme ensemble des plateformes
        //  * @return true s'il y a une colision
        //  * @return false s'il n'y a pas de colision
        // */
        // bool isCol(std::vector<Plateforme> plateforme);
        // /**
        //  * @brief Verifie si il y a collision en X
        //  * 
        //  * @param plateforme ensemble des plateforme
        //  * @param dir -1: vers la droite, 1: vers la gauche
        //  * @return true s'il y a une colision
        //  * @return false s'il n'y a pas de colision
        //  */
        // bool isCol(const std::vector<Plateforme> &plateforme, float dir);

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
        sf::Vector2f pointLeft, pointRight, pointUp, pointDown, pointCenter;
        sf::Vector2f velocity;
        int fall;
        int speed;
        int jump;
        bool onGround;
        sf::Vector2f velocity;
};
#endif