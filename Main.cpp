#include<iostream>
#include"Manager.h"
#include"Object.h"
#include"Menu.h"
using namespace std;

int main(int argc, char* argv[])
{
	sf::RenderWindow win(VideoMode(1280, 720), "TestManager");
	win.setVerticalSyncEnabled(true);
	win.setFramerateLimit(60);
	Manager* MGR = Manager::GetInstance();
	MSG* msg = new MSG;
	msg->type = MsgType::First;
	MGR->SendMsg(msg);
	msg = new MSG;
	msg->type = MsgType::Second;
	MGR->SendMsg(msg);
	msg = new MSG;
	msg->type = MsgType::Third;
	MGR->SendMsg(msg);
	//msg->first.ten = new Object(10);

#pragma region STRUCT
	ButtonMenu Menu;
#pragma endregion

#pragma region VAR
	bool start = false;
#pragma endregion 

	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win.close();
		}
		Menu.CheckPosition(event, start);
		win.draw(Menu);
		MGR->Update(0.001);//seconds

		//win.clear({255,255,255,255});//white
		MGR->DrawObjects(win);//Draw window
		win.display();
	}
	return 0;
}