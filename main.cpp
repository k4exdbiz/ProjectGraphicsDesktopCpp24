#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "GameModuleBase.h"
#include "Phobos.h"

int main()
{
	AppConfig cfg = { 640, 480, "Phobos3D" };

	PhobosGame game(&cfg);
	game.run();

	return 0;
}