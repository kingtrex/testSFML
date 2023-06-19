#include "Monde.h"

Monde::Monde(){
    std::cout << "oui" << std::endl;
    entite.push_back(Cercle());
    std::cout << "nioc" << std::endl;
    sf::Vector2f pos(0,-250);
    sf::Vector2f size(250, 20);
    plateforme.push_back(sf::RectangleShape());
    plateforme[0].setFillColor(sf::Color::Blue);
    plateforme[0].setOrigin(pos);
    plateforme[0].setSize(size);
    plateforme[0].setFillColor(sf::Color::Blue);
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

    for(int i = 0; i < plateforme.size(); i++){
        std::cout << "creation plateforme" << std::endl;
        window.draw(plateforme[i]);
    }    
}