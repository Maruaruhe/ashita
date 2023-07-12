#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix.h"

class Dirt
{
public:
	void Initialize();
	void Update();
	void Draw();

	void SetGravity(float gravity) { mGravity = gravity; }
	void SetMass(float mass) { mMass = mass; }

	float GetGravity() { return mGravity; }
	float GetMass() { return mMass; }

	Vector2 mPosition;
	Vector2 mVelocity;
	Vector2 mFirstVelocity;
	float mRadius;

	float mGravity;
	float mMass;

	bool mIsHit;
	int mFlame;
};

