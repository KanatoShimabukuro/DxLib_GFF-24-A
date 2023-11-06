#include "scene_levelup.h"
#include"weapon.h"

WeaponLevelUp::WeaponLevelUp()
{
	// �摜�̓Ǎ�
	img_tree_diagram = LoadGraph("resources/images/levelup.png");
	img_cursor = LoadGraph("resources/images/levelup_cursor.png");
	img_choose = LoadGraph("resources/images/levelup_choose.png");
	img_sword = LoadGraph("resources/images/sword_longsword_brown.png");
	img_dagger= LoadGraph("resources/images/sword_shortsword_brown.png");
	img_great_sword = LoadGraph("resources/images/tsurugi_bronze_blue.png");

	// �ϐ��̏�����
	interval = 0;
	cursor_x = 580;
	cursor_y = 120;
	point = 10;
	weapon_number = 1;
	weapon_selection = false;

	img_x = 580;
	img_y = 140;

	cursor_pos = 0;

	weapon1_cursor_pos = 0;
	weapon2_cursor_pos = 0;
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
				cursor_x = 580;
				weapon_number--;
				interval = 0;

				if (weapon_number < 1)
				{
					cursor_x = 960;
					weapon_number = 2;
				}
			}
		//}

		// A�{�^���Ō���
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
		{
			weapon_selection = true;
		}
	}
	else
	{
		// ����1�̃��x���A�b�v
		if (weapon_number == 1)
		{
			// ���x���A�b�v
			if (weapon1_level_hierarchy != MAX_LEVEL_HIERARCHY && InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS && point > 0)
			{
				point--;
				weapon1_level_hierarchy++;
				// ���x���K�w�̐���
				if (weapon1_level_hierarchy > MAX_LEVEL_HIERARCHY)
				{
					weapon1_level_hierarchy = MAX_LEVEL_HIERARCHY;
				}

				if (weapon1_cursor_pos == CURSOR_LEFT)
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

			// ����1�̃��x���J�[�\���ړ�
			if (weapon1_level_hierarchy == 0 || weapon1_level_hierarchy == 3)
			{
				// �J�[�\���ړ�����
				weapon1_cursor_pos = 0;
			}
			else if (weapon1_level_hierarchy == 1 || weapon1_level_hierarchy == 4)
			{
				if (weapon1_cursor_pos == 0)
				{
					// ���x���̑I�����ł���Ƃ��J�[�\�������ʒu�͍�
					weapon1_cursor_pos = CURSOR_LEFT;
				}

				// ���x���̑I��
				if (InputCtrl::GetStickRatio(L).x > 0.8 && interval >= 15)
				{
					//���X�e�B�b�N���E��
					weapon1_cursor_pos = CURSOR_RIGHT;
				}
				else if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
				{
					//���X�e�B�b�N������
					weapon1_cursor_pos = CURSOR_LEFT;
				}
			}
		}
		else if (weapon_number == 2)
		{
			// ���x���A�b�v
			if (weapon2_level_hierarchy != MAX_LEVEL_HIERARCHY && InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS && point > 0)
			{
				point--;
				weapon2_level_hierarchy++;
				// ���x���K�w�̐���
				if (weapon2_level_hierarchy > MAX_LEVEL_HIERARCHY)
				{
					weapon2_level_hierarchy = MAX_LEVEL_HIERARCHY;
				}

				if (cursor_pos == CURSOR_LEFT)
				{
					// ���`�}�̍���I��
					weapon2_level++;
				}
				else
				{
					// ���`�}�̉E��I��
					weapon2_level += 2;
				}

				// ����Ƀ��x���̃Z�b�g
				//weapon->SetWeaponLevel(weapon2_level);
			}

			// ����2�̃��x���J�[�\���ړ�
			if (weapon2_level_hierarchy == 0 || weapon2_level_hierarchy == 3)
			{
				// �J�[�\���ړ�����
				weapon2_cursor_pos = 0;
			}
			else if (weapon2_level_hierarchy == 1 || weapon2_level_hierarchy == 4)
			{
				if (weapon2_cursor_pos == 0)
				{
					// ���x���̑I�����ł���Ƃ��J�[�\�������ʒu�͍�
					weapon2_cursor_pos = CURSOR_LEFT;
				}

				// ���x���̑I��
				if (InputCtrl::GetStickRatio(L).x > 0.8 && interval >= 15)
				{
					//���X�e�B�b�N���E��
					weapon2_cursor_pos = CURSOR_RIGHT;
				}
				else if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
				{
					//���X�e�B�b�N������
					weapon2_cursor_pos = CURSOR_LEFT;
				}
			}
		}

		// B�{�^���őI�𕐊�̃L�����Z��
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
		{
			if (weapon1_level_hierarchy == 1 || weapon1_level_hierarchy == 4)
			{
				weapon1_cursor_pos = CURSOR_LEFT;
			}

			if (weapon2_level_hierarchy == 1 || weapon2_level_hierarchy == 4)
			{
				weapon2_cursor_pos = CURSOR_LEFT;
			}

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
	DrawFormatString(160, 10, 0x000000, "level1(State?) : %d", weapon1_level);
	DrawFormatString(160, 30, 0x000000, "����1���x���K�w : %d", weapon1_level_hierarchy);
	DrawFormatString(160, 50, 0x000000, "level2 (State?): %d", weapon2_level);
	DrawFormatString(160, 70, 0x000000, "����2���x���K�w : %d", weapon2_level_hierarchy);
	DrawFormatString(160, 90, 0x000000, "cursor_x : %d", cursor_x);
	DrawFormatString(160, 110, 0x000000, "cursor_pos : %d", cursor_pos);
	DrawFormatString(160, 130, 0x000000, "weapon1_cursor_pos : %d", weapon1_cursor_pos);
	DrawFormatString(160, 150, 0x000000, "weapon2_cursor_pos : %d", weapon2_cursor_pos);

	// �J�[�\���ʒuY�m�F�p
	//DrawFormatString(160, 190, 0x000000, "�����ʒucursor_y : %d", cursor_y);
	//DrawFormatString(160, 210, 0x000000, "�����ʒu����̋��� : %d", 95 * (weapon1_level_hierarchy + 1));
	//DrawFormatString(160, 230, 0x000000, "cursor_y���ݒn : %d", cursor_y + (90 * (weapon1_level_hierarchy + 1)));
	
	DrawFormatString(1000, 20, 0x000000, "P�F%d", point);

	// ���x���A�b�v�̏ڍטg
	//DrawBox(190, 90, 420, 680, 0x000000, FALSE);
	//DrawFormatString(200, 100, 0x000000, "���x���A�b�v�ڍ�");
	//DrawFormatString(200, 120, 0x000000, "��j");
	//DrawFormatString(200, 140, 0x000000, "�_���[�W�@15�@���@20 (+5)");
	//DrawFormatString(200, 160, 0x000000, "�U�����x�@10�@���@15 (+5)");
	//DrawFormatString(200, 180, 0x000000, "�v���C���[�X�e�[�^�X");
	//DrawFormatString(200, 200, 0x000000, "�̗́@30");
	//DrawFormatString(200, 220, 0x000000, "�ړ����x�@30");

	// ����1�̉摜
	switch (weapon1_type)
	{
		case sword:			// �Ў茕
			DrawRotaGraph(img_x, img_y, 0.2f, 0.0f, img_sword, TRUE);
			DrawFormatString(200, 360, 0x000000, "�Ў茕");
			break;
		case dagger:		// �Z��
			DrawRotaGraph(img_x, img_y, 0.18f, 0.0f, img_dagger, TRUE);
			DrawFormatString(200, 360, 0x000000, "�Z��");
			break;
		case greatSword:	// �匕
			DrawRotaGraph(img_x, img_y, 0.2f, 0.0f, img_great_sword, TRUE);
			DrawFormatString(200, 360, 0x000000, "�匕");
			break;
		default:
			DrawFormatString(img_x, img_y, 0x000000, "none");
			break;
	}

	// ����2�̉摜
	switch (weapon2_type)
	{
		case 0:
			//DrawRotaGraph(cursor_x * 2, img_y, 0.2f, 0.0f, img_sword, TRUE);
			break;
		case 1:
			//DrawRotaGraph(cursor_x * 2, img_y, 0.2f, 0.0f, img_dagger, TRUE);
			break;
		case 2:
			//DrawRotaGraph(cursor_x * 2, img_y, 0.2f, 0.0f, img_great_sword, TRUE);
			break;
		default:
			DrawFormatString(img_x + 360, img_y, 0x000000, "none");
			break;
	}

	// ����1�A����2�X�L���c���[�\��
	DrawRotaGraph(img_x, img_y + 300, 1.0f, 0.0f, img_tree_diagram, TRUE);
	DrawRotaGraph(img_x + 380, img_y + 300, 1.0f, 0.0f, img_tree_diagram, TRUE);

	// ����I��p�̉~��`��
	//DrawCircle(cursor_x , cursor_y, 20, 0x000000, FALSE);

	if (weapon_selection == false)
	{
		DrawRotaGraph(cursor_x, cursor_y - 50, 0.08f, 0.0f, img_cursor, TRUE);
	}

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
			else if (point <= 0)
			{
				DrawFormatString(170, 670, 0xb00000, "�|�C���g������܂���");
			}

			// ����1
			// ���x���I���̉~��`��
			DrawCircle(cursor_x + weapon1_cursor_pos, cursor_y + 48 + (90 * (weapon1_level_hierarchy + 1)), 20, 0xb00000, TRUE);
			// �J�[�\���\��
			DrawRotaGraph(cursor_x + weapon1_cursor_pos, cursor_y + (90 * (weapon1_level_hierarchy + 1)), 0.08f, 0.0f, img_cursor, TRUE);
			// �ۉ摜�\��
			//DrawRotaGraph(cursor_x + weapon1_cursor_pos, cursor_y + 47 + (90 * (weapon1_level_hierarchy + 1)), 0.09f, 0.0f, img_choose, TRUE);
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
					DrawFormatString(900, 670, 0xb00000, "���͍ŏI�����ł�");
				}
				else if (point <= 0)
				{
					DrawFormatString(170, 670, 0xb00000, "�|�C���g������܂���");
				}

				// ����2
				// ���x���I���̉~��`��
				DrawCircle(cursor_x + weapon2_cursor_pos, cursor_y + (90 * (weapon2_level_hierarchy + 1)), 20, 0xb00000, FALSE);
				DrawRotaGraph(cursor_x + weapon2_cursor_pos, cursor_y + (90 * (weapon2_level_hierarchy + 1)), 0.08f, 0.0f, img_cursor, TRUE);

		//	}
		}
	}
}