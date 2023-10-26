#include"scene_weapon.h"
#include"inputCtrl.h"
#include"weapon.h"

Weapon_Selection::Weapon_Selection()
{
	interval = 0;
	cursor_num = 0;
	cursor_x = 0;

	sword_image = LoadGraph("resources/images/game_ken.png");
	cursor_image = LoadGraph("resources/images/computer_cursor_finger_black.png");

	is_selecting = false;
	was_selected = false;
}

Weapon_Selection::~Weapon_Selection()
{

}

void Weapon_Selection::update(weapon* _weapon, bool &is_weapon_select)
{
	//�P�T���̃C���^�[�o����݂���
	if (interval < INTERVAL)
	{
		interval++;
	}

	if (is_selecting != true)
	{
		cursor_x = cursor_num * 300;
	}
	else
	{
		cursor_x = cursor_num * 400;
	}

	//���X�e�B�b�N���E��
	if (InputCtrl::GetStickRatio(L).x > 0.8 && interval >= 15)
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
	if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
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
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
		{
			//�܂������I���������Ƃ��Ȃ��Ȃ�
			if (was_selected != true)
			{
				if (cursor_num == 0)
				{
					_weapon->SetWeaponType(dagger);
				}
				else if (cursor_num == 1)
				{
					_weapon->SetWeaponType(sword);
				}
				else
				{
					_weapon->SetWeaponType(greatSword);
				}
			}
			//�����I���������Ƃ�����Ȃ�
			else
			{
				if (cursor_num == 0)
				{
					//_weapon->SetWeaponType();
				}
				else if (cursor_num == 1)
				{
					//_weapon->SetWeaponType();
				}
				else
				{
					//_weapon->SetWeaponType();
				}
			}
			//�����I��������Ԃɂ���
			is_selecting = true;
			//�J�[�\�����u�͂��v�̈ʒu�ɂ���
			cursor_num = 0;
		}
	}
	//�����I�������Ȃ�
	else
	{
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
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
	}
}

void Weapon_Selection::draw() const
{
	//�����I�����Ă��Ȃ��Ȃ�
	if (is_selecting != true)
	{		
		DrawString(530, 10, "�ŏ��̕����I��ł�������\n",0xffffff);

		DrawRotaGraph(350, 300, .45f, .0625f, sword_image, TRUE);
		DrawRotaGraph(650, 300, .45f, .0625f, sword_image, TRUE);
		DrawRotaGraph(950, 300, .45f, .0625f, sword_image, TRUE);

		DrawRotaGraph(250 + cursor_x, 600, .5f, 0, cursor_image, TRUE);


	}
	//�����I�������Ȃ�
	else
	{		
		DrawString(530, 10, "���̕����I�т܂����H\n", 0xffffff);

		if (was_selected != true)
		{
			if (cursor_num == 0)
			{
				DrawRotaGraph(350, 300, .45f, .0625f, sword_image, TRUE);
			}
			else if (cursor_num == 1)
			{
				DrawRotaGraph(350, 300, .45f, .0625f, sword_image, TRUE);
			}
			else
			{
				DrawRotaGraph(350, 300, .45f, .0625f, sword_image, TRUE);
			}
		}
		else
		{
			if (cursor_num == 0)
			{
				DrawRotaGraph(350, 300, .45f, .0625f, sword_image, TRUE);
			}
			else if (cursor_num == 1)
			{
				DrawRotaGraph(350, 300, .45f, .0625f, sword_image, TRUE);
			}
			else
			{
				DrawRotaGraph(350, 300, .45f, .0625f, sword_image, TRUE);
			}
		}

		SetFontSize(64);

		DrawString(400, 600, "�͂�", 0xffffff);
		DrawString(800, 600, "������", 0xffffff);

		SetFontSize(16);

		DrawRotaGraph(320 + cursor_x, 640, .5f, 1.6f, cursor_image, TRUE);
	}
}
