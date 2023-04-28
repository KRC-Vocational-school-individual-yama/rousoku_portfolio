#include "titlefeed.h"
#include"../main/config.h"
#include"../libs/scenemanager.h"
#include"titleui.h"
#include"titleobject.h"

TitleFeed::TitleFeed(Scene* sc)
	:Object(sc)
	,blackOutCount(1.f)
	,mouseIn(false)
	,keystop(false)
{}
TitleFeed::~TitleFeed(){

}
void TitleFeed::Init(){

}
void TitleFeed::Update(){
	TitleUi* tu = GetScene()->Invoke<TitleUi>();
	if (tu == nullptr)return;
	TitleObject* to = GetScene()->Invoke<TitleObject>();
	if (to == nullptr);//return を忘れずに
	
	//Button
	bool feedFlag = tu->GetOn();
	bool key = GetMouseInput() & MOUSE_INPUT_LEFT;
	if (key&&!keystop){//マウスdown
		if(feedFlag)//uiに乗ってたら
			if (mouseIn) {//フェードを切り替え
				//mouseIn = false;
			}
			else {
				mouseIn = true;
				blackOutCount = 50;
		}

	}
	keystop = key;

	//フェードの暗さ
	bool feed = false;
	if (mouseIn)feed = to->GetMyFeed();
	if (feed) {
		//blackOutCount *= 1.006f;
		blackOutCount *= 1.08f;
		if (blackOutCount > 255)
			blackOutCount = 255
			, SceneManager::SceneChange("Game");

	}
	else {
		blackOutCount = 1;
		if (blackOutCount < 1)
			blackOutCount = 1;
	}
#ifdef _DEBUG
	printfDx("Feed blackOutCount = %f\n", blackOutCount);
#endif
}
void TitleFeed::Draw(){

	//フェード
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(blackOutCount));
	DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x0, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
