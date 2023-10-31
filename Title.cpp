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
	TitleImage = LoadGraph("resources/images/Title.png");
	g_MenuNumber = 0;
	interval = 0.7f;
	cursor = LoadGraph("resources/images/cursor.png");

	Ctrl = false;
}

//�X�V
Scene*Title::update()
{
	InputCtrl::Update();
	InputCtrl::GetStickRatio(L).y;
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A))
	{
		if (state == 0) {
			return new GameMain;
		}
		if (state == 1) {
			return new Help;
		}
		if (state == 2) {
			return new Credit;
		}
		if (state == 3) {
			return new End;
		}
	}

	//�\���L�[���{�^���ŃJ�[�\��������

	if (((InputCtrl::GetStickState(L).y < 0.3f) && (InputCtrl::GetStickState(L).y > -0.3f))) Ctrl = true;
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_DPAD_UP) || ((InputCtrl::GetStickState(L).y >= 0.7f) && Ctrl)){
		if (state < 10) state += 20;
		else state -= 10;
			Ctrl = false;
	}
	else if (InputCtrl::GetButtonState(XINPUT_BUTTON_DPAD_DOWN) || (((InputCtrl::GetStickState(L).y <= -0.7f) && Ctrl))){
		if (state >= 20) state -= 20;
		else state += 10;
			Ctrl = false;
	}
	
	return this;
}

//�`��
void Title::draw() const
{
	DrawGraph(0, 0, TitleImage, TRUE);
	SetFontSize(100);
	DrawString(400, 150, "�^�C�g����", 0x000000);
	SetFontSize(75);
	DrawString(550, 300, "Start", 0x000000);
	DrawString(550, 370, "Help", 0x000000);
	DrawString(550, 440, "Credit", 0x000000);
	DrawString(550, 510, "End", 0x000000);

	DrawGraph(470, 290 + state, cursor, TRUE);

}