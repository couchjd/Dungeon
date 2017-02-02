#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

enum CharClass { KNIGHT, FIGHTER, SAGE, WIZARD, ALCHEMIST, JEWELLER, JONES };
enum MoveDir { UP, DOWN, LEFT, RIGHT };

class Player : public sf::Drawable {
public:
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;
	Player(sf::Sprite*);

	void create(CharClass);

	int strength;
	int intelligence;
	int wisdom;
	int dexterity;
	int constitution;
	int charisma;

	void move(MoveDir);

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

	void update(sf::Time deltaTime);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Sprite _sprite;
};

#endif