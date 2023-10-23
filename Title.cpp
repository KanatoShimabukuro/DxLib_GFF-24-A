#include "DxLib.h"
#include "Title.h"
#include "GameMain.h"
#include "sourceFiles/inputCtrl.h"

//�R���X�g���N�^
Title::Title()
{
	EnemyImage0 = LoadGraph("resources/images/(��)���@�g��.png");
	EnemyImage1 = LoadGraph("resources/images/(��)�X�P���g��.png");
	EnemyImage2 = LoadGraph("resources/images/(��)�X���C��.png");
	EnemyImage3 = LoadGraph("resources/images/(��)�~�m�^�E���X.png");
	EnemyImage4 = LoadGraph("resources/images/(��)�܂���.png");
}

//�f�X�g���N�^
Title::~Title()
{

}

//�X�V
Scene*Title::update()
{
	InputCtrl::Update();
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A))
	{
		return new GameMain;
	}
	return this;
}

//�`��
void Title::draw() const
{
	//DrawGraph(0, 0, EnemyImage0,FALSE);
	SetFontSize(75);
	DrawString(470, 300, "Start", 0xffffff);
	DrawString(470, 370, "Help", 0xffffff);
	DrawString(470, 440, "Credit", 0xffffff);
	DrawString(470, 510, "End", 0xffffff);
}