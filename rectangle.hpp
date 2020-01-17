#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "object.hpp"

class rectangle : public object{
    protected:
        sf::Vector2f size;
    
    public:
        rectangle( const sf::Vector2f &startposition, const sf::Vector2f& startspeed, const sf::Vector2f &size, const sf::Color &color):
            object(startposition,startspeed,color),
            size(size)
        {}

        void draw(sf::RenderWindow &window) override;

        void interact(object& item) override;

        sf::FloatRect getCollisionShape() override;

        // sf::Vector2f getBounce(sf::FloatRect &item) override;

        void collide(object& item);
};

#endif //RECTANGLE_HPP