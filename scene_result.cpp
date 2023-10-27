#include "scene_result.h"

ResultScene::ResultScene()
{
	// �摜�Ǎ�
	img_button_a = LoadGraph("resources/images/button_a.png");

	// �ϐ��̏�����
	value = 180;
}

ResultScene::~ResultScene()
{

}

Scene* ResultScene::update()
{
	// �u�����h���[�h�̃p�����[�^
	if (value > 0)
	{
		value--;
	}
	else
	{
		value = 0;
	}

	// �^�C�g���֑J��
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
	{
		return new Title;
	}

	return this;
}

void ResultScene::draw() const
{
	// �w�i�F
	DrawBox(0, 0, 1280, 720, 0xa0a0a0, TRUE);

	// �摜�\��
	DrawGraph(1100, 670, img_button_a, TRUE);

	// �e�L�X�g�\��
	SetFontSize(60);
	DrawFormatString(550, 10, 0x000000, "RESULT");
	SetFontSize(20);
	DrawFormatString(1150, 680, 0x000000, "TITLE");

	DrawFormatString(10, 50, 0x000000, "�k���}�b�v");

	DrawFormatString(700, 200, 0x000000, "����UI�P");
	DrawFormatString(850, 150, 0x000000, "���햼�P");
	DrawFormatString(850, 200, 0x000000, "Lv.              0");
	DrawFormatString(850, 250, 0x000000, "���_���[�W��      100000");

	DrawFormatString(700, 450, 0x000000, "����UI�Q");
	DrawFormatString(850, 400, 0x000000, "���햼�Q");
	DrawFormatString(850, 450, 0x000000, "Lv.              0");
	DrawFormatString(850, 500, 0x000000, "���_���[�W��      100000");

	//�t�F�[�h�̐ݒ�
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, value);

	//���œh��Ԃ�
	DrawBox(0, 0, 1280, 720, 0x000000, TRUE);

	//�f�t�H���g�ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


#ifdef _DEBUG
	DrawFormatString(0, 0, 0xffffff, "�J�[�\���ʒu: %d - %d", InputCtrl::GetMouseCursor().x, InputCtrl::GetMouseCursor().y);
#endif

}
