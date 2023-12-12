#include "main.h"

Credit::Credit()
{
	//�N���W�b�g�摜�̓Ǎ�
	CreditImage = LoadGraph("resources/images/Title/Title_background_tree.png");
	//���Ԃ̏�����
	g_WaitTime = 0;

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

	if (++g_WaitTime < /*2370*/  2700) {

		g_PosY = /*600*/ 450 - g_WaitTime;
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

	//DrawFormatString(0, 300, GetColor(255, 0, 0), "%d", g_WaitTime, TRUE);

	//�g�����T�C�g��֌W�Җ��̖��O��\��
	SetFontSize(50);

	//DrawString(485, 350 + g_PosY, "���낢��q��", 0xffffff);

	DrawString(460, 350 + g_PosY, "�g�p�����T�C�g", 0xffffff);
	DrawString(535, 450 + g_PosY, "�摜�Ȃ�", 0xffffff);
	DrawString(470, 550 + g_PosY, "PIXELART TOWN", 0xffffff);
	DrawString(560, 650 + g_PosY, "DOTOWN", 0xffffff);
	DrawString(520, 750 + g_PosY, "DOTILLUST", 0xffffff);
	DrawString(530, 850 + g_PosY, "illustAC", 0xffffff);
	DrawString(480, 950 + g_PosY, "UTILITY-LABO", 0xffffff);
	DrawString(480, 1050 + g_PosY, "BANNERKOUBOU", 0xffffff);
	DrawString(460, 1150 + g_PosY, "Game-icons.net", 0xffffff);
	DrawString(485, 1250 + g_PosY, "���낢��q��", 0xffffff);

	DrawString(500, 1450 + g_PosY, "SE�EBGM�Ȃ�", 0xffffff);	//+ 200
	DrawString(472, 1550 + g_PosY, "DOVA-SYNDROME", 0xffffff);
	DrawString(510, 1650 + g_PosY, "���[�t���J", 0xffffff);
	DrawString(513, 1750 + g_PosY, "���ʉ��H�[", 0xffffff);
	DrawString(513, 1850 + g_PosY, "���ʉ����{", 0xffffff);

	DrawString(410, 2050 + g_PosY, "�X�y�V�����T���N�X", 0xffffff);		//+ 200
	DrawString(270, 2150 + g_PosY, "�O���t�B�b�N�f�U�C���Ȃ̕��X", 0xffffff);

	//DrawString(200, 350+g_PosY, "pngtree", 0xffffff);
	//DrawString(200, 470+g_PosY, "�`�R�f�U", 0xffffff);
	//DrawString(200, 530+g_PosY, "�c�J�b�e", 0xffffff);
	//DrawString(200, 590+g_PosY, "BOOTH", 0xffffff);
	//DrawString(200, 650+g_PosY, "�C���f�B�[8�r�b�g", 0xffffff);
	//DrawString(200, 710+g_PosY, "AKKODiS", 0xffffff);
	//DrawString(200, 770+g_PosY, "romptnAI", 0xffffff);
	//DrawString(200, 830+g_PosY, "ITOTM", 0xffffff);
	//DrawString(200, 890+g_PosY, "���낭�܂��ӂ�", 0xffffff);
	//DrawString(200, 950+g_PosY, "note_lilish", 0xffffff);
	//DrawString(200, 1010+g_PosY, "A.I. Art Stock", 0xffffff);
	//DrawString(200, 1070+g_PosY, "�h�b�^�E��", 0xffffff);
	//DrawString(200, 1130+g_PosY, "�s�N�Z���A�[�g�^�E��", 0xffffff);
}
