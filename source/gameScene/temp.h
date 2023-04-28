#pragma once
#include"../libs/object.h"

class Temp :public Object{
public:
	Temp(Scene* sc);
	~Temp()			override;
	void Init()		override;
	void Update()	override;
	void Draw()		override;

private:
	std::vector<std::string>str;
	bool keystop;
	int nowPage;
	int frameCount;
	int fontHandle;
};