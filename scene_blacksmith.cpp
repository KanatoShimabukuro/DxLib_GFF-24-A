#include "scene_blacksmith.h"

#include "scene_levelup.h"
#include "weapon.h"
#include "second_weapon.h"

Blacksmith::Blacksmith()
{
	// �摜�̓Ǎ�
	//img_tree_diagram = LoadGraph("resources/images/levelup.png");
	img_cursor = LoadGraph("resources/images/levelup_cursor.png");
	img_branch_point = LoadGraph("resources/images/branch_point.png");
	img_chooce = LoadGraph("resources/images/levelup_choose.png");
	// ����摜
	img_sword = LoadGraph("resources/images/sword_longsword_brown.png");
	img_dagger = LoadGraph("resources/images/sword_shortsword_brown.png");
	img_great_sword = LoadGraph("resources/images/tsurugi_bronze_blue.png");
	img_spear = LoadGraph("resources/images/spear.png");
	img_frail = LoadGraph("resources/images/Frailt_dottoy.png");
	img_book = LoadGraph("resources/images/tsurugi_bronze_blue.png");

	// �ϐ��̏�����
	interval = 0;
	cursor_x = 580;
	cursor_y = 120;
	level_cursor_pos = 85;
	point = 7;
	weapon_number = weapon1;
	weapon_selection = false;

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

	// ����1
	weapon1_type = none;
	weapon1_level = 0;
	weapon1_cursor_pos = 0;
	weapon1_level_hierarchy = 0;

	// ����2
	weapon2_type = none;
	weapon2_level = 0;
	weapon2_cursor_pos = 0;
	weapon2_level_hierarchy = 0;

	action_selection = false;
	action_number = levelup;
	restor_cursor_position = true;
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
		if (InputCtrl::GetStickRatio(L).y > 0.8 && interval >= 15)
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
		else if (InputCtrl::GetStickRatio(L).y < -0.8 && interval >= 15)
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
			// �����I�Ɂi�̂��ɓ���m�F�I�j
			weapon_levelup->update(weapon, second_weapon, restor_cursor_position);

		}
		else
		{
			// ���x���̐U�蒼���A�|�C���g�̕ԋp
		}

		// B�{�^���ŃL�����Z��
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
		{
			action_selection = false;
		}

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
	DrawFormatString(160, 10, 0x000000, "W1level(State) : %d", weapon1_level);
	DrawFormatString(160, 30, 0x000000, "W1���x���K�w : %d", weapon1_level_hierarchy);
	DrawFormatString(160, 50, 0x000000, "W2level (State): %d", weapon2_level);
	DrawFormatString(160, 70, 0x000000, "W2���x���K�w : %d", weapon2_level_hierarchy);

	DrawFormatString(1000, 20, 0x000000, "���jP�F%d", point);

	if (action_selection == false)
	{
		// �s���I�����̉摜�A�e�L�X�g�̕\��
		SetFontSize(25);
		DrawFormatString(160, 300, 0x000000, "���x���A�b�v");
		DrawFormatString(760, 300, 0x000000, "���x���̐U�蒼��");

	}
	else
	{
		if (action_number == levelup)
		{
			// �ŏI���� or ���x���A�b�v���̉摜�A�e�L�X�g�̕\��
			// �����I�Ɂi�̂��ɓ���m�F�I�j
			weapon_levelup->draw();
		}
		else
		{
			// ���x���̐U�蒼�����̉摜�A�e�L�X�g�̕\��
		}
	}
}
