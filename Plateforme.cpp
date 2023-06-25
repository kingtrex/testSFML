#include "Plateforme.h"

Plateforme::Plateforme(sf::Vector2f origine, sf::Vector2f size, int color){
    std::cout << "Création plateforme" << std::endl;
    this->shape = sf::RectangleShape();
    this->shape.setOrigin(origine);
    this->shape.setSize(size);
    switch(color){
        case 1:
        this->shape.setFillColor(sf::Color::Blue);
        break;
    }
    this->setCo();
    std::cout << "plateforme construite" << std::endl;
}

void Plateforme::setCo(sf::Vector2f co){
    this->shape.setOrigin(co);
    this->setCo();
}

void Plateforme::setCo(){
    this->leftBorder = this->shape.getOrigin().x;
    std::cout << "bord gauche: " << this->leftBorder << std::endl;
    this->rightBorder = this->shape.getOrigin().x - this->shape.getSize().x;
    std::cout << "bord droit: " << this->rightBorder << std::endl;

}

