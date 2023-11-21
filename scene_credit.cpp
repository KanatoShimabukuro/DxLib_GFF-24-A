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
	if (++g_WaitTime < 1500)g_PosY = 600 - g_WaitTime;
	if (++g_WaitTime > 900) {
		return new Title;
	}
	return this;
}

void Credit::draw()const
{
	//�N���W�b�g�摜�̕\��
	DrawExtendGraph(0, 0,1280,720, CreditImage, TRUE);
	//�g�����T�C�g��֌W�Җ��̖��O��\��
	SetFontSize(40);
	DrawString(100, 350+g_PosY, "pngtree", 0x000000);
	DrawString(100, 390+g_PosY, "�O���t�B�b�N�f�U�C���Ȃ̕��X", 0x000000);
	DrawString(100, 430+g_PosY, "�`�R�f�U", 0x000000);
	DrawString(100, 470+g_PosY, "�c�J�b�e", 0x000000);
	DrawString(100, 510+g_PosY, "BOOTH", 0x000000);
	DrawString(100, 550+g_PosY, "�C���f�B�[8�r�b�g", 0x000000);
	DrawString(100, 590+g_PosY, "AKKODiS", 0x000000);
	DrawString(100, 630+g_PosY, "romptnAI", 0x000000);
	DrawString(100, 670+g_PosY, "ITOTM", 0x000000);
	DrawString(100, 710+g_PosY, "���낭�܂��ӂ�", 0x000000);
	DrawString(100, 750+g_PosY, "note_lilish", 0x000000);
	DrawString(100, 790+g_PosY, "A.I. Art Stock", 0x000000);
	DrawString(100, 830+g_PosY, "�h�b�^�E��", 0x000000);
	DrawString(100, 870+g_PosY, "�s�N�Z���A�[�g�^�E��", 0x000000);
}
