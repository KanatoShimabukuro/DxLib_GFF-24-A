#include "main.h"

//�R���X�g���N�^
Title::Title()
{
	TitleImage = LoadGraph("resources/images/Title.png");
	g_MenuNumber = 0;
	TitleInterval = 0;
	cursor = LoadGraph("resources/images/cursor.png");
	//state = 10;
}

Title::~Title()
{
	DeleteGraph(TitleImage);
}

//�X�V
Scene*Title::update()
{
	//�X�e�B�b�N�̐���
	if (TitleInterval < TITLEINTERVAL)
	{
		TitleInterval++;
	}

	if (InputCtrl::GetButtonState(XINPUT_BUTTON_DPAD_UP) == PRESS || InputCtrl::GetStickRatio(L).y > 0.8 && TitleInterval >= 15)
	{
		//�X�e�B�b�N�ړ��̏�����
		TitleInterval = 0;
		//�^�C�g���J�[�\���̈ړ�
		if (--g_MenuNumber > TITLECURSOR);
		//�^�C�g���J�[�\���̈ړ��ʂ̐���
		if (g_MenuNumber < 0) g_MenuNumber = 3;
	}
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_DPAD_DOWN) == PRESS || InputCtrl::GetStickRatio(L).y < -0.8 && TitleInterval >= 15)
	{
		//�X�e�B�b�N�ړ��̏�����
		TitleInterval = 0;
		//�^�C�g���J�[�\���̈ړ�
		if (++g_MenuNumber < -TITLECURSOR);
		//�^�C�g���J�[�\���̈ړ��ʂ̐���
		if (g_MenuNumber > 3)g_MenuNumber = 0;
	}
	g_MenuY = g_MenuNumber * 52;
	
	//A�{�^���Ń��j���[����E��ʑJ��
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
	{
		if (g_MenuNumber == 0) {
			return new GameScene;
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
	
	return this;
}

//�`��
void Title::draw() const
{
	//�^�C�g���w�i�̕`��
	DrawGraph(0, 0, TitleImage, TRUE);
	//�^�C�g�����̕\��
	
	//�^�C�g�����j���[�̕\��
	SetFontSize(55);
	DrawString(550, 320, "Start", 0x000000);
	DrawString(550, 370, "Help", 0x000000);
	DrawString(550, 420, "Credit", 0x000000);
	DrawString(550, 470, "End", 0x000000);

	//�^�C�g���J�[�\���̕`��
	DrawGraph(470, 290 + g_MenuY, cursor, TRUE);

}