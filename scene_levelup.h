#pragma once

#include"inputCtrl.h"

#define MAX_LEVEL 7					// ���x���̍ő�l

class weapon;

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
	int interval;
	int initial_cursor_position;	// �����̃J�[�\���ʒu
	int cursor_x;					// �J�[�\��X���W
	int cursor_y;					// �J�[�\��Y���W
	int weapon_number;				// ����ԍ�
	bool weapon_selection;			// ����̑I��
	int level_weapon1;						// ����1�̃��x��
	int level_weapon2;						// ����2�̃��x��

public:
	WeaponLevelUp();
	~WeaponLevelUp();

	// �X�V
	void update(weapon* weapon);

	// �`��
	void draw()const;
};

