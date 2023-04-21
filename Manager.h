#pragma once
//#include"GameObject.h"
#include"MSG.h"
#include<list>

class Manager
{
private:
	static Manager* instance;//instance = пример
	std::list<GameObject*> objs;
	std::list<MSG*> msgs;
	Manager();//Никто кроме менеджера его не сделает
	Manager(const Manager&);//Копия
	~Manager();
public:
	static Manager* GetInstance();
	static void Destroy();

	// delta time dt

	void Update(float dt);
	void SendMsg(MSG* m);
	void DrawObjects(sf::RenderWindow& win);
};