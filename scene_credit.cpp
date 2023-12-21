#include "main.h"

Credit::Credit()
{
	//�N���W�b�g�摜�̓Ǎ�
	CreditImage = LoadGraph("resources/images/Title/Title_background_tree tower_1280.png");
	//���Ԃ̏�����
	g_WaitTime = 0;
	g_PosY_D = 450;

	Credit_Mouse_x = 0;
	Credit_Mouse_y = 0;
}

Credit::~Credit()
{
	DeleteGraph(CreditImage);
}

Scene* Credit::update()
{
	//�N���W�b�g���[������
	//���Ԃ����Ă΃^�C�g���֑J��

	//�f�o�b�O�p ���Ƃŏ���
	//Credit_Mouse_x = InputCtrl::GetMouseCursor().x;
	//Credit_Mouse_y = InputCtrl::GetMouseCursor().y;

	

	if (++g_WaitTime < /*2370*/  2480) {

		//if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESSED) g_PosY_D -= 5;
		g_PosY = /*600*/ g_PosY_D - g_WaitTime;
	}
	else {

		return new Title;
	}
	return this;
}

void Credit::draw()const
{
	//�w�i�摜
	DrawGraph(0, 0, CreditImage, TRUE);

	//�@���S��
	//DrawLine(0, 360, 1280, 360, GetColor(255, 0, 0), TRUE);
	//DrawLine(640, 0, 640, 720, GetColor(255, 0, 0), TRUE);

	//DrawFormatString(0, 300, GetColor(255, 0, 0), "%d", g_PosY, TRUE);
	DrawFormatString(0, 320, GetColor(255, 0, 0), "%d", g_WaitTime, TRUE);

	//�g�����T�C�g��֌W�Җ��̖��O��\��
	SetFontSize(50);

	//DrawString(575, 350 + g_PosY, "BOOTH", 0xffffff);

	DrawString(535, 350 + g_PosY, "�摜�Ȃ�", 0xffffff);
	DrawString(470, 450 + g_PosY, "PIXELART TOWN", 0xffffff);
	DrawString(560, 550 + g_PosY, "DOTOWN", 0xffffff);
	DrawString(520, 650 + g_PosY, "DOTILLUST", 0xffffff);
	DrawString(530, 750 + g_PosY, "illustAC", 0xffffff);
	DrawString(480, 850 + g_PosY, "UTILITY-LABO", 0xffffff);
	DrawString(480, 950 + g_PosY, "BANNERKOUBOU", 0xffffff);
	DrawString(460, 1050 + g_PosY, "Game-icons.net", 0xffffff);
	DrawString(485, 1150 + g_PosY, "���낢��q��", 0xffffff);
	DrawString(575, 1250 + g_PosY, "BOOTH", 0xffffff);
	DrawString(250, 1350 + g_PosY, "�O���t�B�b�N�f�U�C���Ȃ݂̂Ȃ���", 0xffffff);

	DrawString(500, 1550 + g_PosY, "SE�EBGM�Ȃ�", 0xffffff);	//+ 200
	DrawString(472, 1650 + g_PosY, "DOVA-SYNDROME", 0xffffff);
	DrawString(510, 1750 + g_PosY, "���[�t���J", 0xffffff);
	DrawString(513, 1850 + g_PosY, "���ʉ��H�[", 0xffffff);
	DrawString(513, 1950 + g_PosY, "���ʉ����{", 0xffffff);

	//DrawString(410, 2150 + g_PosY, "�X�y�V�����T���N�X", 0xffffff);		//+ 200
	//DrawString(250, 2250 + g_PosY, "�O���t�B�b�N�f�U�C���Ȃ݂̂Ȃ���", 0xffffff);
}
