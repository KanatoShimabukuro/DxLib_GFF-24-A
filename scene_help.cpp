#include "main.h"
#include "DrawHelp.h"

Help::Help()
{
	//�w���v�摜�̓ǂݍ���
	HelpImage1 = LoadGraph("resources/images/Help/Help_Img2.png");
}

Help::~Help()
{

}

Scene*Help::update()
{
	//�w���v2��ʂ֑J��
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
	{
		return new DrawHelp;
	}
	
	return this;
}

void Help::draw()const
{
	//�w���v�摜�̕\��
	DrawGraph(0, 0, HelpImage1, TRUE);
}
