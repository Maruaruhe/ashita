#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix.h"
class Player
{
public:
	void Initialize();
	void Update();
	void Draw();
	void Jump();
	void Move();

	bool GetFlag() { return mIsJump; }
	Vector2 GetPosition() { return mPosition; }

private:
	Vector2 mPosition;
	int mFloor;
	bool mIsJump;
	bool mOnGround;
	Vector2 mVelocity;
};

