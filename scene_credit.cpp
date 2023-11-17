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
}
