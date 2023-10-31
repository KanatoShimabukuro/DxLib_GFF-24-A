#pragma once

#include"inputCtrl.h"

#define MAX_LEVEL 7					// ���x���̍ő�l
#define NONE 99						// ��

class weapon;

class WeaponLevelUp
{
private:
	// �摜�p�ϐ�
	//int img_tree_diagram;			// ���`�}
	//int img_cursor;					// �J�[�\��
	//int img_background;			// �w�i
	int img_sword;					// �Ў茕
	int img_dagger;					// �Z��
	int img_great_sword;			// �匕


	int interval;					// �C���^�[�o��
	int cursor_x;					// �J�[�\��X���W
	int cursor_y;					// �J�[�\��Y���W
	int weapon_number;				// ����ԍ�
	bool weapon_selection;			// ����̑I��

	// ����1
	int weapon1_type;				// ����1�̎��
	int weapon1_level;				// ����1�̃��x��

	// ����2
	int weapon2_type;				// ����2�̎��
	int weapon2_level;				// ����2�̃��x��

public:
	WeaponLevelUp();
	~WeaponLevelUp();

	// �X�V
	void update(weapon* weapon, bool& restor_cursor_position);

	// �`��
	void draw()const;
};

