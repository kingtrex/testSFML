#ifndef MONDE_H
#define MONDE_H
#include <iostream>
#include <vector>

#include "Entity.h"
#include "Plateforme.h"

class Monde{
    public:
    Monde();
    ~Monde()= default;

    void moveEntity(float temps);
    void draw(sf::RenderWindow &window);
    Entity getPlayer() {return this->entite[0];};
    private:
    std::vector<Entity> entite;
    std::vector<Plateforme> plateforme;
};

#endif