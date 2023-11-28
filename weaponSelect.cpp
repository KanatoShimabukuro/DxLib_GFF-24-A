//#include "weaponSelect.h"
#include "main.h"

Weapon_Selection::Weapon_Selection(const bool selected)
{
	cnt = 0;
	interval = 0;
	cursor_num = 0;
	select_num = 0;
	cursor_x = 0;
	image_shift = 0;

	dagger_image = LoadGraph("resources/images/sword_shortsword_brown.png");
	sword_image = LoadGraph("resources/images/sword_longsword_brown.png");
	great_sword_image = LoadGraph("resources/images/tsurugi_bronze_blue.png");

	spear_image = LoadGraph("resources/images/spear.png");
	frail_image = LoadGraph("resources/images/Frailt_dottoy.png");
	book_image = LoadGraph("resources/images/book_madousyo_necronomicon.png");

	button_image = LoadGraph("resources/images/button_a.png");
	cursor_image = LoadGraph("resources/images/computer_cursor_finger_black.png");

	is_selecting = false;
}

Weapon_Selection::~Weapon_Selection()
{

}

void Weapon_Selection::update(weapon* _weapon, second_weapon* _second_weapon, bool& is_weapon_select, int& mode)
{
	//１５ｆのインターバルを設ける
	if (interval < INTERVAL)
	{
		interval++;
	}

	//カウントする
	if (cnt < SCREEN_FPS)
	{
		cnt++;
	}
	else
	{
		cnt = 0;
	}

	if (is_selecting != true)
	{
		cursor_x = cursor_num * 300;
		image_shift = cursor_num * 50;
		if (cursor_num == 1)
		{
			image_shift -= 30;
		}
	}
	else
	{
		cursor_x = cursor_num * 400;
	}

	//左スティックを右に
	if ((InputCtrl::GetStickRatio(L).x > 0.8 || InputCtrl::GetButtonState(XINPUT_BUTTON_DPAD_RIGHT)) && interval >= 15)
	{
		cursor_num++;
		interval = 0;
		//武器を選択していないなら３つまで
		if (is_selecting != true)
		{
			if (cursor_num >= SELECT_WEAPON)
			{
				cursor_num = 0;
			}
		}
		//武器を選択したなら２つまで
		else
		{
			if (cursor_num > 1)
			{
				cursor_num = 0;
			}
		}
	}

	//左スティックを左に
	if ((InputCtrl::GetStickRatio(L).x < -0.8 || InputCtrl::GetButtonState(XINPUT_BUTTON_DPAD_LEFT)) && interval >= 15)
	{
		cursor_num--;
		interval = 0;
		//武器を選択していないなら３つまで
		if (is_selecting != true)
		{
			if (cursor_num < 0)
			{
				cursor_num = SELECT_WEAPON - 1;
			}
		}
		//武器を選択したなら２つまで
		else
		{
			if (cursor_num < 0)
			{
				cursor_num = 1;
			}
		}
	}

	bool switch_flg = is_weapon_select;

	//武器を選択していないなら
	if (is_selecting != true)
	{
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS || InputCtrl::GetKeyState(KEY_INPUT_SPACE) == PRESS)
		{
			//まだ武器を選択したことがないなら
			if (is_weapon_select != true)
			{
				if (cursor_num == 0)
				{
					_weapon->SetWeaponType(dagger);
					select_num = 0;
				}
				else if (cursor_num == 1)
				{
					_weapon->SetWeaponType(sword);
					select_num = 1;
				}
				else
				{
					_weapon->SetWeaponType(greatSword);
					select_num = 2;
				}
			}
			//武器を選択したことがあるなら
			else
			{
				if (cursor_num == 0)
				{
					_second_weapon->SetWeaponType(spear);
					select_num = 0;
				}
				else if (cursor_num == 1)
				{
					_second_weapon->SetWeaponType(frail);
					select_num = 1;
				}
				else
				{
					_second_weapon->SetWeaponType(book);
					select_num = 2;
				}
			}
			//武器を選択した状態にする
			//is_selecting = true;
			//カーソルを「はい」の位置にする
			cursor_num = 0;
			//武器選択画面はなし
			is_weapon_select = true;
			if (switch_flg)
			{
				mode = GameSceneMode::map;
			}
			else
			{
				mode = GameSceneMode::main;
			}
		}
	}
	//武器を選択したなら
	else
	{
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS || InputCtrl::GetKeyState(KEY_INPUT_SPACE) == PRESS)
 		{
			//はい
			if (cursor_num == 0)
			{
				is_weapon_select = true;
			}
			//いいえ
			else
			{
				is_selecting = false;
			}
		}

		if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
		{
			is_selecting = false;
		}
	}
}

void Weapon_Selection::draw(bool flg) const
{
	//武器を選択していないなら
	if (is_selecting != true)
	{		
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
		DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x000000, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (flg != true)
		{
			//DrawBox(230 + cursor_x, 160, 470 + cursor_x, 500, 0xaaaaaa, TRUE);
			//DrawBoxAA(230.5 + cursor_x, 160.5, 469.5 + cursor_x, 499.5, 0xaa0000, FALSE,3.5f);
			//DrawLineAA(230 + cursor_x, 440, 470 + cursor_x, 440, 0xaa0000, 3.5f);

			DrawRotaGraph(380 + cursor_x, 600, .5f, 0, cursor_image, TRUE);

			SetFontSize(32);
			DrawString(430, 10, "最初の武器を選んでください\n",0xffffff);

			if (cursor_num == 0)
			{
				DrawString(320, 450, "短剣", 0xffffff, 0xff0000);
				DrawRotaGraph(350, 300 + sin(M_PI * 2 / SCREEN_FPS * cnt) * 10, .45f, .0625f, dagger_image, TRUE);

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);

				DrawString(600, 450, "片手剣", 0x666666);
				DrawRotaGraph(650, 300, .45f, .0625f, sword_image, TRUE);

				DrawString(920, 450, "大剣", 0x666666);
				DrawRotaGraph(950, 300, .45f, .0625f, great_sword_image, TRUE);

				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
			else if (cursor_num == 1)
			{
				DrawString(600, 450, "片手剣", 0xffffff, 0xff0000);
				DrawRotaGraph(650, 300 + sin(M_PI * 2 / SCREEN_FPS * cnt) * 10, .45f, .0625f, sword_image, TRUE);

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);

				DrawString(320, 450, "短剣", 0x666666);
				DrawRotaGraph(350, 300, .45f, .0625f, dagger_image, TRUE);

				DrawString(920, 450, "大剣", 0x666666);
				DrawRotaGraph(950, 300, .45f, .0625f, great_sword_image, TRUE);

				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
			else
			{
				DrawString(920, 450, "大剣", 0xffffff, 0xff0000);
				DrawRotaGraph(950, 300 + sin(M_PI * 2 / SCREEN_FPS * cnt) * 10, .45f, .0625f, great_sword_image, TRUE);

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);

				DrawString(600, 450, "片手剣", 0x666666);
				DrawRotaGraph(650, 300, .45f, .0625f, sword_image, TRUE);

				DrawString(320, 450, "短剣", 0x666666);
				DrawRotaGraph(350, 300, .45f, .0625f, dagger_image, TRUE);

				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
			SetFontSize(16);
		}
		else
		{
			DrawRotaGraph(350 + cursor_x + image_shift, 600, .5f, 0, cursor_image, TRUE);

			SetFontSize(32);
			DrawString(430, 10, "２つ目の武器を選んでください\n", 0xffffff);


			if (cursor_num == 0)
			{
				DrawString(320, 450, "槍", 0xffffff);
				DrawRotaGraph(330, 300 + sin(M_PI * 2 / SCREEN_FPS * cnt) * 10, .45f, .0625f, spear_image, TRUE);

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);

				DrawString(580, 450, "フレイル", 0xffffff);
				DrawRotaGraph(690, 330, .45f, .2925f, frail_image, TRUE);

				DrawString(980, 450, "魔導書", 0xffffff);
				DrawRotaGraph(1030, 300, .45f, 0.f, book_image, TRUE);

				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
			else if (cursor_num == 1)
			{
				DrawString(580, 450, "フレイル", 0xffffff);
				DrawRotaGraph(690, 330 + sin(M_PI * 2 / SCREEN_FPS * cnt) * 10, .45f, .2925f, frail_image, TRUE);

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);

				DrawString(320, 450, "槍", 0xffffff);
				DrawRotaGraph(330, 300, .45f, .0625f, spear_image, TRUE);

				DrawString(980, 450, "魔導書", 0xffffff);
				DrawRotaGraph(1030, 300, .45f, 0.f, book_image, TRUE);

				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
			else
			{
				DrawString(980, 450, "魔導書", 0xffffff);
				DrawRotaGraph(1030, 300 + sin(M_PI * 2 / SCREEN_FPS * cnt) * 10, .45f, 0.f, book_image, TRUE);

				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);

				DrawString(580, 450, "フレイル", 0xffffff);
				DrawRotaGraph(690, 330, .45f, .2925f, frail_image, TRUE);

				DrawString(320, 450, "槍", 0xffffff);
				DrawRotaGraph(330, 300, .45f, .0625f, spear_image, TRUE);

				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
			SetFontSize(16);
		}
	}

	DrawGraph(1150, 650, button_image, TRUE);
	DrawString(1194, 662, "決定\n", 0xffffff);

}
