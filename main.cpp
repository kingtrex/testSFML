#include "headers.h"
int main(){
    //initialisation de la fenêtre
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    //initialisation du monde
    Monde world;
    sf::Clock clock;

    while (window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event)){
            //fermeture de la fenêtre
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
        }    
        //std::cout << clock.getElapsedTime().asSeconds() << std::endl;
            
        world.mouvementEntite(clock.getElapsedTime().asSeconds());
        //période
        if(clock.getElapsedTime().asSeconds() > 0.01){
            clock.restart();
        }
        //afficher le contenu de la fenêtre
        window.clear();
        world.dessine(window);
        window.display();
    }

    return 0;
}