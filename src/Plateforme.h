#ifndef PLATEFORME_H
#define PLATEFORME_H
#include "SFML/Graphics.hpp"
#include <iostream>
#include <cmath>
#include "define.h"
class Plateforme{
    public:
    /*
        constructeur de la plateforme
        origine: sf::Vector2f: coordonnées de l'origine de la plateforme
        size: sf::Vector2f: taille en pixel des cotés de la plateforme
        color: int: couleur de la plateforme(1: Blue, 2: Res, 3: Green)
    */
    Plateforme(sf::Vector2f origine, sf::Vector2f size, int color, float angle = 0);
    ~Plateforme(){};
    /*
        récupérer la référence de la plateforme
        return: sf::RectangleShape &
    */
    const sf::RectangleShape &getShape()const {return this->shape;}
    /** 
     * @brief 
     * 
     * @return les coordonnées du coin suppérieur gauche
    */
    const sf::Vector2f getUpLeft()const {return this->upLeftCorner;}
    /**
     * @brief
     * 
     * @return les coordonnées du coin suppérieur droit
    */
    const sf::Vector2f getUpRight()const {return this->upRightCorner;}
    /**
     * @brief
     * 
     * @return les coordonnées du coin inférieur gauche
    */
    const sf::Vector2f getBottomLeft()const {return this->bottomLeftCorner;}
    /**
     * @brief
     * 
     * @return les coordonnées du coin inférieur droit
    */
    const sf::Vector2f getBottomRight()const {return this->bottomRightCorner;}
    /**
     * @brief Get the Col object
     * 
     * @return const int 
     */
    const int getCol()const {return this->colId;}
    sf::Vector2f getTop()const;
    sf::Vector2f getBottom()const;

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

    /**
     * @brief update shape edge if the plateform has an angle 
     * 
     * @param co: point's coordinates
     * @param size: distance par rapport a l'origine
     * @param angle: angle of the plateform
     *  
    */
    void fixPoint(sf::Vector2f co, double size, float angle, double radius);

    private:
    sf::Vector2f upRightCorner, upLeftCorner, bottomRightCorner, bottomLeftCorner;
    sf::RectangleShape shape;
    int colId;
};

#endif