#ifndef PHOBOS_3D
#define PHOBOS_3D

#include "GameModuleBase.h"
#include "Logger.h"
#include <string>
#include "Texture.h"
#include <vector>

class PhobosGame : public GameModuleBase
{
private:

	float r, g, b;
	float color[3];

public:

	using base = GameModuleBase;

	PhobosGame(AppConfig* _appCfg) 
		:GameModuleBase(_appCfg)
	{
		//setRenderingFunction(render);
		//setUpdateFunction(update);
		//glfwSetFramebufferSizeCallback(getWindow(), onResize);
		
		r = 0.4;
		g = 0.2;
		b = 0.1;
		setClearColor(0.0f, 0.0f, 0.0f);
	}

	virtual void start() override
	{
		base::start();
	}
	
	virtual void update(float& dt) override
	{

	}

	virtual void render(float& dt) override
	{
		
	}

	virtual void input(float& dt) override
	{
		base::input(dt);
	}
};

#endif