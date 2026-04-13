#pragma once

class Splash;

#include <iostream>

using namespace std;

enum Direction {NONE, LEFT, RIGHT, UP, DOWN};
enum Actor {PLAYER, WATER, TOXIC};

class Object {
protected:
	Splash* splash;
	int x, y;
public:
	virtual int act(Direction fromwhere, Actor fromwho) = 0;
	virtual ~Object() {}
};

class Water : public Object {
	// TODO
};

class Void : public Object {
	// TODO
};

class Barrier : public Object {
	// TODO
};

class Toxic : public Object {
	// TODO
};
