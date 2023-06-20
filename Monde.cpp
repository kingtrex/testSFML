#include "Monde.h"

Monde::Monde(){
    this->entite.push_back(Cercle());
    sf::Vector2f pos(0,-250);
    sf::Vector2f size(250, 20);
    plateforme.push_back(Plateforme(pos, size, 1));
}

void Monde::mouvementEntite(float temps){
    this->entite.begin()->mouvement(temps, this->plateforme);
    // if(entite.size() > 1){
    //     for(int i = 1; i < entite.size(); i++){

    //     }
    // }
}

void Monde::dessine(sf::RenderWindow &window){
    for(int i = 0; i < this->entite.size(); i++){
        window.draw(this->entite[i].getShape());
    }

    for(int i = 0; i < plateforme.size(); i++){
        window.draw(this->plateforme[i].getShape());
    }    
}