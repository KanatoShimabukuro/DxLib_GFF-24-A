#pragma once
#include"scene.h"

class Weapon_Selection : public Scene
{
private:
	int interval;
	int cursor_num;
	int cursor_x;

public:
	//�R���X�g���N�^
	Weapon_Selection();

	//�f�X�g���N�^
	~Weapon_Selection();

	//�`��Ɋւ��邱�ƈȊO�̍X�V����������
	virtual Scene* update()override;

	//�`��Ɋւ��邱�Ƃ̍X�V����������
	virtual void draw()const override;
};