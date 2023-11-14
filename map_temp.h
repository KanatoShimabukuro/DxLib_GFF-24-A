#pragma once
#include"DxLib.h"
#include"scene.h"

#define DATA_MAX 21 // �ő�X�e�[�W��

class map_temp : public Scene
{

private:
	int MapDeta[DATA_MAX]; // �}�b�v�����f�[�^
	int RandNum[3];        // GetRand�i�[�p

	// �A�C�R�����W(����)
	const int icon_loc_def[DATA_MAX][2] = {
	{360, 590}, {630, 610}, {920, 580}, {390, 470}, {570, 510},
	{730, 480}, {910, 470}, {640, 370}, {440, 270}, {580, 220},
	{800, 290}, {340, 180}, {710, 160}, {960, 210}, {460, 80},
	{850, 130}, {760, 40}, {380, -80}, {860, -110}, {640, -200},
	{640, -300},
	};
	int icon_loc[DATA_MAX][2];         // �A�C�R�����W
	int icon_loc_change[DATA_MAX][2];
	int icon_vec;                      // �A�C�R���ړ���
	int total_vec;                     // �����ړ���
	int change_icon;                   // �ړ�������A�C�R��
	int change_icon_tab;               // �ړ�������A�C�R��(�\�̈�)

	// ���ɍs����X�e�[�W(�Ō��1�ԍŏ��̑I���X�e�[�W)
	const int next_stage[DATA_MAX][3]{
		{3,4,-1},{4,-1},{5,6,-1},{7,-1},
		{7,-1},{7,-1},{7,-1},{8,9,10},{11,14,-1},
		{12,14,-1},{12,13,-1},{14,-1},{16,-1},{15,-1},
		{17,18,-1},{16,-1},{17,18,-1},{19,-1},{19,-1},
		{20,-1},{0,1,2}
	};

	// �摜
	int battle_img = 0;
	int event_img = 0;
	int rest_img = 0;
	int anvil_img = 0;
	int boss_img = 0;
	int map_cursor = 0;
public:
	map_temp();

	~map_temp();

	virtual Scene* update() override;

	virtual void draw() const override;
};
