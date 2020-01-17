#ifndef BALL_HPP
#define BALL_HPP
#include "object.hpp"

class ball : public object {
    private:
        int radius;
        
    public:
        ball(const sf::Vector2f &startposition, const sf::Vector2f& startspeed, const sf::Vector2f& bounce, int radius, const sf::Color &color):
            object(startposition,startspeed,color),
            radius(radius)
        {}

        void interact(object& item) override;

        void draw( sf::RenderWindow& window) override;

        sf::FloatRect getCollisionShape() override;

        // sf::Vector2f getBounce(sf::FloatRect &item) override;

        void collide(object& item) override;

};

#endif //BALL_HPP