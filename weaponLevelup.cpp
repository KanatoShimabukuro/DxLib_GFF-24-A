#include "main.h"

WeaponLevelUp::WeaponLevelUp()
{
	// �摜�̓Ǎ�
	img_tree_diagram = LoadGraph("resources/images/tree_diagram01.png");
	img_cursor = LoadGraph("resources/images/levelup_cursor.png");
	img_branch_point = LoadGraph("resources/images/branch_point.png");
	img_chooce = LoadGraph("resources/images/levelup_choose.png");
	img_button_a = LoadGraph("resources/images/button_a01.png");
	img_button_b = LoadGraph("resources/images/button_b.png");
	img_button_x = LoadGraph("resources/images/button_x.png");

	// ����摜
	img_sword = LoadGraph("resources/images/����/�Ў茕.png");
	img_dagger= LoadGraph("resources/images/����/�Z��.png");
	img_great_sword = LoadGraph("resources/images/����/�匕.png");
	img_spear = LoadGraph("resources/images/����/��.png");
	img_frail = LoadGraph("resources/images/����/�t���C��.png");
	img_book = LoadGraph("resources/images/����/�{.png");
	img_question_mark = LoadGraph("resources/images/mark_question.png");

	// �\���̏�����
	weapon1_info = { 0, none, 0, 0, 0, 0, 0, 0, 0, 0, 0.0f, 0.0f };
	weapon2_info = { 1, none, 0, 0, 0, 0, 0, 0, 0, 0, 0.0f, 0.0f };

	// �ϐ��̏�����
	interval = 0;
	cursor_x = 580;
	cursor_y = 120;
	level_cursor_pos = 85;
	lv_point = 0;
	weapon_number = weapon1_info.num;
	weapon_selection = false;

	is_blacksmith = false;
	is_close_level_up = false;

	// �摜�p�����[�^
	img_x = 580;
	img_y = 160;
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

	w_p_speed = 0.0f;
	w_p_avoidancecooltime = 0.0f;
	w_p_upperlimitlimit = 0.0f;

	p_speed = 0.0f;
	p_avoidancecooltime = 0.0f;
	p_upperlimitlimit = 0.0f;

	frail_radiusX = 0.0f;
	frail_radiusY = 0.0f;
	tmp_frail_radiusX = 0.0f;
	tmp_frail_radiusY = 0.0f;

	//close = false;
	close_mode = 2;

	// �e�X�g
	fp = NULL;
	for (int i = 0; i < 2; i++)
	{
		sample[i] = { 0 };
	}
}

WeaponLevelUp::~WeaponLevelUp()
{

}

// �X�V
void WeaponLevelUp::update(weapon* weapon, second_weapon* second_weapon, Player* player, bool& restor_cursor_position, int& point)
{	
	// �e�X�g
	sample[0].type = weapon1_info.type;
	sample[0].level = weapon1_info.level;

	sample[1].type = weapon2_info.type;
	sample[1].level = weapon2_info.level;

	// �t�@�C����������
	fopen_s(&fp, "resources/dat/test.txt", "w");

	if (fp)
	{
		for (int i = 0; i < 2; i++)
		{
			fprintf(fp, "%1d %1d %d\n", sample[i].type, sample[i].level, sample[i].damage);
		}
		//�t�@�C���N���[�Y
		fclose(fp);
	}
	//////////////////////////////

	// weapon����̃v���C���[���
	// �J�[�\���ړ��ōX�V�����l
	w_p_speed = weapon->GetP_Speed();
	w_p_avoidancecooltime = weapon->GetP_AvoidanceCooltime();
	w_p_upperlimitlimit = weapon->GetP_Upperlimitlimit();

	weapon1_info.cool_time = weapon->GetMaxCoolTime();
	weapon1_info.damege = weapon->GetDamage();
	weapon1_info.attack_range = weapon->GetMaxRot();

	weapon2_info.cool_time = second_weapon->GetMaxCoolTime();
	weapon2_info.damege = second_weapon->GetDamage();
	weapon2_info.attack_range = second_weapon->GetMaxRot();

	frail_radiusX = second_weapon->GetP_aiming_radiusX();
	frail_radiusY = second_weapon->GetP_aiming_radiusY();

	lv_point = point;

	// �J�[�\���̈ʒu�����ɖ߂�
	if (restor_cursor_position == true)
	{
		// ������
		Init(weapon, second_weapon, restor_cursor_position);
		// player����̃v���C���[���
		p_speed = player->GetPlayer_Speed();
		p_avoidancecooltime = player->GetAvoidance_limit();
		p_upperlimitlimit = player->GetPlayer_Upperlimit();

		weapon1_info.tmp_cool_time = weapon->GetMaxCoolTime();
		weapon1_info.tmp_damege = weapon->GetDamage();
		weapon1_info.tmp_attack_range = weapon->GetMaxRot();

		weapon2_info.tmp_cool_time = second_weapon->GetMaxCoolTime();
		weapon2_info.tmp_damege = second_weapon->GetDamage();
		weapon2_info.tmp_attack_range = second_weapon->GetMaxRot();

		tmp_frail_radiusX = player->GetPlayer_RadiusX();
		tmp_frail_radiusY = player->GetPlayer_RadiusY();
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
			}
			else if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
			{
				//���X�e�B�b�N������
				interval = 0;
				cursor_x = 580;
				weapon_number = weapon1_info.num;

			}
		//}

		// A�{�^���Ō���
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS && lv_point > 0)
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
			// ���x���A�b�v�ڍ׃J�[�\��
			switch (weapon1_info.level_hierarchy)
			{
			case 0:
				weapon1_info.tmp_level = 1;
				break;
			case 1:
				if (weapon1_info.cursor_pos == -level_cursor_pos)
				{
					// ���`�}�̍���I��
					weapon1_info.tmp_level = 2;
				}
				else
				{
					// ���`�}�̉E��I��
					weapon1_info.tmp_level = 3;
				}
				break;
			case 2:
				if (weapon1_info.cursor_pos == -level_cursor_pos)
				{
					// ���`�}�̍���I��
					weapon1_info.tmp_level = 4;
				}
				else
				{
					// ���`�}�̉E��I��
					weapon1_info.tmp_level = 5;
				}
				break;
			case 3:
				weapon1_info.tmp_level = 6;
				break;
			case 4:
				if (weapon1_info.cursor_pos == -level_cursor_pos)
				{
					// ���`�}�̍���I��
					weapon1_info.tmp_level = 7;
				}
				else
				{
					// ���`�}�̉E��I��
					weapon1_info.tmp_level = 8;
				}
				break;
			default:
				break;
			}
			
			weapon->SetWeaponLevel(weapon1_info.tmp_level);

			if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
			{
				// ����1�̃��x���A�b�v
				LevelUp(weapon, second_weapon, player, &weapon1_info, point);
			}

			// �J�[�\���ړ�
			LevelUpCursorMove(&weapon1_info);
		}
		else
		{
			// ���x���A�b�v�ڍ׃J�[�\��
			switch (weapon2_info.level_hierarchy)
			{
			case 0:
				weapon2_info.tmp_level = 1;
				break;
			case 1:
				if (weapon2_info.cursor_pos == -level_cursor_pos)
				{
					// ���`�}�̍���I��
					weapon2_info.tmp_level = 2;
				}
				else
				{
					// ���`�}�̉E��I��
					weapon2_info.tmp_level = 3;
				}
				break;
			case 2:
				if (weapon2_info.cursor_pos == -level_cursor_pos)
				{
					// ���`�}�̍���I��
					weapon2_info.tmp_level = 4;
				}
				else
				{
					// ���`�}�̉E��I��
					weapon2_info.tmp_level = 5;
				}
				break;
			case 3:
				weapon2_info.tmp_level = 6;
				break;
			case 4:
				if (weapon2_info.cursor_pos == -level_cursor_pos)
				{
					// ���`�}�̍���I��
					weapon2_info.tmp_level = 7;
				}
				else
				{
					// ���`�}�̉E��I��
					weapon2_info.tmp_level = 8;
				}
				break;
			default:
				break;
			}

			second_weapon->SetWeaponLevel(weapon2_info.tmp_level);

			if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
			{
				// ����2�̃��x���A�b�v
				LevelUp(weapon, second_weapon, player, &weapon2_info, point);
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

			// ���݂̕��탌�x���̃Z�b�g
			weapon->SetWeaponLevel(weapon1_info.level);
			second_weapon->SetWeaponLevel(weapon2_info.level);

			weapon_selection = false;
		}
	}

	// X�{�^��������
	if (InputCtrl::GetKeyState(KEY_INPUT_X) == RELEASE || InputCtrl::GetButtonState(XINPUT_BUTTON_X) == RELEASE && close_mode == 0)
	{
		close_mode = 1;
	}

	// ����Ƃ�
	if (InputCtrl::GetKeyState(KEY_INPUT_X) == PRESS || InputCtrl::GetButtonState(XINPUT_BUTTON_X) == PRESS)
	{
		if (close_mode == 1)
		{
			// ���݂̕��탌�x���̃Z�b�g
			weapon->SetWeaponLevel(weapon1_info.level);
			second_weapon->SetWeaponLevel(weapon2_info.level);

			// ����
			close_mode = 2;
			//close = true;
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

	SetFontSize(20);
	DrawFormatString(900, 20, 0x000000, "LevelUpPoint�F%d", lv_point);

	// �{�^���ē�
	DrawRotaGraph(855, 690, 0.2f, 0.0f, img_button_a, TRUE);
	DrawRotaGraph(945, 690, 0.2f, 0.0f, img_button_b, TRUE);
	DrawRotaGraph(1030, 690, 0.2f, 0.0f, img_button_x, TRUE);
	DrawFormatString(875, 680, 0x000000, "����");
	DrawFormatString(965, 680, 0x000000, "�߂�");
	DrawFormatString(1050, 680, 0x000000, "����");

	// ���x���A�b�v�ڍׂ̃e�L�X�g�Q
	DrawLevelUpDetails();

	// ���`�}�̐�
	DrawRotaGraph(img_x + 5, 440, 0.9f, 0.0f, img_tree_diagram, TRUE);
	DrawRotaGraph(img_x + 385, 440, 0.9f, 0.0f, img_tree_diagram, TRUE);

	// ����1�̉摜
	switch (weapon1_info.type)
	{
		case sword:			// �Ў茕
			DrawRotaGraph(img_x, img_y, 0.14f, 0.0f, img_sword, TRUE);
			break;
		case dagger:		// �Z��
			DrawRotaGraph(img_x, img_y, 0.14f, 0.0f, img_dagger, TRUE);
			break;
		case greatSword:	// �匕
			DrawRotaGraph(img_x, img_y, 0.2f, 0.0f, img_great_sword, TRUE);
			break;
		default:
			DrawRotaGraph(img_x, img_y, 0.1f, 0.0f, img_question_mark, TRUE);
			break;
	}

	// ����2�̉摜
	switch (weapon2_info.type)
	{
		case spear:			// ��
			DrawRotaGraph(img_x + 380, img_y, 0.17f, 0.0f, img_spear, TRUE);
			break;
		case frail:			// �t���C��
			DrawRotaGraph(img_x + 380, img_y, 0.17f, 0.0f, img_frail, TRUE);
			break;
		case book:			// �{
			DrawRotaGraph(img_x + 380, img_y, 0.14f, 0.0f, img_book, TRUE);
			break;
		default:
			DrawRotaGraph(img_x + 380, img_y, 0.1f, 0.0f, img_question_mark, TRUE);
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

#ifdef _DEBUG	
	// �e�X�g�\��
	//SetFontSize(20);
	//DrawFormatString(0, 210, 0xa00000, "W1level(State) : %d", weapon1_info.level);
	//DrawFormatString(0, 230, 0xa00000, "W1���x���K�w : %d", weapon1_info.level_hierarchy);
	//DrawFormatString(0, 250, 0xa00000, "W1tmp���x�� : %d", weapon1_info.tmp_level);
	//DrawFormatString(0, 270, 0xa00000, "close_mode : %d", close_mode);
	//DrawFormatString(0, 270, 0x000000, "W2level (State): %d", weapon2_info.level);
	//DrawFormatString(0, 290, 0x000000, "W2���x���K�w : %d", weapon2_info.level_hierarchy);
	//DrawFormatString(0, 310, 0x000000, "W2tmp���x�� : %d", weapon2_info.tmp_level);
	//DrawFormatString(0, 90, 0x000000, "1cursor_pos : %d", weapon1_info.cursor_pos);
	//DrawFormatString(0, 110, 0x000000, "2cursor_pos : %d", weapon2_info.cursor_pos);
	//DrawFormatString(0, 130, 0x000000, "level_cursor_pos : %d", level_cursor_pos);
	//DrawFormatString(0, 130, 0x000000, "level_cursor_pos : %d", level_cursor_pos);
	//DrawFormatString(0, 0, 0x000000, "branch_point_x[0][0] : %d", branch_point_x[0][0]);
	//DrawFormatString(0, 20, 0x000000, "cursor_x : %d", cursor_x);

	// �������݂̃v���C���[�̃X�e�[�^�X
	//DrawFormatString(0, 20, 0xf0f0f0, "weapon.cpp����̏��");
	//DrawFormatString(0, 40, 0xf0f0f0, "w_p_speed : %d", w_p_speed);
	//DrawFormatString(0, 60, 0xf0f0f0, "w_p_avoidancecooltime : %d", w_p_avoidancecooltime);
	//DrawFormatString(0, 80, 0xf0f0f0, "w_p_upperlimitlimit : %d", w_p_upperlimitlimit);
	//
	//DrawFormatString(0, 120, 0xf0f0f0, "player.cpp����̏��");
	//DrawFormatString(0, 140, 0xf0f0f0, "p_speed : %f", p_speed);
	//DrawFormatString(0, 160, 0xf0f0f0, "p_avoidancecooltime : %d", p_avoidancecooltime);
	//DrawFormatString(0, 180, 0xf0f0f0, "p_upperlimitlimit : %f", p_upperlimitlimit);

	//DrawFormatString(0, 210, 0xa00000, "cool_time : %d", weapon1_info.cool_time);
	//DrawFormatString(0, 230, 0xa00000, "damage : %d", weapon1_info.damege);
	//DrawFormatString(0, 250, 0xa00000, "�͈� : %f", weapon1_info.attack_range);

	//DrawFormatString(0, 270, 0xa00000, "tmp_cool_time : %d", weapon1_info.tmp_cool_time);
	//DrawFormatString(0, 290, 0xa00000, "tmp_damage : %d", weapon1_info.tmp_damege);
	//DrawFormatString(0, 310, 0xa00000, "tmp_�͈� : %f", weapon1_info.tmp_attack_range);

#endif
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

	//close = false;
}

// ���x���A�b�v����
void WeaponLevelUp::LevelUp(weapon* weapon, second_weapon* second_weapon, Player* player, weapon_information* info, int& point)
{
	if (info->level_hierarchy < MAX_LEVEL_HIERARCHY && point > 0)
	{
		// �ʏ�̃��x���A�b�v
		point--;

		// �J�[�\���������Ă��郌�x�����Z�b�g
		info->level = info->tmp_level;

		// �I����������_�̉摜�p�p�����[�^�̍X�V
		is_chooce[info->num][info->level_hierarchy] = true;
		branch_point_y[info->num][info->level_hierarchy] += LEVEL_HIERARCHY_HEIGHT * info->level_hierarchy;

		if (info->num == weapon1_info.num)
		{
			// �摜�p�p�����[�^x�̍X�V
			branch_point_x[info->num][info->level_hierarchy] += info->cursor_pos;

			// ����1�Ƀ��x���̃Z�b�g
			weapon->SetWeaponLevel(info->level);
			info->tmp_cool_time = weapon->GetMaxCoolTime();
			info->tmp_damege = weapon->GetDamage();
			info->tmp_attack_range = weapon->GetMaxRot();
		}
		else
		{
			// �摜�p�p�����[�^x�̍X�V
			branch_point_x[info->num][info->level_hierarchy] += 380 + info->cursor_pos;

			// ����2�Ƀ��x���̃Z�b�g
			second_weapon->SetWeaponLevel(info->level);
			info->tmp_cool_time = second_weapon->GetMaxCoolTime();
			info->tmp_damege = second_weapon->GetDamage();
			info->tmp_attack_range = second_weapon->GetMaxRot();
			tmp_frail_radiusX = player->GetPlayer_RadiusX();
			tmp_frail_radiusY = player->GetPlayer_RadiusY();
		}

		info->level_hierarchy++;
		//// ���x���K�w�̐���
		//if (info->level_hierarchy > MAX_LEVEL_HIERARCHY)
		//{
		//	info->level_hierarchy = MAX_LEVEL_HIERARCHY;
		//}

		// player����̃v���C���[���
		p_speed = player->GetPlayer_Speed();
		p_avoidancecooltime = player->GetAvoidance_limit();
		p_upperlimitlimit = player->GetPlayer_Upperlimit();

	}
	else if (info->level_hierarchy == MAX_LEVEL_HIERARCHY && is_blacksmith == true)
	{
		// �ŏI����

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

		info->cursor_pos = 0;

		// player����̃v���C���[���
		p_speed = player->GetPlayer_Speed();
		p_avoidancecooltime = player->GetAvoidance_limit();
		p_upperlimitlimit = player->GetPlayer_Upperlimit();

		info->tmp_cool_time = weapon->GetMaxCoolTime();
		info->tmp_damege = weapon->GetDamage();
		info->tmp_attack_range = weapon->GetMaxRot();
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
	//if (weapon_selection == true)
	//{

	// �e�L�X�g
	DrawFormatString(200, 180, 0x000000, "���x���A�b�v�ڍ�");

		if (weapon_number == weapon1_info.num)
		{
			DrawFormatString(200, 220, 0x000000, "�_���[�W");
			DrawFormatString(200, 240, 0x000000, "�@%d�@���@%d", weapon1_info.tmp_damege, weapon1_info.damege);
			DrawFormatString(200, 260, 0x000000, "�U���N�[���^�C��");
			DrawFormatString(200, 280, 0x000000, "�@%d�@���@%d", weapon1_info.tmp_cool_time, weapon1_info.cool_time);
			DrawFormatString(200, 300, 0x000000, "�U���͈�");
			DrawFormatString(200, 320, 0x000000, "�@%.1f�@���@%.1f", weapon1_info.tmp_attack_range, weapon1_info.attack_range);
			
			DrawFormatString(200, 360, 0x000000, "�v���C���[�X�e�[�^�X");
			DrawFormatString(200, 380, 0x000000, "�ړ����x");
			DrawFormatString(200, 400, 0x000000, "�@%.1f�@���@%.1f", p_speed, w_p_speed);
			DrawFormatString(200, 420, 0x000000, "��𑬓x");
			DrawFormatString(200, 440, 0x000000, "�@%.1f�@���@%.1f", p_avoidancecooltime, w_p_avoidancecooltime);
			DrawFormatString(200, 460, 0x000000, "����N�[���^�C��");
			DrawFormatString(200, 480, 0x000000, "�@%.1f�@���@%.1f", p_upperlimitlimit, w_p_upperlimitlimit);
		}
		else if(weapon2_info.type != none)
		{
			DrawFormatString(200, 220, 0x000000, "�_���[�W");
			DrawFormatString(200, 240, 0x000000, "�@%d�@���@%d", weapon2_info.tmp_damege, weapon2_info.damege);
			DrawFormatString(200, 260, 0x000000, "�U���N�[���^�C��");
			DrawFormatString(200, 280, 0x000000, "�@%d�@���@%d", weapon2_info.tmp_cool_time, weapon2_info.cool_time);
			DrawFormatString(200, 300, 0x000000, "�U���͈�");
			DrawFormatString(200, 320, 0x000000, "�@%.1f�@���@%.1f", weapon2_info.tmp_attack_range, weapon2_info.attack_range);

			if (weapon2_info.type == frail)
			{
				// �Ə��͂ǂ��܂ōU�����͂����i���̒����j
				//DrawFormatString(200, 380, 0x000000, "�U������X");
				//DrawFormatString(200, 400, 0x000000, "�@%.1f�@���@%.1f", tmp_frail_radiusX, frail_radiusX);
				//DrawFormatString(200, 420, 0x000000, "�U������Y");
				//DrawFormatString(200, 440, 0x000000, "�@%.1f�@���@%.1f", tmp_frail_radiusY, frail_radiusY);
				DrawFormatString(200, 340, 0x000000, "�S���̔򋗗�");
				DrawFormatString(200, 360, 0x000000, "�@%.1f�@���@%.1f", tmp_frail_radiusX, frail_radiusX);
			}
		}
	//}

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

		// ���x���̕\��
		DrawFormatString(200, 120, 0x000000, "Lv. %d",weapon1_info.level);
	}
	else
	{
		switch (weapon2_info.type)
		{
		case spear:
			DrawFormatString(200, 100, 0x000000, "��");
			break;
		case frail:
			DrawFormatString(200, 100, 0x000000, "�t���C��");
			break;
		case book:
			DrawFormatString(200, 100, 0x000000, "������");
			break;
		default:
			DrawFormatString(200, 100, 0xb00000, "���킪����܂���");
			break;
		}

		if (weapon2_info.type != none)
		{
			// ���x���̕\��
			DrawFormatString(200, 120, 0x000000, "Lv. %d", weapon2_info.level);
		}
	}
	
	// ����I���ς�
	if (weapon_selection == true)
	{
		if (weapon_number == weapon1_info.num)
		{
			if (weapon1_info.level_hierarchy == MAX_LEVEL_HIERARCHY)
			{
				// ����1�ŏI�����̃e�L�X�g�Q
				DrawWeapon1FinalText();
			}
			else if (lv_point <= 0)
			{
				DrawFormatString(200, 140, 0xb00000, "�|�C���g������܂���");
			}
		}
		else
		{
			if (weapon2_info.level_hierarchy == MAX_LEVEL_HIERARCHY)
			{
				// ����2�ŏI�����̃e�L�X�g�Q
				DrawWeapon2FinalText();
			}
			else if (lv_point <= 0)
			{
				DrawFormatString(200, 140, 0xb00000, "�|�C���g������܂���");
			}
		}
	}
}

// ����1�ŏI�����̃e�L�X�g�Q
void WeaponLevelUp::DrawWeapon1FinalText() const
{
	DrawFormatString(200, 140, 0xb00000, "���͍ŏI�����ł�");
	//DrawFormatString(200, 140, 0xb00000, "���b��");

	if (weapon1_info.cursor_pos == -level_cursor_pos)
	{
		// ���x��7
		switch (weapon1_info.type)
		{
		case sword:			// �Ў茕
			DrawFormatString(200, 520, 0x000000, "�`���̌�");
			DrawFormatString(200, 550, 0x000000, "�a�����΂�");
			break;
		case dagger:		// �Z��
			DrawFormatString(200, 520, 0x000000, "�A�T�V���_�K�\");
			//SetFontSize(15);
			DrawFormatString(200, 550, 0x000000, "��������O���ɂ���G\n�Ƀ_���[�W��^����");
			break;
		case greatSword:	// �匕
			DrawFormatString(200, 520, 0x000000, "�����a");
			DrawFormatString(200, 550, 0x000000, "��]�U���ɕω�����");
			break;
		default:
			DrawFormatString(200, 520, 0xb00000, "���킪����܂���");
			break;
		}
	}
	else
	{
		// ���x��8
		switch (weapon1_info.type)
		{
		case sword:			// �Ў茕
			DrawFormatString(200, 520, 0x000000, "�����u���b�h�t�@���O");
			DrawFormatString(200, 550, 0x000000, "��������ɕω�����\n���������ۂɍU���͂�\n�オ��A�A���ōU����\n���Ă�Ɣ��ʂȂ���\n�񕜂���");
			break;
		case dagger:		// �Z��
			DrawFormatString(200, 520, 0x000000, "�����i�C�t");
			DrawFormatString(200, 550, 0x000000, "�Ə��̕����Ƀi�C�t��\n5�{���˂���");
			break;
		case greatSword:	// �匕
			DrawFormatString(200, 520, 0x000000, "���o�̑���");
			DrawFormatString(200, 550, 0x000000, "���ڂ��肪�N����\n�G�ɏ��_���[�W��\n�^����");
			break;
		default:
			DrawFormatString(200, 520, 0xb00000, "���킪����܂���");
			break;
		}
	}
}

// ����2�ŏI�����̃e�L�X�g�Q
void WeaponLevelUp::DrawWeapon2FinalText() const
{
	DrawFormatString(200, 140, 0xb00000, "���͍ŏI�����ł�");

	if (weapon2_info.cursor_pos == -level_cursor_pos)
	{
		// ���x��7
		switch (weapon2_info.type)
		{
		case spear:
			DrawFormatString(200, 520, 0x000000, "���C���������X");
			DrawFormatString(200, 550, 0x000000, "�U���͈͂��c������\n�g�傳���");
			break;
		case frail:
			DrawFormatString(200, 520, 0x000000, "�O��̍�");
			DrawFormatString(200, 550, 0x000000, "�S�����R�ɂȂ�");
			break;
		case book:
			DrawFormatString(200, 520, 0x000000, "���҂̉���");
			//SetFontSize(15);
			DrawFormatString(200, 550, 0x000000, "����_���[�W���オ��\n��莞�ԕ���̃N�[��\n�^�C�����������o���A\n�������A�o���A�͍U\n�������Ə�����");
			break;
		default:
			DrawFormatString(200, 520, 0xb00000, "���킪����܂���");
			break;
		}
	}
	else
	{
		// ���x��8
		switch (weapon2_info.type)
		{
		case spear:
			DrawFormatString(200, 520, 0x000000, "�O���O�j��");
			DrawFormatString(200, 550, 0x000000, "�U�������������G��\n����������");
			break;
		case frail:
			DrawFormatString(200, 520, 0x000000, "�A�[�X�N���b�V���[");
			DrawFormatString(200, 550, 0x000000, "�S�����傫���Ȃ�\n�n���ꂪ��������");
			break;
		case book:
			DrawFormatString(200, 520, 0x000000, "�G���`�����g�o���b�g");
			DrawFormatString(200, 550, 0x000000, "�����U�~��ɉ�]��\n�U��������");
			break;
		default:
			DrawFormatString(200, 520, 0xb00000, "���킪����܂���");
			break;
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
