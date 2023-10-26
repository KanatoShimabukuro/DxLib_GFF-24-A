#include "Slime.h"
#include "Common.h"

Slime::Slime()
{
	//�摜�Ǎ�
	img = LoadGraph("resources/images/slime_cat.png");
	//�ϐ��̏�����
	location.x = 0;
	location.y = 0;
	vector.x = 0;
	vector.y = 0;

	tmpVX = 0;
	tmpVY = 0;

	//���X�|�[���|�C���g����
	SetRespawnPoint();
}

void Slime::Update()
{
	//�ړ�����//
	X();
	location.x += vector.x;

	Y();
	location.y += vector.y;
}

void Slime::Draw()
{
	DrawRotaGraph((int)location.x, (int)location.y, 1, 0, img, TRUE);
}

void Slime::X()
{
	vector.x = Normalization_X(PlayerLoad_X(location.x), PlayerLoad_Y(location.y));
}

void Slime::Y()
{
	vector.y = Normalization_Y(PlayerLoad_X(location.x), PlayerLoad_Y(location.y));
}

int Slime::GetStageNum()
{
	int r = SLIME_1_STAGE_NUM;
	return r;
}
