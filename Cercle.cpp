#include "Cercle.h"

Cercle::Cercle(){
    std::cout << "construction cercle" << std::endl;
    this->shape = sf::CircleShape(50);
    shape.setFillColor(sf::Color::Green);
    std::cout << "cercle construit" << std::endl;
    this->fall = 0;
    this->speed = 1;
}

void Cercle::mouvement(float temps, std::vector<Plateforme> rect){

    if(temps >= 0.01){
        sf::Vector2f pos = this->shape.getOrigin();
        sf::Vector2f velocity = sf::Vector2f(0, 0);
        if(!this->isCol(rect)){
            velocity.y = -1.0f;
        }
        // velocity.y = -1.0f;
        float movX = static_cast<float>(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) 
        - sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
        if(!this->isCol(rect, movX)){
            velocity.x += movX;
        }
        pos += velocity;
        this->shape.setOrigin(pos);
    }
    updateCo();
    if(fall < 50) fall++;
    
}

void Cercle::updateCo(){
    int x = this->shape.getOrigin().x;
    int y = this->shape.getOrigin().y;
    float radius = this->shape.getRadius();
    this->pointUp.x = x - radius; 
    this->pointUp.y = y;

    this->pointLeft.x = x;
    this->pointLeft.y = y - radius;

    this->pointRight.x = x - (radius*2);
    this->pointRight.y = y - radius;

    this->pointDown.x = x - radius;
    this->pointDown.y = y - (radius*2);
}

bool Cercle::isCol(std::vector<Plateforme> plateforme){
    for(int i = 0; i < plateforme.size(); i++){
        if(this->pointDown.y != plateforme[i].getShape().getOrigin().y) continue;
        if(this->pointDown.x <= plateforme[i].getUpLeft().x && this->pointDown.x >= plateforme[i].getUpRight().x) return true;
    }
    return false;
}

bool Cercle::isCol(std::vector<Plateforme> plateforme, float dir){
    
    for(int i = 0; i < plateforme.size(); i++){
        if(dir == 1){
            if(this->pointLeft.y > plateforme[i].getUpRight().y || this->pointLeft.y < plateforme[i].getBottomRight().y) continue;
            if(this->pointLeft.x == plateforme[i].getUpRight().x) return true;
        }else if(dir == -1){
            if(this->pointRight.y > plateforme[i].getUpLeft().y || this->pointRight.y < plateforme[i].getBottomLeft().y) continue;
            if(this->pointRight.x == plateforme[i].getUpLeft().x) return true;
        }
    }
    
    return false;

}