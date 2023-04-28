#include "temp.h"

Temp::Temp(Scene* sc)
	:Object(sc)
	,str()
	,keystop(false)
	,nowPage(0)
	,frameCount(0)
	,fontHandle(-1)
{}
Temp::~Temp(){
	if(fontHandle>0)
	DeleteFontToHandle(fontHandle);
}
void Temp::Init(){
	fontHandle= CreateFontToHandle("kawaii手書き文字", 32, 2, DX_FONTTYPE_ANTIALIASING_EDGE);
	assert(fontHandle>0);
	str.clear();
	str.emplace_back("   ");
	str.emplace_back("ア  ジャラカモ  クレン");
	str.emplace_back("テケ  レッツの");
	str.emplace_back("パッ . . . ");
	str.emplace_back(". . . . . . ");
	str.emplace_back(". . . . . . . . . . . . . ");
}
void Temp::Update(){
	frameCount++;
	bool anyKey = CheckHitKeyAll(DX_CHECKINPUT_ALL);
	if (anyKey && !keystop) {
		nowPage++;
		if (nowPage > str.size() - 1)
			nowPage = str.size() - 1;
			frameCount = 0;
	}
	keystop = anyKey;

}
void Temp::Draw(){
	//std::string s = str.at(nowPage);
	//for (int i = 0; i < s.size(); i++) {
	//	bool disp = frameCount>i*10;
	//	if (!disp)continue;
	//	std::string oneStr;
	//	oneStr[0] = s.at(i);
	//	i++;
	//	oneStr[1] = s.at(i);
	//	DrawString(100+i*GetFontSize(),600,oneStr.c_str(), 0xffffff);
	//}

	int maxIndex = (str.at(nowPage).size()-1) / 2;
	int nowFontSize = 32;// GetFontSize();
	for (int i = 0; i <maxIndex ; i++) {
		int dispSpeed=8;
		int xSize = (frameCount)*dispSpeed /** nowFontSize/2*/;
		if (maxIndex < frameCount*dispSpeed / nowFontSize /** 2*/) {
			xSize = maxIndex*nowFontSize+nowFontSize/2;//(str.at(nowPage).size()/2.f) * nowFontSize;
			
			if (i == 0) {//下向き三角　描画
			Vec2<float>pos = {100+xSize+nowFontSize,600+sinf((frameCount/8)/DX_PI_F*180)*3};
			int size = 10;
			int off = nowFontSize / 3;
			DrawTriangle(pos.x,pos.y+size+off,pos.x+size,pos.y+off,pos.x-size,pos.y+off,0xffffff,false);
			}
		}



		SetDrawArea(100,600,100+xSize,600+ nowFontSize);

		//DrawFormatString(100,600,0xffffff,str.at(nowPage).c_str());

		//SetDrawArea(100, 600, 100 + xSize, 600 + 32);
		DrawStringToHandle(100,600,str.at(nowPage).c_str(),0xffffff,fontHandle);
	}
	SetDrawAreaFull();
}
