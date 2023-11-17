#include "EnemyBullet.h"
#include "Player.h"

EnemyBullet::EnemyBullet(Location spawnLocation , Player* player)
{
	//�ϐ��̏�����
	img = LoadGraph("resources/images/enemy_tmp_images/kintama.png");
	location.x = spawnLocation.x;
	location.y = spawnLocation.y;
	vector.x = 0;
	vector.y = 0;
	diff.x = 0;
	diff.y = 0;
	radius = BULLET_RADIUS;
	damage = BULLET_ATTAK_DAMAGE;
	speed = BULLET_SPEED;
	lifeTimeCnt = BULLET_LIFE_TIME;

	//�v���C���[�̈ړ��ʂ�diff�ɃZ�b�g
	//SetPlayerAmountOfTravel_X(player->Player_MoveX());
	//SetPlayerAmountOfTravel_Y(player->Player_MoveY());
	////�v���C���[�̍��W��diffLocation�ɃZ�b�g
	SetPlayer_Location(player->GetLocation());
	vector.x = Normalization_X(PlayerLoad_X(location.x), PlayerLoad_Y(location.y)) * BULLET_SPEED;
	vector.y = Normalization_Y(PlayerLoad_X(location.x), PlayerLoad_Y(location.y)) * BULLET_SPEED;
}

void EnemyBullet::Update(Player* player)
{
	//�v���C���[�̈ړ��ʂ�diff�ɃZ�b�g
	SetPlayerAmountOfTravel_X(player->Player_MoveX());
	SetPlayerAmountOfTravel_Y(player->Player_MoveY());

	location.x += vector.x - player->Player_MoveX();
	location.y += vector.y - player->Player_MoveY();

	lifeTimeCnt--;
}

void EnemyBullet::Draw() const
{
	DrawRotaGraph((int)location.x, (int)location.y, 1, 0, img, TRUE);
}

int EnemyBullet::GetDamage()
{
	return damage;
}

int EnemyBullet::GetlifeTimeCnt()
{
	return lifeTimeCnt;
}
