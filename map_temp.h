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
	{630, 590}, {530, 540}, {730, 540}, {470, 470}, {580, 470},
	{730, 470}, {530, 400}, {630, 320}, {530, 220}, {730, 220},
	{430, 120}, {530, 120}, {630, 120}, {480, 30}, {580, 30},
	{730, 30}, {530, -20}, {730, -70}, {630, -130}, {630, -200},
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
		{1,2,-1},{3,4,-1},{5,-1},{6,-1},
		{6,-1},{7,-1},{7,-1},{8,9,-1},{10,11,12},
		{15,-1},{13,-1},{13,14,-1},{14,-1},{16,-1},
		{16,-1},{17,-1},{18,-1},{18,-1},{19,-1},
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
