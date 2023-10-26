#pragma once

#include "DxLib.h"
#include "inputCtrl.h"
#include "scene.h"
#include "scene_result.h"

class GameClearScene : public Scene {
private:
	// �摜�p�ϐ�
	int img_gameclear;
	int img_button_a;
	//int img_background;

public:
	GameClearScene();
	~GameClearScene();

	// �X�V
	Scene* update() override;

	// �`��
	void draw() const override;

};
