#include "Cercle.h"

void Cercle::mouvement(int temps){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        this->shape.setOrigin(this->shape.getOrigin().x + 1, this->shape.getOrigin().y);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        this->shape.setOrigin(this->shape.getOrigin().x - 1, this->shape.getOrigin().y);
    }
    std::cout << temps << std::endl;
    if(temps == 1){
        std::cout << "descente" << std::endl;
        this->shape.setOrigin(this->shape.getOrigin().x, this->shape.getOrigin().y - 1);
    }
    
}