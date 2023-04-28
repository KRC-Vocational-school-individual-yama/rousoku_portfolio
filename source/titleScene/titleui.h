#pragma once

#include"../libs/object.h"

class TitleUi :public Object {
public:
	TitleUi(Scene* sc);
	~TitleUi()		override;
	void Init()		override;
	void Update()	override;
	void Draw()		override;

	bool GetOn() { return on; }
private:
	Vec2<float>pos ;
	Vec2<float>size;
	bool myDisp;
	bool on;
	std::vector<int>fontHandle;
};