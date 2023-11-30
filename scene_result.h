#pragma once

#include "scene.h"

class weapon;								// �ŏ��̕���
class second_weapon;						// ��ڂ̕���

class ResultScene : public Scene
{
private:

	// �摜�p�ϐ�
	//int img_map;					// �}�b�v
	//int img_branchPoint;			// ����_
	//int img_weapon1;				// ����P
	//int img_weapon2;				// ����Q
	//int img_background;			// �w�i
	int img_button_a;				// A�{�^��

	// �}�b�v�A�C�R���Ǎ��p�ϐ�
	int img_battle;					// �ʏ�X�e�[�W
	int img_event;					// �C�x���g
	int img_rest;					// �x�e
	int img_anvil;					// �b��
	int img_boss;					// �{�X

	// ����摜�Ǎ��p�ϐ�
	int img_sword;					// �Ў茕
	int img_dagger;					// �Z��
	int img_great_sword;			//�匕
	int img_question_mark;			// �͂Ăȃ}�[�N�i���햳���̏ꍇ�j
	int img_spear;					// ��
	int img_frail;					// �t���C�A
	int img_book;					// �{

	// �t�F�[�h���o
	int value;						// �s�����x

	struct weapon_info
	{
		int type;					// ���
		int level;					// ���x��
		int damage;					// �_���[�W����
	};

	weapon_info weapon1_info;		// ����1
	weapon_info weapon2_info;		// ����2

	struct map_info
	{
		int battle_count;			// �ʏ�X�e�[�W
		int event_count;			// �C�x���g
		int rest_count;				// �x�e
		int anvil_count;			// �b��
		int boss_count;				// �{�X
	};

	map_info map_info;				// �}�b�v���

public:
	ResultScene(int result_info[11]);
	~ResultScene();

	// �X�V
	Scene* update() override;

	// �`��
	void draw() const override;
};