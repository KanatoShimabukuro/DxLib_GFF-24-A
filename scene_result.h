#pragma once

#include "inputCtrl.h"
#include "scene.h"
#include "scene_title.h"

class ResultScene : public Scene
{
private:
	// �摜�p�ϐ�
	//int img_map;					// �}�b�v
	//int img_branchPoint;			// ����_
	//int img_weapon1;				// ����P
	//int img_weapon2;				// ����Q
	//int img_background;			// �w�i
	int img_button_a;				// A�{�^��

	// �t�F�[�h���o
	int value;						// �s�����x

public:
	ResultScene();
	~ResultScene();

	// �X�V
	Scene* update() override;

	// �`��
	void draw() const override;

};

