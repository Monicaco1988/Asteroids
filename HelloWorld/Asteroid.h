#pragma once
#include "Play.h"
#include "RigidBody.h"

class Asteroid : public RigidBody
{
private:

	Point2D position = { Play::RandomRollRange(-200, 200),Play::RandomRollRange(-200, 200) };

	Vector2D velocity = { float (Play::RandomRollRange(-2, 2)),float (Play::RandomRollRange(-2, 2)) };

	float rotation = { float(Play::RandomRollRange(-1, 1)) };

	int speed = { int(Play::RandomRollRange(-1, 1)) };

	float scale = { float (Play::RandomRollRange(5, 15)) };

public:
	Asteroid() { position, velocity, rotation, speed; };

	void DrawObject();

	void SpeedObject();

	void AsteroidBoundries(); // could have placed this under game physics, oh well

	void PhysicsGameUpdate();

	void Collision(RigidBody* rigidbody);

};

