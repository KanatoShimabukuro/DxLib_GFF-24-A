#pragma once

// �A�j���[�V����
#define FPS_PERIOD 120					// ����
#define AMPLITUDE 40					// �U��

#include "scene.h"

// ���U���g�Ŏg�p�\��
class weapon;								// �ŏ��̕���
class second_weapon;						// ��ڂ̕���
class Map;									// �}�b�v

class GameOverScene : public Scene
{
private:
	// �摜�p�ϐ�
	int img_gameover;					// �Q�[���I�[�o�[�i�����j
	int img_ghost;						// �S�[�X�g
	int img_button_a;					// A�{�^��
	int img_background;				// �w�i
	int img_logo_result;

	// ���W�ړ�
	int ghost_x;
	int ghost_y;
	int count;

	// �t�F�[�h���o
	int value;						// �s�����x

	int result_info[11];			// ���U���g��ʂɓn��������A�}�b�v���

public:
	GameOverScene(weapon* weapon1, second_weapon* weapon2, Map* map);
	~GameOverScene();

	// �X�V
	Scene* update() override;

	// �`��
	void draw() const override;
};