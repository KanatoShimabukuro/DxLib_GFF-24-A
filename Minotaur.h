#pragma once
#include "EnemyBase.h"

class Minotaur :public EnemyBase
{
private:
	int tackleCoolTimeCnt;//�^�b�N��������̃N�[���^�C��
	int tacklePrepTimeCnt;//�^�b�N����������
	bool tackleFlg;//

public:
	Minotaur();
	void Update();
	void Draw() const;

	void Tackle();//�^�b�N�����̈ړ��ʂ��v�Z
	void Roar();//���K
};

