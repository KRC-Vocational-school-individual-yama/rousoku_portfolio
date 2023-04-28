#pragma once
#include"../libs/object.h"

class TitleFeed :public Object {
public:
	 TitleFeed(Scene* sc);
	~TitleFeed()			override;
	void Init()		override;
	void Update()	override;
	void Draw()		override;
private:
	float blackOutCount;
	bool mouseIn;
	bool keystop;
};