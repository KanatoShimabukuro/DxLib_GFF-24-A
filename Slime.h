#pragma once
#include "EnemyBase.h"
class Slime :public EnemyBase
{
private:

	float tmpVX;
	float tmpVY;

public:
	Slime();

	void Update();
	void Draw();

	//�ړ�����
	void X();
	void Y();

	//���݂̃X�e�[�W�ł̏o�����鐔��Ԃ�
	int GetStageNum();
};

