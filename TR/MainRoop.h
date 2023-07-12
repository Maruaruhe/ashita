#define _USE_MATH_DEFINE
#include "Sphere.h"
#include "Dirt.h"
#include "Player.h"
#include <math.h>
#include <ctime>

#include <imgui.h>

#define COUNT 31

class MainRoop
{
public:
	void Initialize();

	void sphereInitialize();
	void dirtInitialize();

	void Update();
	void ImGui();
	void Draw();
	float GetTheta();
	Vector2 GetSpeed();

	void Hit();

	Sphere* sphere;
	Dirt* dirt[COUNT];
	Player* player;

	Vector2 num[COUNT];

private:
	float mGravity;
	float mSphereMass;
	float mDirtMass;

	enum Scene {
		sphereScene,
		playerScene
	};
	Scene scene = sphereScene;
};

