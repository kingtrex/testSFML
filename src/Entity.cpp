#include "Entity.h"

#include <cmath>

Entity::Entity(const std::string& name){
    std::cout << "construction cercle" << std::endl;
    this->texture.loadFromFile(name + "R.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setRotation(45);
    std::cout << "cercle construit" << std::endl;
    this->fall = 0;
    this->speed = 1;
    this->jump = 0;
    this->name = name;
    this->isRight = true;
    this->size = this->texture.getSize();

    updateCo();
}

void Entity::movement(float temps, const std::vector<Plateforme> &rect){

    if(temps >= 0.01){


        // velocity.y = -1.0f;

        //1: a gauche, -1: a droite
        auto movX = static_cast<float>(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
        - sf::Keyboard::isKeyPressed(sf::Keyboard::Left));

        if(movX < 0 && this->isRight){
            this->texture.loadFromFile(name + "L.png");
            this->isRight = false;
        }else if(movX > 0 && !this->isRight){
            this->texture.loadFromFile(name + "R.png");
            this->isRight = true;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (onGround || this->jump < 15)){
            this->velocity.y -= 1;
            this->onGround = false;
            this->jump++;
        }else{
            this->velocity.y += 1;
        }
        if(movX != 0 && abs(static_cast<int>(this->velocity.x)) <= 10){
            this->velocity.x += movX;
        }else{
            this->velocity.x -= sign(this->velocity.x);
        }
        //collision en X
        sf::Vector2f pos = this->sprite.getPosition();

        //float radius = this->shape.getRadius();
        auto sizeX = static_cast<float>(this->size.x);
        auto sizeY = static_cast<float>(this->size.y);


        switch(sign(this->velocity.x)){
            case -1:
            if(hasCollide((pos.x + sizeX)  + this->velocity.x, pos.y - (sizeY / 2), rect)){
                while(!hasCollide((pos.x - sizeX) + sign(this->velocity.x), pos.y - (sizeY / 2), rect)){
                    pos.x = pos.x + sign(this->velocity.x);
                }
                this->velocity.x = 0;
            }
            break;
            case 1:
            if(hasCollide((pos.x + sizeX)  + this->velocity.x, pos.y - (sizeY / 2), rect)){
                while(!hasCollide((pos.x + sizeX) + sign(this->velocity.x), pos.y - (sizeY / 2), rect)){
                    pos.x = pos.x + sign(this->velocity.x);
                }
                this->velocity.x = 0;
            }
            break;
        }
        //collision en Y
        //modifier cet endroit pour les jump

        if(sign(this->velocity.y) > 0){
            if(hasCollide(pos.x + (sizeX/2), pos.y + sizeY + this->velocity.y, rect)){
                while(!hasCollide(pos.x + (sizeX/2), pos.y + sizeY + sign(this->velocity.y), rect)){
                    pos.y = pos.y + sign(this->velocity.y);
                }
                this->velocity.y = 0;
                this->onGround = true;
                this->jump = 0;
            }
        }else{
            if(hasCollide(pos.x + (sizeX/2), pos.y + this->velocity.y, rect)){
                while(!hasCollide(pos.x + (sizeX/2), pos.y + sign(this->velocity.y), rect)){
                    pos.y = pos.y - sign(this->velocity.y);
                }
                this->velocity.y = 0;

            }
        }

        // if(hasCollide(pos.x - radius, (pos.y - 2*radius) + this->velocity.y, rect)){
        //     while(!hasCollide(pos.x - radius, (pos.y - 2*radius) + sign(this->velocity.y), rect)){
        //         pos.y = pos.y + sign(this->velocity.y);
        //     }
        //     this->velocity.y = 0;
        // }

        pos += this->velocity;
        if(pos.y > 500) {
            pos.y = 0;
            velocity.y = 0;
        }
        this->sprite.setPosition(pos.x, pos.y);
    }
    if(this->co.y > 500){
        std::cout << "aaaa" << std::endl;
        this->sprite.setPosition(static_cast<float>(this->co.x), static_cast<float>(this->co.y)-500);

        //this->shape.setPosition(this->shape.getPosition().x,this->shape.getPosition().y - 500);
        this->velocity.y = 0;
    }
    updateCo();

}

void Entity::updateCo(){
    float x = this->sprite.getPosition().x;
    float y = this->sprite.getPosition().y;
    float angle = this->sprite.getRotation() * M_PI / 180;

    auto sizeX = static_cast<float>(this->size.x);
    auto sizeY = static_cast<float>(this->size.y);
    this->pointUp.x = (x + sizeX /2)* std::cos(angle);
    this->pointUp.y = y * std::sin(angle);

    this->pointLeft.x = x * std::cos(angle);
    this->pointLeft.y = (y + (sizeY/2)) * std::sin(angle);

    this->pointRight.x = (x + (sizeX)) * std::cos(angle);
    this->pointRight.y = (y + (sizeY/2)) * std::sin(angle);

    this->pointDown.x = (x + (sizeX/2)) * std::cos(angle);
    this->pointDown.y = (y + (sizeY)) * std::sin(angle);

    this->pointCenter.x = (x + sizeX/2) * std::cos(angle);
    this->pointCenter.y = (y + (sizeY/2)) * std::sin(angle);

    this->topRight.x = (x + sizeX) * std::cos(angle);
    this->topRight.y = y * std::sin(angle);

    this->bottomRight.x = (x + sizeX) * std::cos(angle);
    this->bottomRight.y = (y + sizeY) * std::sin(angle);

    this->bottomLeft.x = x * std::cos(angle);
    this->bottomLeft.y = (y + sizeY) * std::sin(angle);
}

bool Entity::hasCollide(const float x, const float y, const std::vector<Plateforme> &plateforme){
    for (const auto & i : plateforme){
        sf::Vector2f origine = i.getShape().getPosition();
        sf::Vector2f size = i.getShape().getSize();
        if(x < origine.x || x > origine.x + size.x) continue;
        if(y < origine.y || y > origine.y + size.y) continue;
        return true;
    }
    return false;
}

int Entity::sign(const float x){
    if(x < 0) return -1;
    if(x > 0) return 1;
    return 0;
}
