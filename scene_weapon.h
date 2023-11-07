#pragma once
#include"scene.h"

class weapon;
class second_weapon;

#define INTERVAL 15
#define SELECT_WEAPON 3

class Weapon_Selection
{
private:
	int interval;				//�C���^�[�o��
	int cursor_num;				//�J�[�\���ԍ�
	int select_num;				//�I�������ԍ�
	int cursor_x;				//�J�[�\�����̍��W

	int dagger_image;			//�Z���̉摜
	int sword_image;			//�Ў茕�̉摜
	int great_sword_image;		//�匕�̉摜
	//int spear_image;			//���̉摜
	//int frail_image;			//�t���C���̉摜
	//int magic_book;				//�������̉摜

	int button_image;			//�{�^���̉摜
	int cursor_image;			//�J�[�\���摜

	bool is_selecting;			//�����I�����Ă���H
	bool was_selected;			//���łɕ����I�������H

public:
	//�R���X�g���N�^
	Weapon_Selection(const bool selected);

	//�f�X�g���N�^
	~Weapon_Selection();

	//�`��Ɋւ��邱�ƈȊO�̍X�V����������
	virtual void update(weapon* _weapon, second_weapon* _second_weapon, bool& is_weapon_select);

	//�`��Ɋւ��邱�Ƃ̍X�V����������
	virtual void draw()const;
};