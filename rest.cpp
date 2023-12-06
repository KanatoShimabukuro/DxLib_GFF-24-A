//#include "rest.h"
#include "main.h"

//#include"Player.h"
//#include"game_ui.h"

Rest::Rest(GameUI* ui)
{
	this->ui = ui;

	interval = 0;
	cursor_num = 0;


	cursor_image = LoadGraph("resources/images/computer_cursor_finger_black.png");
	bonfire_image = LoadGraph("resources/images/bonfirelit.png");
	button_image = LoadGraph("resources/images/button_a.png");

	SoundManager::SetBGM("bgm_breakstage");

	is_select = false;
	is_ok = false;
}

Rest::~Rest()
{
	DeleteGraph(cursor_image);
	DeleteGraph(bonfire_image);
	DeleteGraph(button_image);
}

void Rest::update(Player* player, int& mode, int& stage)
{
	SoundManager::PlaySoundBGM("bgm_breakstage");

	ui->setHP(player->GetPlayer_HP(), 100, (int)(player->GetPlayer_HP()));
	ui->update();


	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS || InputCtrl::GetKeyState(KEY_INPUT_SPACE) == PRESS)
	{
		if (cursor_num == 0)
		{
			player->SetPlayer_HP(-100);
			is_select = true;
		}
	}
	
	if (is_select)
	{
		if (interval < 120)
		{
			interval++;
		}
		else
		{
			is_ok = true;
			stage++;
			mode = GameSceneMode::map;
			Init();
			SoundManager::StopSoundBGM("bgm_breakstage");
		}
	}

}

void Rest::draw() const
{
	ui->drawHP();

	DrawRotaGraph(640, 300, .7f, 0, bonfire_image, TRUE);
	DrawRotaGraph(480, 630, .5f, 1.6f, cursor_image, TRUE);
	DrawGraph(1150, 650, button_image, TRUE);
	DrawString(1194, 662, "����\n", 0xffffff);

	if (is_select != true)
	{
		SetFontSize(48);
		DrawString(570, 600, "�x�e����", 0xffffff);
		SetFontSize(16);
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
		DrawBox(0, (SCREEN_HEIGHT / 3), SCREEN_WIDTH, (SCREEN_HEIGHT / 3) * 2, 0x000000, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		SetFontSize(48);
		DrawString((SCREEN_WIDTH / 2) - 48 * 4.5, (SCREEN_HEIGHT / 2) - 24, "HP���S�񕜂��܂���", 0xffffff);
		SetFontSize(16);
	}
}

void Rest::Init()
{
	interval = 0;

	is_select = false;
	is_ok = false;

}
