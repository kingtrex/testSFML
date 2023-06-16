#ifndef MONDE_H
#define MONDE_H
#include <iostream>
#include <vector>
#include "Cercle.h"

class Monde{
    public:
    Monde();
    ~Monde(){};

    void mouvementEntite(float temps);
    void dessine(sf::RenderWindow &window);
    private:
    std::vector<Cercle> entite;
    // std::vector<sf::RectangleShape> plateforme;
};

#endif