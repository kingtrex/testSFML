#include "headers.h"

#include "define.h"
int main(){
    //initialisation de la fenêtre
    sf::RenderWindow window(sf::VideoMode(SIZE, SIZE), "SFML works!");
    sf::View view;
    view.reset(sf::FloatRect(0,0,SIZE,SIZE));
    window.setView(view);
    //initialisation du monde
    Monde world;
    sf::Clock clock;
    float coView = 0;
    while (window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event)){
            //fermeture de la fenêtre
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
        }    
        //std::cout << clock.getElapsedTime().asSeconds() << std::endl;

        world.moveEntity(clock.getElapsedTime().asSeconds());
        //période
        if(clock.getElapsedTime().asSeconds() > 0.01){
            clock.restart();
        }

        if(world.getPlayer().getPointCenter().x < coView){
            coView-=SIZE;
            view.reset(sf::FloatRect(coView, 0, SIZE, SIZE));
            window.setView(view);
        }else if(world.getPlayer().getPointCenter().x > coView + SIZE){
            coView+=SIZE;
            view.reset(sf::FloatRect(coView, 0, SIZE, SIZE));
            window.setView(view);
        }
        
        //afficher le contenu de la fenêtre
        window.clear();
        world.draw(window);
        window.display();
    }

    return 0;
}