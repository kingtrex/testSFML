#include "Cercle.h"

Cercle::Cercle(){
    std::cout << "feur";
    shape = sf::CircleShape(50);
    std::cout << "boop";
    shape.setFillColor(sf::Color::Green);
    std::cout << "atcha" << std::endl;
}

void Cercle::mouvement(int temps){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        this->shape.setOrigin(this->shape.getOrigin().x + 1, this->shape.getOrigin().y);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        this->shape.setOrigin(this->shape.getOrigin().x - 1, this->shape.getOrigin().y);
    }
    if(temps == 1){
        this->shape.setOrigin(this->shape.getOrigin().x, this->shape.getOrigin().y - 1);
    }
    
}