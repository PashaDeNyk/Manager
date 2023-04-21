#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class ButtonMenu :public Drawable, public Transformable
{
private:
	Font font;
	Text text[3];
	Texture background;
	Sprite sprite;
	
public:
	ButtonMenu();
	~ButtonMenu();

	bool CheckClickButton();

	void CheckPosition(Event& event, bool& start);
	
	void Update(float dt);
	virtual void draw(RenderTarget& target, RenderStates states)const;
};