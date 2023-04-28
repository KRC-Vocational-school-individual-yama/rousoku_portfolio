#include "titlescene.h"

#include"titleobject.h"
#include"titleui.h"
#include"titlefeed.h"

TitleScene::TitleScene(){
	Create<TitleObject>();
	Create<TitleUi>();
	Create<TitleFeed>();
}
TitleScene::~TitleScene(){

}
