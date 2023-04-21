#pragma once
//#include"GameObject.h"
#include"MSG.h"
#include<list>

class Manager
{
private:
	static Manager* instance;//instance = ������
	std::list<GameObject*> objs;
	std::list<MSG*> msgs;
	Manager();//����� ����� ��������� ��� �� �������
	Manager(const Manager&);//�����
	~Manager();
public:
	static Manager* GetInstance();
	static void Destroy();

	// delta time dt

	void Update(float dt);
	void SendMsg(MSG* m);
	void DrawObjects(sf::RenderWindow& win);
};