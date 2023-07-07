#include "Cercle.h"

Cercle::Cercle(){
    std::cout << "construction cercle" << std::endl;
    this->shape = sf::CircleShape(50);
    shape.setFillColor(sf::Color::Green);
    std::cout << "cercle construit" << std::endl;
    this->fall = 0;
    this->speed = 1;
    updateCo();
}

void Cercle::mouvement(float temps, std::vector<Plateforme> rect){

    if(temps >= 0.01){


        // velocity.y = -1.0f;
        float movX = static_cast<float>(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) 
        - sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
        float grav = -1; 

        this->velocity.y += grav;
        this->velocity.x += movX;
        //collision en X
        sf::Vector2f pos = this->shape.getOrigin();
        
        // switch(sign(movX)){
        //     case -1:
        //     pos = this->pointRight;
        //     break;
        //     case 1:
        //     pos = this->pointLeft;
        //     break;
        //     case 0:
        //     pos = this->pointDown;
        // }
        // if(hasCollide(pos.x + velocity.x, pos.y, rect)){
        //     while(!hasCollide(pos.x + sign(velocity.x), pos.y, rect)){
        //         pos.x = pos.x + sign(velocity.x);
        //     }
        //     velocity.x = 0;
        // }

        //collision en Y
        float size = this->shape.getRadius();
        // if(hasCollide(pos.x, pos.y + velocity.y, rect)){
        //     while(!hasCollide(pos.x, pos.y + sign(velocity.y), rect)){
        //         pos.y = pos.y + sign(velocity.y);
        //     }
        //     velocity.y = 0;
        // }        

        // if(hasCollide(this->pointDown.x, this->pointDown.y + velocity.y, rect)){
        //     while(!hasCollide(this->pointDown.x, this->pointDown.y + sign(velocity.y), rect)){
        //         pos.y = pos.y + sign(velocity.y);
        //     }
        //     velocity.y = 0;
        // }

        if(hasCollide(pos.x - size, (pos.y - 2*size) + velocity.y, rect)){
            while(!hasCollide(pos.x - size, (pos.y - 2*size) + sign(velocity.y), rect)){
                pos.y = pos.y + sign(velocity.y);
            }
            velocity.y = 0;
        }      


        //if(!this->isCol(rect, movX)){
        //     velocity.x += movX;
        // }

        // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->jump == 0 && onGround) this->jump = 100;
        // velocity.y -= 1.0f;
        // if(this->jump != 0){
        //     this->jump--;
            
        // }

        // if(this->isCol(rect)){
        //     velocity.y = 0.0f;
        //     std::cout << velocity.y << std::endl;

        //     onGround = false;
        // }else onGround = !onGround;

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

    // this->pointCenter.x = x - radius;
    // this->pointCenter.y = y - radius;
}

bool Cercle::isCol(std::vector<Plateforme> plateforme){
    for(int i = 0; i < plateforme.size(); i++){
        sf::Vector2f upLeftCorner = plateforme[i].getUpLeft();
        sf::Vector2f upRightCorner = plateforme[i].getUpRight();
        float coY = plateforme[i].getShape().getOrigin().y;
        //std::cout << "centreX: " << this->centreX << std::endl;
        if(this->pointDown.y == coY && this->pointDown.x >= upRightCorner.x && this->pointDown.x <= upLeftCorner.x){
            return true;
        }
    }
    return false;
}

bool Cercle::isCol(const std::vector<Plateforme> &plateforme, float dir){
    
    for(int i = 0; i < plateforme.size(); i++){
        if(dir == 1){
            if(this->pointLeft.y > plateforme[i].getUpRight().y || this->pointLeft.y < plateforme[i].getBottomRight().y) continue;
            if(this->pointLeft.x == plateforme[i].getUpRight().x) return true;
        }else if(dir == -1){
            // if(plateforme[i].getShape().getFillColor() == sf::Color::Red) std::cout << "plateforme: " << plateforme[i].getUpLeft().x << " ; " << plateforme[i].getUpLeft().y << std::endl;
            if(this->pointRight.y > plateforme[i].getUpLeft().y || this->pointRight.y < plateforme[i].getBottomLeft().y) continue;
            if(this->pointRight.x == plateforme[i].getUpLeft().x) return true;
        }
    }
    
    return false;

}

bool Cercle::hasCollide(const float x, const float y, const std::vector<Plateforme> &plateforme){
    std::cout << x << " " << y << std::endl;
    for (int i = 0; i < plateforme.size(); i++){
        sf::Vector2f origine = plateforme[i].getShape().getOrigin();
        sf::Vector2f size = plateforme[i].getShape().getSize();
        if(x > origine.x || x < origine.x - size.x) continue;
        if(y > origine.y || y < origine.y - size.y) continue;
        if(y <= origine.y && y >= origine.y - size.y && x <= origine.x && x >= origine.x - size.x) return true;



        // sf::Vector2f topPoint = plateforme[i].getTop();
        // sf::Vector2f bottomPoint = plateforme[i].getBottom();
        // if(y > topPoint.y || y < bottomPoint.y) continue;
        // if(x > plateforme[i].getUpLeft().x || x < plateforme[i].getUpRight().x) continue;
        // std::cout << "return true" << std::endl;
        // return true;

        // switch(plateforme[i].getCol()){
        //     case 1:
        //     if(y != plateforme[i].getShape().getOrigin().y) continue;
        //     if(x <= plateforme[i].getUpLeft().x && x >= plateforme[i].getUpRight().x) return true;
        //     break;
        //     case 2:

        //     break;

        // }

    }
    std::cout << "return false" << std::endl;
    return false;
}

int Cercle::sign(const float x){
    if(x < 0) return -1;
    if(x > 0) return 1;
    return 0;
}