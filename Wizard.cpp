#include "Wizard.h"
#include "Common.h"
#include <math.h>
#include "inputCtrl.h"
#include"Stage.h"

Wizard::Wizard(int arrayNum, int WizardMaxNum)
{
	//�摜�Ǎ�
	img = LoadGraph("resources/images/enemy_tmp_images/wizard_sato.png");
	//�ϐ��̏�����
	hp = WIZARD_HP_MAX;
	damage = WIZARD_ATTAK_DAMAGE;
	location.x = 0;
	location.y = 0;
	vector.x = 0;
	vector.y = 0;

	respawnTimeCnt = 0;
	respawnTime = SetRespawnTime(arrayNum, WizardMaxNum);

	//���X�|�[���|�C���g����
	SetRespawnPoint();
}

void Wizard::Update(int arrayNum, Player* player, weapon* w, Stage stage)
{

}

void Wizard::Draw(int arrayNum)
{

}

void Wizard::X()
{

}

void Wizard::Y()
{

}

float Wizard::GetWizardDamage()
{
	return damage;
}

