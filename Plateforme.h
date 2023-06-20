#ifndef PLATEFORME_H
#define PLATEFORME_H
#include <SFML/Graphics.hpp>

class Plateforme{
    public:
    Plateforme(sf::Vector2f origine, sf::Vector2f size, int color);
    ~Plateforme(){};
    sf::RectangleShape &getShape(){return this->shape;}

    float getLeft(){return this->leftBorder;}
    float getRight(){return this->rightBorder;}
    void setCo();
    void setCo(sf::Vector2f co);
    private:
    float leftBorder, rightBorder;
    sf::RectangleShape shape;
};

#endif