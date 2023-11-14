#pragma once
#include"DxLib.h"
#include"scene_rest.h"

class GameScene;
class GameUI;

#define DATA_MAX 21

class Map
{
private:
	int MapDeta[DATA_MAX];
	int RandNum[3];

	// �A�C�R�����W(����)
	const int icon_loc_def[21][2] = {
	{360, 590}, {630, 610}, {920, 580}, {390, 470}, {570, 510},
	{730, 480}, {910, 470}, {640, 370}, {440, 270}, {580, 220},
	{800, 290}, {340, 180}, {710, 160}, {960, 210}, {460, 80},
	{850, 130}, {760, 40}, {380, -80}, {860, -110}, {640, -200},
	{640, -300},
	};
	int icon_loc[21][2];  // �A�C�R�����W
	int icon_vec;         // �A�C�R���ړ���

	// ���ɍs����X�e�[�W
	const int next_stage[21][3]{
		{3,4,-1},{4,-1},{5,6,-1},{7,-1},
		{7,-1},{7,-1},{7,-1},{8,9,10},{11,14,-1},
		{12,14,-1},{12,13,-1},{14,-1},{16,-1},{15,-1},
		{17,18,-1},{16,-1},{17,18,-1},{19,-1},{19,-1},
		{20,-1},{0,1,2}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
	};
	int stage_log[10]{0};

	Rest* rest;
	GameUI* ui;

	int cursor_pos;    // �J�[�\���ʒu
	int cursor_loc;
	int move_cool;     // �J�[�\���ړ��N�[���^�C��
	bool cursor_move;  // �J�[�\���ړ��ɂ��J�����ړ������邩(�X�N���[���ړ�����Ɖ���)
	int now_stage;

	bool is_map_mode;

	bool is_rest;		//�x�e�X�e�[�W�̃t���O
	bool is_show_rest;	//�x�e�X�e�[�W���f���H

	// �摜
	int battle_img = 0;
	int event_img = 0;
	int rest_img = 0;
	int anvil_img = 0;
	int boss_img = 0;
	int map_cursor = 0;
public:
	Map(GameUI* ui);

	~Map();

	int update();

	void draw() const;

	bool GetIsMapMode() {
		return is_map_mode;
	}

	void SetIsMapMode(const bool flg) {
		is_map_mode = flg;
	}

	void ClearStage() {
		cursor_pos = 0;
		cursor_loc = next_stage[now_stage][0];
	}

	void ResetStage();
};