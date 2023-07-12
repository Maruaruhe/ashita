#include "Dirt.h"
#include <Novice.h>

void Dirt::Initialize() {
	mPosition = {};
	mVelocity = {};
	mFirstVelocity = {};
	mRadius = 3;
	mGravity = 9.8f;
	mMass = 10.0f;
	mFlame = 0;
}
void Dirt::Update() {
	mPosition = Add(mPosition, mVelocity);
	mVelocity.y += mGravity/20.0f;
}
void Dirt::Draw() {
	Novice::DrawEllipse(int(mPosition.x), int(mPosition.y), int(mRadius), int(mRadius), 0.0f, 0x8D6449FF, kFillModeSolid);
}