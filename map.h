#pragma once

#include "rest.h"


#define PATTERN_MAX 3
#define DATA_MAX 21

class Map
{
private:
	int MapData[DATA_MAX];

	// �A�C�R�����W(����)
	const int icon_loc_def[PATTERN_MAX][DATA_MAX][2] = { {
		{430, 620}, {630, 620}, {830, 620}, {390, 500}, {530, 510},
		{730, 510}, {880, 500}, {630, 400}, {470, 300}, {630, 230},
		{820, 300}, {380, 110}, {560, 110}, {760, 170}, {880, 170},
		{820, 50}, {470, -70}, {630, 0}, {820, -70}, {630, -170},
		{630, -270},
	}, {
		{530, 620}, {730, 620}, {430, 500}, {630, 500}, {730, 500},
		{530, 400}, {730, 400}, {630, 350}, {430, 250}, {780, 250},
		{430, 160}, {560, 160}, {780, 160}, {430, 60}, {560, 60},
		{730, 60}, {830, 60}, {560, -60}, {780, -60}, {630, -170},
		{630, -270},
	}, {
		{630, 620}, {550, 550}, {750, 570}, {470, 470}, {630, 470},
		{750, 500}, {750, 430}, {630, 350}, {500, 250}, {750, 250},
		{450, 150}, {550, 150}, {700, 150}, {800, 150}, {500, 60},
		{750, 60}, {500, -40}, {750, -40}, {630, -70}, {630, -170},
		{630, -270},
	} };
	int icon_loc[DATA_MAX][2];        // �A�C�R�����W
	int icon_loc_center[DATA_MAX][2]; // �A�C�R�����W(����)
	int map_move;
	int map_move_log;

	// ���ɍs����X�e�[�W
	const int next_stage[PATTERN_MAX][DATA_MAX][3]{ {
			{3,-1,-1},{4,5,-1},{6,-1,-1},{7,-1,-1},{7,-1,-1},
		    {7,-1,-1},{7,-1,-1},{8,9,10},{11,12,-1},{17,-1,-1},
			{13,14,-1},{16,-1,-1},{16,-1,-1},{15,-1,-1},{15,-1,-1},
			{18,-1,-1},{19,-1,-1},{19,-1,-1},{19,-1,-1},{20,-1,-1},
			{0,1,2}
		}, {
			{2,3,-1},{4,-1,-1},{5,-1,-1},{5,-1,-1},{6,-1,-1},
			{7,-1,-1},{7,-1,-1},{8,9,-1},{10,11,-1},{12,-1,-1},
			{13,-1,-1},{14,-1,-1},{15,16,-1},{17,-1,-1},{17,-1,-1},
			{18,-1,-1},{18,-1,-1},{19,-1,-1},{19,-1,-1},{20,-1,-1},
			{0,1,-1}
		}, {
			{1,2,-1},{3,4,-1},{5,-1,-1},{7,-1,-1},{7,-1,-1},
			{6,-1,-1},{7,-1,-1},{8,9,-1},{10,11,-1},{12,13,-1},
			{14,-1,-1},{14,-1,-1},{15,-1,-1},{15,-1,-1},{16,-1,-1},
			{17,-1,-1},{18,-1,-1},{18,-1,-1},{19,-1,-1},{20,-1,-1},
			{0,-1,-1}
		},
	};
	int stage_log[10];
	int pattern;
	const int pattern_data_max[PATTERN_MAX]{ 21,21,21 };
	int data_max;

	int cursor_pos;    // �J�[�\���ʒu(���X�e�[�W)
	int cursor_loc;    // �J�[�\���ʒu(�S�̃}�b�v)
	int move_cool;     // �J�[�\���ړ��N�[���^�C��
	bool cursor_move;  // �J�[�\���ړ��ɂ��J�����ړ������邩(�X�N���[���ړ�����Ɖ���)
	int cursor_r;      // �J�[�\�����a
	int alpha;
	bool alpha_flg;
	int now_stage;     // ���݂̃X�e�[�W
	int no_input_time;
	bool intro_flg;
	int intro_time;
	int select_draw;
	int select_loc;

	// �摜
	int battle_img = 0;
	int event_img = 0;
	int rest_img = 0;
	int anvil_img = 0;
	int boss_img = 0;
	int icon_back_img = 0;
	int cross_img = 0;
	int roof_img = 0;
	int wall_img = 0;
	int map_back_img = 0;
	int button_a_image = 0;
	int decision_img = 0;
	int map_first_img = 0;
	int stage_select_img = 0;

	// ���U���g��ʂŎg�p�i�k���}�b�v�쐬�������������ꍇ�j
	// �X�e�[�W�ɉ��񓞒B������
	int battle_count;		// �ʏ�X�e�[�W
	int event_count;		// �C�x���g
	int rest_count;			// �x�e
	int anvil_count;		// �b��
	int boss_count;			// �{�X

public:
	Map();

	~Map();

	int update(int&, int&, bool&);

	void draw() const;

	int NowStage() {
		return now_stage;
	}

	// �X�e�[�W�N���A�㏈��
	void ClearStage() {
		cursor_pos = 0;
		cursor_loc = next_stage[pattern][now_stage][0];
		cursor_r = 45;
		int center_def = 360 - icon_loc[cursor_loc][1];
		map_move = map_move + center_def;
		alpha = 0;
		alpha_flg = TRUE;
		no_input_time = 30;
		select_draw = 180;
		select_loc = -120;
		for (int i = 0; i <= 10; i++) {
			if (stage_log[i] == -1) {
				stage_log[i] = now_stage;
				break;
			}
		}
		switch (MapData[now_stage])
		{
		case 0:		//�퓬
			battle_count++;
			break;
		case 1:		//�C�x���g�i���{�X�j
			event_count++;
			break;
		case 2:		//�x�e
			rest_count++;
			break;
		case 3:		//�b�艮
			anvil_count++;
			break;
		case 4:		//�{�X
			boss_count++;
			break;
		default:
			break;
		}
	}

	void ResetStage();

	void SetStage(int st_min, int st_max, int rand_min, int rand_max, int type, int data_num);

	// ���U���g��ʗp
	int GetBattleCount() { return battle_count; }
	int GetEventCount() { return event_count; }
	int GetRestCount() { return rest_count; }
	int GetAnvilCount() { return anvil_count; }
	int GetBossCount() { return boss_count; }
};