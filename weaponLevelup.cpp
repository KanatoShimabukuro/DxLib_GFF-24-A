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

	//// ���x��7�̕���摜
	//img_assasinsdagger = LoadGraph("resources/images/����/�Ў茕.png");
	//img_legendsword = LoadGraph("resources/images/����/�Ў茕.png");
	//img_windslash = LoadGraph("resources/images/����/�Ў茕.png");
	//img_royallance = LoadGraph("resources/images/����/�Ў茕.png");
	//img_threechain = LoadGraph("resources/images/����/�Ў茕.png");
	//img_blessing = LoadGraph("resources/images/����/�Ў茕.png");

	//// ���x��8�̕���摜
	//img_throwingknife = LoadGraph("resources/images/����/�Ў茕.png");
	//img_magicsword = LoadGraph("resources/images/����/�Ў茕.png");
	//img_dustsword = LoadGraph("resources/images/����/�Ў茕.png");
	//img_gungnir = LoadGraph("resources/images/����/�Ў茕.png");
	//img_earthcrusher = LoadGraph("resources/images/����/�Ў茕.png");
	//img_bullet = LoadGraph("resources/images/����/�Ў茕.png");

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

	book_bullet_speed = 0;
	tmp_book_bullet_speed = 0;

	close_mode = 2;
}

WeaponLevelUp::~WeaponLevelUp()
{
	DeleteGraph(img_tree_diagram);
	DeleteGraph(img_cursor);
	DeleteGraph(img_branch_point);
	DeleteGraph(img_chooce);
	DeleteGraph(img_button_a);
	DeleteGraph(img_button_b);
	DeleteGraph(img_button_x);

	// ����摜
	DeleteGraph(img_sword);
	DeleteGraph(img_dagger);
	DeleteGraph(img_great_sword);
	DeleteGraph(img_spear);
	DeleteGraph(img_frail);
	DeleteGraph(img_book);
	DeleteGraph(img_question_mark);

	//// ���x��7�̕���摜
	//DeleteGraph(img_assasinsdagger);
	//DeleteGraph(img_legendsword);
	//DeleteGraph(img_windslash);
	//DeleteGraph(img_royallance);
	//DeleteGraph(img_threechain);
	//DeleteGraph(img_blessing);

	//// ���x��8�̕���摜
	//DeleteGraph(img_throwingknife);
	//DeleteGraph(img_magicsword);
	//DeleteGraph(img_dustsword);
	//DeleteGraph(img_gungnir);
	//DeleteGraph(img_earthcrusher);
	//DeleteGraph(img_bullet);
}

// �X�V
void WeaponLevelUp::update(weapon* weapon, second_weapon* second_weapon, Player* player, bool& restor_cursor_position, int& point)
{	
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

	if (weapon2_info.type == frail)
	{
		frail_radiusX = second_weapon->GetP_aiming_radiusX();
		frail_radiusY = second_weapon->GetP_aiming_radiusY();
	}
	else if (weapon2_info.type == book)
	{
		book_bullet_speed = second_weapon->GetBulletSpeed();
	}

	lv_point = point;

	// �J�[�\���̈ʒu�����ɖ߂�
	if (restor_cursor_position == true)
	{
		// ������
		Init(weapon, second_weapon, player, restor_cursor_position);
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

		if (InputCtrl::GetStickRatio(L).x > 0.8 && interval >= 15)
			{
			//�J�[�\���̈ړ���
			SoundManager::PlaySoundSE("se_system_select_syu", false);
			//���X�e�B�b�N���E��
			interval = 0;
			cursor_x = 960;
			weapon_number = weapon2_info.num;
		}
		else if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
		{
			//�J�[�\���̈ړ���
			SoundManager::PlaySoundSE("se_system_select_syu", false);
			//���X�e�B�b�N������
			interval = 0;
			cursor_x = 580;
			weapon_number = weapon1_info.num;
		}

		// A�{�^���Ō���
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
		{
			if (weapon_number == weapon1_info.num && weapon1_info.level < 7)
			{
				//�J�[�\���̌��艹
				SoundManager::PlaySoundSE("se_system_normal_decision",false);
				weapon_selection = true;
			}
			else if (weapon_number == weapon2_info.num && weapon2_info.type != none && weapon2_info.level < 7)
			{
				//�J�[�\���̌��艹
				SoundManager::PlaySoundSE("se_system_normal_decision", false);
				weapon_selection = true;
			}
			else
			{
				//�J�[�\����NG��
				SoundManager::PlaySoundSE("se_system_ng", false);
			}
		}

		// B�{�^���ŕ���
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
		{
			// ����
			close_mode = 2;
		}
	}
	else
	{
		// �b��X�e�[�W�Ŏg�p
		is_close_level_up = false;

		if (weapon_number == weapon1_info.num)
		{
			AfterSelectingWeapon(weapon, second_weapon, player, &weapon1_info, point);
		}
		else
		{
			AfterSelectingWeapon(weapon, second_weapon, player, &weapon2_info, point);
		}

		// B�{�^���őI�𕐊�̃L�����Z��
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
		{
			//�J�[�\���̃L�����Z����
			SoundManager::PlaySoundSE("se_system_cancel", false);

			// ���x���J�[�\���̈ʒu����
			if (weapon_number == weapon1_info.num)
			{
				ResetLevelUpCursorPos(&weapon1_info);
			}
			else
			{
				ResetLevelUpCursorPos(&weapon2_info);
			}

			// ���݂̕��탌�x���̃Z�b�g
			weapon->SetWeaponLevel(weapon1_info.level);
			second_weapon->SetWeaponLevel(weapon2_info.level);

			weapon_selection = false;
		}
	}

	// X�{�^��������
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_X) == RELEASE && close_mode == 0)
	{
		close_mode = 1;
	}

	// ����Ƃ�
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_X) == PRESS)
	{
		if (close_mode == 1)
		{
			// ���݂̕��탌�x���̃Z�b�g
			weapon->SetWeaponLevel(weapon1_info.level);
			second_weapon->SetWeaponLevel(weapon2_info.level);

			// ����
			close_mode = 2;
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

	DrawBox(190, 40, 420, 80, 0x000000, FALSE);
	SetFontSize(20);
	DrawFormatString(220, 50, 0x000000, "LevelUpPoint�F%d", lv_point);

	// �{�^���ē�
	if (is_blacksmith == false)
	{
		DrawRotaGraph(850, 690, 0.2f, 0.0f, img_button_x, TRUE);
		DrawFormatString(870, 680, 0x000000, "����");
	}
	DrawRotaGraph(960, 690, 0.2f, 0.0f, img_button_a, TRUE);
	DrawFormatString(980, 680, 0x000000, "����");
	DrawRotaGraph(1050, 690, 0.2f, 0.0f, img_button_b, TRUE);
	DrawFormatString(1070, 680, 0x000000, "�߂�");

	// ���x���A�b�v�ڍׂ̃e�L�X�g�Q
	DrawLevelUpDetails();

	// ���`�}�̐�
	DrawRotaGraph(img_x + 5, 440, 0.9f, 0.0f, img_tree_diagram, TRUE);
	DrawRotaGraph(img_x + 385, 440, 0.9f, 0.0f, img_tree_diagram, TRUE);

	// ����̉摜�`��
	DrawWeaponImages();

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
			}
		}
		else
		{
			// ����2
			if (weapon2_info.level_hierarchy <= MAX_LEVEL_HIERARCHY)
			{
				// �J�[�\���\��
				DrawRotaGraph(cursor_x + weapon2_info.cursor_pos, cursor_y + (LEVEL_HIERARCHY_HEIGHT * (weapon2_info.level_hierarchy + 1)), 0.08f, 0.0f, img_cursor, TRUE);
			}
		}
	}

#ifdef _DEBUG	
	// �e�X�g�\��
	//SetFontSize(20);
	//DrawFormatString(0, 210, 0xa00000, "is_blacksmith : %d", is_blacksmith);
	//DrawFormatString(0, 210, 0xa00000, "W1level(State) : %d", weapon1_info.level);
	//DrawFormatString(0, 230, 0xa00000, "W1���x���K�w : %d", weapon1_info.level_hierarchy);
	//DrawFormatString(0, 250, 0xa00000, "W1tmp���x�� : %d", weapon1_info.tmp_level);
	//DrawFormatString(0, 270, 0xa00000, "close_mode : %d", close_mode);
	//DrawFormatString(0, 270, 0x000000, "W2level (State): %d", weapon2_info.level);
	//DrawFormatString(0, 290, 0x000000, "W2���x���K�w : %d", weapon2_info.level_hierarchy);
	//DrawFormatString(0, 310, 0x000000, "W2tmp���x�� : %d", weapon2_info.tmp_level);
	//DrawFormatString(0, 20, 0x000000, "1cursor_pos : %d", weapon1_info.cursor_pos);
	//DrawFormatString(0, 40, 0x000000, "2cursor_pos : %d", weapon2_info.cursor_pos);
	//DrawFormatString(0, 40, 0x000000, "1level_hierarchy : %d", weapon1_info.level_hierarchy);
	//DrawFormatString(0, 20, 0x000000, "cursor_x : %d", cursor_x);
	//DrawFormatString(0, 40, 0x000000, "weapon_selection : %d", weapon_selection);
#endif
}

// ����������
void WeaponLevelUp::Init(weapon* weapon, second_weapon* second_weapon, Player* player, bool& restor_cursor_position)
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

	// ����1���
	weapon1_info.type = weapon->GetWeaponType();
	weapon1_info.level = weapon->GetWeaponLevel();
	weapon1_info.tmp_cool_time = weapon->GetMaxCoolTime();
	weapon1_info.tmp_damege = weapon->GetDamage();
	weapon1_info.tmp_attack_range = weapon->GetMaxRot();

	// ����2���
	weapon2_info.type = second_weapon->GetWeaponType();
	weapon2_info.level = second_weapon->GetWeaponLevel();
	weapon2_info.tmp_cool_time = second_weapon->GetMaxCoolTime();
	weapon2_info.tmp_damege = second_weapon->GetDamage();
	weapon2_info.tmp_attack_range = second_weapon->GetMaxRot();

	if (weapon2_info.type == frail)
	{
		// �t���C���̏��
		tmp_frail_radiusX = player->GetPlayer_RadiusX();
		tmp_frail_radiusY = player->GetPlayer_RadiusY();
	}
	else if (weapon2_info.type == book)
	{
		book_bullet_speed = second_weapon->GetBulletSpeed();
	}

	// ���݂̃v���C���[�X�e�[�^�X
	p_speed = player->GetPlayer_Speed();
	p_avoidancecooltime = player->GetAvoidance_limit();
	p_upperlimitlimit = player->GetPlayer_Upperlimit();

	// ����������
	restor_cursor_position = false;
}

// ����I����̏���
void WeaponLevelUp::AfterSelectingWeapon(weapon* weapon, second_weapon* second_weapon, Player* player, weapon_information* info, int& point)
{
	// ���x���A�b�v�ڍ׃J�[�\��
	switch (info->level_hierarchy)
	{
	case 0:
		info->tmp_level = 1;
		break;
	case 1:
		if (info->cursor_pos == -level_cursor_pos)
		{
			// ���`�}�̍���I��
			info->tmp_level = 2;
		}
		else
		{
			// ���`�}�̉E��I��
			info->tmp_level = 3;
		}
		break;
	case 2:
		if (info->cursor_pos == -level_cursor_pos)
		{
			// ���`�}�̍���I��
			info->tmp_level = 4;
		}
		else
		{
			// ���`�}�̉E��I��
			info->tmp_level = 5;
		}
		break;
	case 3:
		info->tmp_level = 6;
		break;
	case 4:
		if (info->cursor_pos == -level_cursor_pos)
		{
			// ���`�}�̍���I��
			info->tmp_level = 7;
		}
		else
		{
			// ���`�}�̉E��I��
			info->tmp_level = 8;
		}
		break;
	default:
		break;
	}

	// ���x���𕐊�ɃZ�b�g
	if (info->num == weapon1_info.num)
	{
		weapon->SetWeaponLevel(weapon1_info.tmp_level);
	}
	else
	{
		second_weapon->SetWeaponLevel(weapon2_info.tmp_level);
	}

	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
	{
		// ���탌�x���A�b�v
		LevelUp(weapon, second_weapon, player, info, point);
	}

	// �J�[�\���ړ�
	LevelUpCursorMove(info);

}

// ���x���A�b�v����
void WeaponLevelUp::LevelUp(weapon* weapon, second_weapon* second_weapon, Player* player, weapon_information* info, int& point)
{
	if (info->level_hierarchy < MAX_LEVEL_HIERARCHY && point > 0)
	{
		//�J�[�\���̌��艹
		SoundManager::PlaySoundSE("se_system_normal_decision", false);

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
			if (info->type == frail)
			{
				tmp_frail_radiusX = player->GetPlayer_RadiusX();
				tmp_frail_radiusY = player->GetPlayer_RadiusY();
			}
			else if (info->type == book)
			{
				tmp_book_bullet_speed = second_weapon->GetBulletSpeed();
			}
		}

		info->level_hierarchy++;
		//// ���x���K�w�̐���
		//if (info->level_hierarchy > MAX_LEVEL_HIERARCHY)
		//{
		//	info->level_hierarchy = MAX_LEVEL_HIERARCHY;
		//}

		// �v���C���[�X�e�[�^�X�X�V
		p_speed = player->GetPlayer_Speed();
		p_avoidancecooltime = player->GetAvoidance_limit();
		p_upperlimitlimit = player->GetPlayer_Upperlimit();

	}
	else if (info->level_hierarchy == MAX_LEVEL_HIERARCHY && is_blacksmith == true)
	{
		//�n���}�[�̉�
		SoundManager::PlaySoundSE("se_system_hammer");

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

		// �v���C���[�X�e�[�^�X�X�V
		p_speed = player->GetPlayer_Speed();
		p_avoidancecooltime = player->GetAvoidance_limit();
		p_upperlimitlimit = player->GetPlayer_Upperlimit();

		info->tmp_cool_time = weapon->GetMaxCoolTime();
		info->tmp_damege = weapon->GetDamage();
		info->tmp_attack_range = weapon->GetMaxRot();
	}
	else
	{
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
		{
			if (!CheckSoundMem(SoundManager::GetSEHandle("se_system_hammer")))
			{
				//�J�[�\����NG��
				SoundManager::PlaySoundSE("se_system_ng", false);
			}
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
void WeaponLevelUp::ResetLevelUpCursorPos(weapon_information* info)
{
	if (info->level_hierarchy == 1 || info->level_hierarchy == MAX_LEVEL_HIERARCHY)
	{
		// ���x���A�b�v�J�[�\���̈ʒu�����ɂ���
		info->cursor_pos = -level_cursor_pos;
	}
}

// ����̉摜�`��
void WeaponLevelUp::DrawWeaponImages() const
{
	// ����1�̉摜
	switch (weapon1_info.type)
	{
	case sword:			// �Ў茕
		DrawRotaGraph(img_x, img_y, 0.14f, 0.0f, img_sword, TRUE);
		//if (weapon1_info.level == 7)
		//{
		//	 DrawRotaGraph(img_x, img_y, 0.14f, 0.0f, img_legendsword, TRUE);
		//}
		//else if (weapon1_info.level == 8)
		//{
		//	 DrawRotaGraph(img_x, img_y, 0.14f, 0.0f, img_throwingknife, TRUE);
		//}
		//else
		//{
		//	DrawRotaGraph(img_x, img_y, 0.14f, 0.0f, img_sword, TRUE);
		//}
		break;
	case dagger:		// �Z��
		DrawRotaGraph(img_x, img_y, 0.14f, 0.0f, img_dagger, TRUE);
		//if (weapon1_info.level == 7)
		//{
		//	 DrawRotaGraph(img_x, img_y, 0.14f, 0.0f, img_assasinsdagger, TRUE);
		//}
		//else if (weapon1_info.level == 8)
		//{
		//	 DrawRotaGraph(img_x, img_y, 0.14f, 0.0f, img_magicsword, TRUE);
		//}
		//else
		//{
		//	DrawRotaGraph(img_x, img_y, 0.14f, 0.0f, img_dagger, TRUE);
		//}
		break;
	case greatSword:	// �匕
		DrawRotaGraph(img_x, img_y, 0.2f, 0.0f, img_great_sword, TRUE);
		//if (weapon1_info.level == 7)
		//{
		//	 DrawRotaGraph(img_x, img_y, 0.14f, 0.0f, img_windslash, TRUE);
		//}
		//else if (weapon1_info.level == 8)
		//{
		//	 DrawRotaGraph(img_x, img_y, 0.14f, 0.0f, img_dustsword, TRUE);
		//}
		//else
		//{
		//	DrawRotaGraph(img_x, img_y, 0.2f, 0.0f, img_great_sword, TRUE);
		//}
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
		//if (weapon2_info.level == 7)
		//{
		//	 DrawRotaGraph(img_x + 380, img_y, 0.17f, 0.0f, img_royallance, TRUE);
		//}
		//else if (weapo2_info.level == 8)
		//{
		//	 DrawRotaGraph(img_x + 380, img_y, 0.17f, 0.0f, img_gungnir, TRUE);
		//}
		//else
		//{
		//	DrawRotaGraph(img_x + 380, img_y, 0.17f, 0.0f, img_spear, TRUE);
		//}
		break;
	case frail:			// �t���C��
		DrawRotaGraph(img_x + 380, img_y, 0.17f, 0.0f, img_frail, TRUE);
		//if (weapon2_info.level == 7)
		//{
		//	 DrawRotaGraph(img_x + 380, img_y, 0.17f, 0.0f, img_threechain, TRUE);
		//}
		//else if (weapon2_info.level == 8)
		//{
		//	 DrawRotaGraph(img_x + 380, img_y, 0.17f, 0.0f, img_earthcrusher, TRUE);
		//}
		//else
		//{
		//	DrawRotaGraph(img_x + 380, img_y, 0.17f, 0.0f, img_frail, TRUE);
		//}
		break;
	case book:			// �{
		DrawRotaGraph(img_x + 380, img_y, 0.14f, 0.0f, img_book, TRUE);
		//if (weapon2_info.level == 7)
		//{
		//	 DrawRotaGraph(img_x + 380, img_y, 0.17f, 0.0f, img_blessing, TRUE);
		//}
		//else if (weapon2_info.level == 8)
		//{
		//	 DrawRotaGraph(img_x + 380, img_y, 0.17f, 0.0f, img_bullet, TRUE);
		//}
		//else
		//{
		//	DrawRotaGraph(img_x + 380, img_y, 0.14f, 0.0f, img_book, TRUE);
		//}
		break;
	default:
		DrawRotaGraph(img_x + 380, img_y, 0.1f, 0.0f, img_question_mark, TRUE);
		break;
	}
}

// ���x���A�b�v�ڍׂ̃e�L�X�g�Q
void WeaponLevelUp::DrawLevelUpDetails() const
{
	// ���x���A�b�v�̏ڍטg
	DrawBox(190, 90, 420, 680, 0x000000, FALSE);

	// �e�L�X�g
	DrawFormatString(200, 180, 0x000000, "���x���A�b�v�ڍ�");

	if (weapon_number == weapon1_info.num)
	{
		if (weapon1_info.level >= 7) {
			DrawFormatString(200, 140, 0xb00000, "�ŏI�����ς݂ł�");
		}
		DrawFormatString(200, 220, 0x000000, "�_���[�W");
		DrawFormatString(200, 240, 0x000000, "�@%d�@���@%d", weapon1_info.tmp_damege, weapon1_info.damege);
		DrawFormatString(200, 260, 0x000000, "�U���N�[���^�C��");
		DrawFormatString(200, 280, 0x000000, "�@%d�@���@%d", weapon1_info.tmp_cool_time, weapon1_info.cool_time);
		DrawFormatString(200, 300, 0x000000, "�U���͈�");
		DrawFormatString(200, 320, 0x000000, "�@%.1f�@���@%.1f", weapon1_info.tmp_attack_range, weapon1_info.attack_range);
			
		if (weapon1_info.type != greatSword)
		{
			DrawFormatString(200, 360, 0x000000, "�v���C���[�X�e�[�^�X");
			DrawFormatString(200, 380, 0x000000, "�ړ����x");
			DrawFormatString(200, 400, 0x000000, "�@%.1f�@���@%.1f", p_speed, w_p_speed);
			DrawFormatString(200, 420, 0x000000, "��𑬓x");
			DrawFormatString(200, 440, 0x000000, "�@%.1f�@���@%.1f", p_upperlimitlimit, w_p_upperlimitlimit);
			DrawFormatString(200, 460, 0x000000, "����N�[���^�C��");
			DrawFormatString(200, 480, 0x000000, "�@%.1f�@���@%.1f", p_avoidancecooltime, w_p_avoidancecooltime);
		}

		if (weapon1_info.level == 7)
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
		else if(weapon1_info.level == 8)
		{
			// ���x��8
			switch (weapon1_info.type)
			{
			case sword:			// �Ў茕
				DrawFormatString(200, 520, 0x000000, "����");
				DrawFormatString(200, 550, 0x000000, "��������ɕω�����\n���������ۂɍU���͂�\n�オ��A�A���ōU����\n���Ă�Ɣ��ʂȂ���\n�񕜂���");
				break;
			case dagger:		// �Z��
				DrawFormatString(200, 520, 0x000000, "�����i�C�t");
				DrawFormatString(200, 550, 0x000000, "�Ə��̕����Ƀi�C�t��\n5�{���˂���\n+�_���[�W�@6 x 5");
				break;
			case greatSword:	// �匕
				DrawFormatString(200, 520, 0x000000, "���o�̑���");
				DrawFormatString(200, 550, 0x000000, "���o�������G��\n���_���[�W��^����");
				break;
			default:
				DrawFormatString(200, 520, 0xb00000, "���킪����܂���");
				break;
			}
		}
	}
	else if(weapon2_info.type != none)
	{
		if (weapon2_info.level >= 7) {
			DrawFormatString(200, 140, 0xb00000, "�ŏI�����ς݂ł�");
		}
		DrawFormatString(200, 220, 0x000000, "�_���[�W");
		DrawFormatString(200, 240, 0x000000, "�@%d�@���@%d", weapon2_info.tmp_damege, weapon2_info.damege);
		DrawFormatString(200, 260, 0x000000, "�U���N�[���^�C��");
		DrawFormatString(200, 280, 0x000000, "�@%d�@���@%d", weapon2_info.tmp_cool_time, weapon2_info.cool_time);
		DrawFormatString(200, 300, 0x000000, "�U���͈�");
		DrawFormatString(200, 320, 0x000000, "�@%.1f�@���@%.1f", weapon2_info.tmp_attack_range, weapon2_info.attack_range);
		
		if (weapon_selection == true)
		{
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
			else if (weapon2_info.type == book)
			{
				DrawFormatString(200, 340, 0x000000, "�e�̑��x");
				DrawFormatString(200, 360, 0x000000, "�@%d�@���@%d", tmp_book_bullet_speed, book_bullet_speed);
			}
		}
		else
		{
			if (weapon2_info.type == frail)
			{
				// �Ə��͂ǂ��܂ōU�����͂����i���̒����j
				//DrawFormatString(200, 380, 0x000000, "�U������X");
				//DrawFormatString(200, 400, 0x000000, "�@%.1f�@���@%.1f", tmp_frail_radiusX, frail_radiusX);
				//DrawFormatString(200, 420, 0x000000, "�U������Y");
				//DrawFormatString(200, 440, 0x000000, "�@%.1f�@���@%.1f", tmp_frail_radiusY, frail_radiusY);
				DrawFormatString(200, 340, 0x000000, "�S���̔򋗗�");
				DrawFormatString(200, 360, 0x000000, "�@%.1f�@���@%.1f", tmp_frail_radiusX, tmp_frail_radiusX);
			}
			else if (weapon2_info.type == book)
			{
				DrawFormatString(200, 340, 0x000000, "�e�̑��x");
				DrawFormatString(200, 360, 0x000000, "�@%d�@���@%d", tmp_book_bullet_speed, tmp_book_bullet_speed);
			}
		}

		if (weapon2_info.level == 7)
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
		else if(weapon2_info.level == 8)
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

		if (weapon1_info.level_hierarchy < MAX_LEVEL_HIERARCHY && lv_point <= 0)
		{
			DrawFormatString(200, 140, 0xb00000, "�|�C���g������܂���");
		}
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

			if (weapon2_info.level_hierarchy < MAX_LEVEL_HIERARCHY && lv_point <= 0)
			{
				DrawFormatString(200, 140, 0xb00000, "�|�C���g������܂���");
			}
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
		}
		else
		{
			if (weapon2_info.level_hierarchy == MAX_LEVEL_HIERARCHY)
			{
				// ����2�ŏI�����̃e�L�X�g�Q
				DrawWeapon2FinalText();
			}
		}
	}
}

// ����1�ŏI�����̃e�L�X�g�Q
void WeaponLevelUp::DrawWeapon1FinalText() const
{
	DrawFormatString(200, 140, 0xb00000, "���͍ŏI�����ł�");

	// ���x���A�b�v�J�[�\���������ɂ��鎞
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
			DrawFormatString(200, 520, 0x000000, "����");
			DrawFormatString(200, 550, 0x000000, "��������ɕω�����\n���������ۂɍU���͂�\n�オ��A�A���ōU����\n���Ă�Ɣ��ʂȂ���\n�񕜂���");
			break;
		case dagger:		// �Z��
			DrawFormatString(200, 520, 0x000000, "�����i�C�t");
			DrawFormatString(200, 550, 0x000000, "�Ə��̕����Ƀi�C�t��\n5�{���˂���\n+�_���[�W�@6 x 5");
			break;
		case greatSword:	// �匕
			DrawFormatString(200, 520, 0x000000, "���o�̑���");
			DrawFormatString(200, 550, 0x000000, "���o�������G��\n���_���[�W��^����");
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
	weapon1_info.level = 0;
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
	weapon2_info.level = 0;
	weapon2_info.level_hierarchy = 0;
	weapon2_info.cursor_pos = 0;

	for (int i = 0; i <= MAX_LEVEL_HIERARCHY; i++)
	{
		branch_point_x[1][i] = cursor_x;
		branch_point_y[1][i] = img_branch_point_y;
		is_chooce[1][i] = false;
	}
}
