#ifndef MONDE_H
#define MONDE_H
#include <iostream>
#include <vector>

#include "Entity.h"
#include "Plateforme.h"

class Monde{
    public:
    Monde();
    ~Monde(){};

    void mouvementEntite(float temps);
    void dessine(sf::RenderWindow &window);
    Entity getJoueur() {return this->entite[0];};
    private:
    std::vector<Entity> entite;
    std::vector<Plateforme> plateforme;
};

#endif