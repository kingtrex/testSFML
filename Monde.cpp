#include "Monde.h"

Monde::Monde(){
    this->entite.push_back(Cercle());
    sf::Vector2f pos(0,-250);
    sf::Vector2f size(250, 20);
    plateforme.push_back(Plateforme(pos, size, 1));
    pos = sf::Vector2f(-150, -350);
    
    plateforme.push_back(Plateforme(pos, size, 1));
    pos = sf::Vector2f(-150-250, 0);
    size = sf::Vector2f(20, 500);
    plateforme.push_back(Plateforme(pos, size, 2));
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