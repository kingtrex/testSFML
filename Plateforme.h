#ifndef PLATEFORME_H
#define PLATEFORME_H
#include <SFML/Graphics.hpp>
#include <iostream>
class Plateforme{
    public:
    /*
        constructeur de la plateforme
        origine: sf::Vector2f: coordonnées de l'origine de la plateforme
        size: sf::Vector2f: taille en pixel des cotés de la plateforme
        color: int: couleur de la plateforme(1: Blue)
    */
    Plateforme(sf::Vector2f origine, sf::Vector2f size, int color);
    ~Plateforme(){};
    /*
        récupérer la référence de la plateforme
        return: sf::RectangleShape &
    */
    sf::RectangleShape &getShape(){return this->shape;}
    /*
        récupérer la coordonnées gauche en x de la plateforme pour les colisions
    */
    float getLeft(){return this->leftBorder;}
    /*
        récupérer la coordonnée droite en x de la plateforme pour les colisions
        return: float
    */
    float getRight(){return this->rightBorder;}
    /*
        modifier les coordonnées des bords gauche et droite de la plateforme
        return: float
    */
    void setCo();
    /*
        modifier l'origine de la plateforme
        co: sf::Vector2f: coordonnées en x et y de la nouvelle origine de la plateforme
    */    
    void setCo(sf::Vector2f co);

    private:
    float leftBorder, rightBorder;
    sf::RectangleShape shape;
};

#endif