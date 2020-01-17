#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SFML/Graphics.hpp>

class object {
    protected:
        sf::Vector2f position;
        sf::Vector2f speed;
        sf::Color color;
        
    public:
        object(const sf::Vector2f& startposition, const sf::Vector2f& startspeed, const sf::Color& color):
            position(startposition),
            speed(startspeed),
            color(color)
        {}

        virtual void draw(sf::RenderWindow &window);

        void move( sf::Vector2f change );

        void jump( sf::Vector2i pos );

        virtual sf::FloatRect getCollisionShape();

        void updatePos();

        sf::Vector2f getBounce(sf::FloatRect &item);

        virtual void interact(object& item);

        virtual void collide(object& item);
};

#endif // OBJECT_HPP