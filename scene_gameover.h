#pragma once

#include "DxLib.h"
#include "inputCtrl.h"
#include "scene.h"
#include "scene_result.h"

class GameOverScene : public Scene
{
private:
	// �摜�p�ϐ�
	int img_gameover;
	int img_button_a;			// A�{�^��
	//int img_background;

public:
	GameOverScene();
	~GameOverScene();

	// �X�V
	Scene* update() override;

	// �`��
	void draw() const override;

};

