#pragma once
#include "GameObject.h"

enum class MsgType { First,Second,Third,Creature};
using namespace std;
struct MSG
{
	MsgType type;
	GameObject* sender;
	union {
		struct {
			GameObject* ten;
			GameObject* y;
		}first;
		struct {
			GameObject* s;
		} second;
		struct {
			GameObject* t;
		} third;
		struct {
			GameObject* creature;
		}creature;
	};
	MSG();
};