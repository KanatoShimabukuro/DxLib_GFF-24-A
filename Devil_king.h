#pragma once
#include "EnemyBase.h"
#include "Common.h"
#define DEVILKING_MAX_HP 2000//�����̍ő�̗�
#define DEVILKING_ATTAK_DAMAGE 10//�����̃_���[�W

class Devil_king:public EnemyBase
{
private:
	float shield;//�����̃V�[���h
public:
	Devil_king();
	~Devil_king();
	void Update(Player* player);
	void Draw() const;
};

