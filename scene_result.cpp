#include "scene_result.h"

ResultScene::ResultScene()
{
	img_button_a = LoadGraph("resources/images/button_a.png");
	//img = LoadGraph("resources/images/slime_cat.png");
}

ResultScene::~ResultScene()
{
}

Scene* ResultScene::update()
{
	// �^�C�g���֑J��
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS) {
		//return new Title;
	}

	return this;
}

void ResultScene::draw() const
{
	// �w�i�F
	DrawBox(0, 0, 1280, 720, 0x646464, TRUE);

	// �摜�\��
	DrawGraph(1100, 670, img_button_a, TRUE);

	// �e�L�X�g�\��
	SetFontSize(60);
	DrawFormatString(550, 10, 0xffffff, "RESULT");
	SetFontSize(20);
	DrawFormatString(1150, 680, 0xffffff, "TITLE");

	DrawFormatString(10, 50, 0xffffff, "�k���}�b�v");

	DrawFormatString(700, 200, 0xffffff, "����UI�P");
	DrawFormatString(850, 150, 0xffffff, "���햼�P");
	DrawFormatString(850, 200, 0xffffff, "Lv.              0");
	DrawFormatString(850, 250, 0xffffff, "���_���[�W��      100000");

	DrawFormatString(700, 450, 0xffffff, "����UI�Q");
	DrawFormatString(850, 400, 0xffffff, "���햼�Q");
	DrawFormatString(850, 450, 0xffffff, "Lv.              0");
	DrawFormatString(850, 500, 0xffffff, "���_���[�W��      100000");

#ifdef _DEBUG
	DrawFormatString(0, 0, 0xffffff, "�J�[�\���ʒu: %d - %d", InputCtrl::GetMouseCursor().x, InputCtrl::GetMouseCursor().y);
#endif

}
