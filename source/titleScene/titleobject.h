#pragma once
#include"../libs/object.h"

class Smoke {
public:
	Smoke(Object* obj);
	~Smoke();

	void Draw();
	bool Anim();
	void Reset();

	void SetPos(Vec2<float>_p) { pos = _p; }
private:
	int hImage;
	Vec2<float>move;
	Vec2<float>pos;
	float vec;
	int alpha;

	Object* object;
};

class TitleObject :public Object {
public:
	TitleObject(Scene* sc);
	~TitleObject()	override;
	void Init()		override;
	void Update()	override;
	void Draw()		override;

	Vec2<float>GetPos() { return pos; }
	bool IsUiDisp() { return uiDisp; }
	bool GetMyFeed() { return myFeed; }
	void SetPanishment() { switchOn=true; }
private:
	//bool Collision(Vec2<float>_pos,float _rad,Vec2<float>_pos2,float _rad2);
	std::vector<int>hImage;
	Vec2<float>pos;
	Smoke* smoke;
	bool keystop;
	bool switchOn;
	bool uiDisp;
	bool myFeed;
	int frameCount;
	float blackOutCount;
};
