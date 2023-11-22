#pragma once

class weapon;
class second_weapon;
class WeaponLevelUp;
class Player;

class Blacksmith
{
private:
	enum FirstAction
	{
		levelup,
		reset_level
	};

	enum ActionState
	{
		state_first,
		state_weapon,
		//state_reset
	};

	// �摜�Ǎ��p�ϐ�
	int img_cursor;					// �J�[�\��
	int img_chooce;					// ���x���I���ʒu
	int img_hammer;					// �n���}�[
	int img_spark;					// �Ή�
	int img_exclamation_mark;		// �r�b�N���}�[�N
	int img_arrow;					// ���
	int img_question_mark;			// �͂Ăȃ}�[�N�i���햳���̏ꍇ�j
	int img_button_b;				// B�{�^��
	int img_background;			// �w�i

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
		bool can_reset;				// ���x�����Z�b�g�ł��邩
	};

	weapon_information weapon1_info;		// ����1
	weapon_information weapon2_info;		// ����2

	int interval;					// �C���^�[�o��
	int cursor_x;					// �J�[�\��X���W
	int cursor_y;					// �J�[�\��Y���W
	int weapon_number;				// ����ԍ�
	bool is_blacksmith;				// �b��ŌĂяo����Ă��邩�i���x���A�b�v��ʂɓn�����́j

	// �摜�p�����[�^
	int img_x;						// �摜��X���W
	int img_y;						// �摜��Y���W

	bool action_selection;			// �s���̑I��
	int action_number;				// �I�������s���̔ԍ��i�[�p
	bool restore_cursor_position;	// �J�[�\���ʒu��߂���
	int cursor_action;				// ���̍s���i�J�[�\���ړ��Ŏg�p�j

public:
	Blacksmith();
	~Blacksmith();

	// �X�V
	void update(weapon* weapon, second_weapon* second_weapon, WeaponLevelUp* weapon_levelup, Player* player);

	// �`��
	void draw(WeaponLevelUp* weapon_levelup)const;

private:
	// �����ݒ�
	void Init(weapon* weapon, second_weapon* second_weapon, WeaponLevelUp* weapon_levelup);

	// �J�[�\���ړ�����
	void CursorMove();

	// ���x�����Z�b�g�֐�
	void ResetLevel(weapon* weapon, second_weapon* second_weapon, WeaponLevelUp* weapon_levelup, weapon_information* info);

	// �s���I�����̕`��
	void FirstDraw(WeaponLevelUp* weapon_levelup)const;

	// ���x�����Z�b�g��ʕ`��
	void DrawResetLevel(WeaponLevelUp* weapon_levelup)const;

	// ����̉摜�`��
	void DrawWeaponImages()const;

	// ���x�����Z�b�g���̃e�L�X�g
	void DrawResetLevelText()const;
};