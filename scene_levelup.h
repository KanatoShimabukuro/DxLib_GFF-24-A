#pragma once

#include"inputCtrl.h"

class WeaponLevelUp
{
private:
	// �摜�p�ϐ�
	//int img_weapon1;				// ����P
	//int img_weapon2;				// ����Q
	//int img_tree_diagram;			// ���`�}
	//int img_cursor;					// �J�[�\��
	//int img_background;			// �w�i

	int test;
	int initial_cursor_position;	// �����̃J�[�\���ʒu

public:
	WeaponLevelUp();
	~WeaponLevelUp();

	// �X�V
	void update();

	// �`��
	void draw()const;
};

