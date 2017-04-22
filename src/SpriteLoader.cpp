#include "SpriteLoader.h"

void SpriteLoader::load()
{
	this->loadTextures();
	this->loadSprites();
}

const sf::Sprite &SpriteLoader::getSprite(const std::string &key) const
{
	return (this->_sprites.at(key));
}

const AnimatedSprite &SpriteLoader::getAnimatedSprite(const std::string & key) const
{
	return (this->_animatedSprites.at(key));
}

void SpriteLoader::loadTextures()
{
	// TODO: Check if the file is properly loaded
	this->_textures["sheet"].loadFromFile("resources/textures/sheet.png");
	this->_textures["ui_select"].loadFromFile("resources/textures/ui_select.png");
	this->_textures["ui_toolbar"].loadFromFile("resources/textures/ui_toolbar.png");
}

void SpriteLoader::loadSprites()
{
	this->_sprites["human"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(3, 5, 1, 3));
	this->_sprites["tree"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(10, 2, 4, 6));
	this->_sprites["mine"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(17, 4, 6, 4));
	this->_sprites["woodenHouse1"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(0, 11, 8, 5));
	this->_sprites["woodenHouse2"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(8, 11, 8, 5));
	this->_sprites["woodenHouse3"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(16, 11, 8, 5));
	this->_sprites["woodenHouse4"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(24, 11, 8, 5));
	this->_sprites["stoneHouse1"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(0, 19, 8, 5));
	this->_sprites["stoneHouse2"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(8, 19, 8, 5));
	this->_sprites["stoneHouse3"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(16, 19, 8, 5));
	this->_sprites["stoneHouse4"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(24, 19, 8, 5));
	this->_sprites["terrainBorderLeft"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(0, 30, 8, 2));
	this->_sprites["terrainFlat"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(8, 30, 8, 2));
	this->_sprites["terrainBorderRight"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(16, 30, 8, 2));
	this->_sprites["terrainWater"] = sf::Sprite(this->_textures.at("sheet"), sf::IntRect(24, 30, 8, 2));
	this->_animatedSprites["ui_select"] = AnimatedSprite(0.5f);
	this->_animatedSprites.at("ui_select").addFrame(sf::Sprite(this->_textures.at("ui_select"), sf::IntRect(0, 0, 8, 8)));
	this->_animatedSprites.at("ui_select").addFrame(sf::Sprite(this->_textures.at("ui_select"), sf::IntRect(8, 0, 8, 8)));
	this->_sprites["ui_toolbar_end"] = sf::Sprite(this->_textures.at("ui_toolbar"), sf::IntRect(0, 0, 12, 12));
	this->_sprites["ui_toolbar_middle"] = sf::Sprite(this->_textures.at("ui_toolbar"), sf::IntRect(12, 0, 12, 12));
	this->_sprites["ui_toolbar_single"] = sf::Sprite(this->_textures.at("ui_toolbar"), sf::IntRect(24, 0, 12, 12));
}
