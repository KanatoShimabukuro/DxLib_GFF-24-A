#include "DrawHelp.h"
#include "DxLib.h"
#include "main.h"

//DrawHelp::DrawHelp()
//{
//	//�w���v2�摜�̓Ǎ�
//	HelpImage2 = LoadGraph("resources/images/Help/Help2.png");
//}
//
//Scene* DrawHelp::update()
//{
//	//A�{�^���ŃQ�[�����C���֑J��
//	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
//	{
//		SoundManager::StopSoundBGMs();
//		return new GameScene;
//	}
//	//B�{�^���Ń^�C�g���֑J��
//	if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
//	{
//		return new Title;
//	}
//	return this;
//}
//
//void DrawHelp::draw() const
//{
//	//�w���v2��ʂ̕\��
//	DrawGraph(0, 0, HelpImage2, TRUE);
//	SetFontSize(40);
//	DrawString(520, 670, "A�{�^���F�X�^�[�g", 0xff0000);
//	DrawString(900, 670, "B�{�^���F�^�C�g��", 0xff0000);
//}
