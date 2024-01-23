#ifndef GRAPHICS_RESOURCE_MANAGER_H
#define GRAPHICS_RESOURCE_MANAGER_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include <glm/glm.hpp>

using ShaderID = unsigned int;

class GraphicsResourceManager
{
private:

	static std::map<std::string, ShaderID> shaders;

public:
	
	void loadResources()
	{
		GraphicsResourceManager::GetShaders()["defaultShader"] = 1;
	}

	static std::map<std::string, ShaderID>& GetShaders()
	{
		return shaders;
	}
};

std::map<std::string, ShaderID> GraphicsResourceManager::shaders;

#endif