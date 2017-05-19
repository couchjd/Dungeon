#ifndef ACTOR_H
#define ACTOR_H
#include <SFML/Graphics.hpp>

enum MoveDir { UP, DOWN, LEFT, RIGHT };

class Actor : public sf::Drawable {
public:
	virtual void move(MoveDir) = 0;
	sf::Sprite _sprite;

  bool _isMoving = false;

	auto getPosition() {
		return _sprite.getPosition();
	}

	auto getTextureRect() {
		return _sprite.getTextureRect();
	}

	template<typename ... Args>
	void setPosition(Args&& ... args) {
		_sprite.setPosition(std::forward<Args>(args)...);
	}

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
};

#endif // ACTOR_H