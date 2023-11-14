#pragma once
#include "EnemyBase.h"
#include "Player.h"
#include "weapon.h"

class Wizard :public EnemyBase
{
private:

public:
	Wizard(int arrayNum, int WizardMaxNum);

	void Update(int arrayNum, Player* player, weapon* w, Stage stage);
	void Draw(int arrayNum);

	//�ړ�����
	void X();
	void Y();

	//�X���C���̃_���[�W�擾
	float GetWizardDamage();
};

