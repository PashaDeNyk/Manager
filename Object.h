#pragma once
#include"GameObject.h"

class Object :public GameObject
{
private:

public:
	Object(int x);
	Object(const Object&);
	~Object();
	
	void Update(float dt);
};