#pragma once

// �A�j���[�V����
#define FPS_PERIOD 120					// ����
#define AMPLITUDE 40					// �U��

#include "scene.h"

// ���U���g�Ŏg�p�\��
class weapon;								// �ŏ��̕���
class second_weapon;						// ��ڂ̕���

class GameOverScene : public Scene
{
private:
	// ���U���g�Ŏg�p�\��
	int num1;
	int num2;

	// �摜�p�ϐ�
	int img_gameover;					// �Q�[���I�[�o�[�i�����j
	int img_ghost;						// �S�[�X�g
	int img_button_a;					// A�{�^��
	//int img_background;				// �w�i

	// ���W�ړ�
	int ghost_x;
	int ghost_y;
	int count;

	// �t�F�[�h���o
	int value;							// �s�����x

public:
	GameOverScene(weapon* weapon1, second_weapon* weapon2);
	~GameOverScene();

	// �X�V
	Scene* update() override;

	// �`��
	void draw() const override;

};

