#pragma once
#include"scene.h"

class weapon;

#define INTERVAL 15
#define SELECT_WEAPON 3

class Weapon_Selection
{
private:
	int interval;
	int cursor_num;
	int cursor_x;

	int sword_image;
	int cursor_image;

public:
	//�R���X�g���N�^
	Weapon_Selection();

	//�f�X�g���N�^
	~Weapon_Selection();

	//�`��Ɋւ��邱�ƈȊO�̍X�V����������
	virtual void update(weapon* _weapon, bool &flg);

	//�`��Ɋւ��邱�Ƃ̍X�V����������
	virtual void draw()const;
};