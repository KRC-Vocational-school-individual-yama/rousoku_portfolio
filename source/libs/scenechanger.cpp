#include "scenechanger.h"
#include<Windows.h>
#include<assert.h>
#include"testscene.h"
#include"scene.h"
#include"../titleScene/titlescene.h"
#include"../gameScene/gamescene.h"

SceneChanger::SceneChanger()
{}
SceneChanger::~SceneChanger(){
}

Scene* SceneChanger::Changer(std::string scene) {
	if (scene == "boot") {

		return new TestScene();
	}
	else if (scene == "Title") {
		return new TitleScene();
	}
	else if (scene == "Game") {
		return new GameScene();
	}
	else {
		MessageBox(NULL, ("éüÇÃÉVÅ[ÉìÇÕÇ†ÇËÇ‹ÇπÇÒ\n" + scene).c_str(), "SceneFactory", MB_ICONERROR | MB_OK);
		assert(false);
		return nullptr;
	}

}
