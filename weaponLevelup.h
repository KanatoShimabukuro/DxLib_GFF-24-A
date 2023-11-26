#pragma once

#include"inputCtrl.h"

//#define MAX_LEVEL					8		// ���x���̍ő�l
#define MAX_LEVEL_HIERARCHY			4		// ���x���K�w�̍ő�l
#define LEVEL_HIERARCHY_HEIGHT		90		// 1�K�w�̍���

class weapon;								// �ŏ��̕���
class second_weapon;						// ��ڂ̕���
class Player;								// �v���C���[

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
		int tmp_level;			// �J�[�\���������Ă��郌�x��
	};

	weapon_information weapon1_info;		// ����1
	weapon_information weapon2_info;		// ����2

	int interval;					// �C���^�[�o��
	int cursor_x;					// �J�[�\��X���W
	int cursor_y;					// �J�[�\��Y���W
	int level_cursor_pos;			// ���x���A�b�v���J�[�\���\���ʒu
	int lv_point;						// ���x���A�b�v�p�|�C���g
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

	// �v���C���[���i�[�p�iweapon����j
	int w_p_speed;					// ���x
	int w_p_avoidancecooltime;		// ����̃N�[���^�C��
	int w_p_upperlimitlimit;		// ��𑬓x

	// �v���C���[���i�[�p�iplayer����j
	float p_speed;					// ���x
	int p_avoidancecooltime;		// ����̃N�[���^�C��
	float p_upperlimitlimit;		// ��𑬓x

	bool close;						// ��ʂ���邩

	// �e�X�g
	FILE* fp;
	struct Sample
	{
		int type;
		int level;
		int damage;
	};
	struct Sample sample[2];

public:
	WeaponLevelUp();
	~WeaponLevelUp();

	// �X�V
	void update(weapon* weapon, second_weapon* second_weapon, Player* player, bool& restor_cursor_position, int& point);

	// �`��
	void draw()const;

	// ����������
	void Init(weapon* weapon, second_weapon* second_weapon, bool& restor_cursor_position);

private:

	// ���x���A�b�v����
	void LevelUp(weapon* weapon, second_weapon* second_weapon, weapon_information* info, int& point);

	// ���x���A�b�v�̃J�[�\���ړ�
	void LevelUpCursorMove(weapon_information* info);

	// ���x���A�b�v�J�[�\���̈ʒu��߂�
	void ReturnLevelUpCursorPos(weapon_information* info);

	// ���x���A�b�v�ڍׂ̃e�L�X�g�Q
	void DrawLevelUpDetails()const;

	// ����1�ŏI�����̃e�L�X�g�Q
	void DrawWeapon1FinalText()const;

	// ����2�ŏI�����̃e�L�X�g�Q
	void DrawWeapon2FinalText()const;

public:
	// �b��ŕԋp���ꂽ�|�C���g�̐ݒ�
	void SetLevelUpPoint(int& point, int return_point)
	{
		point += return_point;
	}

	// ���ݏ������Ă���|�C���g�̎擾
	int GetLevelUpPoint(int& point) { return point; }

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


	// ����1�̃��x�����Z�b�g
	void Weapon1LevelInit();

	// ����2�̃��x�����Z�b�g
	void Weapon2LevelInit();

	bool GetClose() { return close; }

};