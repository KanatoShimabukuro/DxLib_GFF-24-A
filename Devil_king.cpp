#include "Devil_king.h"
#include "Common.h"

Devil_king::Devil_king()
{
	img = LoadGraph("resources/images/enemy_tmp_images/ma.png");
	hp = DEVILKING_MAX_HP;
	shield = 100;
	damage = DEVILKING_ATTAK_DAMAGE;
	location.x = _SCREEN_WIDHT_ / 2;
	location.y = 60;

	//-----�傫���e-----//
}

Devil_king::~Devil_king()
{
	DeleteGraph(img);
}

void Devil_king::Update(Player* player)
{
	//�v���C���[�̈ړ��ʂ�diff�ɃZ�b�g
	SetPlayerAmountOfTravel_X(player->Player_MoveX());
	SetPlayerAmountOfTravel_Y(player->Player_MoveY());
	//�v���C���[�̍��W��diffLocation�ɃZ�b�g
	SetPlayer_Location(player->GetLocation());

	location.x = location.x - diff.x;
	location.y = location.y - diff.y;
}

void Devil_king::Draw() const
{
	DrawRotaGraph((int)location.x, (int)location.y, 1, 0, img, TRUE);
}
