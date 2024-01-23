#include "GameModuleBase.h"

#define LOG_APP "GameModuleBase::"

GameModuleBase::GameModuleBase(AppConfig* _appCfg)
{
	appCfg = *_appCfg;

	bool init = initWindow(_appCfg);
	if (!init)
	{
		std::cout << LOG_APP"Constructor -> failed";
	}
	clearColor[0] = 0.1f;
	clearColor[1] = 0.2f;
	clearColor[2] = 0.3f;

	setCallbacks();
	
}

GameModuleBase::~GameModuleBase()
{
	destroy();
}


bool GameModuleBase::initWindow(AppConfig* _appCfg)
{
	if (!glfwInit())
	{
		return false;
	}

	window = glfwCreateWindow(_appCfg->width, _appCfg->height, _appCfg->title, NULL, NULL);

	if (window == NULL)
	{
		return false;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = true;
	if (glewInit() != 0)
	{
		return false;
	}

	return true;
}

void GameModuleBase::run()
{
	Timer::startTime = Timer::getTime();

	start();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(clearColor[0], clearColor[1], clearColor[2], 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		input(Timer::dt);
		update(Timer::dt);
		render(Timer::dt);

		glfwSwapBuffers(window);
		glfwPollEvents();

		float endTime = Timer::getTime();
		Timer::dt = endTime - Timer::startTime;
		Timer::startTime = endTime;
	}

	glfwTerminate();
}

void GameModuleBase::destroy()
{
	glfwDestroyWindow(window);
}

AppConfig GameModuleBase::getConfiguration() const
{
	return appCfg;
}

GLFWwindow* GameModuleBase::getWindow()
{
	return window;
}

void GameModuleBase::update(float& dt)
{

}

void GameModuleBase::render(float& dt)
{
	
}

void GameModuleBase::input(float& dt)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void GameModuleBase::onResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void GameModuleBase::setCallbacks()
{
	glfwSetFramebufferSizeCallback(window, onResize);
}

void GameModuleBase::setClearColor(float r, float g, float b)
{
	clearColor[0] = r;
	clearColor[1] = g;
	clearColor[2] = b;
}

void GameModuleBase::start()
{
	std::cout << "app started" << std::endl;
}

float Timer::dt = 0.0f;
float Timer::startTime;