#include"scene_weapon.h"
#include"second_weapon.h"
#include"main.h"

Weapon_Selection::Weapon_Selection(const bool selected)
{
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
	was_selected = selected;
}

Weapon_Selection::~Weapon_Selection()
{

}

void Weapon_Selection::update(weapon* _weapon, second_weapon* _second_weapon, bool& is_weapon_select)
{
	//�P�T���̃C���^�[�o����݂���
	if (interval < INTERVAL)
	{
		interval++;
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

	//���X�e�B�b�N���E��
	if ((InputCtrl::GetStickRatio(L).x > 0.8 || InputCtrl::GetButtonState(XINPUT_BUTTON_DPAD_RIGHT)) && interval >= 15)
	{
		cursor_num++;
		interval = 0;
		//�����I�����Ă��Ȃ��Ȃ�R�܂�
		if (is_selecting != true)
		{
			if (cursor_num >= SELECT_WEAPON)
			{
				cursor_num = 0;
			}
		}
		//�����I�������Ȃ�Q�܂�
		else
		{
			if (cursor_num > 1)
			{
				cursor_num = 0;
			}
		}
	}

	//���X�e�B�b�N������
	if ((InputCtrl::GetStickRatio(L).x < -0.8 || InputCtrl::GetButtonState(XINPUT_BUTTON_DPAD_LEFT)) && interval >= 15)
	{
		cursor_num--;
		interval = 0;
		//�����I�����Ă��Ȃ��Ȃ�R�܂�
		if (is_selecting != true)
		{
			if (cursor_num < 0)
			{
				cursor_num = SELECT_WEAPON - 1;
			}
		}
		//�����I�������Ȃ�Q�܂�
		else
		{
			if (cursor_num < 0)
			{
				cursor_num = 1;
			}
		}
	}

	//�����I�����Ă��Ȃ��Ȃ�
	if (is_selecting != true)
	{
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS || InputCtrl::GetKeyState(KEY_INPUT_SPACE) == PRESS)
		{
			//�܂������I���������Ƃ��Ȃ��Ȃ�
			if (was_selected != true)
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
			//�����I���������Ƃ�����Ȃ�
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
			//�����I��������Ԃɂ���
			is_selecting = true;
			//�J�[�\�����u�͂��v�̈ʒu�ɂ���
			cursor_num = 0;
			//����I����ʂ͂Ȃ�
			is_weapon_select = true;
		}
	}
	//�����I�������Ȃ�
	else
	{
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS || InputCtrl::GetKeyState(KEY_INPUT_SPACE) == PRESS)
 		{
			//�͂�
			if (cursor_num == 0)
			{
				is_weapon_select = true;
			}
			//������
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

void Weapon_Selection::draw() const
{

	DrawGraph(1150, 650, button_image, TRUE);
	DrawString(1194, 662, "����\n", 0xffffff);

	//�����I�����Ă��Ȃ��Ȃ�
	if (is_selecting != true)
	{		
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
		DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0x000000, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (was_selected != true)
		{
			SetFontSize(32);
			DrawString(430, 10, "�ŏ��̕����I��ł�������\n",0xffffff);

			DrawString(330, 450, "�Z��", 0xffffff);
			DrawString(600, 450, "�Ў茕", 0xffffff);
			DrawString(930, 450, "�匕", 0xffffff);

			SetFontSize(16);

			DrawRotaGraph(350, 300, .45f, .0625f, dagger_image, TRUE);
			DrawRotaGraph(650, 300, .45f, .0625f, sword_image, TRUE);
			DrawRotaGraph(950, 300, .45f, .0625f, great_sword_image, TRUE);

			DrawRotaGraph(380 + cursor_x, 600, .5f, 0, cursor_image, TRUE);
		}
		else
		{
			SetFontSize(32);
			DrawString(430, 10, "�Q�ڂ̕����I��ł�������\n", 0xffffff);

			DrawString(320, 450, "��", 0xffffff);
			DrawString(580, 450, "�t���C��", 0xffffff);
			DrawString(980, 450, "������", 0xffffff);

			SetFontSize(16);

			DrawRotaGraph(330, 300, .45f, .0625f, spear_image, TRUE);
			DrawRotaGraph(690, 330, .45f, .2925f, frail_image, TRUE);
			DrawRotaGraph(1030, 300, .45f, 0.f, book_image, TRUE);

			DrawRotaGraph(350 + cursor_x + image_shift, 600, .5f, 0, cursor_image, TRUE);
		}
	}
	//�����I�������Ȃ�
	else
	{		
		SetFontSize(32);
		DrawString(430, 10, "���̕����I�т܂����H\n", 0xffffff);

		if (was_selected != true)
		{
			if (select_num == 0)
			{
				DrawRotaGraph(350, 300, .45f, .0625f, dagger_image, TRUE);
				DrawString(350, 450, "�Z��", 0xffffff);
				DrawString(500, 200, "�G�ɗ^����_���[�W���Ⴂ\n", 0xffffff);
				DrawString(500, 250, "����U��̂�����\n", 0xffffff);
				DrawString(500, 300, "�N�[���^�C�����Z��\n", 0xffffff);
			}
			else if (select_num == 1)
			{
				DrawRotaGraph(350, 300, .45f, .0625f, sword_image, TRUE);
				DrawString(350, 450, "�Ў茕", 0xffffff);
			}
			else
			{
				DrawRotaGraph(350, 300, .45f, .0625f, great_sword_image, TRUE);
				DrawString(350, 450, "�匕", 0xffffff);
			}
		}
		else
		{
			if (select_num == 0)
			{
				DrawRotaGraph(350, 300, .45f, .0625f, sword_image, TRUE);
				DrawString(350, 450, "�Z��", 0xffffff);
			}
			else if (select_num == 1)
			{
				DrawRotaGraph(350, 300, .45f, .0625f, sword_image, TRUE);
				DrawString(350, 450, "�Z��", 0xffffff);
			}
			else
			{
				DrawRotaGraph(350, 300, .45f, .0625f, sword_image, TRUE);
				DrawString(350, 450, "�Z��", 0xffffff);
			}
		}

		SetFontSize(64);

		DrawString(400, 600, "�͂�", 0xffffff);
		DrawString(800, 600, "������", 0xffffff);

		SetFontSize(16);

		DrawRotaGraph(320 + cursor_x, 640, .5f, 1.6f, cursor_image, TRUE);
	}
}
