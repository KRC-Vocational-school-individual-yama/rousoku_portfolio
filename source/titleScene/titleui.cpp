#include "titleui.h"
#include"../main/config.h"
#include"../libs/scene.h"
#include"titleobject.h"

TitleUi::TitleUi(Scene* sc)
	:Object(sc)
	,pos( Vec2<float>{750,450})
	,size(Vec2<float>{175,100})
	,myDisp(false)
	,on(false)
	,fontHandle()
{}
TitleUi::~TitleUi(){
	for(int i=0;i<fontHandle.size();i++)
	if(fontHandle.at(i)>0)
		DeleteFontToHandle(fontHandle.at(i));
}
void TitleUi::Init(){
	int font = -1;
	//font=CreateFontToHandle("Ç†ÇÒÇ∏Ç‡Ç∂2020",64,2,DX_FONTTYPE_ANTIALIASING);
	font=CreateFontToHandle("kawaiiéËèëÇ´ï∂éö",64,2,DX_FONTTYPE_ANTIALIASING);
	fontHandle.emplace_back(font);
	font = CreateFontToHandle("Ç»Ç¬ÇﬂÇ‡Ç∂",96,5, DX_FONTTYPE_ANTIALIASING_EDGE,-1,5,3);
	fontHandle.emplace_back(font);
	for(int i=0;i<fontHandle.size();i++)
	assert(fontHandle.at(i)>0);

}
void TitleUi::Update() {

	if (myDisp) {

		Vec2<int>mouse;
		GetMousePoint(&mouse.x, &mouse.y);
		on = SquareCollision(pos, size, mouse.Cast<float>(), Vec2<float>{5, 5});

		//uiButtonÇÃìñÇΩÇËîªíË
		if (on) {
			if (GetMouseInput() & MOUSE_INPUT_LEFT) {

				TitleObject* tobj = GetScene()->Invoke<TitleObject>();
				if (tobj != nullptr)
					tobj->SetPanishment();
			}
		}
	}
	else {



		//UiÇÃï\é¶

		TitleObject* tobj = GetScene()->Invoke<TitleObject>();
		if (tobj == nullptr)return;

		myDisp = tobj->IsUiDisp();
	}
}
void TitleUi::Draw(){
	if (!myDisp)return;

	
	//button Ui
	DrawBoxAA(pos.x,pos.y,pos.x+size.x,pos.y+size.y,0xffffff,on, 0.5f);
	if(on&&!(GetMouseInput()&MOUSE_INPUT_LEFT))
		DrawBoxAA(pos.x-5, pos.y-5, pos.x + size.x+5,5+ pos.y + size.y, 0xffffff, false, 0.5f);


	std::string str="è¡Ç∑ÅB";
	unsigned int color = 0xffffff;
	if (on)
		color = 0x0;
	DrawStringToHandle(pos.x+8,pos.y+16, str.c_str(),color, fontHandle.at(0));



	//Title
	unsigned int color2 = 0x0;
				 color = 0xffffff;
	//if (on)
	//	color=0x0,
	//	color2 = 0xffffff;
	DrawStringToHandle(SCREEN_WIDTH/2,100.f,"ÇÎÇ§ÇªÇ≠", color,fontHandle.at(1),color2);
}
