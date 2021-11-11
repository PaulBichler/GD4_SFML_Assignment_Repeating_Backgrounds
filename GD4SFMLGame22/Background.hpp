#pragma once
#include "Entity.hpp"
#include <SFML/Graphics/Sprite.hpp>

class Background : public Entity
{
public:
	explicit Background(const sf::Texture& texture, const sf::IntRect& texture_rect);
	unsigned GetCategory() const override;

private:
	void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Sprite m_sprite;
};

