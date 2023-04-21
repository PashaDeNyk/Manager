#pragma once
#include<iostream>
#include"SFML/Graphics.hpp"
using namespace std;
using namespace sf;
struct MSG;

class GameObject
{
private:
	static int lastID;
protected:
	int id;
	sf::Vector2f position;
	sf::Sprite sprite;

	static sf::Texture* LoadTexure(const char* filename, const sf::IntRect& src_box);
public:

	GameObject();
	GameObject(const GameObject&);
	virtual ~GameObject();

	
	virtual void Update(float dt) = 0;
	//virtual void SendMsg(MSG* m) = 0;

	void Draw(sf::RenderWindow& win);
};