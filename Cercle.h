#include <SFML/Graphics.hpp>
#include <iostream>
class Cercle{
    public:
        Cercle(): shape(50, 50){}
        ~Cercle(){};
        void mouvement(int temps);
        sf::CircleShape &getShape(){return this->shape;}
    private:
        sf::CircleShape shape;
};