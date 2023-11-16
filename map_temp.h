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
	{430, 590}, {630, 590}, {830, 590}, {390, 470}, {530, 480},
	{730, 480}, {880, 470}, {630, 370}, {430, 270}, {630, 200},
	{870, 270}, {330, 80}, {630, -30}, {870, 40}, {530, 80},
	{930, 140}, {810, 140}, {430, -100}, {870, -100}, {630, -200},
	{630, -300},
	};
	int icon_loc[DATA_MAX][2];         // �A�C�R�����W
	int icon_vec;                      // �A�C�R���ړ���
	int total_vec;                     // �����ړ���

	// �e���v���[�g�����p�ϐ�
	int icon_loc_change[DATA_MAX][2];  // �ύX��f�t�H���g�A�C�R�����W
	int change_icon;                   // �ړ�������A�C�R��
	int change_icon_tab;               // �ړ�������A�C�R��(�\�̈�)

	// ���ɍs����X�e�[�W(�Ō��1�ԍŏ��̑I���X�e�[�W)
	const int next_stage[DATA_MAX][3]{
		{3,-1},{4,5,-1},{6,-1},{7,-1},
		{7,-1},{7,-1},{7,-1},{8,9,10},{11,14,-1},
		{12,-1},{15,-1},{17,-1},{9,19,-1},{18,-1},
		{17,-1},{13,-1},{10,13,-1},{19,-1},{19,-1},
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
