#include "Sphere.h"
#include <Novice.h>
#include "Matrix.h"

void Sphere::Initialize() {
	mPosition = { 640.0f, 360.0f };
	mVelocity = {};
	mIsShot = false;
	mRadius = 30.0f;
	mGravity = 9.8f;
	mMass = 10.0f;
	mFloor = 720 - 30;
	mFlame = 0;
}


void Sphere::Update() {
	//Position
	if (!mIsHit) {
		mBeforePosition.x = mPosition.x;
		mBeforePosition.y = mPosition.y;
	}
	//Reset
	if (Novice::CheckHitKey(DIK_R)) {
		Initialize();
	}
	Shot();
	if (mPosition.y == mFloor - mRadius) {
		Initialize();
	}
	if (mIsShot) {
		mFlame += 1;
		mVelocity.y= mVelocity.y = mGravity * (mFlame / 15.0f) + mFirstVelocity.y;
		mPosition = Add(mPosition, mVelocity);
		if (mPosition.x <= mRadius) {
			mVelocity.x *= -1;
		}
		else if (mPosition.x >= 1280 - mRadius) {
			mVelocity.x *= -1;
		}
		if (mPosition.y >= float(mFloor) - mRadius &&!mIsHit) {
			mIsHit = true;
			mCurrentPosition.x = mPosition.x;
			mCurrentPosition.y = mPosition.y;
			mPosition.y = mFloor - mRadius;
		}
	}
	//
	if (!mIsShot) {
		Novice::GetMousePosition(&px, &py);
		//x
		if (px > mPosition.x) {
			mArrow.x = mPosition.x - (px - mPosition.x);
		}
		else {
			mArrow.x = mPosition.x + (mPosition.x - px);
		}
		//y
		if (py > mPosition.y) {
			mArrow.y = mPosition.y - (py - mPosition.y);
		}
		else {
			mArrow.y = mPosition.y + (mPosition.y - py);
		}
	}
}


void Sphere::Draw() {
	Novice::DrawLine(0, mFloor, 1280, mFloor, WHITE);
	//if (mIsShot) {
		Novice::DrawEllipse(int(mPosition.x), int(mPosition.y), int(mRadius), int(mRadius), 0.0f, WHITE, kFillModeSolid);
	//}
	if (!mIsShot) {
		Novice::DrawLine(int(mPosition.x), int(mPosition.y), px, py, WHITE);
		Novice::DrawLine(int(mPosition.x), int(mPosition.y), int(mArrow.x), int(mArrow.y), WHITE);
	}
	if (mIsHit) {
		Novice::DrawEllipse(int(mCurrentPosition.x), int(mCurrentPosition.y), int(mRadius), int(mRadius), 0.0f, RED, kFillModeSolid);
		Novice::DrawEllipse(int(mBeforePosition.x), int(mBeforePosition.y), int(mRadius), int(mRadius), 0.0f, BLUE, kFillModeSolid);
	}
}


void Sphere::Shot() {
	if (Novice::CheckHitKey(DIK_SPACE)&&!mIsShot) {
		mIsShot = true;
		mIsHit = false;

		mFirstVelocity = { (mArrow.x - mPosition.x) / 20,(mArrow.y - mPosition.y) / 20 };

		mVelocity = mFirstVelocity;
	}
}