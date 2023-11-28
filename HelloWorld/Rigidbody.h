#pragma once
#include "Play.h"

//frameCounter in main Globally
//int timeStepOne;


class RigidBody
{
public:

	//poisition
	int x = 10;
	int y = 10;

//public:
	// position
	Point2D position;
	
	// velocity
	Vector2D velocity;

	// acceleration
	Vector2D acceleration;

	// rotation in radians
	float rotation;

	// radius of object
	int radius;

	
	RigidBody()	 // constructor for rigidbody.acceleration
	{
		
		position = { x, y };
		velocity = { 0.0f, 0.0f };
		acceleration = { 0.0f, 0.0f };
		rotation = { 0.0f }; // I radianer
		radius = {0};
	}

	~RigidBody() 
	{
	}

	// pure virtual function for drawing, use drawspriterotaded

	virtual void DrawObject()
	{
	};
};

void SpeedObject(RigidBody rigidBody, int speed);
void Collision();
void PhysicsGameUpdate(RigidBody rigidBody);