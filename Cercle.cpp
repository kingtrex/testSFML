#include "Cercle.h"

Cercle::Cercle(){
    this->shape = sf::CircleShape(50);
    int x = this->shape.getOrigin().x;
    int y = this->shape.getOrigin().y;
    float radius = this->shape.getRadius();
    this->centreX = x - radius/2; 
    this->basY = y - radius;
    shape.setFillColor(sf::Color::Green);
}

void Cercle::mouvement(int temps, std::vector<Plateforme> rect){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        this->shape.setOrigin(this->shape.getOrigin().x + 1, this->shape.getOrigin().y);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        this->shape.setOrigin(this->shape.getOrigin().x - 1, this->shape.getOrigin().y);
    }
    if(temps == 1){
        float coX = this->shape.getOrigin().x;
        float coY = this->shape.getOrigin().y;
    
        for(int i = 0; i < rect.size(); i++){
            float recX = rect[i].getLeft();
            float maxX = rect[i].getRight();
            if((coX + (this->shape.getRadius()/2) <= recX) && (coX + (this->shape.getRadius()/2) >= maxX)){
                this->shape.setOrigin(this->shape.getOrigin().x, this->shape.getOrigin().y - 1);
            }
        }
    }
    
}