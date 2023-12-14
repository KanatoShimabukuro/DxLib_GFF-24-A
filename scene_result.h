#pragma once

#include "scene.h"

class weapon;								// �ŏ��̕���
class second_weapon;						// ��ڂ̕���

class ResultScene : public Scene
{
private:

	// �摜�p�ϐ�
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

	// ���S�摜�Ǎ��p�ϐ�
	int img_logo_result;
	int img_logo_lv;
	int img_logo_title;
	int img_logo_totaldamage;

	// ���햼���S�摜
	int img_logo_dagger;
	int img_logo_sword;
	int img_logo_greatsword;
	int img_logo_spear;
	int img_logo_frail;
	int img_logo_book;

	// ���x��7�̕��햼���S�摜
	int img_logo_assasinsdagger;
	int img_logo_legendsword;
	int img_logo_windslash;
	int img_logo_royallance;
	int img_logo_threechain;
	int img_logo_blessing;

	// ���x��8�̕��햼���S�摜
	int img_logo_throwingknife;
	int img_logo_magicsword;
	int img_logo_dustsword;
	int img_logo_gungnir;
	int img_logo_earthcrusher;
	int img_logo_bullet;

	// �}�b�v�A�C�R�����m�̕�
	int img_width;

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