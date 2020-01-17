#include "object.hpp"

void object::move( sf::Vector2f change ) {
    position.x += change.x;
    position.y += change.y;
}

void object::jump( sf::Vector2i pos ) {
    position.x = pos.x;
    position.y = pos.y;
}

void object::updatePos() {
    position.x += speed.x;
    position.y += speed.y;
}

sf::Vector2f object::getBounce(sf::FloatRect &item){
    auto ownrect = getCollisionShape();
    sf::FloatRect top = sf::FloatRect(ownrect.left, ownrect.top, ownrect.width, 0.5);
    sf::FloatRect left = sf::FloatRect(ownrect.left, ownrect.top, 0.5, ownrect.height);
    sf::FloatRect right = sf::FloatRect(ownrect.left+ownrect.width, ownrect.top, 0.5, ownrect.height);
    sf::FloatRect bot = sf::FloatRect(ownrect.left, ownrect.top+ownrect.height, ownrect.width, 0.5);
    if(item.intersects(top)) {
        return sf::Vector2f{1,-1};
    } else if(item.intersects(left)){
        return sf::Vector2f{-1,1};
    } else if(item.intersects(right)){
        return sf::Vector2f{-1,1};
    } else if(item.intersects(bot)){
        return sf::Vector2f{1,-1};
    } else {
        return sf::Vector2f{1,1};
    }
}
