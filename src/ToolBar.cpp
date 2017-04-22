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
	this->_selectSprite.setActive(false);
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
	uint32_t size = 12;

	this->_toolBarTexture.create(size * this->_availableEntities.size(), size);
	this->_toolBarTexture.clear(sf::Color::Transparent);
	if (this->_availableEntities.size() == 1)
	{
		tmp = SpriteLoader::getInstance().getSprite("ui_toolbar_single");
		tmp.setPosition(0.0f, 0.0f);
		this->_toolBarTexture.draw(tmp);
		this->_availableEntities.at(0).setPosition(static_cast<float>(size) * i + static_cast<float>(size) / 2.0f - this->_availableEntities.at(0).getLocalBounds().width / 2.0f, static_cast<float>(size) / 2.0f - this->_availableEntities.at(0).getLocalBounds().height / 2.0f);
		this->_toolBarTexture.draw(this->_availableEntities.at(0));
	}
	else
		for (auto &availableEntity : this->_availableEntities)
		{
			if (i == 0 || i == this->_availableEntities.size() - 1)
				tmp = SpriteLoader::getInstance().getSprite("ui_toolbar_end");
			else
				tmp = SpriteLoader::getInstance().getSprite("ui_toolbar_middle");
			tmp.setPosition(static_cast<float>(size) * i, 0.0f);
			if (i == this->_availableEntities.size() - 1)
			{
				std::cout << "OUI" << std::endl;
				tmp.setOrigin(6.0f, 6.0f);
				tmp.setRotation(180.0f);
				tmp.move(static_cast<float>(size) / 2.0f, static_cast<float>(size) / 2.0f);
			}
			this->_toolBarTexture.draw(tmp);
			availableEntity.setPosition(static_cast<float>(size) * i + static_cast<float>(size) / 2.0f - availableEntity.getLocalBounds().width / 2.0f, static_cast<float>(size) / 2.0f - availableEntity.getLocalBounds().height / 2.0f);
			this->_toolBarTexture.draw(availableEntity);
			++i;
		}
	this->_toolBarTexture.display();
	this->_toolBarSprite = sf::Sprite(this->_toolBarTexture.getTexture());
	this->setPosition(- static_cast<float>(size) * static_cast<float>(this->_availableEntities.size()) / 2.0f, 1.0f);
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
