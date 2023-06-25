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
    
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    //     this->speed++;
    // }
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    //     this->shape.setOrigin(this->shape.getOrigin().x + (this->speed), this->shape.getOrigin().y);
    // }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    //     this->shape.setOrigin(this->shape.getOrigin().x - (this->speed), this->shape.getOrigin().y);
    // }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->fall == 50){
    //     std::cout << "fall: " << this->fall << std::endl;
    //     //this->shape.setOrigin(this->shape.getOrigin().x, this->shape.getOrigin().y - 1);
    // }
    


    // float dirX = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) - sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    // if(dirX != 0){
    //     float norm = pow(dirX, 2.f);
    //     if(dirX < 0){
    //         this->shape.setOrigin(this->shape.getOrigin().x - 1, this->shape.getOrigin().y);
    //     }else if(dirX > 0){
    //         this->shape.setOrigin(this->shape.getOrigin().x + 1, this->shape.getOrigin().y);
    //     }
    // }
    if(temps >= 0.01){
        sf::Vector2f pos = this->shape.getOrigin();
        sf::Vector2f velocity = sf::Vector2f(0, 0);
        if(!this->isCol(rect, 0)){
            velocity.y = -1.0f;
        }
        // velocity.y = -1.0f;
        float movX = static_cast<float>(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) 
        - sf::Keyboard::isKeyPressed(sf::Keyboard::Right));

        velocity.x += movX;
        pos += velocity;
        this->shape.setOrigin(pos);
    }
    // if(temps > 0.1){

    //     bool surPlateforme = false;
    //     for(int i = 0; i < rect.size(); i++){
    //         std::cout << "basY: " << this->basY << std::endl;
    //         std::cout << "centreX: " << this->centreX << std::endl;
    //         std::cout << "y: " << rect[i].getShape().getOrigin().y << std::endl;
    //         std::cout << "x: " << rect[i].getLeft() << " " << rect[i].getRight() << std::endl;
    //         if((this->basY != rect[i].getShape().getOrigin().y) || (this->basY == rect[i].getShape().getOrigin().y && (this->centreX > rect[i].getLeft() || this->centreX < rect[i].getRight())) && (!surPlateforme && fall == 50)){
    //             this->shape.setOrigin(this->shape.getOrigin().x, this->shape.getOrigin().y - 1);
    //             surPlateforme = true;
    //             this->fall = 0;
    //         }
    //     }
    // }
    updateCo();
    if(fall < 50) fall++;
    
}

void Cercle::updateCo(){
    int x = this->shape.getOrigin().x;
    int y = this->shape.getOrigin().y;

    float radius = this->shape.getRadius();
    this->centreX = x - radius; 
    this->basY = y - (radius*2);
}

bool Cercle::isCol(std::vector<Plateforme> plateforme, int axe){
    for(int i = 0; i < plateforme.size(); i++){
        std::cout << "BasY: " << this->basY << std::endl;
        std::cout << "Origine Y plateforme: " << plateforme[i].getShape().getOrigin().y << std::endl;
        std::cout << "centreX: " << this->centreX << std::endl;
        if(this->basY == plateforme[i].getShape().getOrigin().y && this->centreX >= plateforme[i].getRight() && this->centreX <= plateforme[i].getLeft()){
            return true;
        }
    }
    return false;

}