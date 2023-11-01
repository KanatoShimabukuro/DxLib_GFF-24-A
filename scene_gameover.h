#pragma once

#define _USE_MATH_DEFINES				// <math.h>

// �A�j���[�V����
#define FPS_PERIOD 120					// ����
#define AMPLITUDE 40					// �U��

#include <math.h>
#include "DxLib.h"
#include "inputCtrl.h"
#include "scene.h"
#include "scene_result.h"

class GameOverScene : public Scene
{
private:
	// �摜�p�ϐ�
	int img_gameover;
	int img_ghost;
	int img_button_a;
	//int img_background;

	// ���W�ړ�
	int ghost_x;
	int ghost_y;
	int count;

	// �t�F�[�h���o
	int value;

public:
	GameOverScene();
	~GameOverScene();

	// �X�V
	Scene* update() override;

	// �`��
	void draw() const override;

};

