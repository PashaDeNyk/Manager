#include<iostream>
#include"GameObject.h"

sf::Texture* GameObject::LoadTexure(const char* filename, const sf::IntRect& src_box)
{
	Texture* tex = new Texture();
	if (tex->loadFromFile(filename, src_box))
		return tex;
	delete tex;
	return nullptr;
}

GameObject::GameObject()
{
	;
}

GameObject::GameObject(const GameObject&)
{
	;
}

GameObject::~GameObject()
{
	;
}



void GameObject::Draw(sf::RenderWindow& win)
{
	sprite.setPosition(position);
	win.draw(sprite);
}