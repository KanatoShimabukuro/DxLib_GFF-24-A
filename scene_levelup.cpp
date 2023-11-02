#include "scene_levelup.h"
#include"weapon.h"

WeaponLevelUp::WeaponLevelUp()
{
	// �摜�̓Ǎ�
	img_sword = LoadGraph("resources/images/sword_longsword_brown.png");
	img_dagger= LoadGraph("resources/images/sword_shortsword_brown.png");
	img_great_sword = LoadGraph("resources/images/tsurugi_bronze_blue.png");

	// �ϐ��̏�����
	interval = 0;
	cursor_x = 320;
	cursor_y = 120;
	weapon_number = 1;
	weapon_selection = false;

	cursor_pos = -70;
	weapon1_level_hierarchy = 0;

	// ����1
	weapon1_type = NONE_WEAPON;				// ��
	weapon1_level = 0;

	// ����2
	weapon2_type = NONE_WEAPON;				// ��
	weapon2_level = 0;
}

WeaponLevelUp::~WeaponLevelUp()
{

}

// �X�V
void WeaponLevelUp::update(weapon* weapon, bool& restor_cursor_position)
{
	// �J�[�\���̈ʒu�����ɖ߂�
	if (restor_cursor_position == true)
	{
		weapon_selection = false;
		weapon_number = 1;
		restor_cursor_position = false;
		// ���݂̕��탌�x���̃Z�b�g
		weapon1_level = weapon->GetWeaponLevel();
		// ����̎�ނ̃Z�b�g
		weapon1_type = weapon->GetWeaponType();
	}

	// 15f�̃C���^�[�o��
	if (interval < 15)
	{
		interval++;
	}

	// ����̑I��
	if (weapon_selection == false)
	{
		// �����2��ގ����Ă����畐��I�����ł���
		//if (weapon2_type != NONE_WEAPON)
		//{
			if (InputCtrl::GetStickRatio(L).x > 0.8 && interval >= 15)
			{
				//���X�e�B�b�N���E��
				weapon_number++;
				interval = 0;

				if (weapon_number > MAX_WEAPON)
				{
					weapon_number = 1;
				}
			}
			else if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
			{
				//���X�e�B�b�N������
				weapon_number--;
				interval = 0;

				if (weapon_number < 1)
				{
					weapon_number = 2;
				}
			}
		//}

		// A�{�^���Ō���
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
		{
			cursor_y++;
			weapon_selection = true;
		}
	}
	else
	{
		if (weapon1_level_hierarchy != MAX_LEVEL_HIERARCHY)
		{
			if (InputCtrl::GetStickRatio(L).x > 0.8 && interval >= 15)
			{
				//���X�e�B�b�N���E��
				cursor_pos = 70;
			}
			else if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
			{
				//���X�e�B�b�N������
				cursor_pos = -70;
			}

			// ���x���A�b�v
			if (weapon_number == 1)
			{
				// ����1
				// ���x���A�b�v
				if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
				{
					weapon1_level_hierarchy++;
					// ���x���K�w�̐���
					if (weapon1_level_hierarchy > MAX_LEVEL_HIERARCHY)
					{
						weapon1_level_hierarchy = MAX_LEVEL_HIERARCHY;
					}

					if (cursor_pos == -70)
					{
						weapon1_level++;
					}
					else
					{
						weapon1_level += 2;
					}

					// ���x���̐���
					//if (weapon1_level > MAX_LEVEL)
					//{
					//	weapon1_level = MAX_LEVEL;
					//}
					// ����Ƀ��x���̃Z�b�g
					weapon->SetWeaponLevel(weapon1_level);
				}
			}
			else
			{
				if (weapon2_type == NONE_WEAPON)
				{
					// ����2
					// ���x���A�b�v
					if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
					{
						weapon2_level++;
					
						// ���x���̐���
						//if (weapon2_level > MAX_LEVEL)
						//{
						//	weapon2_level = MAX_LEVEL;
						//}
						// ����Ƀ��x���̃Z�b�g
						//weapon->SetWeaponLevel(weapon2_level);
					}
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
	// �w�i
	DrawBox(0, 0, 960, 700, 0xa0a0a0, TRUE);

	SetFontSize(30);
	DrawFormatString(300, 0, 0x000000, "����ʁj���x���A�b�v");

	// �e�X�g�\��
	SetFontSize(20);
	DrawFormatString(0, 0, 0x000000, "X�{�^���F����");
	DrawFormatString(0, 20, 0x000000, "A�{�^���F���Z");
	DrawFormatString(0, 40, 0x000000, "B�{�^���F�L�����Z��");
	DrawFormatString(0, 60, 0x000000, "level1 : %d", weapon1_level);
	DrawFormatString(0, 80, 0x000000, "����1���x���K�w : %d", weapon1_level_hierarchy);
	//DrawFormatString(0, 100, 0x000000, "level2 : %d", weapon2_level);

	// ����1�̉摜
	switch (weapon1_type)
	{
		case sword:			// �Ў茕
			DrawRotaGraph(cursor_x, cursor_y, 0.2f, 0.0f, img_sword, TRUE);	
			DrawFormatString(300, 50, 0x000000, "�Ў茕");
			break;
		case dagger:		// �Z��
			DrawRotaGraph(cursor_x, cursor_y, 0.2f, 0.0f, img_dagger, TRUE);
			DrawFormatString(300, 50, 0x000000, "�Z��");
			break;
		case greatSword:	// �匕
			DrawRotaGraph(cursor_x, cursor_y, 0.2f, 0.0f, img_great_sword, TRUE);
			DrawFormatString(300, 50, 0x000000, "�匕");
			break;
		default:
			DrawFormatString(cursor_x, cursor_y, 0x000000, "none");
			break;
	}

	// ����2�̉摜
	switch (weapon2_type)
	{
		case 0:
			//DrawRotaGraph(cursor_x * 2, cursor_y, 0.2f, 0.0f, img_sword, TRUE);
			break;
		case 1:
			//DrawRotaGraph(cursor_x * 2, cursor_y, 0.2f, 0.0f, img_dagger, TRUE);
			break;
		case 2:
			//DrawRotaGraph(cursor_x * 2, cursor_y, 0.2f, 0.0f, img_great_sword, TRUE);
			break;
		default:
			DrawFormatString(cursor_x * 2, cursor_y, 0x000000, "none");
			break;
	}

	// ����I��p�̉~��`��
	DrawCircle(cursor_x * weapon_number, cursor_y, 20, 0x000000, FALSE);

	// ����I���ς�
	if (weapon_selection == true)
	{
		if (weapon_number == 1)
		{
			if (weapon1_level_hierarchy == MAX_LEVEL_HIERARCHY)
			{
				//DrawFormatString(250, 650, 0xb00000, "�ŉ��w�ł�");
				DrawFormatString(250, 670, 0xb00000, "���͍ŏI�����ł�");
			}

			// ����1
			// ���x���I���̉~��`��
			DrawCircle(cursor_x * weapon_number + cursor_pos, cursor_y + 100 + (50 * (weapon1_level_hierarchy + 1)), 20, 0xb00000, FALSE);
		}
		else
		{
			if (weapon2_type == NONE_WEAPON)
			{
				DrawFormatString(600, 50, 0x000000, "���킪����܂���");
			}
			else
			{
				//if (weapon2_level == MAX_LEVEL)
				//{
				//	DrawFormatString(250, 650, 0xb00000, "�ő僌�x���ł�");
				//	DrawFormatString(250, 670, 0xb00000, "���͍ŏI�����ł�");
				//}

				// ����2
				// ���x���I���̉~��`��
				DrawCircle(cursor_x * weapon_number, cursor_y + 100 + (50 * weapon2_level), 20, 0xb00000, FALSE);
			}
		}
	}
}
