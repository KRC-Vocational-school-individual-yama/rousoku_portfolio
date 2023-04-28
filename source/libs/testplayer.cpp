#include "testplayer.h"
#include"scenemanager.h"

Test::Test(Scene* sc)
	:Object(sc)
{}
Test::~Test(){

}
void Test::Init(){
}
void Test::Update(){
	SceneManager::SceneChange("Title");
}
void Test::Draw(){
}
