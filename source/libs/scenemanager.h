#pragma once
#include<string>
#include"scene.h"

namespace SceneManager {
	void Init();
	void Update();
	void Draw();
	void Delete();

	void SceneChange(std::string sceneName);
	int GetFrame();
	Scene* GetCommonScene();
}