#include "Monde.h"

Monde::Monde(){
    this->entite.push_back(Cercle());
    sf::Vector2f pos(-50,150);
    sf::Vector2f size(300, 20);
    this->plateforme.push_back(Plateforme(pos, size, 1));
    pos = sf::Vector2f(150, 350);
    this->plateforme.push_back(Plateforme(pos, size, 1));
    
    pos = sf::Vector2f(150+250, 0);
    size = sf::Vector2f(20, 500);
    this->plateforme.push_back(Plateforme(pos, size, 2));

    pos = sf::Vector2f(400, 0);
    size = sf::Vector2f(200, 50);
    this->plateforme.push_back(Plateforme(pos, size, 3, 45));

    pos = sf::Vector2f(-250, 250);
    size = sf::Vector2f(500, 20);
    this->plateforme.push_back(Plateforme(pos, size, 1));


}

void Monde::mouvementEntite(float temps){
    for(int i = 0; i < this->entite.size(); i++){
        this->entite[i].mouvement(temps, this->plateforme);
    }
}

void Monde::dessine(sf::RenderWindow &window){
    for(int i = 0; i < this->entite.size(); i++){
        window.draw(this->entite[i].getShape());
    }

    for(int i = 0; i < plateforme.size(); i++){
        window.draw(this->plateforme[i].getShape());
    }    
}