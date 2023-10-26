#include "scene_gameclear.h"
#include "scene_gameover.h"			// ��

GameClearScene::GameClearScene()
{
	// �摜�Ǎ�
	img_gameclear = LoadGraph("resources/images/gameclear.png");
	img_button_a = LoadGraph("resources/images/button_a.png");
}

GameClearScene::~GameClearScene()
{

}

Scene* GameClearScene::update()
{
#ifdef _DEBUG
	// �X�y�[�X�L�[�ŃQ�[���I�[�o�[��ʂ�
	if (InputCtrl::GetKeyState(KEY_INPUT_SPACE) == PRESS) {
		return new GameOverScene;
	}
#endif

	// ���U���g�֑J��
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS) {
		return new ResultScene;
	}

	return this;
}

void GameClearScene::draw() const
{
	// �w�i�F
	//DrawBox(0, 0, 1280, 720, 0xFFFFB5, TRUE);

	// �摜�\��
	DrawGraph(0, 0, img_gameclear, TRUE);
	DrawGraph(1100, 670, img_button_a, TRUE);

	// �e�L�X�g�\��
	SetFontSize(60);
	DrawFormatString(545, 515, 0xffffff, "GAME CLEAR");
	SetFontSize(20);
	DrawFormatString(1150, 680, 0xffffff, "RESULT");

#ifdef _DEBUG
	DrawFormatString(0, 0, 0xffffff, "�J�[�\���ʒu: %d - %d", InputCtrl::GetMouseCursor().x, InputCtrl::GetMouseCursor().y);
#endif
}
