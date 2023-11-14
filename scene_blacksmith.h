#pragma once

class weapon;
class second_weapon;
class WeaponLevelUp;

class Blacksmith
{
private:
	enum ActionNum
	{
		levelup,
		reset_level
	};

	// �摜�Ǎ��p�ϐ�
	//int img_tree_diagram;			// ���`�}
	int img_cursor;					// �J�[�\��
	//int img_branch_point;			// ���x������_
	//int img_chooce;					// ���x���I���ʒu
	//int img_background;			// �w�i

	int img_hammer;					// �n���}�[
	int img_spark;					// �Ή�
	int img_question_mark;			// �͂Ăȃ}�[�N
	int img_exclamation_mark;		// �r�b�N���}�[�N
	int img_arrow;					// ���

	// ����摜�Ǎ��p�ϐ�
	int img_sword;					// �Ў茕
	int img_dagger;					// �Z��
	int img_great_sword;			// �匕
	int img_spear;					// ��
	int img_frail;					// �t���C�A
	int img_book;					// �{

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
	bool is_blacksmith;				// �b��ŌĂяo����Ă��邩

	// �摜�p�����[�^
	int img_x;						// �摜��X���W
	int img_y;						// �摜��Y���W
	int img_branch_point_x;			// ���`�}�̋N�_X���W
	int img_branch_point_y;			// ���`�}�̋N�_Y���W
	int branch_point_x[2][5];		// �I����������_��X���W���i�[
	int branch_point_y[2][5];		// �I����������_��Y���W���i�[
	bool is_chooce[2][5];			// �ǂ̃��x���K�w�܂őI��������

	bool action_selection;			// �s���̑I��
	int action_number;
	bool restore_cursor_position;

public:
	Blacksmith();
	~Blacksmith();

	// �X�V
	void update(weapon* weapon, second_weapon* second_weapon, WeaponLevelUp* weapon_levelup);

	// �`��
	void draw(WeaponLevelUp* weapon_levelup)const;
};