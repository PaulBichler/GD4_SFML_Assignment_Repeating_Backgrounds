#include "BackgroundManager.hpp"

BackgroundManager::BackgroundManager(sf::Texture& bg_texture, sf::FloatRect world_bounds, sf::Vector2f scroll_speed, SceneNode* parent)
	: m_bg_texture(bg_texture),
	m_world_bounds(world_bounds),
	m_scroll_speed(scroll_speed),
	m_backgrounds {nullptr, nullptr},
	m_current_bg_index(),
	m_repeat_y_offset()
{
	BuildBackground(parent);
	Initialize();
}

void BackgroundManager::Update()
{
	if (m_backgrounds[m_current_bg_index]->getPosition().y > m_world_bounds.top + m_repeat_y_offset)
	{
		m_backgrounds[m_current_bg_index]->setPosition(m_world_bounds.left, m_world_bounds.top - m_repeat_y_offset);
		m_current_bg_index = (m_current_bg_index + 1) % 2;
	}
}

void BackgroundManager::Initialize()
{
	//determines the max possible move distance before the next background needs to take over
	m_repeat_y_offset = (int)(m_world_bounds.height / m_bg_texture.getSize().y) * m_bg_texture.getSize().y;

	//First background is positioned within the camera view
	m_backgrounds[0]->setPosition(m_world_bounds.left, m_world_bounds.top);
	m_backgrounds[0]->SetVelocity(m_scroll_speed);

	//Second background is positioned above the first
	m_backgrounds[1]->setPosition(m_world_bounds.left, m_world_bounds.top - m_repeat_y_offset);
	m_backgrounds[1]->SetVelocity(m_scroll_speed);
}

void BackgroundManager::BuildBackground(SceneNode* parent)
{
	//Prepare the background
	const sf::IntRect texture_rect(m_world_bounds);
	//Tile the texture to cover our world
	m_bg_texture.setRepeated(true);

	std::unique_ptr<Background> bg1(new Background(m_bg_texture, texture_rect));
	m_backgrounds[0] = bg1.get();
	parent->AttachChild(std::move(bg1));

	std::unique_ptr<Background> bg2(new Background(m_bg_texture, texture_rect));
	m_backgrounds[1] = bg2.get();
	parent->AttachChild(std::move(bg2));
}
