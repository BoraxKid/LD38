#ifndef TOOLBAR_H_
#define TOOLBAR_H_
#pragma once

#include "SpriteLoader.h"

class ToolBar : public sf::Drawable, public sf::Transformable
{
public:
	ToolBar();
	virtual ~ToolBar();

	void init();
	void addAvailableEntity(const sf::Sprite &availableEntity);

private:
	void updateToolbar();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::View _view;
	AnimatedSprite _selectSprite;
	sf::RenderTexture _toolBarTexture;
	sf::Sprite _toolBarSprite;
	std::vector<sf::Sprite> _availableEntities;
};

#endif // TOOLBAR_H_
