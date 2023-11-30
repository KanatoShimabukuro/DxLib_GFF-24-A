#include "main.h"

Blacksmith::Blacksmith()
{
	// �摜�̓Ǎ�
	img_cursor = LoadGraph("resources/images/levelup_cursor.png");
	img_chooce = LoadGraph("resources/images/levelup_choose.png");
	img_hammer = LoadGraph("resources/images/hammer.png");
	img_spark = LoadGraph("resources/images/spark.png");
	img_exclamation_mark = LoadGraph("resources/images/mark_exclamation_white.png");
	img_arrow = LoadGraph("resources/images/arrow.png");
	img_question_mark = LoadGraph("resources/images/mark_question.png");
	img_button_b = LoadGraph("resources/images/button_b.png");
	// �e�X�g�p
	img_background = LoadGraph("resources/images/stageimage2.png");

	// ����摜
	img_sword = LoadGraph("resources/images/sword_longsword_brown.png");
	img_dagger = LoadGraph("resources/images/sword_shortsword_brown.png");
	img_great_sword = LoadGraph("resources/images/tsurugi_bronze_blue.png");
	img_spear = LoadGraph("resources/images/spear.png");
	img_frail = LoadGraph("resources/images/Frailt_dottoy.png");
	img_book = LoadGraph("resources/images/book_madousyo_necronomicon.png");

	// �\���̏�����
	weapon1_info = { 0, none, 0, 0, 0, false };
	weapon2_info = { 1, none, 0, 0, 0, false };

	// �ϐ��̏�����
	interval = 0;
	cursor_x = 370;
	cursor_y = 320;
	weapon_number = weapon1_info.num;
	//is_blacksmith = false;

	// �摜�p�����[�^
	img_x = 350;
	img_y = 350;

	action_selection = false;
	action_number = levelup;
	restore_cursor_position = true;
	cursor_action = state_first;
}

Blacksmith::~Blacksmith()
{

}

// �X�V
void Blacksmith::update(weapon* weapon, second_weapon* second_weapon, WeaponLevelUp* weapon_levelup, Player* player, int& point, int& mode, int& stage)
{
	// 15f�̃C���^�[�o��
	if (interval < 15)
	{
		interval++;
	}

	// �s���I��
	if (action_selection == false)
	{
		// �J�[�\�����E�ړ�
		CursorMove();

		// A�{�^���Ō���
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
		{
			action_selection = true;

			if (action_number == reset_level)
			{
				cursor_action = state_weapon;
				// �J�[�\���ʒu�𕐊�1�̏�ɕύX
				cursor_x = img_x;
				cursor_y = 160;
			}
		}

		// B�{�^���ŏo��
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
		{
			stage++;
			mode = GameSceneMode::map;
		}
	}
	else
	{
		if (action_number == levelup)
		{
			// �ŏI���� or ���x���A�b�v
			weapon_levelup->SetIsBlacksmith(true);
			weapon_levelup->update(weapon, second_weapon, player, restore_cursor_position, point);

			// ���x���A�b�v��ʂŕ���̑I�������Ă����ꍇ
			if (weapon_levelup->GetIsCloseLevelUp() == true)
			{
				// B�{�^���ōs���I���ɖ߂�
				if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
				{
					// ���x���A�b�v��ʂ̕ϐ�������
					// ���x���A�b�v��ʂ�����Ƃ��ɏ��������Ȃ��Ɖ摜�̕\���ʒu�����������Ȃ��Ă��܂�
					//restore_cursor_position = true;
					weapon_levelup->Init(weapon, second_weapon, restore_cursor_position);

					action_selection = false;
				}
			}
		}
		else
		{
			// ���x���̐U�蒼���A�|�C���g�̕ԋp


			// ����̎�ނ̃Z�b�g
			weapon1_info.type = weapon->GetWeaponType();
			weapon2_info.type = second_weapon->GetWeaponType();

			// �����ݒ�
			Init(weapon, second_weapon, weapon_levelup);

			// �J�[�\�����E�ړ�
			CursorMove();

			// ����̌���
			if (weapon_number == weapon1_info.num && weapon1_info.level != 0)
			{
				weapon1_info.can_reset = true;

				// �ߋ��Ƀ��x���A�b�v�������Ƃ�����ꍇ�I���ł���
				if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
				{
					ResetLevel(weapon, second_weapon, weapon_levelup, &weapon1_info, point);
				}
			}
			else if (weapon2_info.num != none && weapon2_info.level_hierarchy != 0)
			{
				weapon2_info.can_reset = true;

				if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
				{
					ResetLevel(weapon, second_weapon, weapon_levelup, &weapon2_info, point);
				}
			}

			// B�{�^���ōs���I���ɖ߂�
			if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
			{
				cursor_action = state_first;
				action_number = levelup;
				weapon_number = weapon1_info.num;
				cursor_x = 370;
				cursor_y = 320;
				action_selection = false;
			}
		}
	}
}

// �`��
void Blacksmith::draw(WeaponLevelUp* weapon_levelup) const
{
	// �w�i
	DrawBox(0, 0, 1280, 720, 0x808080, TRUE);
	DrawGraph(0, 0, img_background, TRUE);

	if (action_selection == false)
	{
		// �s���I�����̕`��
		FirstDraw(weapon_levelup);
	}
	else
	{
		// �s���I���ς�
		if (action_number == levelup)
		{
			// �ŏI���� or ���x���A�b�v���̉摜�A�e�L�X�g�̕\��
			weapon_levelup->draw();
		}
		else
		{
			// ���x�����Z�b�g��ʕ`��
			DrawResetLevel(weapon_levelup);
		}
	}


#ifdef _DEBUG	
	// �e�X�g�\��
	SetFontSize(20);
	//DrawFormatString(160, 30, 0x000000, "W1���x���K�w : %d", weapon1_level_hierarchy);
	//DrawFormatString(160, 50, 0x000000, "W2level (State): %d", weapon2_level);
	//DrawFormatString(160, 70, 0x000000, "W2���x���K�w : %d", weapon2_level_hierarchy);

	//DrawFormatString(1000, 20, 0x000000, "���jP�F%d", point);
	//DrawFormatString(0, 0, 0x000000, "action_number�F%d", action_number);
	//DrawFormatString(0, 20, 0x000000, "GetWeaponSelection�F%d", weapon_levelup->GetIsCloseLevelUp());
	//DrawFormatString(0, 40, 0x000000, "action_selection�F%d", action_selection);
	//DrawFormatString(0, 60, 0x000000, "weapon_selection�F%d", weapon_selection);
	//DrawFormatString(0, 80, 0x000000, "action_number�F%d", action_number);
	//DrawFormatString(0, 100, 0x000000, "cursor_x�F%d", cursor_x);
	//DrawFormatString(0, 120, 0x000000, "cursor_y�F%d", cursor_y);
	//DrawFormatString(0, 140, 0xb00000, "�L�[�{�[�hB�F����");
	//DrawFormatString(0, 160, 0xb00000, "A�{�^���F����");
	//DrawFormatString(0, 180, 0xb00000, "B�{�^���F�L�����Z���E�߂�");
	//DrawFormatString(0, 200, 0x000000, "weapon_number %d", weapon_number);
	//DrawFormatString(0, 220, 0x000000, "cursor_action %d", cursor_action);
	//DrawFormatString(0, 240, 0x000000, "cursor_x %d", cursor_x);
	//DrawFormatString(0, 260, 0x000000, "cursor_y %d", cursor_y);
	//DrawFormatString(0, 280, 0x000000, "action_number %d", action_number);

	// �K�C�h���C��
	// �c
	//DrawLine(1280 / 2, 0, 1280 / 2, 720, 0xffffaa);
	//DrawLine(1280 / 2 / 2, 0, 1280 / 2 / 2, 720, 0xffaaaa);
	//DrawLine(1280 / 2 / 2 + 1280 / 2, 0, 1280 / 2 / 2 + 1280 / 2, 720, 0xaaaaff);
	//// ��
	//DrawLine(0, 720 / 2, 1280, 720 / 2, 0xffffaa);
	//DrawLine(0, 720 / 2 / 2, 1280, 720 / 2 / 2, 0xffaaaa);
	//DrawLine(0, 720 / 2 / 2 + 720 / 2, 1280, 720 / 2 / 2 + 720 / 2, 0xaaaaff);
	
//	DrawFormatString(0, 0, 0x000000, "�J�[�\���ʒu: %d - %d", InputCtrl::GetMouseCursor().x, InputCtrl::GetMouseCursor().y);
#endif

}

// �����ݒ�
void Blacksmith::Init(weapon* weapon, second_weapon* second_weapon, WeaponLevelUp* weapon_levelup)
{
	// ���݂̕��탌�x���̃Z�b�g
	weapon1_info.level = weapon->GetWeaponLevel();
	weapon2_info.level = second_weapon->GetWeaponLevel();

	// ���x���K�w�̃Z�b�g
	weapon1_info.level_hierarchy = weapon_levelup->GetWeapon1LevelHierarchy();
	weapon2_info.level_hierarchy = weapon_levelup->GetWeapon2LevelHierarchy();
}

// �J�[�\�����E�ړ�����
void Blacksmith::CursorMove()
{
	if (InputCtrl::GetStickRatio(L).x > 0.8 && interval >= 15)
	{
		//���X�e�B�b�N���E��
		interval = 0;

		if (cursor_action == state_first)
		{
			cursor_x = 900;
			action_number = reset_level;
		}
		else
		{
			cursor_x = img_x + 555;
			weapon_number = weapon2_info.num;
		}
	}
	else if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
	{
		//���X�e�B�b�N������
		interval = 0;

		if (cursor_action == state_first)
		{
			cursor_x = 370;
			action_number = levelup;
		}
		else
		{
			cursor_x = img_x;
			weapon_number = weapon1_info.num;
		}
	}
}

// ���x�����Z�b�g
void Blacksmith::ResetLevel(weapon* weapon, second_weapon* second_weapon, WeaponLevelUp* weapon_levelup, weapon_information* info, int& point)
{
	// ���x�����Z�b�g
	if (info->num == weapon1_info.num)
	{
		// ����1
		weapon->SetWeaponLevel(0);
		weapon_levelup->Weapon1LevelInit();
	}
	else
	{
		// ����2
		second_weapon->SetWeaponLevel(0);
		weapon_levelup->Weapon2LevelInit();
	}

	// �|�C���g�̕ԋp
	if (info->level_hierarchy >= 3)
	{
		weapon_levelup->SetLevelUpPoint(point, 3);
	}
	else
	{
		weapon_levelup->SetLevelUpPoint(point, info->level_hierarchy - 1);
	}

	info->can_reset = false;

	// �����ݒ�
	Init(weapon, second_weapon, weapon_levelup);

}

// �s���I�����̕`��
void Blacksmith::FirstDraw(WeaponLevelUp* weapon_levelup) const
{
	// �J�[�\���摜
	DrawRotaGraph(cursor_x , 100, 0.1f, 0.0f, img_cursor, TRUE);

	DrawBox(170, 130, 570, 590, 0xaa0000, TRUE);
	DrawBox(710, 130, 1110, 590, 0xaa0000, TRUE);

	if (action_number == reset_level)
	{
		DrawBox(170, 130, 570, 590, 0xd3d3d3, TRUE);
	}
	else
	{
		DrawBox(710, 130, 1110, 590, 0xd3d3d3, TRUE);
	}

	SetFontSize(50);
	DrawFormatString(740, 520, 0x000000, "���x�����Z�b�g");
	DrawFormatString(210, 520, 0x000000, "���x���A�b�v");

	// �摜�̕\��
	DrawRotaGraph(430, 280, 0.5f, 0.0f, img_hammer, TRUE);
	DrawRotaGraph(250, 370, 0.2f, 0.0f, img_spark, TRUE);
	DrawRotaGraph(1030, 210, 0.2f, 0.0f, img_sword, TRUE);
	DrawRotaGraph(930, 270, 0.2f, M_PI / - 4.0f, img_arrow, TRUE);
	DrawRotaGraph(780, 340, 0.15f, 0.0f, img_chooce, TRUE);
	DrawRotaGraph(840, 355, 0.15f, 0.0f, img_chooce, TRUE);
	DrawRotaGraph(800, 390, 0.15f, 0.0f, img_chooce, TRUE);

	// �ŏI�����ł���ꍇ
	if (weapon_levelup->GetWeapon1LevelHierarchy() == MAX_LEVEL_HIERARCHY || weapon_levelup->GetWeapon2LevelHierarchy() == MAX_LEVEL_HIERARCHY)
	{
		// �r�b�N���}�[�N
		DrawRotaGraph(170, 130, 0.2f, 0.0f, img_exclamation_mark, TRUE);
	}

	DrawBox(1100, 660, 1250, 710, 0xd3d3d3, TRUE);
	DrawRotaGraph(1150, 685, 0.25f, 0.0f, img_button_b, TRUE);
	SetFontSize(20);
	//DrawFormatString(1100, 675, 0x000000, "B�L�[��");
	DrawFormatString(1180, 675, 0x000000, "�o��");
}

// ���x�����Z�b�g��ʕ`��
void Blacksmith::DrawResetLevel(WeaponLevelUp* weapon_levelup) const
{
	DrawBox(200, 200, 500, 600, 0x909090, TRUE);
	DrawBox(770, 200, 1070, 600, 0x909090, TRUE);
	if (weapon_number == weapon1_info.num)
	{
		DrawBox(200, 200, 500, 600, 0xd3d3d3, TRUE);
	}
	else
	{
		DrawBox(770, 200, 1070, 600, 0xd3d3d3, TRUE);
	}

	DrawBox(490, 35, 790, 120, 0xd3d3d3, TRUE);
	SetFontSize(35);
	DrawFormatString(510, 45, 0x000000, "���x�����Z�b�g");
	SetFontSize(15);
	DrawFormatString(530, 100, 0xb00000, "����̃��x����0�ɂȂ�܂�");

	// ����̉摜�`��
	DrawWeaponImages();

	// ����̏��̃e�L�X�g
	DrawResetLevelText();

	// �J�[�\���摜
	DrawRotaGraph(cursor_x, cursor_y, 0.1f, 0.0f, img_cursor, TRUE);
	DrawBox(1100, 660, 1250, 710, 0xd3d3d3, TRUE);
	DrawRotaGraph(1150, 685, 0.25f, 0.0f, img_button_b, TRUE);
	DrawFormatString(1180, 675, 0x000000, "�߂�");
}

// ����̉摜�`��
void Blacksmith::DrawWeaponImages() const
{
	SetFontSize(20);
	// ����1�̉摜
	switch (weapon1_info.type)
	{
	case sword:			// �Ў茕
		DrawRotaGraph(img_x, img_y, 0.4f, 0.0f, img_sword, TRUE);
		DrawFormatString(250, 530, 0x000000, "�Ў茕");
		break;
	case dagger:		// �Z��
		DrawRotaGraph(img_x, img_y, 0.4f, 0.0f, img_dagger, TRUE);
		DrawFormatString(250, 530, 0x000000, "�Z��");
		break;
	case greatSword:	// �匕
		DrawRotaGraph(img_x, img_y, 0.4f, 0.0f, img_great_sword, TRUE);
		DrawFormatString(250, 530, 0x000000, "�匕");
		break;
	default:
		DrawRotaGraph(img_x, img_y, 0.2f, 0.0f, img_question_mark, TRUE);
		DrawFormatString(250, 530, 0x000000, "���킪����܂���");
		break;
	}

	// ����2�̉摜
	switch (weapon2_info.type)
	{
	case spear:			// ��
		DrawRotaGraph(img_x + 570, img_y, 0.4f, 0.0f, img_spear, TRUE);
		DrawFormatString(830, 530, 0x000000, "��");
		break;
	case frail:			// �t���C��
		DrawRotaGraph(img_x + 570, img_y, 0.4f, 0.0f, img_frail, TRUE);
		DrawFormatString(830, 530, 0x000000, "�t���C��");
		break;
	case book:			// ������
		DrawRotaGraph(img_x + 570, img_y, 0.4f, 0.0f, img_book, TRUE);
		DrawFormatString(830, 530, 0x000000, "������");
		break;
	default:
		DrawRotaGraph(img_x + 570, img_y, 0.2f, 0.0f, img_question_mark, TRUE);
		DrawFormatString(830, 530, 0x000000, "���킪����܂���");
		break;
	}

}

// ����̏��̃e�L�X�g
void Blacksmith::DrawResetLevelText() const
{
	SetFontSize(20);
	// ����1
	DrawFormatString(250, 550, 0x000000, "Lv�K�w %d", weapon1_info.level_hierarchy);
	DrawFormatString(400, 550, 0x000000, "Lv. %d", weapon1_info.level);

	if (weapon1_info.can_reset == false)
	{
		DrawFormatString(250, 570, 0xb00000, "���x�����Z�b�g�s��");
	}
	else
	{
		if (weapon1_info.level_hierarchy > 0 && weapon1_info.level_hierarchy <= 3)
		{
			DrawFormatString(250, 570, 0x000000, "�ԋp�|�C���g�F %d", weapon1_info.level_hierarchy - 1);
		}
		else if (weapon1_info.level_hierarchy > 3)
		{
			DrawFormatString(250, 570, 0x000000, "�ԋp�|�C���g�F 3");
		}
	}

	// ����2
	DrawFormatString(830, 550, 0x000000, "Lv. %d", weapon2_info.level_hierarchy);
	if (weapon2_info.can_reset == false)
	{
		DrawFormatString(830, 570, 0xb00000, "���x�����Z�b�g�s��");
	}
	else
	{
		if (weapon2_info.level_hierarchy > 0 && weapon2_info.level_hierarchy <= 3)
		{
			DrawFormatString(830, 570, 0x000000, "�ԋp�|�C���g�F %d", weapon2_info.level_hierarchy - 1);
		}
		else if (weapon2_info.level_hierarchy > 3)
		{
			DrawFormatString(830, 570, 0x000000, "�ԋp�|�C���g�F 3");
		}
	}

}
