#include "Plateforme.h"

Plateforme::Plateforme(sf::Vector2f origine, sf::Vector2f size, int color, float angle){
    std::cout << "Création plateforme" << std::endl;
    this->shape = sf::RectangleShape();
    this->shape.setPosition(origine);
    this->shape.setRotation(angle);    
    this->shape.setSize(size);
    switch(color){
        case 1:
        this->shape.setFillColor(sf::Color::Blue);
        break;
        case 2:
        this->shape.setFillColor(sf::Color::Red);
        break;
        case 3:
        this->shape.setFillColor(sf::Color::Green);
    }

    this->setCo();
    this->colId = color;
    std::cout << "plateforme construite" << std::endl;
    std::cout << "(" << this->shape.getPosition().x << " ; " << this->shape.getPosition().y << ")" << std::endl;
}

void Plateforme::setCo(sf::Vector2f co){
    this->shape.setOrigin(co);
    this->setCo();
}

void Plateforme::setCo(){
    sf::Vector2f origin = this->shape.getOrigin();
    sf::Vector2f size = this->shape.getSize();
    this->upLeftCorner.x = origin.x;
    this->upLeftCorner.y = origin.y;

    this->upRightCorner.x = origin.x - size.x;
    this->upRightCorner.y = origin.y;

    this->bottomLeftCorner.x = origin.x;
    this->bottomLeftCorner.y = origin.y - size.y;

    this->bottomRightCorner.x = origin.x - size.x;
    this->bottomRightCorner.y = origin.y - size.y;
}

const sf::Vector2f Plateforme::getTop()const{
    sf::Vector2f topRight = this->getUpRight();
    sf::Vector2f topLeft = this->getUpLeft();

    return topLeft.y>topRight.y?topLeft:topRight;
}

const sf::Vector2f Plateforme::getBottom()const{
    sf::Vector2f bottomRight = this->getBottomRight();
    sf::Vector2f bottomLeft = this->getBottomLeft();

    return bottomLeft.y>bottomRight.y?bottomLeft:bottomRight;
}

void fixPoint(sf::Vector2f co, double size, float angle, double radius){
    
}