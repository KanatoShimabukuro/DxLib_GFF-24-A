#pragma once

#include "rest.h"

class GameScene;
class GameUI;

#define DATA_MAX 22

class Map
{
private:
	int MapDeta[DATA_MAX];
	int RandNum[3];

	// �A�C�R�����W(����)
	const int icon_loc_def[DATA_MAX][2] = {
	{360, 590}, {610, 620}, {920, 580}, {390, 470}, {520, 510},
	{670, 530}, {790, 510}, {910, 470}, {640, 370}, {440, 270},
	{580, 220}, {800, 290}, {340, 180}, {710, 160}, {910, 210},
	{850, 130}, {460, 80}, {760, 40}, {380, -80}, {860, -110},
	{640, -200}, {640, -300},
	};
	int icon_loc[DATA_MAX][2];  // �A�C�R�����W
	int icon_vec;         // �A�C�R���ړ���

	// ���ɍs����X�e�[�W
	const int next_stage[DATA_MAX][3]{
		{3,4,-1},{4,5,-1},{6,7,-1},{8,-1,-1},{8,-1,-1},
		{8,-1,-1}, {8,-1,-1},{8,-1,-1},{9,10,11},{12,16,-1},{13,16,-1},
		{13,14,-1},{16,-1,-1},{17,-1,-1},{15,-1,-1},{17,-1,-1},
		{18,19,-1},{18,19,-1},{20,-1,-1},{20,-1,-1},{21,-1,-1},
		{0,1,2},
	};
	int stage_log[10];

	Rest* rest;
	GameUI* ui;

	int cursor_pos;    // �J�[�\���ʒu(���X�e�[�W)
	int cursor_loc;    // �J�[�\���ʒu(�S�̃}�b�v)
	int move_cool;     // �J�[�\���ړ��N�[���^�C��
	bool cursor_move;  // �J�[�\���ړ��ɂ��J�����ړ������邩(�X�N���[���ړ�����Ɖ���)
	int now_stage;     // ���݂̃X�e�[�W

	bool is_map_mode;

	bool is_rest;		//�x�e�X�e�[�W�̃t���O
	bool is_show_rest;	//�x�e�X�e�[�W���f���H

	// �摜
	int battle_img = 0;
	int event_img = 0;
	int rest_img = 0;
	int anvil_img = 0;
	int boss_img = 0;
	int icon_back_img = 0;
	int map_cursor = 0;
public:
	Map(GameUI* ui);

	~Map();

	int update(int&, bool&);


	void draw() const;

	bool GetIsMapMode() {
		return is_map_mode;
	}

	void SetIsMapMode(const bool flg) {
		is_map_mode = flg;
	}

	int NowStage() {
		return now_stage;
	}

	void ClearStage() {
		cursor_pos = 0;
		cursor_loc = next_stage[now_stage][0];
		for (int i = 0; i <= 10; i++) {
			if (stage_log[i] == -1) {
				stage_log[i] = now_stage;
				break;
			}
		}
	}

	void ResetStage();
};