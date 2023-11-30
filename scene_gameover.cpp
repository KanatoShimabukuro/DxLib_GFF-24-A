#include "main.h"

// ���U���g�Ŏg�p�\��
class weapon;								// �ŏ��̕���
class second_weapon;						// ��ڂ̕���

GameOverScene::GameOverScene(weapon* weapon1, second_weapon* weapon2)
{
	//weapon1 = new weapon();
	//weapon2 = new second_weapon();
	num1 = weapon1->GetWeaponType();
	num2 = weapon2->GetWeaponType();

	// �摜�Ǎ�
	img_gameover = LoadGraph("resources/images/gameover.png");
	img_ghost = LoadGraph("resources/images/ghost.png");
	img_button_a = LoadGraph("resources/images/button_a01.png");

	// �ϐ��̏�����
	ghost_x = 750;
	ghost_y = 150;
	count = 0;

	value = 180;
}

GameOverScene::~GameOverScene()
{
	//delete weapon1;
	//delete weapon2;
}

Scene* GameOverScene::update()
{
	// �X�y�[�X�L�[�ŃQ�[���N���A��ʂ�
	if (InputCtrl::GetKeyState(KEY_INPUT_SPACE) == PRESS) {
		return new GameClearScene;
	}

	// �u�����h���[�h�̃p�����[�^
	if (value > 0)
	{
		value--;
	}
	else
	{
		value = 0;
	}

	if (count < FPS_PERIOD)
	{
		count++;
	}
	else
	{
		count = 0;
	}

	// ���U���g�֑J��
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS) {
		return new ResultScene(num1,num2);
	}

	return this;
}

void GameOverScene::draw() const
{
	// �w�i�F
	DrawBox(0, 0, 1280, 720, 0xa0a0a0, TRUE);

	// �摜�\��
	DrawGraph(0, 0, img_gameover, TRUE);
	// sin( PI*2 / ���� * Count ) * �U��
	DrawGraph(ghost_x, ghost_y + sinf(M_PI * 2 / FPS_PERIOD * count) * 40, img_ghost, TRUE);
	DrawRotaGraph(1150, 690, 0.2f, 0.0f, img_button_a, TRUE);

	// �e�L�X�g�\��
	SetFontSize(60);
	DrawFormatString(545, 515, 0x000000, "GAME OVER");
	SetFontSize(20);
	DrawFormatString(1175, 680, 0x000000, "RESULT");

	//�t�F�[�h�̐ݒ�
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, value);

	//���œh��Ԃ�
	DrawBox(0, 0, 1280, 720, 0x000000, TRUE);

	//�f�t�H���g�ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
