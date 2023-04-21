#include"Menu.h"
#include<iostream>
#include"Config.h"
ButtonMenu::ButtonMenu()
{

	background.loadFromFile("Images/Wallpaper_black.jpg");
	sprite.setTexture(background);
	font.loadFromFile("bahnschrift.ttf");
	text[0].setString("Start");
	text[1].setString("Info");
	text[2].setString("Exit");
	int x = WIN_WIDTH / 2, y = WIN_HEIGHT / 3;
	for (int i = 0; i < 3; i++)
	{
		text[i].setFont(font);
		text[i].setCharacterSize(25);
		text[i].setFillColor(sf::Color(255, 255, 255));
		text[i].setPosition(x, y);
		text[i].setOutlineThickness(2);
		y += 50;
	}
}

ButtonMenu::~ButtonMenu()
{

}

void ButtonMenu::CheckPosition(Event& event, bool& start)
{
	for (int i = 0; i < 3; i++)
	{
		if (event.mouseMove.x >= text[i].getPosition().x and event.mouseMove.x <= text[i].getPosition().x + 100 and event.mouseMove.y >= text[i].getPosition().y and event.mouseMove.y <= text[i].getPosition().y + 25)
		{
			text[i].setOutlineColor(Color(0, 0, 255, 255));
		}
		else
			text[i].setOutlineColor(Color(0, 0, 0, 0));

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			if (event.mouseButton.x >= text[i].getPosition().x and event.mouseButton.x <= text[i].getPosition().x + 100 and event.mouseButton.y >= text[i].getPosition().y and event.mouseButton.y <= text[i].getPosition().y + 25)
			{
				if (i == 0)
					start = true;
				else if (i == 1)
				{
					//info
				}
				else if (i == 2)
				{
					exit;
				}
			}
	}
}

void ButtonMenu::draw(RenderTarget& target, RenderStates states)const
{
	target.draw(sprite);
	for (int i = 0; i < 3; i++)
		target.draw(text[i]);
}