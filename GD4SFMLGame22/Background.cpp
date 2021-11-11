#include "Background.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

Background::Background(const sf::Texture& texture, const sf::IntRect& texture_rect) : m_sprite(texture, texture_rect)
{
}

unsigned Background::GetCategory() const
{
	return Category::kBackground;
}

void Background::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
