#include"scenemanager.h"
#include"scenechanger.h"
#include"../titleScene/titleobject.h"
namespace {
	std::string scene;
	std::string nextScene;
	SceneChanger* changer;
	Scene* game;
	Scene* commonGame;
	int frameCount;
}
namespace SceneManager {

	void Init() {
		changer = new SceneChanger();
		game = nullptr;
		commonGame = new Scene();
		scene = "";
		frameCount = 0;
		nextScene = "boot";

		//game = dynamic_cast<Scene*>(changer->Changer(nextScene));
		//game->Init();
	}
	void Update() {
		frameCount++;
		if (nextScene != scene) {
			if(game!=nullptr)
			delete game;
			game = dynamic_cast<Scene*>(changer->Changer(nextScene));
			scene = nextScene;
		}
		game->Update();
		commonGame->Update();
	}
	void Draw() {
		game->Draw();
		commonGame->Draw();
	}
	void Delete() {
		delete game;
		delete changer;
		delete commonGame;
	}

	void SceneChange(std::string sceneName){
		nextScene = sceneName;
	}
	int GetFrame() {
		return frameCount;
	}
	Scene* GetCommonScene() {
		return commonGame;
	}
}