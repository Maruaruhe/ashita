#pragma once
#include <Vector3.h>
#include <Vector2.h>

class Sphere
{
public:
	void Initialize();
	void Update();
	void Draw();
	void Shot();

	void SetGravity(float gravity) { mGravity = gravity; }
	void SetMass(float mass) { mMass = mass; }

	float GetGravity() { return mGravity; }
	float GetMass() { return mMass; }

	Vector2 mPosition;
	Vector2 mBeforePosition;
	Vector2 mCurrentPosition;

	Vector2 mVelocity;
	Vector2 mFirstVelocity;

	float mRadius;
	Vector2 mArrow;
	int px;
	int py;

	float mGravity;
	float mMass;

	bool mIsShot;
	bool mIsHit;
	int mFloor;
	int mFlame;
};

