#include <SFML/Graphics.hpp>
#include <functional>
#include "rectangle.hpp"
#include "ball.hpp"

class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
	   std::function< bool() > condition, 
	   std::function< void() > work
	) : condition( condition ), 
		work( work ) 
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition(
			[ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
		),
		work(work)
	{}

	void operator()(){
		if( condition() ){
			work();
		}
	}
};

int main(){
   sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
   rectangle wall1{sf::Vector2f{0.0,40.0}, sf::Vector2f{0.0,0.0}, sf::Vector2f{40.0,400.0}, sf::Color{127,127,127}};
   rectangle wall2{sf::Vector2f{0.0,440.0}, sf::Vector2f{0.0,0.0}, sf::Vector2f{640.0,40.0}, sf::Color{127,127,127}};
   rectangle wall3{sf::Vector2f{600.0,40.0}, sf::Vector2f{0.0,0.0}, sf::Vector2f{40.0,400.0}, sf::Color{127,127,127}};
   rectangle wall4{sf::Vector2f{0.0,0.0}, sf::Vector2f{0.0,0.0}, sf::Vector2f{640.0,40.0}, sf::Color{127,127,127}};
   ball balletje{sf::Vector2f{100.0,100.0}, sf::Vector2f{1.0,1.0}, sf::Vector2f{0.0,0.0},15, sf::Color{255,0,0}};
   rectangle movableBlock{sf::Vector2f{200.0,200.0}, sf::Vector2f{0.0,0.0},sf::Vector2f{210.0,210.0},sf::Color{0,255,0}};
   std::array<object*, 6> objectlijst= { &wall1, &wall2, &wall3, &wall4, &balletje, &movableBlock };

   action actions[] = {
		action( sf::Keyboard::Left,  [&](){ movableBlock.move( sf::Vector2f( -1.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ movableBlock.move( sf::Vector2f( +1.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ movableBlock.move( sf::Vector2f(  0.0, -1.0 )); }),
		action( sf::Keyboard::Down,  [&](){ movableBlock.move( sf::Vector2f(  0.0, +1.0 )); }),
		action( sf::Mouse::Left,     [&](){ movableBlock.jump( sf::Mouse::getPosition( window )); })
	};

   window.clear();
   wall1.draw(window);
   wall2.draw(window);
   wall3.draw(window);
   wall4.draw(window);
   balletje.draw(window);
   movableBlock.draw(window);
   window.display();

   while( window.isOpen() ){ 
      for( auto & action : actions){
         action();
      }

      for(auto item1 : objectlijst){
         for(auto item2 : objectlijst){
            if(item1 != item2){
               item1->collide(*item2);
            }
         }
      }

      balletje.updatePos();

      window.clear();
      wall1.draw(window);
      wall2.draw(window);
      wall3.draw(window);
      wall4.draw(window);
      balletje.draw(window);
      movableBlock.draw(window);
      window.display();

      sf::sleep( sf::milliseconds( 20 ) );

      sf::Event event;
      while( window.pollEvent( event) ){
         if( event.type == sf::Event::Closed ){
            window.close();
         }
      }
   }
   return 0;

}