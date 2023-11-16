//#include "weaponLevelup.h"
#include "main.h"

WeaponLevelUp::WeaponLevelUp()
{
	// �摜�̓Ǎ�
	//img_tree_diagram = LoadGraph("resources/images/levelup.png");
	img_cursor = LoadGraph("resources/images/levelup_cursor.png");
	img_branch_point = LoadGraph("resources/images/branch_point.png");
	img_chooce = LoadGraph("resources/images/levelup_choose.png");

	// ����摜
	img_sword = LoadGraph("resources/images/sword_longsword_brown.png");
	img_dagger= LoadGraph("resources/images/sword_shortsword_brown.png");
	img_great_sword = LoadGraph("resources/images/tsurugi_bronze_blue.png");
	img_spear = LoadGraph("resources/images/spear.png");
	img_frail = LoadGraph("resources/images/Frailt_dottoy.png");
	img_book = LoadGraph("resources/images/tsurugi_bronze_blue.png");
	img_question_mark = LoadGraph("resources/images/mark_question.png");

	// �\���̏�����
	weapon1_info = { 0, none, 0, 0, 0 };
	weapon2_info = { 1, none, 0, 0, 0 };

	// �ϐ��̏�����
	interval = 0;
	cursor_x = 580;
	cursor_y = 120;
	level_cursor_pos = 85;
	point = 7;
	weapon_number = weapon1_info.num;
	weapon_selection = false;

	is_blacksmith = false;
	is_close_level_up = false;

	// �摜�p�����[�^
	img_x = 580;
	img_y = 140;
	img_branch_point_x = cursor_x;
	img_branch_point_y = 260;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			branch_point_x[i][j] = cursor_x;
			branch_point_y[i][j] = img_branch_point_y;
			is_chooce[i][j] = false;

		}
	}

}

WeaponLevelUp::~WeaponLevelUp()
{

}

// �X�V
void WeaponLevelUp::update(weapon* weapon, second_weapon* second_weapon, bool& restor_cursor_position)
{
	// �J�[�\���̈ʒu�����ɖ߂�
	if (restor_cursor_position == true)
	{
		// ������
		Init(weapon, second_weapon, restor_cursor_position);
	}

	// 15f�̃C���^�[�o��
	if (interval < 15)
	{
		interval++;
	}

	// ����̑I��
	if (weapon_selection == false)
	{
		// �b��X�e�[�W�Ŏg�p
		is_close_level_up = true;

		// �����2��ގ����Ă����畐��I�����ł���
		//if (weapon2_info.type != none)
		//{
			if (InputCtrl::GetStickRatio(L).x > 0.8 && interval >= 15)
				{
				//���X�e�B�b�N���E��
				interval = 0;
				cursor_x = 960;
				weapon_number = weapon2_info.num;
				//weapon_number++;

				//if (weapon_number > weapon2_info.num)
				//{
				//	cursor_x = 580;
				//	weapon_number = weapon1_info.num;
				//}
			}
			else if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
			{
				//���X�e�B�b�N������
				interval = 0;
				cursor_x = 580;
				weapon_number = weapon1_info.num;

				//weapon_number--;

				//if (weapon_number < weapon1_info.num)
				//{
				//	cursor_x = 960;
				//	weapon_number = weapon2_info.num;
				//}
			}
		//}

		// A�{�^���Ō���
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
		{
			// ����2��none�������畐��2�̑I������͕s��
			// ����ȊO�̏ꍇ�͑I������\
			if (cursor_x == 580 || weapon2_info.type != none)
			{
				weapon_selection = true;
			}
		}
	}
	else
	{
		// �b��X�e�[�W�Ŏg�p
		is_close_level_up = false;

		if (weapon_number == weapon1_info.num)
		{
			if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
			{
				// ����1�̃��x���A�b�v
				LevelUp(weapon, second_weapon, &weapon1_info);
			}

			// �J�[�\���ړ�
			LevelUpCursorMove(&weapon1_info);
		}
		else
		{
			if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
			{
				// ����2�̃��x���A�b�v
				LevelUp(weapon, second_weapon, &weapon2_info);
			}

			// �J�[�\���ړ�
			LevelUpCursorMove(&weapon2_info);
		}

		// B�{�^���őI�𕐊�̃L�����Z��
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
		{
			// ���x���J�[�\���̈ʒu����
			if (weapon_number == weapon1_info.num)
			{
				ReturnLevelUpCursorPos(&weapon1_info);
			}
			else
			{
				ReturnLevelUpCursorPos(&weapon2_info);
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
	//DrawFormatString(160, 10, 0x000000, "W1level(State) : %d", weapon1_info.level);
	//DrawFormatString(160, 30, 0x000000, "W1���x���K�w : %d", weapon1_info.level_hierarchy);
	//DrawFormatString(160, 50, 0x000000, "W2level (State): %d", weapon2_info.level);
	//DrawFormatString(160, 70, 0x000000, "W2���x���K�w : %d", weapon2_info.level_hierarchy);
	DrawFormatString(160, 50, 0x000000, "1cursor_pos : %d", weapon1_info.cursor_pos);
	DrawFormatString(160, 70, 0x000000, "2cursor_pos : %d", weapon2_info.cursor_pos);
	//DrawFormatString(160, 30, 0x000000, "level_cursor_pos : %d", level_cursor_pos);

	DrawFormatString(1000, 20, 0x000000, "���jP�F%d", point);
	
	// ���x���A�b�v�ڍׂ̃e�L�X�g�Q
	DrawLevelUpDetails();

	// ����1�̉摜
	switch (weapon1_info.type)
	{
		case sword:			// �Ў茕
			DrawRotaGraph(img_x, img_y, 0.2f, 0.0f, img_sword, TRUE);
			break;
		case dagger:		// �Z��
			DrawRotaGraph(img_x, img_y, 0.18f, 0.0f, img_dagger, TRUE);
			break;
		case greatSword:	// �匕
			DrawRotaGraph(img_x, img_y, 0.2f, 0.0f, img_great_sword, TRUE);
			break;
		default:
			//DrawRotaGraph(img_x, img_y, 0.1f, 0.0f, img_question_mark, TRUE);
			//DrawFormatString(img_x, img_y, 0x000000, "none");
			break;
	}

	// ����2�̉摜
	switch (weapon2_info.type)
	{
		case spear:			// ��
			DrawRotaGraph(img_x + 380, img_y, 0.2f, 0.0f, img_spear, TRUE);
			break;
		case frail:			// �t���C��
			DrawRotaGraph(img_x + 380, img_y, 0.2f, 0.0f, img_frail, TRUE);
			break;
		case book:			// �{
			DrawRotaGraph(img_x + 380, img_y, 0.2f, 0.0f, img_book, TRUE);
			break;
		default:
			DrawRotaGraph(img_x + 380, img_y, 0.1f, 0.0f, img_question_mark, TRUE);
			//DrawFormatString(img_x + 360, img_y, 0x000000, "none");
			break;
	}
	
	// �X�L���c���[����_�摜�̕\��
	for (int i = 0; i <= MAX_LEVEL_HIERARCHY; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			// ���x���K�w�ɂ���ĕ���
			if (i == 0 || i == 3)
			{
				DrawRotaGraph(img_branch_point_x + 380 * j, img_branch_point_y + LEVEL_HIERARCHY_HEIGHT * i, 0.08f, 0.0f, img_branch_point, TRUE);
			}
			else
			{
				DrawRotaGraph(img_branch_point_x + level_cursor_pos + 380 * j, img_branch_point_y + LEVEL_HIERARCHY_HEIGHT * i, 0.08f, 0.0f, img_branch_point, TRUE);
				DrawRotaGraph(img_branch_point_x - level_cursor_pos + 380 * j, img_branch_point_y + LEVEL_HIERARCHY_HEIGHT * i, 0.08f, 0.0f, img_branch_point, TRUE);
			}
		}
	}

	// �I���������x���ɉ摜�̕\��
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j <= MAX_LEVEL_HIERARCHY; j++)
		{
			if (is_chooce[i][j] == true)
			{
				DrawRotaGraph(branch_point_x[i][j], branch_point_y[i][j], 0.1f, 0.0f, img_chooce, TRUE);
			}
		}
	}

	// ����I��p�̉~��`��
	//DrawCircle(cursor_x , cursor_y, 20, 0x000000, FALSE);
	
	// ����I���J�[�\��
	if (weapon_selection == false)
	{
		DrawRotaGraph(cursor_x, cursor_y - 50, 0.08f, 0.0f, img_cursor, TRUE);
	}
	else
	{
		// ����I���ς�
		if (weapon_number == weapon1_info.num)
		{
			// ����1
			if(weapon1_info.level_hierarchy <= MAX_LEVEL_HIERARCHY)
			{
				// �J�[�\���\��
				DrawRotaGraph(cursor_x + weapon1_info.cursor_pos, cursor_y + (LEVEL_HIERARCHY_HEIGHT * (weapon1_info.level_hierarchy + 1)), 0.08f, 0.0f, img_cursor, TRUE);
				// ���x���I���̉~��`��
				//DrawCircle(cursor_x + weapon1_info.cursor_pos, cursor_y + 50 + (LEVEL_HIERARCHY_HEIGHT * (weapon1_info.level_hierarchy + 1)), 20, 0xb00000, FALSE);
				// �ۉ摜�\��
				//DrawRotaGraph(cursor_x + weapon1_cursor_pos, cursor_y + 50 + (LEVEL_HIERARCHY_HEIGHT * (weapon1_level_hierarchy + 1)), 0.1f, 0.0f, img_chooce, TRUE);
			}
		}
		else
		{
			// ����2
			if (weapon2_info.level_hierarchy <= MAX_LEVEL_HIERARCHY)
			{
				// �J�[�\���\��
				DrawRotaGraph(cursor_x + weapon2_info.cursor_pos, cursor_y + (LEVEL_HIERARCHY_HEIGHT * (weapon2_info.level_hierarchy + 1)), 0.08f, 0.0f, img_cursor, TRUE);

				// ���x���I���̉~��`��
				//DrawCircle(cursor_x + weapon2_info.cursor_pos, cursor_y + 50 + (LEVEL_HIERARCHY_HEIGHT * (weapon2_info.level_hierarchy + 1)), 20, 0xb00000, FALSE);
			}
		}
	}

}

// ����������
void WeaponLevelUp::Init(weapon* weapon, second_weapon* second_weapon, bool& restor_cursor_position)
{
	// ����I�����ϐ�
	weapon_selection = false;
	cursor_x = 580;
	weapon_number = weapon1_info.num;

	// ���x���A�b�v�J�[�\���̏�����
	if (weapon1_info.level_hierarchy == 1 || weapon1_info.level_hierarchy == MAX_LEVEL_HIERARCHY)
	{
		// �J�[�\���ʒu�͍�
		weapon1_info.cursor_pos = -level_cursor_pos;
	}
	else if (weapon2_info.level_hierarchy == 1 || weapon2_info.level_hierarchy == MAX_LEVEL_HIERARCHY)
	{		
		// �J�[�\���ʒu�͍�
		weapon2_info.cursor_pos = -level_cursor_pos;
	}

	// ���݂̕��탌�x���̃Z�b�g
	weapon1_info.level = weapon->GetWeaponLevel();
	weapon2_info.level = second_weapon->GetWeaponLevel();

	// ����̎�ނ̃Z�b�g
	weapon1_info.type = weapon->GetWeaponType();
	weapon2_info.type = second_weapon->GetWeaponType();

	// ����������
	restor_cursor_position = false;
}

// ���x���A�b�v����
void WeaponLevelUp::LevelUp(weapon* weapon, second_weapon* second_weapon, weapon_information* info)
{
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
	{
		if (info->level_hierarchy < MAX_LEVEL_HIERARCHY && point > 0)
		{
			// �ʏ�̃��x���A�b�v
			point--;

			// ���x���A�b�v
			switch (info->level_hierarchy)
			{
			case 0:
				info->level++;
				break;
			case 1:
			case 4:
				if (info->cursor_pos == -level_cursor_pos)
				{
					// ���`�}�̍���I��
					info->level++;
				}
				else
				{
					// ���`�}�̉E��I��
					info->level += 2;
				}
				break;
			case 2:
				info->level += 2;
				break;
			case 3:
				info->level = 6;
			default:
				break;
			}

			// �I����������_�̉摜�p�p�����[�^�̍X�V
			is_chooce[info->num][info->level_hierarchy] = true;
			branch_point_y[info->num][info->level_hierarchy] += LEVEL_HIERARCHY_HEIGHT * info->level_hierarchy;

			if (info->num == weapon1_info.num)
			{
				// �摜�p�p�����[�^x�̍X�V
				branch_point_x[info->num][info->level_hierarchy] += info->cursor_pos;

				// ����1�Ƀ��x���̃Z�b�g
				weapon->SetWeaponLevel(info->level);
			}
			else
			{
				// �摜�p�p�����[�^x�̍X�V
				branch_point_x[info->num][info->level_hierarchy] += 380 + info->cursor_pos;

				// ����2�Ƀ��x���̃Z�b�g
				second_weapon->SetWeaponLevel(info->level);
			}

			info->level_hierarchy++;
			//// ���x���K�w�̐���
			//if (info->level_hierarchy > MAX_LEVEL_HIERARCHY)
			//{
			//	info->level_hierarchy = MAX_LEVEL_HIERARCHY;
			//}

		}
		else if (info->level_hierarchy == MAX_LEVEL_HIERARCHY && is_blacksmith == true)
		{
			// �ŏI����

			//// �I����������_�̉摜�p�p�����[�^�̍X�V
			//is_chooce[info->num][info->level_hierarchy] = true;
			//branch_point_x[info->num][info->level_hierarchy] += info->cursor_pos;
			//branch_point_y[info->num][info->level_hierarchy] += LEVEL_HIERARCHY_HEIGHT * info->level_hierarchy;

			if (info->cursor_pos == -level_cursor_pos)
			{
				// ���`�}�̍���I��
				info->level = 7;
			}
			else
			{
				// ���`�}�̉E��I��
				info->level = 8;
			}

			// �I����������_�̉摜�p�p�����[�^�̍X�V
			is_chooce[info->num][info->level_hierarchy] = true;
			branch_point_y[info->num][info->level_hierarchy] += LEVEL_HIERARCHY_HEIGHT * info->level_hierarchy;

			if (info->num == weapon1_info.num)
			{
				// �摜�p�p�����[�^x�̍X�V
				branch_point_x[info->num][info->level_hierarchy] += info->cursor_pos;

				// ����1�Ƀ��x���̃Z�b�g
				weapon->SetWeaponLevel(info->level);
			}
			else
			{
				// �摜�p�p�����[�^x�̍X�V
				branch_point_x[info->num][info->level_hierarchy] += 380 + info->cursor_pos;

				// ����2�Ƀ��x���̃Z�b�g
				second_weapon->SetWeaponLevel(info->level);
			}

			info->level_hierarchy++;

			//// ����Ƀ��x���̃Z�b�g
			//if (info->num == weapon1)
			//{
			//	weapon->SetWeaponLevel(info->level);
			//}
			//else if (info->num == weapon2)
			//{
			//	second_weapon->SetWeaponLevel(info->level);
			//}

			info->cursor_pos = 0;

		}
	}
}

// ���x���A�b�v�̃J�[�\���ړ�
void WeaponLevelUp::LevelUpCursorMove(weapon_information* info)
{
	// ����1�̃��x���J�[�\���ړ�
	if (info->level_hierarchy == 0 || info->level_hierarchy == 3)
	{
		// �J�[�\���ړ�����
		info->cursor_pos = 0;
	}
	else if (info->level_hierarchy == 1 || info->level_hierarchy == MAX_LEVEL_HIERARCHY)
	{
		if (info->cursor_pos == 0)
		{
			// ���x���̑I�����ł���Ƃ��J�[�\�������ʒu�͍�
			info->cursor_pos = -level_cursor_pos;
		}

		// ���x���̑I��
		if (InputCtrl::GetStickRatio(L).x > 0.8 && interval >= 15)
		{
			//���X�e�B�b�N���E��
			info->cursor_pos = level_cursor_pos;
		}
		else if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
		{
			//���X�e�B�b�N������
			info->cursor_pos = -level_cursor_pos;
		}
	}

}

// ���x���A�b�v�J�[�\���̈ʒu��߂�
void WeaponLevelUp::ReturnLevelUpCursorPos(weapon_information* info)
{
	if (info->level_hierarchy == 1 || info->level_hierarchy == MAX_LEVEL_HIERARCHY)
	{
		// ���x���A�b�v�J�[�\���̈ʒu�����ɂ���
		info->cursor_pos = -level_cursor_pos;
	}

}

// ���x���A�b�v�ڍׂ̃e�L�X�g�Q
void WeaponLevelUp::DrawLevelUpDetails() const
{
	// ���x���A�b�v�̏ڍטg
	DrawBox(190, 90, 420, 680, 0x000000, FALSE);

	// �e�L�X�g
	DrawFormatString(200, 160, 0x000000, "���x���A�b�v�ڍ�");
	DrawFormatString(200, 180, 0x000000, "��j");
	DrawFormatString(200, 200, 0x000000, "�_���[�W");
	DrawFormatString(200, 220, 0x000000, "�@15�@���@20 (+5)");
	DrawFormatString(200, 240, 0x000000, "�U�����x");
	DrawFormatString(200, 280, 0x000000, "�@10�@���@15 (+5)");
	DrawFormatString(200, 340, 0x000000, "�v���C���[�X�e�[�^�X");
	DrawFormatString(200, 360, 0x000000, "�̗�");
	DrawFormatString(200, 380, 0x000000, "�@        30");
	DrawFormatString(200, 400, 0x000000, "�ړ����x");
	DrawFormatString(200, 420, 0x000000, "�@        30");

	// �ڍטg�̒���
	//DrawBox(190, 240, 420, 680, 0xff0000, FALSE);

	// ���햼�̕\��
	if (cursor_x == 580)
	{
		switch (weapon1_info.type)
		{
		case sword:			// �Ў茕
			DrawFormatString(200, 100, 0x000000, "�Ў茕");
			break;
		case dagger:		// �Z��
			DrawFormatString(200, 100, 0x000000, "�Z��");
			break;
		case greatSword:	// �匕
			DrawFormatString(200, 100, 0x000000, "�匕");
			break;
		default:
			DrawFormatString(200, 100, 0xb00000, "���킪����܂���");
			break;
		}
	}
	else
	{
		switch (weapon2_info.type)
		{
		case 0:
			DrawFormatString(200, 100, 0x000000, "��");
			break;
		case 1:
			DrawFormatString(200, 100, 0x000000, "�t���C��");
			break;
		case 2:
			DrawFormatString(200, 100, 0x000000, "�{");
			break;
		default:
			DrawFormatString(200, 100, 0xb00000, "���킪����܂���");
			break;
		}
	}
	
	// ����I���ς�
	if (weapon_selection == true)
	{
		if (weapon_number == weapon1_info.num)
		{
			if (weapon1_info.level_hierarchy == MAX_LEVEL_HIERARCHY)
			{
				DrawFormatString(200, 120, 0xb00000, "���͍ŏI�����ł�");
			}
			else if (point <= 0)
			{
				DrawFormatString(200, 120, 0xb00000, "�|�C���g������܂���");
			}
		}
		else
		{
			if (weapon2_info.level_hierarchy == MAX_LEVEL_HIERARCHY)
			{
				DrawFormatString(200, 120, 0xb00000, "���͍ŏI�����ł�");
			}
			else if (point <= 0)
			{
				DrawFormatString(200, 120, 0xb00000, "�|�C���g������܂���");
			}
		}

	}

}

// ����1�̃��x�����Z�b�g����
void WeaponLevelUp::Weapon1LevelInit()
{
	weapon1_info.level_hierarchy = 0;
	weapon1_info.cursor_pos = 0;

	for (int i = 0; i <= MAX_LEVEL_HIERARCHY; i++)
	{
		branch_point_x[0][i] = cursor_x;
		branch_point_y[0][i] = img_branch_point_y;
		is_chooce[0][i] = false;
	}
}

// ����2�̃��x�����Z�b�g����
void WeaponLevelUp::Weapon2LevelInit()
{
	weapon2_info.level_hierarchy = 0;
	weapon2_info.cursor_pos = 0;

	for (int i = 0; i <= MAX_LEVEL_HIERARCHY; i++)
	{
		branch_point_x[1][i] = cursor_x;
		branch_point_y[1][i] = img_branch_point_y;
		is_chooce[1][i] = false;
	}
}
