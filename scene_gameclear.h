#pragma once

#include "inputCtrl.h"
#include "scene.h"
#include "scene_result.h"

class GameClearScene : public Scene
{
private:
	// �摜�p�ϐ�
	int img_gameclear;					// �Q�[���N���A�i�����j
	int img_button_a;					// A�{�^��
	//int img_background;				// �w�i

public:
	GameClearScene();
	~GameClearScene();

	// �X�V
	Scene* update() override;

	// �`��
	void draw() const override;

};
