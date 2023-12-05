#include "main.h"

GameClearScene::GameClearScene(weapon* weapon1, second_weapon* weapon2, Map* map)
{
	// �摜�Ǎ�
	img_gameclear = LoadGraph("resources/images/gameclear.png");
	img_player = LoadGraph("resources/images/player_images/Player_right50�E50.png");
	img_button_a = LoadGraph("resources/images/button_a01.png");
	img_background = LoadGraph("resources/images/stageimage2.png");

	value = 180;

	// ����1���
	result_info[0] = weapon1->GetWeaponType();
	result_info[1] = weapon1->GetWeaponLevel();
	result_info[2] = weapon1->GetTotalDamage();

	// ����2���
	result_info[3] = weapon2->GetWeaponType();
	result_info[4] = weapon2->GetWeaponLevel();
	result_info[5] = weapon2->GetTotalDamage();

	// �}�b�v���
	result_info[6] = map->GetBattleCount();
	result_info[7] = map->GetEventCount();
	result_info[8] = map->GetRestCount();
	result_info[9] = map->GetAnvilCount();
	result_info[10] = map->GetBossCount();

	SoundManager::SetBGM("bgm_gameclear");
	SoundManager::SetVolumeBGM("bgm_gameclear", 50);
}

GameClearScene::~GameClearScene()
{

}

Scene* GameClearScene::update()
{
	SoundManager::PlaySoundBGM("bgm_gameclear");

	// �u�����h���[�h�̃p�����[�^
	if (value > 0)
	{
		value--;
	}
	else
	{
		value = 0;
	}

	// �X�y�[�X�L�[�ŃQ�[���I�[�o�[��ʂ�
	if (InputCtrl::GetKeyState(KEY_INPUT_SPACE) == PRESS) {
		//return new GameOverScene();
	}

	// ���U���g�֑J��
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS) {
		return new ResultScene(result_info);
	}

	return this;
}

void GameClearScene::draw() const
{
	// �w�i�F
	DrawBox(0, 0, 1280, 720, 0x68030c, TRUE);
	//DrawGraph(0, 0, img_background, TRUE);

	// �摜�\��
	DrawGraph(0, 0, img_gameclear, TRUE);
	DrawRotaGraph(1150, 690, 0.2f, 0.0f, img_button_a, TRUE);
	DrawRotaGraph(650, 350, 3.0, 0.0f, img_player, TRUE);

	// �e�L�X�g�\��
	SetFontSize(60);
	DrawFormatString(545, 515, 0xffffff, "GAME CLEAR");
	SetFontSize(20);
	DrawFormatString(1175, 680, 0xffffff, "RESULT");

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
