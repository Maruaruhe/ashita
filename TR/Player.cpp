#include "Player.h"
#include <Novice.h>

void Player::Initialize() {
	mPosition = { 640.0f,690.0f };
	mVelocity = { 0.0f,0.0f };
	mFloor = 720 - 30;
	mIsJump = false;
	mOnGround = false;
}
void Player::Update() {
	Move();
	Jump();
}
void Player::Draw() {
	Novice::DrawLine(0, mFloor, 1280, mFloor, 0x8D6449FF);
	Novice::DrawBox(mPosition.x-10, mPosition.y - 100, 20, 100, 0.0f, WHITE, kFillModeSolid);
}
void Player::Jump() {
	if (Novice::CheckHitKey(DIK_SPACE) && !mIsJump) {
		mVelocity.y = -15;
		mIsJump = true;
		mOnGround = false;
	}
	if (mIsJump) {
		mVelocity.y += 1;
		if (mPosition.y >= 691) {
			mIsJump = false;
			mOnGround = true;
			mPosition.y = 690;
			mVelocity.y = 0.0f;
		}
	}
}
void Player::Move() {
	if (Novice::CheckHitKey(DIK_A)) {
		mVelocity.x = -5;
	}
	else if (Novice::CheckHitKey(DIK_D)) {
		mVelocity.x = 5;
	}
	else {
		mVelocity.x = 0;
	}
	mPosition = Add(mPosition, mVelocity);
}