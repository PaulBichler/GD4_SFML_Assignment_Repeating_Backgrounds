#pragma once
#include <SFML/Graphics/Texture.hpp>

#include "Background.hpp"

class BackgroundManager
{
private:
	sf::Texture& m_bg_texture;
	sf::FloatRect m_world_bounds;
	float m_scroll_speed;
	Background* m_backgrounds[2];
	int m_current_bg_index;
	float m_repeat_y_offset;

private:
	void Initialize();
	void BuildBackground(SceneNode* parent);

public:
	BackgroundManager(sf::Texture& bg_texture, sf::FloatRect world_bounds, float y_scroll_speed, SceneNode* parent);
	void Update();
};

