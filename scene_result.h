#pragma once

#include "inputCtrl.h"
#include "scene.h"
#include "scene_title.h"

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

	// �t�F�[�h���o
	int value;

public:
	ResultScene();
	~ResultScene();

	// �X�V
	Scene* update() override;

	// �`��
	void draw() const override;

};

