#pragma once

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
	int img_tree_diagram;			// ���`�}
	int img_cursor;					// �J�[�\��
	int img_branch_point;			// ���x������_
	int img_chooce;					// ���x���I���ʒu
	int img_button_a;				// A�{�^��
	int img_button_b;				// B�{�^��
	int img_button_x;				// X�{�^��
	//int img_background;			// �w�i

	// ����摜�Ǎ��p�ϐ�
	int img_sword;					// �Ў茕
	int img_dagger;					// �Z��
	int img_great_sword;			// �匕
	int img_spear;					// ��
	int img_frail;					// �t���C�A
	int img_book;					// �{
	int img_question_mark;			// �͂Ăȃ}�[�N�i���햳���̏ꍇ�j

	//// ���x��7�̕���摜
	//int img_assasinsdagger;
	//int img_legendsword;
	//int img_windslash;
	//int img_royallance;
	//int img_threechain;
	//int img_blessing;

	//// ���x��8�̕���摜
	//int img_throwingknife;
	//int img_magicsword;
	//int img_dustsword;
	//int img_gungnir;
	//int img_earthcrusher;
	//int img_bullet;

	// ����̏��
	struct weapon_information
	{
		int num;
		int type;					// ����̎��
		int level;					// ����̃��x��
		int cursor_pos;				// ����̃��x���A�b�v���J�[�\���\���ʒu
		int level_hierarchy;		// ����̃��x���̊K�w
		int damege;					// ����̍U����
		int cool_time;				// ����̃N�[���^�C��
		int tmp_level;				// �J�[�\���������Ă��郌�x��
		int tmp_damege;				// ����̍U���͈ꎞ����
		int tmp_cool_time;			// ����̃N�[���^�C���ꎞ����
		float attack_range;			// �U���͈�
		float tmp_attack_range;		// �U���͈͈ꎞ����
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
	int branch_point_x[2][5];		// �I����������_��X���W���i�[ [����ԍ�][X���W]
	int branch_point_y[2][5];		// �I����������_��Y���W���i�[ [����ԍ�][Y���W]
	bool is_chooce[2][5];			// �ǂ̃��x���K�w�܂őI��������

	// �v���C���[���i�[�p�iweapon����j
	float w_p_speed;				// ���x
	float w_p_avoidancecooltime;		// ����̃N�[���^�C��
	float w_p_upperlimitlimit;		// ��𑬓x

	// �v���C���[���i�[�p�iplayer����j
	float p_speed;					// ���x
	float p_avoidancecooltime;		// ����̃N�[���^�C��
	float p_upperlimitlimit;		// ��𑬓x

	// �t���C���̏��i�[�p
	float frail_radiusX;
	float frail_radiusY;
	float tmp_frail_radiusX;
	float tmp_frail_radiusY;

	// �������̏��i�[�p
	int book_bullet_speed;
	int tmp_book_bullet_speed;

	int close_mode;					// 0:�J���@1:X�{�^���������@2:����

public:
	WeaponLevelUp();
	~WeaponLevelUp();

	// �X�V
	void update(weapon* weapon, second_weapon* second_weapon, Player* player, bool& restor_cursor_position, int& point);

	// �`��
	void draw()const;

	// ����������
	void Init(weapon* weapon, second_weapon* second_weapon, Player* player, bool& restor_cursor_position);

private:

	// ����I����̏���
	void AfterSelectingWeapon(weapon* weapon, second_weapon* second_weapon, Player* player, weapon_information* info, int& point);

	// ���x���A�b�v����
	void LevelUp(weapon* weapon, second_weapon* second_weapon, Player* player, weapon_information* info, int& point);

	// ���x���A�b�v�̃J�[�\���ړ�
	void LevelUpCursorMove(weapon_information* info);

	// ���x���A�b�v�J�[�\���̈ʒu��߂�
	void ResetLevelUpCursorPos(weapon_information* info);

	// ����̉摜�`��
	void DrawWeaponImages()const;

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

	int GetCloseMode() { return close_mode; }

	void SetCloseMode(int num)
	{
		close_mode = num;
	}
};