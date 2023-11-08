#pragma once

#include"inputCtrl.h"

//#define MAX_LEVEL					8		// ���x���̍ő�l
#define MAX_LEVEL_HIERARCHY			4		// ���x���K�w�̍ő�l
#define LEVEL_HIERARCHY_HEIGHT		90		// 1�K�w�̍���

class weapon;
class second_weapon;

class WeaponLevelUp
{
private:
	enum WeaponNum
	{
		weapon1,
		weapon2
	};

	// �摜�Ǎ��p�ϐ�
	//int img_tree_diagram;			// ���`�}
	int img_cursor;					// �J�[�\��
	int img_branch_point;			// ���x������_
	int img_chooce;					// ���x���I���ʒu
	//int img_background;			// �w�i

	// ����摜�Ǎ��p�ϐ�
	int img_sword;					// �Ў茕
	int img_dagger;					// �Z��
	int img_great_sword;			// �匕
	int img_spear;					// ��
	int img_frail;					// �t���C�A
	int img_book;					// �{

	int interval;					// �C���^�[�o��
	int cursor_x;					// �J�[�\��X���W
	int cursor_y;					// �J�[�\��Y���W
	int level_cursor_pos;			// ���x���A�b�v���J�[�\���\���ʒu
	int point;						// ���x���A�b�v�p�|�C���g
	int weapon_number;				// ����ԍ�
	bool weapon_selection;			// ����̑I��

	// �摜�p�����[�^
	int img_x;						// �摜��X���W
	int img_y;						// �摜��Y���W
	int img_branch_point_x;			// ���`�}�̋N�_X���W
	int img_branch_point_y;			// ���`�}�̋N�_Y���W
	int branch_point_x[2][5];		// �I����������_��X���W���i�[
	int branch_point_y[2][5];		// �I����������_��Y���W���i�[
	bool is_chooce[2][5];			// �ǂ̃��x���K�w�܂őI��������

	// ����1
	int weapon1_type;				// ����1�̎��
	int weapon1_level;				// ����1�̃��x��
	int weapon1_cursor_pos;			// ����1�̃��x���A�b�v���J�[�\���\���ʒu
	int weapon1_level_hierarchy;	// ����1�̃��x���̊K�w

	// ����2
	int weapon2_type;				// ����2�̎��
	int weapon2_level;				// ����2�̃��x��
	int weapon2_cursor_pos;			// ����2�̃��x���A�b�v���J�[�\���\���ʒu
	int weapon2_level_hierarchy;	// ����2�̃��x���̊K�w

public:
	WeaponLevelUp();
	~WeaponLevelUp();

	// �X�V
	void update(weapon* weapon, second_weapon* second_weapon, bool& restor_cursor_position);

	// �`��
	void draw()const;

	// ���x���A�b�v�ڍׂ̃e�L�X�g�Q
	void DrawLevelUpDetails()const;
};