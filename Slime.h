#pragma once
#include "EnemyBase.h"
#include "Player.h"

class Slime :public EnemyBase
{
private:

	float tmpVX;
	float tmpVY;

public:
	Slime();

	void Update(Player* player);
	void Draw();

	//�ړ�����
	void X();
	void Y();

	//���݂̃X�e�[�W�ł̏o�����鐔��Ԃ�
	int GetStageNum();
};

