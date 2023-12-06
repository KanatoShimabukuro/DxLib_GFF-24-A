#include "main.h"
#include "DrawHelp.h"

Help::Help()
{
	//ヘルプ画像の読み込み
	if (HelpImage1 = LoadGraph("resources/images/Help/Help_Img2.png")) {}
	if (HelpImage2 = LoadGraph("resources/images/Help/Help2.png")) {}

	Help_Abtn_Count = 0;

}

Help::~Help()
{

}

Scene*Help::update()
{
	//ヘルプ2画面へ遷移
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
	{
		Help_Abtn_Count++;
		//return new DrawHelp;
	}
	
	return this;
}

void Help::draw()const
{
	if (Help_Abtn_Count > 0) {

		DrawGraph(0, 0, HelpImage2, TRUE);
	}
	else {

		//ヘルプ画像の表示
		DrawGraph(0, 0, HelpImage1, TRUE);
	}
}
