#ifndef GAME_MODULE_BASE_H
#define GAME_MODULE_BASE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

struct AppConfig
{
	int width;
	int height;
	const char* title;
};

class GameModuleBase
{
private:
	GLFWwindow* window;
	AppConfig appCfg;
	float clearColor[3];

public:

	GameModuleBase(AppConfig* _appCfg);
	~GameModuleBase();

	void run();
	void destroy();
	AppConfig getConfiguration() const;
	GLFWwindow* getWindow();
	virtual void start();
	virtual void update(float& dt);
	virtual void render(float& dt);
	virtual void input(float& dt);
	static void onResize(GLFWwindow* window, int width, int height);
	void setClearColor(float r, float g, float b);
	
private:

	bool initWindow(AppConfig* _appCfg);
	void setCallbacks();
};

class Timer
{
public:

	static float dt;
	static float startTime;

	static float getTime()
	{
		return static_cast<float>(glfwGetTime());
	}


};

#endif