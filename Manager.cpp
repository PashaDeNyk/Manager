#include "Manager.h"
#include<algorithm>
#include<iostream>
using namespace std;

Manager* Manager::instance = nullptr;

Manager::Manager()
{
	;
}

Manager::Manager(const Manager&)
{
	;
}

Manager::~Manager()
{
	for (auto x : objs)
	{
		delete x;
	}
	objs.clear();

	for (auto x : msgs)
	{
		delete x;
	}
	msgs.clear();
}

Manager* Manager::GetInstance()
{
	if (!instance) instance = new Manager();//Создание нового менеджера
	return instance;
}

void Manager::Destroy()
{
	if (instance) delete instance;
}

void Manager::Update(float dt)
{
	for (auto obj : objs)
	{
		obj->Update(dt);
	}
	while (!msgs.empty())
	{
			MSG* m = msgs.front();
			msgs.pop_front();
			switch (m->type)
			{
			case MsgType::First:
			{
				std::cout << "Manager: First ";
			}break;
			case MsgType::Second:
			{
				std::cout << "Manager: second ";
			}break;
			case MsgType::Third:
			{
				std::cout << "Manager: third ";
			}break;
			//case MsgType::Death:
			//{
			//	auto res = find(objs.begin(), objs.end(), m->death.who_to_die);
			//	delete* res;
			//	objs.erase(res);
			//}break;
			//case MsgType::Create:
			//{
			//	objs.push_back(m->create.new_object);
			//}break;
			}

			//if (m->type == MsgType::Move ||
			//	m->type == MsgType::DealDmg)
			//{
			//	for (auto obj : objs)
			//	{
			//		obj->SendMsg(m);
			//	} 
			//}
			delete m;
		//}
	}
}

void Manager::SendMsg(MSG* m)
{
	msgs.push_back(m);
}

void Manager::DrawObjects(sf::RenderWindow& win)
{
	for (auto obj : objs)
	{
		obj->Draw(win);
	}
}