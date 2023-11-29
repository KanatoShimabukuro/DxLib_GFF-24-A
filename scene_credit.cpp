#include "main.h"

Credit::Credit()
{
	//�N���W�b�g�摜�̓Ǎ�
	CreditImage = LoadGraph("resources/images/background.png");
	//���Ԃ̏�����
	g_WaitTime = 0;
}

Credit::~Credit()
{

}

Scene* Credit::update()
{
	//�N���W�b�g���[������
	//���Ԃ����Ă΃^�C�g���֑J��
	if (++g_WaitTime < 1800)g_PosY = 600 - g_WaitTime;
	if (++g_WaitTime > 1200) {
		return new Title;
	}
	return this;
}

void Credit::draw()const
{
	//�N���W�b�g�摜�̕\��
	DrawExtendGraph(0, 0,1280,720, CreditImage, TRUE);
	//�g�����T�C�g��֌W�Җ��̖��O��\��
	SetFontSize(50);
	DrawString(550, 350+g_PosY, "pngtree", 0x000000);
	DrawString(300, 410+g_PosY, "�O���t�B�b�N�f�U�C���Ȃ̕��X", 0x000000);
	DrawString(550, 470+g_PosY, "�`�R�f�U", 0x000000);
	DrawString(550, 530+g_PosY, "�c�J�b�e", 0x000000);
	DrawString(560, 590+g_PosY, "BOOTH", 0x000000);
	DrawString(400, 650+g_PosY, "�C���f�B�[8�r�b�g", 0x000000);
	DrawString(560, 710+g_PosY, "AKKODiS", 0x000000);
	DrawString(560, 770+g_PosY, "romptnAI", 0x000000);
	DrawString(570, 830+g_PosY, "ITOTM", 0x000000);
	DrawString(500, 890+g_PosY, "���낭�܂��ӂ�", 0x000000);
	DrawString(565, 950+g_PosY, "note_lilish", 0x000000);
	DrawString(455, 1010+g_PosY, "A.I. Art Stock", 0x000000);
	DrawString(550, 1070+g_PosY, "�h�b�^�E��", 0x000000);
	DrawString(350, 1130+g_PosY, "�s�N�Z���A�[�g�^�E��", 0x000000);
}
