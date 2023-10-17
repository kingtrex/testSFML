#include "Monde.h"

Monde::Monde(){
    this->entite.emplace_back();
    sf::Vector2f pos(-50,150);
    sf::Vector2f size(300, 20);
    this->plateforme.emplace_back(pos, size, 1);
    pos = sf::Vector2f(150, 350);
    this->plateforme.emplace_back(pos, size, 1);
    
    pos = sf::Vector2f(150+250, 0);
    size = sf::Vector2f(20, 500);
    this->plateforme.emplace_back(pos, size, 2);

    pos = sf::Vector2f(-150, 100);
    this->plateforme.emplace_back(pos, size, 2);

    pos = sf::Vector2f(400, 0);
    size = sf::Vector2f(200, 50);
    this->plateforme.emplace_back(pos, size, 3, 45);

    pos = sf::Vector2f(-250, 250);
    size = sf::Vector2f(500, 20);
    this->plateforme.emplace_back(pos, size, 1);


}

void Monde::moveEntity(float temps){
    for(auto & i : this->entite){
        i.movement(temps, this->plateforme);
    }
}

void Monde::draw(sf::RenderWindow &window){
    for(auto & i : this->entite){
        window.draw(i.getSprite());
    }

    for (const auto & i : this->plateforme) {
        window.draw(i.getShape());
    }
}