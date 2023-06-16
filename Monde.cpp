#include "Monde.h"

Monde::Monde(){
    std::cout << "oui" << std::endl;
    entite.push_back(Cercle());
    std::cout << "nioc" << std::endl;
    // sf::Vector2f pos(-400,0);
    // sf::Vector2f size(-500, -20);
    // plateforme.push_back(sf::RectangleShape());
    // plateforme.end()->setOrigin(pos);
    // plateforme.end()->setSize(size);
    // plateforme.end()->setFillColor(sf::Color::Blue);
}

void Monde::mouvementEntite(float temps){
    entite.begin()->mouvement(temps);
    // if(entite.size() > 1){
    //     for(int i = 1; i < entite.size(); i++){

    //     }
    // }
}

void Monde::dessine(sf::RenderWindow &window){
    std::cout << "oui" << std::endl;
    for(int i = 0; i < entite.size(); i++){
        window.draw(entite[i].getShape());
    }
    // for(int i = 0; i < plateforme.size(); i++){
    //     window.draw(plateforme[i]);
    // }    
}