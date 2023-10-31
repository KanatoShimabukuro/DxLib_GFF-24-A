#include "scene_levelup.h"
#include"weapon.h"

WeaponLevelUp::WeaponLevelUp()
{
	test = 0;
	interval = 0;
	initial_cursor_position = 0;
	cursor_x = 320;
	cursor_y = 120;
	weapon_number = 1;
	weapon_selection = false;
	level_weapon1 = 0;
	level_weapon2 = 0;
}

WeaponLevelUp::~WeaponLevelUp()
{

}

// �X�V
void WeaponLevelUp::update(weapon* weapon)
{
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
	{
		test++;
	}

	// 15f�̃C���^�[�o��
	if (interval < 15)
	{
		interval++;
	}

	// ����̑I��
	if (weapon_selection == false)
	{
		//���X�e�B�b�N���E��
		if (InputCtrl::GetStickRatio(L).x > 0.8 && interval >= 15)
		{
			weapon_number++;
			interval = 0;

			if (weapon_number > 2)
			{
				weapon_number = 1;
			}
		}

		// A�{�^���őI��
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
		{
			cursor_y++;
			weapon_selection = true;
		}
	}
	else
	{
		if (weapon_number == 1)
		{
			// ����1
			// ���x���A�b�v
			if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
			{
				level_weapon1++;
				if (level_weapon1 >= MAX_LEVEL)
				{
					level_weapon1 = MAX_LEVEL;
				}
				// ���x���̃Z�b�g
				weapon->LevelUpDebug(level_weapon1);
			}
		}
		else
		{
			// ����2
			// ���x���A�b�v
			if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
			{
				level_weapon2++;
				if (level_weapon2 >= MAX_LEVEL)
				{
					level_weapon2 = MAX_LEVEL;
				}
			}

		}

		// B�{�^���őI�𕐊�̃L�����Z��
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
		{
			cursor_y--;
			weapon_selection = false;
		}

	}

}

// �`��
void WeaponLevelUp::draw() const
{
	DrawBox(0, 0, 960, 600, 0xa0a0a0, TRUE);
	SetFontSize(30);
	DrawFormatString(100, 300, 0x000000, "���x���A�b�v");

	// �e�X�g�\��
	SetFontSize(20);
	DrawFormatString(0, 0, 0x000000, "X�{�^���F����");
	DrawFormatString(0, 20, 0x000000, "A�{�^���F���Z");
	DrawFormatString(0, 40, 0x000000, "B�{�^���F�L�����Z��");
	DrawFormatString(0, 60, 0x000000, "test : %d", test);
	DrawFormatString(0, 80, 0x000000, "level1 : %d", level_weapon1);
	DrawFormatString(0, 100, 0x000000, "level2 : %d", level_weapon2);

	// �~��`��
	DrawCircle(cursor_x * weapon_number, cursor_y, 20, 0x000000, FALSE);

	// ����I���ς�
	if (weapon_selection == true)
	{
		if (weapon_number == 1)
		{
			// ����1
			// ���x���I���̉~��`��
			DrawCircle(cursor_x * weapon_number, cursor_y + 100 + (50 * level_weapon1), 20, 0xff0000, FALSE);
		}
		else
		{
			// ����2
			// ���x���I���̉~��`��
			DrawCircle(cursor_x * weapon_number, cursor_y + 100 + (50 * level_weapon2), 20, 0xff0000, FALSE);
		}
	}

}
