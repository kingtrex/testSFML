#include "Cercle.h"

Cercle::Cercle(){
    std::cout << "construction cercle" << std::endl;
    this->shape = sf::CircleShape(50);
    shape.setFillColor(sf::Color::Green);
    std::cout << "cercle construit" << std::endl;
    this->fall = 0;
    this->speed = 1;
    this->jump = 0;
    updateCo();
}

void Cercle::mouvement(float temps, const std::vector<Plateforme> &rect){

    if(temps >= 0.01){


        // velocity.y = -1.0f;
        
        //1: a gauche, -1: a droite
        float movX = static_cast<float>(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) 
        - sf::Keyboard::isKeyPressed(sf::Keyboard::Right));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (onGround || this->jump < 15)){
            this->velocity.y += 1;
            this->onGround = false;
            this->jump++;
        }else{
            this->velocity.y += -1;
        }
        if(movX != 0 && abs(this->velocity.x) <= 10){
            this->velocity.x += movX;
        }else{
            this->velocity.x -= sign(this->velocity.x);
        }
        //collision en X
        sf::Vector2f pos = this->shape.getOrigin();
        float radius = this->shape.getRadius();
        switch(sign(this->velocity.x)){
            case -1:
            if(hasCollide((pos.x - 2*radius)  + this->velocity.x, pos.y - radius, rect)){
                while(!hasCollide((pos.x - 2*radius) + sign(this->velocity.x), pos.y - radius, rect)){
                    pos.x = pos.x + sign(this->velocity.x);
                }
                this->velocity.x = 0;
            }
            break;
            case 1:
            if(hasCollide((pos.x + 2*radius)  + this->velocity.x, pos.y - radius, rect)){
                while(!hasCollide((pos.x + 2*radius) + sign(this->velocity.x), pos.y - radius, rect)){
                    pos.x = pos.x + sign(this->velocity.x);
                }
                this->velocity.x = 0;
            }            
            break;
        }
        //collision en Y
        //modifier cet endroit pour les jump

        if(sign(this->velocity.y) > 0){
            if(hasCollide(pos.x - radius, pos.y + this->velocity.y, rect)){
                while(!hasCollide(pos.x - radius, pos.y + sign(this->velocity.y), rect)){
                    pos.y = pos.y + sign(this->velocity.y);
                }
                this->velocity.y = 0;
            }      
        }else{
            if(hasCollide(pos.x - radius, (pos.y - 2*radius) + this->velocity.y, rect)){
                while(!hasCollide(pos.x - radius, (pos.y - 2*radius) + sign(this->velocity.y), rect)){
                    pos.y = pos.y + sign(this->velocity.y);
                }
                this->velocity.y = 0;
                this->onGround = true;
                this->jump = 0;
            }      
        }

        // if(hasCollide(pos.x - radius, (pos.y - 2*radius) + this->velocity.y, rect)){
        //     while(!hasCollide(pos.x - radius, (pos.y - 2*radius) + sign(this->velocity.y), rect)){
        //         pos.y = pos.y + sign(this->velocity.y);
        //     }
        //     this->velocity.y = 0;
        // }      

        pos += this->velocity;
        this->shape.setOrigin(pos);
    }
    updateCo();
    
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

// bool Cercle::isCol(std::vector<Plateforme> plateforme){
//     for(int i = 0; i < plateforme.size(); i++){
//         if(this->pointDown.y != plateforme[i].getShape().getOrigin().y) continue;
//         if(this->pointDown.x <= plateforme[i].getUpLeft().x && this->pointDown.x >= plateforme[i].getUpRight().x) return true;
//     }
//     return false;
// }

// bool Cercle::isCol(const std::vector<Plateforme> &plateforme, float dir){
    
//     for(int i = 0; i < plateforme.size(); i++){
//         if(dir == 1){
//             if(this->pointLeft.y > plateforme[i].getUpRight().y || this->pointLeft.y < plateforme[i].getBottomRight().y) continue;
//             if(this->pointLeft.x == plateforme[i].getUpRight().x) return true;
//         }else if(dir == -1){
//             if(this->pointRight.y > plateforme[i].getUpLeft().y || this->pointRight.y < plateforme[i].getBottomLeft().y) continue;
//             if(this->pointRight.x == plateforme[i].getUpLeft().x) return true;
//         }
//     }
    
//     return false;

// }

bool Cercle::hasCollide(const float x, const float y, const std::vector<Plateforme> &plateforme){
    for (int i = 0; i < plateforme.size(); i++){
        sf::Vector2f origine = plateforme[i].getShape().getOrigin();
        sf::Vector2f size = plateforme[i].getShape().getSize();
        if(x > origine.x || x < origine.x - size.x) continue;
        if(y > origine.y || y < origine.y - size.y) continue;
        return true;
    }
    return false;
}

int Cercle::sign(const float x){
    if(x < 0) return -1;
    if(x > 0) return 1;
    return 0;
}
