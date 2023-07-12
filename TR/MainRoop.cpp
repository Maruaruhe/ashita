#include "MainRoop.h"
#include <Novice.h>

void MainRoop::Initialize() {
	sphere = new Sphere;
	sphere->Initialize();
	player = new Player;
	player->Initialize();
	for (int i = 0; i < COUNT; i++) {
		dirt[i] = new Dirt;
		dirt[i]->Initialize();
	}
	mGravity = 9.8f;
	mSphereMass = 10.0f;
	mDirtMass = 10.0f;
}

void MainRoop::sphereInitialize() {
	sphere->Initialize();
}

void MainRoop::dirtInitialize() {
	for (int i = 0; i < COUNT; i++) {
		dirt[i]->Initialize();
	}
}

void MainRoop::Update() {
	//imgui
	ImGui();
	//scene
	if (Novice::CheckHitKey(DIK_1)) {
		scene = sphereScene;
		sphere->Initialize();
	}
	if (Novice::CheckHitKey(DIK_2)) {
		scene = playerScene;
		player->Initialize();
	}

	if (Novice::CheckHitKey(DIK_R)) {
		Initialize();
	}

	//update
	switch (scene) {
	case sphereScene:
		sphere->SetGravity(mGravity);
		sphere->SetMass(mSphereMass);
		sphere->Update();
		break;
	case playerScene:
		player->Update();
		break;
	}
	for (int i = 0; i < COUNT; i++) {
		dirt[i]->SetGravity(mGravity);
		dirt[i]->SetMass(mDirtMass);
		dirt[i]->Update();
	}
	//Hit
	Hit();
}

void MainRoop::Draw() {
	switch (scene) {
	case sphereScene:
		sphere->Draw();
		break;
	case playerScene:
		player->Draw();
		break;
	}
	for (int i = 0; i < COUNT; i++) {
		dirt[i]->Draw();
	}
}

void MainRoop::Hit() {
	switch (scene) {
	case sphereScene:
		if (sphere->mIsHit && sphere->mPosition.y != 360.0f) {
			dirtInitialize();
			for (int i = 0; i < COUNT; i++) {
				dirt[i]->mPosition.x = sphere->mPosition.x;
				dirt[i]->mPosition.y = sphere->mPosition.y;

				num[i].x = rand() % 25 - 25;
				num[i].y = rand() % 30 - 30;
			}
			Vector2 spd;
			spd = GetSpeed();

			for (int i = 0; i < COUNT; i++) {
				if (i <= COUNT / 2) {
					dirt[i]->mVelocity.x = spd.x + num[i].x * 0.1;
					dirt[i]->mVelocity.y = spd.y - num[i].y * 0.2;
				}
				else {
					dirt[i]->mVelocity.x = spd.x - num[i].x * 0.1;
					dirt[i]->mVelocity.y = spd.y - num[i].y * 0.2;
				}
			}
		}
		break;
	case playerScene:
		if (player->GetFlag()) {
			dirtInitialize();
			for (int i = 0; i < COUNT; i++) {
				dirt[i]->mPosition.x = player->GetPosition().x;
				dirt[i]->mPosition.y = player->GetPosition().y - 5;


				num[i].x = rand() % 25 - 25;
				num[i].y = rand() % 30 - 30;
			}

			for (int i = 0; i < COUNT; i++) {
				if (i <= COUNT / 2) {
					dirt[i]->mVelocity.x = 0 + num[i].x * 0.1;
					dirt[i]->mVelocity.y = -10 - num[i].y * 0.2;
				}
				else {
					dirt[i]->mVelocity.x = 0 - num[i].x * 0.1;
					dirt[i]->mVelocity.y = -10 - num[i].y * 0.2;
				}
			}
		}
		break;
	}
}

float MainRoop::GetTheta() {
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

Vector2 MainRoop::GetSpeed() {
	Vector2 speed;
	float theta = GetTheta();

	float mass = (mSphereMass / mDirtMass);

	speed.x = theta * 5 * mass;
	speed.y = -(sphere->mVelocity.y) * mass / 3;
	return speed;
}

void MainRoop::ImGui() {
	ImGui::Begin("Window");
	ImGui::DragFloat("Gravity", &mGravity, 0.01f);
	ImGui::DragFloat("sphereMass", &mSphereMass, 0.01f);
	ImGui::DragFloat("dirtMass", &mDirtMass, 0.01f);
	ImGui::End();
}