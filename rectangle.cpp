#include "rectangle.hpp"
//============================================
// RECTANGLE FUNCTIONS
//============================================
void rectangle::draw(sf::RenderWindow &window) {
    sf::RectangleShape rechthoek;
    rechthoek.setPosition(position);
    rechthoek.setSize(size);
    rechthoek.setFillColor(color);
    window.draw(rechthoek);
}

void rectangle::interact(object& item){
    color = sf::Color{255,0,255};
}

sf::FloatRect rectangle::getCollisionShape() {
    sf::RectangleShape rechthoek;
    rechthoek.setPosition(position);
    rechthoek.setSize(size);
    return rechthoek.getGlobalBounds();
}

void rectangle::collide(object& item) {
    auto ownrect = getCollisionShape();
    auto itemrect = item.getCollisionShape();
    sf::RectangleShape rechthoek;
    rechthoek.setPosition(position);
    rechthoek.setSize(size);
    if(ownrect.intersects(itemrect)){
        interact(item);
    }
}

