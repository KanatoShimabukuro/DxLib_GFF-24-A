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
		{430, 160}, {560, 160}, {780, 160}, {430, 60}, {730, 60},
		{830, 60}, {780, -10}, {560, -60}, {780, -100}, {630, -170},
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


	// �}�b�v��������
	const int map_ctrl[PATTERN_MAX][5][5]{ {
		{7, 7, 1, 1, 0},
		{3, 6, 1, 2, 0},
		{13, 14, 0, 1, 1},
		{16, 18, 0, 1, 1},
		{19, 19, 1, 1, 1},
		},{
		{7, 7, 1, 1, 0},
		{2, 6, 1, 2, 0},
		{8, 9, 0, 1, 1},
		{11, 14, 0, 1, 1},
		{17, 18, 1, 1, 1},
		},{
		{7, 7, 1, 1, 0},
		{1, 6, 1, 2, 0},
		{10, 11, 0, 1, 1},
		{12, 13, 0, 1, 1},
		{16, 17, 1, 1, 1},
		},
	};


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
			{13,-1,-1},{17,-1,-1},{14,15,-1},{17,-1,-1},{16,-1,-1},
			{16,-1,-1},{18,-1,-1},{19,-1,-1},{19,-1,-1},{20,-1,-1},
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

	// �摜
	int battle_img = 0;
	int event_img = 0;
	int rest_img = 0;
	int anvil_img = 0;
	int boss_img = 0;
	int icon_back_img = 0;
	int cross_img = 0;
	int crown_img = 0;
	int roof_img = 0;
	int wall_img = 0;
	int tower_img = 0;
	int map_back_img = 0;
	int button_a_image = 0;
	int decision_img = 0;

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

	void ClearStage() {
		cursor_pos = 0;
		cursor_loc = next_stage[pattern][now_stage][0];
		cursor_r = 45;
		int center_def = 360 - icon_loc[cursor_loc][1];
		map_move = map_move + center_def;
		alpha = 0;
		alpha_flg = TRUE;
		for (int i = 0; i <= 10; i++) {
			if (stage_log[i] == -1) {
				stage_log[i] = now_stage;
				break;
			}
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