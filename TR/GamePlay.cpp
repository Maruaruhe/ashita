#include "GamePlay.h"
void GamePlay::Initialize() {
	sphere = new Sphere;
	sphere->Initialize();
	for (int i = 0; i < DIRTCOUNT; i++) {
		dirt[i] = new Dirt;
		dirt[i]->Initialize();
	}
}

void GamePlay::sphereInitialize() {
	sphere->Initialize();
}
void GamePlay::dirtInitialize() {
	for (int i = 0; i < DIRTCOUNT; i++) {
		dirt[i]->Initialize();
	}
}

void GamePlay::Update() {
	ImGui();
	sphere->Update();
	for (int i = 0; i < DIRTCOUNT; i++) {
		dirt[i]->Update();
	}

	if (sphere->mIsHit && sphere->mPosition.y != 360.0f) {
		dirtInitialize();
		for (int i = 0; i < DIRTCOUNT; i++) {
			dirt[i]->mPosition.x = sphere->mPosition.x;
			dirt[i]->mPosition.y = sphere->mPosition.y;
		}
		Vector2 spd;
		spd = GetSpeed();

		for (int i = 0; i < DIRTCOUNT; i++) {
			dirt[i]->mVelocity.x = spd.x;
			dirt[i]->mVelocity.y = spd.y;
		}
	}

}

void GamePlay::Draw() {
	sphere->Draw();
	for (int i = 0; i < DIRTCOUNT; i++) {
		dirt[i]->Draw();
	}
}

void GamePlay::Hit() {

}



float GamePlay::GetTheta() {
	Vector2 delta;
	if (sphere->mIsHit) {
		delta.x = sphere->mCurrentPosition.x - sphere->mBeforePosition.x;
		delta.y = sphere->mCurrentPosition.y - sphere->mBeforePosition.y;
		float Radian;
		Radian = delta.x / delta.y;
		float theta = tanf(Radian);
		if (sphere->mCurrentPosition.x >= sphere->mBeforePosition.x&& theta<=0) {
			theta *= -1;
		}
		if (sphere->mCurrentPosition.x <= sphere->mBeforePosition.x && theta >= 0) {
			theta *= -1;
		}
		return theta;
	}
	return 0.0f;
}

Vector2 GamePlay::GetSpeed() {
	Vector2 speed;
	float theta = GetTheta();
	speed.x = theta * 5;
	speed.y = -(sphere->mVelocity.y) / 3;
	return speed;
}

void GamePlay::ImGui() {
	ImGui::Begin("Window");
		ImGui::DragFloat("sGravity", &sphere->mGravity, 0.01f);
		/*ImGui::DragFloat("dGravity", &dirt[i]->mGravity, 0.01f);*/
		/*ImGui::DragFloat("SphereMass", &sphereMass, 0.01f);
		ImGui::DragFloat("DirtMass", &dirtMass, 0.01f);*/
	ImGui::End();
}