#pragma once
#include"DxLib.h"
#include"scene.h"

#define DATA_MAX 21

class Map : public Scene
{
private:
	int MapData[DATA_MAX];
	int RandNum[3];

	// �A�C�R�����W(����)
	int icon_loc_def[21][2] = {
	{420, 590}, {690, 610}, {980, 580}, {450, 470}, {630, 510},
	{790, 480}, {970, 470}, {710, 370}, {500, 270}, {640, 220},
	{860, 290}, {400, 180}, {770, 160}, {1020, 210}, {520, 80},
	{910, 130}, {820, 40}, {440, -80}, {920, -110}, {700, -200},
	{700, -300},
	};
	int icon_loc[21][2];  // �A�C�R�����W
	int icon_vec;         // �A�C�R���ړ���

	// ���ɍs����X�e�[�W
	int next_stage[21][3]{
		{3,4},{4},{5,6},{7},{7},
		{7},{7},{8,9,10},{11,14},{12,14},
		{12,13},{14},{16},{15},{17,18},
		{16},{17,18},{19},{19},{20},
	};

	int cursor_pos;    // �J�[�\���ʒu
	int move_cool;     // �J�[�\���ړ��N�[���^�C��
	bool cursor_move;  // �J�[�\���ړ��ɂ��J�����ړ������邩(�X�N���[���ړ�����Ɖ���)

	// �摜
	int battle_img = 0;
	int event_img = 0;
	int rest_img = 0;
	int anvil_img = 0;
	int boss_img = 0;
	int map_cursor = 0;
public:
	Map();

	~Map();

	virtual Scene* update() override;

	virtual void draw() const override;
};

