#include"Object.h"
#include<iostream>

using namespace std;

Object::Object(int x)
{
	cout << x;
}

Object::Object(const Object&)
{
	
}

Object::~Object()
{

}

void Object::Update(float dt)
{
	std::cout<<"Object Update";
}