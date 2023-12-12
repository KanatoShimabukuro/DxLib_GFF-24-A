#include "main.h"

Blacksmith::Blacksmith()
{
	// �摜�̓Ǎ�
	img_cursor = LoadGraph("resources/images/levelup_cursor.png");
	img_chooce = LoadGraph("resources/images/blacksmith_choose.png");
	img_hammer = LoadGraph("resources/images/hammer.png");
	img_spark = LoadGraph("resources/images/spark.png");
	img_exclamation_mark = LoadGraph("resources/images/mark_exclamation_white.png");
	img_arrow = LoadGraph("resources/images/arrow.png");
	img_button_b = LoadGraph("resources/images/button_b.png");
	img_button_a = LoadGraph("resources/images/button_a01.png");
	img_background = LoadGraph("resources/images/stageimage2.png");

	// ����摜
	img_sword = LoadGraph("resources/images/����/�Ў茕.png");
	img_dagger = LoadGraph("resources/images/����/�Z��.png");
	img_great_sword = LoadGraph("resources/images/����/�匕.png");
	img_spear = LoadGraph("resources/images/����/��.png");
	img_frail = LoadGraph("resources/images/����/�t���C��.png");
	img_book = LoadGraph("resources/images/����/�{.png");
	img_question_mark = LoadGraph("resources/images/mark_question.png");

	// �\���̏�����
	weapon1_info = { 0, none, 0, 0, 0, false };
	weapon2_info = { 1, none, 0, 0, 0, false };

	// �ϐ��̏�����
	interval = 0;
	cursor_x = 370;
	cursor_y = 320;
	weapon_number = weapon1_info.num;

	// �摜�p�����[�^
	img_x = 380;
	img_y = 350;

	action_selection = false;
	action_number = levelup;
	restore_cursor_position = true;
	cursor_action = state_first;
	box_color = 0x696868;
	box_color_hover = 0xb0b0b0;
	value = 80;
}

Blacksmith::~Blacksmith()
{
	DeleteGraph(img_cursor);
	DeleteGraph(img_chooce);
	DeleteGraph(img_hammer);
	DeleteGraph(img_spark);
	DeleteGraph(img_exclamation_mark);
	DeleteGraph(img_arrow);
	DeleteGraph(img_button_b);
	DeleteGraph(img_button_a);
	DeleteGraph(img_background);
	DeleteGraph(img_sword);
	DeleteGraph(img_dagger);
	DeleteGraph(img_great_sword);
	DeleteGraph(img_spear);
	DeleteGraph(img_frail);
	DeleteGraph(img_book);
	DeleteGraph(img_question_mark);
}

// �X�V
void Blacksmith::update(weapon* weapon, second_weapon* second_weapon, WeaponLevelUp* weapon_levelup, Player* player, int& point, int& mode, int& stage)
{
	SoundManager::PlaySoundBGM("bgm_smith");

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
			//�J�[�\���̌��艹
			SoundManager::PlaySoundSE("se_system_normal_decision");
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
			weapon_levelup->SetIsBlacksmith(false);
			stage++;
			SoundManager::StopSoundBGM("bgm_smith");
			SoundManager::SetSoundBGMsPosition(0);
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
					//�J�[�\���̃L�����Z����
					SoundManager::PlaySoundSE("se_system_cancel", false);

					// ���x���A�b�v��ʂ̕ϐ�������
					// ���x���A�b�v��ʂ�����Ƃ��ɏ��������Ȃ��Ɖ摜�̕\���ʒu�����������Ȃ��Ă��܂�
					weapon_levelup->Init(weapon, second_weapon, player, restore_cursor_position);

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
					//�J�[�\���̌��艹
					SoundManager::PlaySoundSE("se_system_normal_decision");
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
			else
			{
				if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
				{
					//�J�[�\����NG��
					SoundManager::PlaySoundSE("se_system_ng", false);
				}
			}

			// B�{�^���ōs���I���ɖ߂�
			if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
			{
				//�J�[�\���̃L�����Z����
				SoundManager::PlaySoundSE("se_system_cancel", false);

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
	//DrawBox(0, 0, 1280, 720, 0x808080, TRUE);
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
	//SetFontSize(20);
	//DrawFormatString(160, 30, 0x000000, "W1���x���K�w : %d", weapon1_level_hierarchy);
	//DrawFormatString(160, 50, 0x000000, "W2level (State): %d", weapon2_level);
	//DrawFormatString(160, 70, 0x000000, "W2���x���K�w : %d", weapon2_level_hierarchy);

	//DrawFormatString(0, 0, 0x000000, "action_number�F%d", action_number);
	//DrawFormatString(0, 20, 0x000000, "GetWeaponSelection�F%d", weapon_levelup->GetIsCloseLevelUp());
	//DrawFormatString(0, 40, 0x000000, "action_selection�F%d", action_selection);
	//DrawFormatString(0, 60, 0x000000, "weapon_selection�F%d", weapon_selection);
	//DrawFormatString(0, 80, 0x000000, "action_number�F%d", action_number);
	//DrawFormatString(0, 100, 0x000000, "cursor_x�F%d", cursor_x);
	//DrawFormatString(0, 120, 0x000000, "cursor_y�F%d", cursor_y);
	//DrawFormatString(0, 200, 0x000000, "weapon_number %d", weapon_number);
	//DrawFormatString(0, 220, 0x000000, "cursor_action %d", cursor_action);
	//DrawFormatString(0, 240, 0x000000, "cursor_x %d", cursor_x);
	//DrawFormatString(0, 260, 0x000000, "cursor_y %d", cursor_y);
	//DrawFormatString(0, 280, 0x000000, "action_number %d", action_number);

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
		//�J�[�\���̈ړ���
		SoundManager::PlaySoundSE("se_system_select_syu", false);

		//���X�e�B�b�N���E��
		interval = 0;

		if (cursor_action == state_first)
		{
			cursor_x = 900;
			action_number = reset_level;
		}
		else
		{
			cursor_x = img_x + 510;
			weapon_number = weapon2_info.num;
		}
	}
	else if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
	{
		//�J�[�\���̈ړ���
		SoundManager::PlaySoundSE("se_system_select_syu", false);

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
	if (info->level_hierarchy >= 4)
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

	SetFontSize(50);
	if (action_number == levelup)
	{		
		DrawBox(170, 130, 570, 590, box_color_hover, TRUE);
		DrawBox(710, 130, 1110, 590, box_color, TRUE);

		DrawRotaGraph(430, 280, 0.5f, 0.0f, img_hammer, TRUE);
		DrawRotaGraph(250, 370, 0.2f, 0.0f, img_spark, TRUE);
		DrawFormatString(210, 520, 0x000000, "���x���A�b�v");

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, value);

		DrawRotaGraph(1030, 210, 0.2f, 0.0f, img_sword, TRUE);
		DrawRotaGraph(900, 300, 0.2f, M_PI / -4.0f, img_arrow, TRUE);
		DrawRotaGraph(800, 400, 1.0f, 0.0f, img_chooce, TRUE);
		DrawFormatString(740, 520, 0x000000, "���x�����Z�b�g");
		
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	else
	{
		DrawBox(170, 130, 570, 590, box_color, TRUE);
		DrawBox(710, 130, 1110, 590, box_color_hover, TRUE);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, value);

		DrawRotaGraph(430, 280, 0.5f, 0.0f, img_hammer, TRUE);
		DrawRotaGraph(250, 370, 0.2f, 0.0f, img_spark, TRUE);
		DrawFormatString(210, 520, 0x000000, "���x���A�b�v");

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		DrawRotaGraph(1030, 210, 0.2f, 0.0f, img_sword, TRUE);
		DrawRotaGraph(900, 300, 0.2f, M_PI / -4.0f, img_arrow, TRUE);
		DrawRotaGraph(800, 400, 1.0f, 0.0f, img_chooce, TRUE);
		DrawFormatString(740, 520, 0x000000, "���x�����Z�b�g");
	}

	// �ŏI�����ł���ꍇ
	if (weapon_levelup->GetWeapon1LevelHierarchy() == MAX_LEVEL_HIERARCHY || weapon_levelup->GetWeapon2LevelHierarchy() == MAX_LEVEL_HIERARCHY)
	{
		// �r�b�N���}�[�N
		DrawRotaGraph(170, 130, 0.2f, 0.0f, img_exclamation_mark, TRUE);
	}

	DrawBox(1020, 660, 1240, 710, box_color_hover, TRUE);

	DrawRotaGraph(1050, 685, 0.25f, 0.0f, img_button_a, TRUE);
	DrawRotaGraph(1150, 685, 0.25f, 0.0f, img_button_b, TRUE);

	SetFontSize(20);
	DrawFormatString(1080, 675, 0x000000, "����");
	DrawFormatString(1180, 675, 0x000000, "�o��");
}

// ���x�����Z�b�g��ʕ`��
void Blacksmith::DrawResetLevel(WeaponLevelUp* weapon_levelup) const
{
	DrawBox(490, 35, 790, 110, box_color_hover, TRUE);

	SetFontSize(35);
	DrawFormatString(510, 45, 0x000000, "���x�����Z�b�g");
	SetFontSize(15);
	DrawFormatString(530, 85, 0xb00000, "����̃��x����0�ɂȂ�܂�");

	SetFontSize(20);
	if (weapon_number == weapon1_info.num)
	{
		DrawBox(230, 200, 530, 600, box_color_hover, TRUE);
		DrawBox(740, 200, 1040, 600, box_color, TRUE);

		// ����1�̉摜�A�e�L�X�g
		DrawWeapon1Images();
		DrawWeapon1ResetText();

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, value);
		
		// ����2�̉摜�A�e�L�X�g
		DrawWeapon2Images();
		DrawWeapon2ResetText();

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	else
	{
		DrawBox(230, 200, 530, 600, box_color, TRUE);
		DrawBox(740, 200, 1040, 600, box_color_hover, TRUE);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, value);

		// ����1�̉摜�A�e�L�X�g
		DrawWeapon1Images();
		DrawWeapon1ResetText();

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		// ����2�̉摜�A�e�L�X�g
		DrawWeapon2Images();
		DrawWeapon2ResetText();
	}

	// �J�[�\���摜
	DrawRotaGraph(cursor_x, cursor_y, 0.1f, 0.0f, img_cursor, TRUE);

	DrawBox(1020, 660, 1240, 710, box_color_hover, TRUE);

	DrawRotaGraph(1050, 685, 0.25f, 0.0f, img_button_a, TRUE);
	DrawRotaGraph(1150, 685, 0.25f, 0.0f, img_button_b, TRUE);

	//SetFontSize(20);
	DrawFormatString(1080, 675, 0x000000, "����");
	DrawFormatString(1180, 675, 0x000000, "�߂�");
}

// ����1�̉摜�`��
void Blacksmith::DrawWeapon1Images() const
{
	// ����1�̉摜
	switch (weapon1_info.type)
	{
	case sword:			// �Ў茕
		DrawRotaGraph(img_x, img_y, 0.28f, 0.0f, img_sword, TRUE);
		DrawFormatString(290, 520, 0x000000, "�Ў茕");
		break;
	case dagger:		// �Z��
		DrawRotaGraph(img_x, img_y, 0.28f, 0.0f, img_dagger, TRUE);
		DrawFormatString(290, 520, 0x000000, "�Z��");
		break;
	case greatSword:	// �匕
		DrawRotaGraph(img_x, img_y, 0.4f, 0.0f, img_great_sword, TRUE);
		DrawFormatString(290, 520, 0x000000, "�匕");
		break;
	default:
		DrawRotaGraph(img_x, img_y, 0.2f, 0.0f, img_question_mark, TRUE);
		DrawFormatString(290, 520, 0x000000, "���킪����܂���");
		break;
	}
}

// ����2�̉摜�`��
void Blacksmith::DrawWeapon2Images() const
{
	// ����2�̉摜
	switch (weapon2_info.type)
	{
	case spear:			// ��
		DrawRotaGraph(img_x + 510, img_y, 0.34f, 0.0f, img_spear, TRUE);
		DrawFormatString(800, 520, 0x000000, "��");
		break;
	case frail:			// �t���C��
		DrawRotaGraph(img_x + 510, img_y, 0.34f, 0.0f, img_frail, TRUE);
		DrawFormatString(800, 520, 0x000000, "�t���C��");
		break;
	case book:			// ������
		DrawRotaGraph(img_x + 510, img_y, 0.28f, 0.0f, img_book, TRUE);
		DrawFormatString(800, 520, 0x000000, "������");
		break;
	default:
		DrawRotaGraph(img_x + 510, img_y, 0.2f, 0.0f, img_question_mark, TRUE);
		DrawFormatString(800, 520, 0x000000, "���킪����܂���");
		break;
	}
}

// ����1�̏��̃e�L�X�g
void Blacksmith::DrawWeapon1ResetText() const
{
	DrawFormatString(290, 540, 0x000000, "Lv. %d", weapon1_info.level);

	if (weapon1_info.can_reset == false)
	{
		DrawFormatString(290, 560, 0xb00000, "���x�����Z�b�g�s��");
	}
	else
	{
		if (weapon1_info.level_hierarchy > 0 && weapon1_info.level_hierarchy <= 3)
		{
			DrawFormatString(290, 560, 0x000000, "�ԋp�|�C���g�F %d", weapon1_info.level_hierarchy - 1);
		}
		else if (weapon1_info.level_hierarchy > 3)
		{
			DrawFormatString(290, 560, 0x000000, "�ԋp�|�C���g�F 3");
		}
	}
}

// ����2�̏��̃e�L�X�g
void Blacksmith::DrawWeapon2ResetText() const
{
	// ����2
	DrawFormatString(800, 540, 0x000000, "Lv. %d", weapon2_info.level);
	if (weapon2_info.can_reset == false)
	{
		DrawFormatString(800, 560, 0xb00000, "���x�����Z�b�g�s��");
	}
	else
	{
		if (weapon2_info.level_hierarchy > 0 && weapon2_info.level_hierarchy <= 3)
		{
			DrawFormatString(800, 560, 0x000000, "�ԋp�|�C���g�F %d", weapon2_info.level_hierarchy - 1);
		}
		else if (weapon2_info.level_hierarchy > 3)
		{
			DrawFormatString(800, 560, 0x000000, "�ԋp�|�C���g�F 3");
		}
	}
}