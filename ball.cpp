#include "ball.hpp"

void ball::draw(sf::RenderWindow &window) {
    sf::CircleShape circle;
    circle.setPosition(position);
    circle.setRadius(radius);
    circle.setFillColor(color);
    window.draw(circle);
}

// sf::Vector2f ball::getBounce(sf::FloatRect &item){
//     auto ownrect = getCollisionShape();
//     sf::FloatRect top = sf::FloatRect(ownrect.left, ownrect.top, ownrect.width, 0.5);
//     sf::FloatRect left = sf::FloatRect(ownrect.left, ownrect.top, 0.5, ownrect.height);
//     sf::FloatRect right = sf::FloatRect(ownrect.left+ownrect.width, ownrect.top, 0.5, ownrect.height);
//     sf::FloatRect bot = sf::FloatRect(ownrect.left, ownrect.top+ownrect.width, ownrect.width, 0.5);
//     if(item.intersects(top)) {
//         return sf::Vector2f{1,-1};
//     } else if(item.intersects(left)){
//         return sf::Vector2f{-1,1};
//     } else if(item.intersects(right)){
//         return sf::Vector2f{-1,1};
//     } else if(item.intersects(bot)){
//         return sf::Vector2f{1,-1};
//     } else {
//         return sf::Vector2f{1,1};
//     }
// }

void ball::interact(object& item){
    auto ownrect = getCollisionShape();
    auto itembounce = item.getBounce(ownrect);
    speed.x *= itembounce.x;
    speed.y *= itembounce.y;
}

sf::FloatRect ball::getCollisionShape() {
    sf::CircleShape circle;
    circle.setPosition(position);
    circle.setRadius(radius);
    return circle.getGlobalBounds();
}

void ball::collide(object& item) {
    auto circlerect = getCollisionShape();
    auto itemrect = item.getCollisionShape();
    if(circlerect.intersects(itemrect)){
        interact(item);
    }
}
