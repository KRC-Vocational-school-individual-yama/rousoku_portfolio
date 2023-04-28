#include "scene.h"
#include"object.h"

Scene::Scene()
	:objectList()
{}
Scene::~Scene(){
	AllDestroy();
}

void Scene::Update(){

	for (auto& object : objectList) {
		if (object->GetInitFlag()) {
			object->Init();
			object->SetInitFlag(false);
		}

		object->Update();
	}
}
void Scene::Draw(){
	for (auto& object : objectList) {
		object->Draw();
	}
}

void Scene::AllDestroy(){
	if (objectList.empty())return;
	for (auto it = objectList.begin(); it != objectList.end(); ) {
		auto& object = (*it);
		if (nullptr != object) {
			delete object;
			it=objectList.erase(it);
		}
	}
}
