#include "main.h"
#include "DrawHelp.h"

Help::Help()
{
	//ヘルプ画像の読み込み
	HelpImage1 = LoadGraph("resources/images/Help/Help_Img2.png");
}

Help::~Help()
{

}

Scene*Help::update()
{
	//ヘルプ2画面へ遷移
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
	{
		return new DrawHelp;
	}
	
	return this;
}

void Help::draw()const
{
	//ヘルプ画像の表示
	DrawGraph(0, 0, HelpImage1, TRUE);
}
