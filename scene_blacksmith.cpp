#include "scene_blacksmith.h"

#include "scene_levelup.h"
#include "weapon.h"
#include "second_weapon.h"

Blacksmith::Blacksmith()
{
	// �摜�̓Ǎ�
	//img_tree_diagram = LoadGraph("resources/images/levelup.png");
	img_cursor = LoadGraph("resources/images/levelup_cursor.png");
	//img_branch_point = LoadGraph("resources/images/branch_point.png");
	img_chooce = LoadGraph("resources/images/levelup_choose.png");
	img_hammer = LoadGraph("resources/images/hammer.png");
	img_spark = LoadGraph("resources/images/spark.png");
	img_exclamation_mark = LoadGraph("resources/images/mark_exclamation_white.png");
	img_arrow = LoadGraph("resources/images/arrow.png");

	// ����摜
	img_sword = LoadGraph("resources/images/sword_longsword_brown.png");
	img_dagger = LoadGraph("resources/images/sword_shortsword_brown.png");
	img_great_sword = LoadGraph("resources/images/tsurugi_bronze_blue.png");
	img_spear = LoadGraph("resources/images/spear.png");
	img_frail = LoadGraph("resources/images/Frailt_dottoy.png");
	img_book = LoadGraph("resources/images/tsurugi_bronze_blue.png");

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

	action_selection = false;
	action_number = levelup;
	restore_cursor_position = true;

	is_cancel = false;
	count = 0;

}

Blacksmith::~Blacksmith()
{

}

// �X�V
void Blacksmith::update(weapon* weapon, second_weapon* second_weapon, WeaponLevelUp* weapon_levelup)
{
	// �J�[�\���̈ʒu�����ɖ߂�
	//if (restor_cursor_position == true)
	//{
	//	weapon_selection = false;
	//	cursor_x = 580;
	//	weapon_number = weapon1;
	//	restor_cursor_position = false;
	//	// ���݂̕��탌�x���̃Z�b�g
	//	weapon1_level = weapon->GetWeaponLevel();
	//	weapon2_level = second_weapon->GetWeaponLevel();

	//	// ����̎�ނ̃Z�b�g
	//	weapon1_type = weapon->GetWeaponType();
	//	weapon2_type = second_weapon->GetWeaponType();
	//}

	// 15f�̃C���^�[�o��
	if (interval < 15)
	{
		interval++;
	}

	// �s���I��
	if (action_selection == false)
	{
		if (InputCtrl::GetStickRatio(L).x > 0.8 && interval >= 15)
		{
			//���X�e�B�b�N���E��
			interval = 0;
			cursor_x = 960;
			action_number++;

			if (action_number > reset_level)
			{
				cursor_x = 580;
				action_number = levelup;
			}
		}
		else if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
		{
			//���X�e�B�b�N������
			interval = 0;
			cursor_x = 580;
			action_number--;

			if (action_number < levelup)
			{
				cursor_x = 960;
				action_number = reset_level;
			}
		}

		// A�{�^���Ō���
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
		{
			action_selection = true;
		}
	}
	else
	{
		if (action_number == levelup)
		{
			// �ŏI���� or ���x���A�b�v
			weapon_levelup->SetIsBlacksmith(true);
			weapon_levelup->update(weapon, second_weapon, restore_cursor_position);

			// ���x���A�b�v��ʂŕ���̑I�������Ă����ꍇ
			if (weapon_levelup->GetIsCloseLevelUp() == true)
			{				
				// B�{�^���ōs���I���ɖ߂�
				if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
				{
					action_selection = false;
				}
			}
		}
		else if (action_number == reset_level)
		{
			// ���x���̐U�蒼���A�|�C���g�̕ԋp
			// ���ݏ������Ă��镐��̃p�����[�^��ϐ��Ɋi�[
			// ����I���i�J�[�\���ړ��j
			// A�{�^���Ō��聨�m�F������\�����������߃t���O�𗧂Ă�
			// �@yes��I���iA�{�^���j
			// �E�|�C���g�̕ԋp
			// �E�I����������̃��x���K�w��0��
			// �E�i�I����������̃��x����0�Ɂj
			// �Elevel_up �� bool is_chose[i][5] ��S�� false �Ɂi�I����������_�̉摜���\���j
			// �Ano��I���iA�{�^�� or B�{�^���j
			// �E�m�F�������\���i�t���O�Ǘ��j�ɂ��A����I���ɖ߂��i�J�[�\���ړ��j
			// B�{�^���ōs���I���ɖ߂�
			// 
		}

		//if (is_cancel == false)
		//{
		//	// B�{�^���ŃL�����Z��
		//	if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
		//	{
		//		is_cancel = true;
		//	}
		//}
		//else
		////if (is_cancel == true)
		//{
		//	count++;
		//	if (count >= 10)
		//	{
		//		action_selection = false;
		//		is_cancel = false;
		//		count = 0;
		//	}
		//}

	}

}

// �`��
void Blacksmith::draw(WeaponLevelUp* weapon_levelup) const
{
	// �w�i
	DrawBox(0, 0, 1280, 720, 0xb0c4de, TRUE);

	SetFontSize(30);
	DrawFormatString(560, 10, 0x000000, "�b��");

	// �e�X�g�\��
	SetFontSize(20);
	//DrawFormatString(160, 30, 0x000000, "W1���x���K�w : %d", weapon1_level_hierarchy);
	//DrawFormatString(160, 50, 0x000000, "W2level (State): %d", weapon2_level);
	//DrawFormatString(160, 70, 0x000000, "W2���x���K�w : %d", weapon2_level_hierarchy);

	//DrawFormatString(1000, 20, 0x000000, "���jP�F%d", point);
	DrawFormatString(0, 0, 0x000000, "action_number�F%d", action_number);
	DrawFormatString(0, 0, 0x000000, "GetWeaponSelection�F%d", weapon_levelup->GetIsCloseLevelUp());

	if (action_selection == false)
	{
		// �J�[�\���摜
		DrawRotaGraph(cursor_x, cursor_y - 50, 0.08f, 0.0f, img_cursor, TRUE);

		DrawBox(100, 400, 200, 450, 0xff0000, TRUE);

		// �s���I�����̉摜�A�e�L�X�g�̕\��
		SetFontSize(25);
		DrawFormatString(160, 300, 0x000000, "���x���A�b�v");
		DrawFormatString(760, 300, 0x000000, "���x���̐U�蒼��");

		// �摜�̕\��
		if (action_number == reset_level)
		{
			DrawRotaGraph(img_x, img_y - 50, 0.08f, 0.0f, img_hammer, TRUE);
			DrawRotaGraph(img_x, img_y - 50, 0.08f, 0.0f, img_spark, TRUE);
		}
		else
		{
			DrawRotaGraph(img_x, img_y - 50, 0.08f, 0.0f, img_sword, TRUE);
			DrawRotaGraph(img_x, img_y - 50, 0.08f, 0.0f, img_arrow, TRUE);
			DrawRotaGraph(img_x, img_y - 50, 0.08f, 0.0f, img_chooce, TRUE);
		}

		// �ŏI�����ł���ꍇ
		if (weapon_levelup->GetWeapon1LevelHierarchy() == MAX_LEVEL_HIERARCHY || weapon_levelup->GetWeapon2LevelHierarchy() == MAX_LEVEL_HIERARCHY)
		{
			// �r�b�N���}�[�N
			DrawRotaGraph(img_x, img_y - 50, 0.08f, 0.0f, img_exclamation_mark, TRUE);

		}
	
	}
	else
	{
		if (action_number == levelup)
		{
			// �ŏI���� or ���x���A�b�v���̉摜�A�e�L�X�g�̕\��
			weapon_levelup->draw();
		}
		else
		{
			// ���x���̐U�蒼�����̉摜�A�e�L�X�g�̕\��
			DrawFormatString(500, 100, 0x000000, "���x���̐U�蒼��");

			// ����摜
			// �J�[�\��
			// �m�F����
		}
	}


#ifdef _DEBUG	
	// �K�C�h���C��
	// �c
	DrawLine(1280 / 2, 0, 1280 / 2, 720, 0xffff00);
	DrawLine(1280 / 2 / 2, 0, 1280 / 2 / 2, 720, 0xff0000);
	DrawLine(1280 / 2 / 2 + 1280 / 2, 0, 1280 / 2 / 2 + 1280 / 2, 720, 0x0000ff);
	// ��
	DrawLine(0, 720 / 2, 1280, 720 / 2, 0xffff00);
	DrawLine(0, 720 / 2 / 2, 1280, 720 / 2 / 2, 0xff0000);
	DrawLine(0, 720 / 2 / 2 + 720 / 2, 1280, 720 / 2 / 2 + 720 / 2, 0x0000ff);

#endif

}
