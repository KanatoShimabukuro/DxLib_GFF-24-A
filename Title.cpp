#include "DxLib.h"
#include "Title.h"

//�R���X�g���N�^
Title::Title()
{
	EnemyImage0 = LoadGraph("resources/images/���@�g��.png");
	EnemyImage1 = LoadGraph("resources/images/�X�P���g��.png");
	EnemyImage2 = LoadGraph("resources/images/�X���C��.png");
	EnemyImage3 = LoadGraph("resources/images/�~�m�^�E���X.png");
	EnemyImage4 = LoadGraph("resources/images/�܂���.png");
}

//�f�X�g���N�^
Title::~Title()
{

}

//�X�V
Scene*Title::Update()
{
	return this;
}

//�`��
void Title::draw() const
{
	DrawGraph(1200, 640, EnemyImage0,FALSE);
}