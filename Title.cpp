#include "DxLib.h"
#include "Title.h"
#include "GameMain.h"
#include "sourceFiles/inputCtrl.h"
#include "Help.h"
#include "Credit.h"
#include "End.h"

//�R���X�g���N�^
Title::Title()
{
	EnemyImage0 = LoadGraph("resources/images/(��)���@�g��.png");
	EnemyImage1 = LoadGraph("resources/images/(��)�X�P���g��.png");
	EnemyImage2 = LoadGraph("resources/images/(��)�X���C��.png");
	EnemyImage3 = LoadGraph("resources/images/(��)�~�m�^�E���X.png");
	EnemyImage4 = LoadGraph("resources/images/(��)�܂���.png");
	g_MenuNumber = 0;
}

//�f�X�g���N�^
Title::~Title()
{

}

//�X�V
Scene*Title::update()
{
	InputCtrl::Update();
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A))
	{
		if (g_MenuNumber == 0) {
			return new GameMain;
		}
		if (g_MenuNumber == 1) {
			return new Help;
		}
		if (g_MenuNumber == 2) {
			return new Credit;
		}
		if (g_MenuNumber == 3) {
			return new End;
		}
	}

	//�\���L�[���{�^���ŃJ�[�\�������Ɉړ�
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_DPAD_DOWN) == PRESS )
	{
		if (++g_MenuNumber > 3)g_MenuNumber = 0;
	}
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_DPAD_UP) == PRESS )
	{
		if (--g_MenuNumber < 0)g_MenuNumber = 3;
	}
	g_MenuY = g_MenuNumber * 65;

	return this;
}

//�`��
void Title::draw() const
{
	SetFontSize(100);
	DrawString(350, 150, "�^�C�g����", 0xffffff);
	SetFontSize(75);
	DrawString(470, 300, "Start", 0xffffff);
	DrawString(470, 370, "Help", 0xffffff);
	DrawString(470, 440, "Credit", 0xffffff);
	DrawString(470, 510, "End", 0xffffff);

	DrawTriangle(420, 315 + g_MenuY, 460, 345 + g_MenuY, 420, 375 + g_MenuY, 0xff0000, TRUE);

}