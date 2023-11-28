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

	// ����摜�Ǎ��p�ϐ�
	int img_sword;					// �Ў茕
	int img_dagger;					// �Z��
	int img_great_sword;			//�匕
	int img_question_mark;			// �͂Ăȃ}�[�N�i���햳���̏ꍇ�j

	// �t�F�[�h���o
	int value;						// �s�����x

	// �e�X�g
	FILE* fp;
	struct Sample
	{
		int type;
		int level;
		int damage;
	};
	struct Sample sample[2];
	bool is_fopen;

public:
	ResultScene();
	~ResultScene();

	// �X�V
	Scene* update() override;

	// �`��
	void draw() const override;

};

