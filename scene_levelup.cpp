#include "scene_levelup.h"
#include"weapon.h"

WeaponLevelUp::WeaponLevelUp()
{
	// �摜�̓Ǎ�
	img_tree_diagram = LoadGraph("resources/images/levelup.png");
	img_cursor = LoadGraph("resources/images/levelup_cursor.png");
	img_choose = LoadGraph("resources/images/levelup_choose.png");			// ���ݖ��g�p
	img_sword = LoadGraph("resources/images/sword_longsword_brown.png");
	img_dagger= LoadGraph("resources/images/sword_shortsword_brown.png");
	img_great_sword = LoadGraph("resources/images/tsurugi_bronze_blue.png");

	// �ϐ��̏�����
	interval = 0;
	cursor_x = 580;
	cursor_y = 130;
	weapon_number = 1;
	weapon_selection = false;

	img_x = 580;
	weapon1_img_x = 580;
	weapon2_img_x = 960;

	cursor_pos = -70;
	weapon1_level_hierarchy = 0;
	weapon2_level_hierarchy = 0;

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
				cursor_x = 960;
				weapon_number++;
				interval = 0;

				if (weapon_number > MAX_WEAPON)
				{
					cursor_x = 580;
					weapon_number = 1;
				}
			}
			else if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
			{
				//���X�e�B�b�N������
				cursor_x = 960;
				weapon_number--;
				interval = 0;

				if (weapon_number < 1)
				{
					cursor_x = 580;
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

		if (weapon_number == 1 && weapon1_level_hierarchy != MAX_LEVEL_HIERARCHY)
		{
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
					// ���`�}�̍���I��
					weapon1_level++;
				}
				else
				{
					// ���`�}�̉E��I��
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

		if (weapon_number == 2 && weapon2_level_hierarchy != MAX_LEVEL_HIERARCHY)
		{
			// ����2
			// ���x���A�b�v
			if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
			{
				weapon2_level_hierarchy++;
				// ���x���K�w�̐���
				if (weapon2_level_hierarchy > MAX_LEVEL_HIERARCHY)
				{
					weapon2_level_hierarchy = MAX_LEVEL_HIERARCHY;
				}

				if (cursor_pos == -70)
				{
					// ���`�}�̍���I��
					weapon2_level++;
				}
				else
				{
					// ���`�}�̉E��I��
					weapon2_level += 2;
				}

				// ���x���̐���
				//if (weapon2_level > MAX_LEVEL)
				//{
				//	weapon2_level = MAX_LEVEL;
				//}
				// ����Ƀ��x���̃Z�b�g
				//weapon->SetWeaponLevel(weapon2_level);
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
	DrawBox(160, 10, 1120, 710, 0xa0a0a0, TRUE);

	SetFontSize(30);
	DrawFormatString(560, 10, 0x000000, "���x���A�b�v");

	// �e�X�g�\��
	SetFontSize(20);
	DrawFormatString(160, 10, 0x000000, "X�{�^���F����");
	DrawFormatString(160, 30, 0x000000, "A�{�^���F���Z");
	DrawFormatString(160, 50, 0x000000, "B�{�^���F�L�����Z��");
	DrawFormatString(160, 70, 0x000000, "level1 : %d", weapon1_level);
	DrawFormatString(160, 90, 0x000000, "����1���x���K�w : %d", weapon1_level_hierarchy);
	DrawFormatString(160, 110, 0x000000, "level2 : %d", weapon2_level);
	DrawFormatString(160, 130, 0x000000, "����2���x���K�w : %d", weapon2_level_hierarchy);

	// ���x���A�b�v�̏ڍטg
	DrawBox(180, 100, 420, 680, 0x000000, FALSE);
	DrawFormatString(200, 400, 0x000000, "���x���A�b�v�ڍ�");

	// ����1�̉摜
	switch (weapon1_type)
	{
		case sword:			// �Ў茕
			DrawRotaGraph(img_x, cursor_y, 0.2f, 0.0f, img_sword, TRUE);
			DrawFormatString(460, 60, 0x000000, "�Ў茕");
			break;
		case dagger:		// �Z��
			DrawRotaGraph(img_x, cursor_y, 0.2f, 0.0f, img_dagger, TRUE);
			DrawFormatString(460, 60, 0x000000, "�Z��");
			break;
		case greatSword:	// �匕
			DrawRotaGraph(img_x, cursor_y, 0.2f, 0.0f, img_great_sword, TRUE);
			DrawFormatString(460, 60, 0x000000, "�匕");
			break;
		default:
			DrawFormatString(img_x, cursor_y, 0x000000, "none");
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
			DrawFormatString(img_x + 380, cursor_y, 0x000000, "none");
			break;
	}

	// ����1�A����2�X�L���c���[�\��
	DrawRotaGraph(img_x, 400, 1.0f, 0.0f, img_tree_diagram, TRUE);
	DrawRotaGraph(img_x + 380, 400, 1.0f, 0.0f, img_tree_diagram, TRUE);

	// ����I��p�̉~��`��
	DrawCircle(cursor_x , cursor_y, 20, 0x000000, FALSE);

	// ����I���ς�
	if (weapon_selection == true)
	{
		if (weapon_number == 1)
		{
			if (weapon1_level_hierarchy == MAX_LEVEL_HIERARCHY)
			{
				//DrawFormatString(500, 650, 0xb00000, "�ŉ��w�ł�");
				DrawFormatString(500, 670, 0xb00000, "���͍ŏI�����ł�");
			}

			// ����1
			// ���x���I���̉~��`��
			DrawCircle(cursor_x + cursor_pos, cursor_y + 100 + (50 * (weapon1_level_hierarchy + 1)), 20, 0xb00000, FALSE);
			// �J�[�\���\��
			DrawRotaGraph(cursor_x + cursor_pos, cursor_y + 100 + (50 * (weapon1_level_hierarchy + 1)), 0.1f, 0.0f, img_cursor, TRUE);
		}
		else
		{
			//if (weapon2_type == NONE_WEAPON)
			//{
			//	DrawFormatString(600, 50, 0x000000, "���킪����܂���");
			//}
			//else
			//{
				if (weapon2_level_hierarchy == MAX_LEVEL_HIERARCHY)
				{
					//DrawFormatString(250, 650, 0xb00000, "�ŉ��w�ł�");
					DrawFormatString(660, 670, 0xb00000, "���͍ŏI�����ł�");
				}
				// ����2
				// ���x���I���̉~��`��
				DrawCircle(cursor_x + cursor_pos, cursor_y + 100 + (50 * (weapon2_level_hierarchy + 1)), 20, 0xb00000, FALSE);

		//	}
		}
	}
}