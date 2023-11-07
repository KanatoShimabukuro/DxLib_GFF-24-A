#include "scene_levelup.h"
#include"weapon.h"
#include "second_weapon.h"

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
	img_frail = LoadGraph("resources/images/sword_shortsword_brown.png");
	img_book = LoadGraph("resources/images/tsurugi_bronze_blue.png");

	// �ϐ��̏�����
	interval = 0;
	cursor_x = 580;
	cursor_y = 120;
	point = 10;
	weapon_number = 1;
	weapon_selection = false;

	img_x = 580;
	img_y = 140;

	// ���`�}�̕���_�̋N�_���W
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

	cursor_pos = 0;

	weapon1_cursor_pos = 0;
	weapon2_cursor_pos = 0;
	weapon1_level_hierarchy = 0;
	weapon2_level_hierarchy = 0;

	// ����1
	weapon1_type = NONE_WEAPON;
	weapon1_level = 0;

	// ����2
	weapon2_type = NONE_WEAPON;
	weapon2_level = 0;
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
		weapon_selection = false;
		weapon_number = 1;
		restor_cursor_position = false;
		// ���݂̕��탌�x���̃Z�b�g
		weapon1_level = weapon->GetWeaponLevel();
		weapon2_level = second_weapon->GetWeaponLevel();

		// ����̎�ނ̃Z�b�g
		weapon1_type = weapon->GetWeaponType();
		weapon2_type = second_weapon->GetWeaponType();
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
		if (weapon2_type != NONE_WEAPON)
		{
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
		}

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
				
				// �I����������_�̉摜�p�p�����[�^�̍X�V
				is_chooce[0][weapon1_level_hierarchy] = true;
				branch_point_x[0][weapon1_level_hierarchy] += weapon1_cursor_pos;
				branch_point_y[0][weapon1_level_hierarchy] += 90 * weapon1_level_hierarchy;

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

				// �I����������_�̉摜�p�p�����[�^�̍X�V
				is_chooce[1][weapon2_level_hierarchy] = true;
				branch_point_x[1][weapon2_level_hierarchy] += 380 + weapon2_cursor_pos;
				branch_point_y[1][weapon2_level_hierarchy] += 90 * weapon2_level_hierarchy;

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
				second_weapon->SetWeaponLevel(weapon2_level);
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
			// ���x���J�[�\���̈ʒu����
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
	//DrawFormatString(160, 10, 0x000000, "level1(State?) : %d", weapon1_level);
	//DrawFormatString(160, 30, 0x000000, "����1���x���K�w : %d", weapon1_level_hierarchy);
	//DrawFormatString(160, 50, 0x000000, "level2 (State?): %d", weapon2_level);
	//DrawFormatString(160, 70, 0x000000, "����2���x���K�w : %d", weapon2_level_hierarchy);

	DrawFormatString(1000, 20, 0x000000, "P�F%d", point);

	// ���x���A�b�v�̏ڍטg
	DrawBox(190, 90, 420, 680, 0x000000, FALSE);
	DrawFormatString(200, 140, 0x000000, "���x���A�b�v�ڍ�");
	DrawFormatString(200, 160, 0x000000, "��j");
	DrawFormatString(200, 180, 0x000000, "�_���[�W");
	DrawFormatString(200, 200, 0x000000, "�@15�@���@20 (+5)");
	DrawFormatString(200, 240, 0x000000, "�U�����x");
	DrawFormatString(200, 260, 0x000000, "�@10�@���@15 (+5)");
	DrawFormatString(200, 320, 0x000000, "�v���C���[�X�e�[�^�X");
	DrawFormatString(200, 360, 0x000000, "�̗�");
	DrawFormatString(200, 380, 0x000000, "�@        30");
	DrawFormatString(200, 400, 0x000000, "�ړ����x");
	DrawFormatString(200, 420, 0x000000, "�@        30");

	// ����1�̉摜
	switch (weapon1_type)
	{
		case sword:			// �Ў茕
			DrawRotaGraph(img_x, img_y, 0.2f, 0.0f, img_sword, TRUE);
			DrawFormatString(200, 100, 0x000000, "�Ў茕");
			break;
		case dagger:		// �Z��
			DrawRotaGraph(img_x, img_y, 0.18f, 0.0f, img_dagger, TRUE);
			DrawFormatString(200, 100, 0x000000, "�Z��");
			break;
		case greatSword:	// �匕
			DrawRotaGraph(img_x, img_y, 0.2f, 0.0f, img_great_sword, TRUE);
			DrawFormatString(200, 100, 0x000000, "�匕");
			break;
		default:
			DrawFormatString(img_x, img_y, 0x000000, "none");
			break;
	}

	// ����2�̉摜
	switch (weapon2_type)
	{
		case 0:
			DrawRotaGraph(img_x + 380, img_y, 0.2f, 0.0f, img_spear, TRUE);
			DrawFormatString(img_x + 400, img_y - 60, 0x000000, "��");
			break;
		case 1:
			DrawRotaGraph(img_x + 380, img_y, 0.2f, 0.0f, img_frail, TRUE);
			DrawFormatString(img_x + 400, img_y - 60, 0x000000, "�t���C��");
			break;
		case 2:
			DrawRotaGraph(img_x + 380, img_y, 0.2f, 0.0f, img_book, TRUE);
			DrawFormatString(img_x + 400, img_y - 60, 0x000000, "�{");
			break;
		default:
			DrawFormatString(img_x + 360, img_y, 0x000000, "none");
			break;
	}

	// �X�L���c���[�\��
	//DrawRotaGraph(img_x + 380, img_y + 300, 1.0f, 0.0f, img_tree_diagram, TRUE);
	
	// �X�L���c���[����_
	for (int i = 0; i <= MAX_LEVEL_HIERARCHY; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			// ���x���K�w�ɂ���ĕ���
			if (i == 0 || i == 3)
			{
				DrawRotaGraph(img_branch_point_x + 380 * j, img_branch_point_y + 90 * i, 0.08f, 0.0f, img_branch_point, TRUE);
			}
			else
			{
				DrawRotaGraph(img_branch_point_x + CURSOR_LEFT + 380 * j, img_branch_point_y + 90 * i, 0.08f, 0.0f, img_branch_point, TRUE);
				DrawRotaGraph(img_branch_point_x + CURSOR_RIGHT + 380 * j, img_branch_point_y + 90 * i, 0.08f, 0.0f, img_branch_point, TRUE);
			}
		}
	}

	// �I���������x��
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
			DrawCircle(cursor_x + weapon1_cursor_pos, cursor_y + 50 + (90 * (weapon1_level_hierarchy + 1)), 20, 0xb00000, FALSE);
			// �J�[�\���\��
			DrawRotaGraph(cursor_x + weapon1_cursor_pos, cursor_y + (90 * (weapon1_level_hierarchy + 1)), 0.08f, 0.0f, img_cursor, TRUE);
			// �ۉ摜�\��
			//DrawRotaGraph(cursor_x + weapon1_cursor_pos, cursor_y + 50 + (90 * (weapon1_level_hierarchy + 1)), 0.1f, 0.0f, img_chooce, TRUE);
		}
		else
		{
			if (weapon2_type == NONE_WEAPON)
			{
				DrawFormatString(600, 50, 0x000000, "���킪����܂���");
			}
			else
			{
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
			}
		}
	}
}