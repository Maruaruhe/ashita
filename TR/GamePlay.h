#define _USE_MATH_DEFINE
#include "Sphere.h"
#include "Dirt.h"
#include <math.h>

#include <imgui.h>

#define DIRTCOUNT 30

class GamePlay
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
	Dirt* dirt[DIRTCOUNT];
private:
};

