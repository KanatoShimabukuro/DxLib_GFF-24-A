#include"scene_rest.h"
#include"inputCtrl.h"
#include"Player.h"

Rest::Rest()
{
	interval = 0;
	cursor_num = 0;


	cursor_image = LoadGraph("resources/images/computer_cursor_finger_black.png");
	bonfire_image = LoadGraph("resources/images/bonfire.png");
	button_image = LoadGraph("resources/images/button_a.png");

	is_select = false;
}

Rest::~Rest()
{

}

void Rest::update(Player* player, bool& flg)
{
	if (interval < 60)
	{
		interval++;
	}
	else
	{
		interval = 0;
	}

	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS || InputCtrl::GetKeyState(KEY_INPUT_SPACE) == PRESS)
	{
		if (cursor_num == 0)
		{
			if (interval > 1)
			{
				player->SetPlayer_HP(-100);
				is_select = true;

			}
		}
	}
	
	if (is_select)
	{
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS || InputCtrl::GetKeyState(KEY_INPUT_SPACE) == PRESS)
		{
			flg = true;
		}
	}

}

void Rest::draw() const
{
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
		SetFontSize(48);
		DrawString(570, 600, "HP���S�񕜂��܂���", 0xffffff);
		SetFontSize(16);
	}
}
