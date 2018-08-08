#include <iostream>
#include "EngineDefine.h"
#include "Ray.h"
#include "Vect3.h"
#include "World.h"

using namespace std;

int main()
{

	World* world = new World;
	world->Build();
	world->RenderScene();

	return 0;
}