#ifndef PICKUP_H
#define PICKUP_H

#include <SFML/Graphics.hpp>

class Pickup : public sf::Drawable {
public:
	Pickup();
	~Pickup();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};

#endif // PICKUP_H