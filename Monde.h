#ifndef MONDE_H
#define MONDE_H
#include <iostream>
#include <vector>

#include "Cercle.h"
#include "Plateforme.h"

class Monde{
    public:
    Monde();
    ~Monde(){};

    void mouvementEntite(float temps);
    void dessine(sf::RenderWindow &window);
    Cercle getJoueur() {return this->entite[0];};
    private:
    std::vector<Cercle> entite;
    std::vector<Plateforme> plateforme;
};

#endif