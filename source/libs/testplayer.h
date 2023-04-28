#pragma once
#include"object.h"
#include<string>


class Test :public Object {
public:
	Test(Scene* sc);
	~Test()			override;
	void Init()		override;
	void Update()	override;
	void Draw()		override;

private:

};