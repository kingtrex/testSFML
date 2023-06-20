#ifndef MAIN_H
#define MAIN_H
#include "headers.h"
int main(){

    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    Monde world;
    sf::Clock clock;

    while (window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
        }    
        std::cout << clock.getElapsedTime().asSeconds() << std::endl;
            
        world.mouvementEntite(clock.getElapsedTime().asSeconds());

        if(clock.getElapsedTime().asSeconds() > 0.1){
            clock.restart();
        }

        window.clear();
        world.dessine(window);
        //world.dessine(window);
        window.display();
    }

    return 0;
}
#endif