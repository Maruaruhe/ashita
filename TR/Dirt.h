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

	Vector2 mPosition;
	Vector2 mVelocity;
	Vector2 mFirstVelocity;
	float mRadius;
	float mGravity;

	bool mIsHit;
	int mFlame;
};

