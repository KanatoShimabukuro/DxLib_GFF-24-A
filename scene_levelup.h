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
	int img_question_mark;			// �͂Ăȃ}�[�N�i���햳���̏ꍇ�j

	// ����̏��
	struct weapon_information
	{
		int num;
		int type;					// ����̎��
		int level;					// ����̃��x��
		int cursor_pos;				// ����̃��x���A�b�v���J�[�\���\���ʒu
		int level_hierarchy;		// ����̃��x���̊K�w
	};

	weapon_information weapon1_info;		// ����1
	weapon_information weapon2_info;		// ����2

	int interval;					// �C���^�[�o��
	int cursor_x;					// �J�[�\��X���W
	int cursor_y;					// �J�[�\��Y���W
	int level_cursor_pos;			// ���x���A�b�v���J�[�\���\���ʒu
	int point;						// ���x���A�b�v�p�|�C���g
	int weapon_number;				// ����ԍ�
	bool weapon_selection;			// ����̑I��

	// �b��Ƃ̂����
	bool is_blacksmith;				// �b��ŌĂяo����Ă��邩
	bool is_close_level_up;			// �b��Ń��x���A�b�v��ʂ���Ă��ǂ���

	// �摜�p�����[�^
	int img_x;						// �摜��X���W
	int img_y;						// �摜��Y���W
	int img_branch_point_x;			// ���`�}�̋N�_X���W
	int img_branch_point_y;			// ���`�}�̋N�_Y���W
	int branch_point_x[2][5];		// �I����������_��X���W���i�[
	int branch_point_y[2][5];		// �I����������_��Y���W���i�[
	bool is_chooce[2][5];			// �ǂ̃��x���K�w�܂őI��������

public:
	WeaponLevelUp();
	~WeaponLevelUp();

	// �X�V
	void update(weapon* weapon, second_weapon* second_weapon, bool& restor_cursor_position);

	// �`��
	void draw()const;

private:
	// ����������
	void Init(weapon* weapon, second_weapon* second_weapon, bool& restor_cursor_position);

	// ���x���A�b�v����
	void LevelUp(weapon* weapon, second_weapon* second_weapon, weapon_information* info);

	// ���x���A�b�v�̃J�[�\���ړ�
	void LevelUpCursorMove(weapon_information* info);

	// ���x���A�b�v�J�[�\���̈ʒu��߂�
	void ReturnLevelUpCursorPos(weapon_information* info);

	// ���x���A�b�v�ڍׂ̃e�L�X�g�Q
	void DrawLevelUpDetails()const;

public:
	/***********************
	**	Set�֐��AGet�֐�
	***********************/

	// �b��ŕԋp���ꂽ�|�C���g�̐ݒ�
	void SetLevelUpPoint(int return_point)
	{
		point += return_point;
	}

	// ���ݏ������Ă���|�C���g�̎擾
	int GetLevelUpPoint() { return point; }

	// �b��Ŏg�����
	void SetIsBlacksmith(bool set_bool)
	{
		is_blacksmith = set_bool;
	}

	bool GetIsCloseLevelUp()const
	{ 
		return is_close_level_up;
	}

	// ���x���K�w�̎擾
	int GetWeapon1LevelHierarchy() { return weapon1_info.level_hierarchy; }
	int GetWeapon2LevelHierarchy() { return weapon2_info.level_hierarchy; }

	void SetWeapon1LevelHierarchy()
	{
		weapon1_info.level_hierarchy = 0;
	}

	void SetWeapon2LevelHierarchy()
	{
		weapon2_info.level_hierarchy = 0;
	}

	void SetWeapon1LevelDisplay()
	{
		for (int i = 0; i <= MAX_LEVEL_HIERARCHY; i++)
		{
			is_chooce[0][i] = false;
		}
	}

	void SetWeapon2LevelDisplay()
	{
		for (int i = 0; i <= MAX_LEVEL_HIERARCHY; i++)
		{
			is_chooce[1][i] = false;
		}
	}

};