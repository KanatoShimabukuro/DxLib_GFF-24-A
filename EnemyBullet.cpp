#include"main.h"

EnemyBullet::EnemyBullet(Location spawnLocation , Player* player)
{
	//変数の初期化
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

	angle = 0;

	//プレイヤーの移動量をdiffにセット
	//SetPlayerAmountOfTravel_X(player->Player_MoveX());
	//SetPlayerAmountOfTravel_Y(player->Player_MoveY());
	////プレイヤーの座標をdiffLocationにセット
	SetPlayer_Location(player->GetLocation());
	vector.x = Normalization_X(PlayerLoad_X(location.x), PlayerLoad_Y(location.y)) * BULLET_SPEED;
	vector.y = Normalization_Y(PlayerLoad_X(location.x), PlayerLoad_Y(location.y)) * BULLET_SPEED;
	angle = asinf(PlayerLoad_Y(location.y) / PlayerLoad(this->location, true));
}

EnemyBullet::~EnemyBullet()
{
	DeleteGraph(img);
}

void EnemyBullet::Update(Player* player, Wizard* enemy)
{
	//プレイヤーの移動量をdiffにセット
	SetPlayerAmountOfTravel_X(player->Player_MoveX());
	SetPlayerAmountOfTravel_Y(player->Player_MoveY());

	location.x += vector.x - diff.x;
	location.y += vector.y - diff.y;

	//location.x += cosf(angle) * speed - diff.x;
	//location.y += sinf(angle) * speed - diff.y;

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
