#include "ToolBar.h"

ToolBar::ToolBar()
{
}

ToolBar::~ToolBar()
{
}

void ToolBar::init()
{
	this->_selectSprite = SpriteLoader::getInstance().getAnimatedSprite("ui_select");
}

void ToolBar::addAvailableEntity(const sf::Sprite &availableEntity)
{
	this->_availableEntities.push_back(availableEntity);
	this->updateToolbar();
}

void ToolBar::updateToolbar()
{
	uint32_t i = 0;
	sf::Sprite tmp;

	this->_toolBarTexture.create(10 * this->_availableEntities.size(), 10);
	this->_toolBarTexture.clear(sf::Color::Transparent);
	if (this->_availableEntities.size() == 1)
	{
		tmp = SpriteLoader::getInstance().getSprite("ui_toolbar_single");
		tmp.setPosition(0.0f, 0.0f);
		this->_toolBarTexture.draw(tmp);
		this->_availableEntities.at(0).setPosition(10.0f * i + 5.0f - this->_availableEntities.at(0).getLocalBounds().width / 2.0f, 5.0f - this->_availableEntities.at(0).getLocalBounds().height / 2.0f);
		this->_toolBarTexture.draw(this->_availableEntities.at(0));
	}
	else
		for (auto &availableEntity : this->_availableEntities)
		{
			tmp.setRotation(0.0f);
			if (i == 0)
				tmp = SpriteLoader::getInstance().getSprite("ui_toolbar_end");
			else if (i == this->_availableEntities.size() - 1)
			{
				tmp = SpriteLoader::getInstance().getSprite("ui_toolbar_end");
				tmp.setRotation(180.0f);
			}
			else
				tmp = SpriteLoader::getInstance().getSprite("ui_toolbar_middle");
			tmp.setPosition(10.0f * i, 0.0f);
			this->_toolBarTexture.draw(tmp);
			availableEntity.setPosition(10.0f * i + 5.0f - availableEntity.getLocalBounds().width / 2.0f, 5.0f - availableEntity.getLocalBounds().height / 2.0f);
			this->_toolBarTexture.draw(availableEntity);
			++i;
		}
	this->_toolBarTexture.display();
	this->_view.setCenter(sf::Vector2f(10.0f * static_cast<float>(this->_availableEntities.size()) / 2.0f, 10.0f / 2.0f));
	this->_view.setSize(sf::Vector2f(10.0f * static_cast<float>(this->_availableEntities.size()), 10.0f));
	this->_toolBarSprite.setTexture(this->_toolBarTexture.getTexture());
}

void ToolBar::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= this->getTransform();
	if (!this->_availableEntities.empty())
	{
		target.draw(this->_toolBarSprite, states);
		target.draw(this->_selectSprite, states);
	}
}
