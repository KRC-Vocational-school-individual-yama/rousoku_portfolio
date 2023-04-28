#pragma once
#include<string>

class Scene;

class SceneChanger {
public:
	SceneChanger();
	~SceneChanger();
	Scene* Changer(std::string sceneName);

private:



};