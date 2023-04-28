#include "titleobject.h"
#include"../main/config.h"
#include"../libs/scenemanager.h"

TitleObject::TitleObject(Scene* sc)
	:Object(sc)
	,hImage()
	,pos(Vec2<float>{300,400})
	,smoke(nullptr)
	,keystop(false)
	,switchOn(false)
	,frameCount(0)
	,blackOutCount(255)
	,uiDisp(false)
	,myFeed(false)
{}
TitleObject::~TitleObject(){
	for (int i = 0; i < hImage.size(); i++) {
		if (hImage.at(i) > 0)
			DeleteGraph(hImage.at(i)),
			hImage.at(i) = -1;
	}
	if (smoke != nullptr)
		delete smoke;
}
void TitleObject::Init(){
	smoke = new Smoke(this);

	int ahImage = LoadGraph("data/texture/fire_000292.png");
	hImage.emplace_back(ahImage);
	ahImage = LoadGraph("data/texture/kakuremiti__.png");
	hImage.emplace_back(ahImage);
	ahImage = LoadGraph("data/texture/f1486_1.png");
	hImage.emplace_back(ahImage);
	ahImage = LoadGraph("data/texture/fog.png");
	hImage.emplace_back(ahImage);
	ahImage = LoadGraph("data/texture/wood-texture_00004.jpg");
	hImage.emplace_back(ahImage);
	ahImage = LoadGraph("data/texture/DSC_0546_.png");
	hImage.emplace_back(ahImage);
	for (int i = 0; i < hImage.size(); i++) {
		assert(hImage[i] > 0);
	}



	//smoke->SetPos(pos);
}
void TitleObject::Update(){
	frameCount++;
	//フェード数値推移
	if (myFeed) {
		//blackOutCount*=1.025f;
		//blackOutCount*=1.007;
		blackOutCount*=1.05;
		if (blackOutCount > 255)blackOutCount = 255;

	}
	else {
	blackOutCount-=1;
	if (blackOutCount < 50)
		blackOutCount = 50,
		uiDisp = true;
	}
	//マウス座標
	Vec2<int>mouse;
	GetMousePoint(&mouse.x,&mouse.y);

	//マウスろうそく　当たり判定
	bool inFlag = false;
	Vec2<float>_p =pos;
	_p.x += 16;
	_p.y -= 64;
	inFlag= CircleCollision(mouse.Cast<float>(),5,_p,50)||switchOn;
#ifdef _DEBUG
	printfDx(inFlag?"inFlag ON\n":"inFlag OFF\n");
#endif


	//クリック判定
	bool key = (GetMouseInput() & MOUSE_INPUT_LEFT);
	if (key && !keystop) 
		if (inFlag&&uiDisp) {

		switchOn? switchOn = false: switchOn=true;
		if (!switchOn) 
			smoke->Reset(),
			myFeed = false;
		if (switchOn)
			blackOutCount = 50;
		
	}
	
	keystop = key;
	

	//ウィンドウが非アクティブ
	if (!GetWindowActiveFlag()) {
		//switchOn = true;
	}
#ifdef _DEBUG
	printfDx("mouse.x = %d\n",mouse.x);
	printfDx("mouse.y = %d\n",mouse.y);
	printfDx("blackOutCount = %f\n",blackOutCount);
#endif
	if (switchOn)
		myFeed= smoke->Anim();
}
void TitleObject::Draw() {
	int fontSize = GetFontSize();
	//DrawFormatString(400-fontSize*10/4,300-fontSize/2,0xffffff,"TitleScene");
	int size = 512;
	int gSize = 75;

	//壁描画
	DrawExtendGraph(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, hImage.at(4), true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
	DrawBox(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0x0,true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


	//額縁
	DrawExtendGraph(100- gSize,100- gSize,size+100+ gSize,size+ 100+gSize,hImage.at(2),true);
	DrawBoxAA(100-25,100-25,25+100+size,25+100+size,0x351910,true,5);
	DrawBoxAA(100-25,100-25,25+100+size,25+100+size,0x130808,false,15);
	DrawGraph(100,100,hImage.at(1), true);
	
	
	

	
	//煙描画
	smoke->Draw();

	//蝋燭の火
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
	Vec2<float>p = pos;
	p.y -= 128;
	p.x -= 8;


	int moveX = GetRand(1)-GetRand(1);
	int fireSize = 7;
	if (!GetWindowActiveFlag())
		fireSize = 14,
		moveX = GetRand(3)-GetRand(3);
	if(!switchOn)
	DrawExtendGraph(p.x,p.y+GetRand(fireSize),p.x+64+moveX,p.y+128,hImage.at(0),true);
	

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	
	




	//光のぼやけ
	if(!switchOn)
	for (int i = 0; i < 10; i++) {
	
		int num = 100 * i / 75;
		int blend = 0;
		int rand = GetRand(10)+1;
		if (frameCount %rand == 0) {
			float backblink = num;
			if (!GetWindowActiveFlag())
				backblink = num*0.8f;

			blend = num;
		}
		else {
			float backblink = 0.7f;
			if (!GetWindowActiveFlag())
				backblink = 0.3f;

			blend = num*backblink;
		}
		SetDrawBlendMode(DX_BLENDMODE_ADD, blend);
		DrawCircle(p.x, p.y, 50+i*15*i/5, 0xddee00, true);

	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//ろうそく
	//DrawBox(p.x,pos.y,p.x+64,pos.y+512,0xffffff,true);
	if (switchOn)
	//	SetDrawBlendMode(DX_BLENDMODE_SUB, 150);
	SetDrawBright(0,0,0);
	else
		SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
	DrawExtendGraph(p.x-10,pos.y-60,p.x+64+40,pos.y+512,hImage.at(5),true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	SetDrawBright(255,255,255);


	size = 50;
	DrawExtendGraph(0- size,0- size,SCREEN_WIDTH,SCREEN_HEIGHT+size/2,hImage.at(3),true);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220);
	size /= 2;
	DrawExtendGraph(0 - size, 0 - size, SCREEN_WIDTH, SCREEN_HEIGHT + size / 2, hImage.at(3), true);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);





	//フェード
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(blackOutCount));
	DrawBox(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0x0,true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//bool TitleObject::Collision(Vec2<float>_pos, float _rad,Vec2<float>_pos2, float _rad2){
//	float a, b, c;
//	a = _pos2.x - _pos.x;
//	b = _pos2.y - _pos.y;
//	c = _rad+_rad2;
//	if (a * a + b * b < c * c) {
//		return true;
//	}
//	return false;
//}



Smoke::Smoke(Object* obj)
	:object(obj)
	,hImage(-1)
{
	hImage = LoadGraph("data/texture/wallpaper_00273.png");
	assert(hImage > 0);

	pos= obj->GetScene()->Invoke<TitleObject>()->GetPos();
	move = { 0,0 };
	vec = 5.0f;
	alpha = 60;

}

Smoke::~Smoke()
{
	if (hImage < 0)
		DeleteGraph(hImage);
}

void Smoke::Draw()
{
	Vec2<float>p = pos;
	p = { pos.x + 50 + move.x ,pos.y + move.y };

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	
	DrawExtendGraph(pos.x, pos.y, p.x, p.y, hImage, true);
	DrawModiGraphF(pos.x + 25, p.y, p.x - 25, p.y, p.x, pos.y, p.x, pos.y, hImage, true);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
#ifdef _DEBUG
	printfDx("%f", vec);
#endif
}

bool Smoke::Anim(){

	move.y -= vec;

	vec *= 0.99f;
	if (vec <= 1.5f)
		alpha--;
	if (alpha < 0) {
		alpha = 0;
		return true;
	}

	return false;
}

void Smoke::Reset(){

	pos = { 300,400 };
	move = { 0,0 };
	vec = 5.0f;
	alpha = 60;
}