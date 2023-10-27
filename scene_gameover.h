#pragma once

#define _USE_MATH_DEFINES				// <math.h>

// �A�j���[�V����
#define FPS_PERIOD 120					// ����
#define AMPLITUDE 40					// �U��

#include <math.h>
#include "inputCtrl.h"
#include "scene.h"
#include "scene_result.h"

class GameOverScene : public Scene
{
private:
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
	GameOverScene();
	~GameOverScene();

	// �X�V
	Scene* update() override;

	// �`��
	void draw() const override;

};

