#pragma once

#include "DxLib.h"
#include "inputCtrl.h"
#include "scene.h"

class ResultScene : public Scene
{
private:

	// �摜�p�ϐ�
	//int img_map;
	//int img_branchPoint;
	//int img_weapon1;
	//int img_weapon2;
	//int img_background;
	int img_button_a;

public:
	ResultScene();
	~ResultScene();

	// �X�V
	Scene* update() override;

	// �`��
	void draw() const override;

};

