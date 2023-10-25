#include "scene_gameclear.h"

GameClearScene::GameClearScene()
{
	img_gameclear = LoadGraph("resources/images/gameclear.png");
	img_button_a = LoadGraph("resources/images/button_a.png");
}

GameClearScene::~GameClearScene()
{

}

Scene* GameClearScene::update()
{
#ifdef _DEBUG
	if (InputCtrl::GetKeyState(KEY_INPUT_SPACE) == PRESS) {
		return new ResultScene;
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
#ifdef _DEBUG
	DrawFormatString(0, 0, 0xffffff, "GameClear");
#endif
	// �摜�\��
	DrawGraph(0, 0, img_gameclear, TRUE);
	DrawGraph(1000, 600, img_button_a, TRUE);

	DrawFormatString(0, 70, 0xffffff, "���U���g");

}
