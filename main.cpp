#include "cercle.h"
int main(){

    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    Cercle agent;
    agent.getShape().setOrigin(-100,-100);
    agent.getShape().setFillColor(sf::Color::Green);
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
        window.draw(agent.getShape());
        window.display();
    }

    return 0;
}