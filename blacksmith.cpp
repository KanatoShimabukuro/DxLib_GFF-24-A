#include "blacksmith.h"

#include "weaponLevelup.h"
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
	img_question_mark = LoadGraph("resources/images/mark_question.png");

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
	cursor_x = 300;
	cursor_y = 320;
	level_cursor_pos = 85;
	//point = 7;
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
	text_display = false;
	is_yes = false;
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
			cursor_x = 900;
			action_number = reset_level;
			//action_number++;

			//if (action_number > reset_level)
			//{
			//	cursor_x = 580;
			//	action_number = levelup;
			//}
		}
		else if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
		{
			//���X�e�B�b�N������
			interval = 0;
			cursor_x = 300;
			action_number = levelup;

			//action_number--;

			//if (action_number < levelup)
			//{
			//	cursor_x = 960;
			//	action_number = reset_level;
			//}
		}

		// A�{�^���Ō���
		if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
		{
			action_selection = true;

			if (action_number == reset_level)
			{
				// �J�[�\���ʒu�𕐊�1�̏�ɕύX
				cursor_x = 580;
				cursor_y = 100;
			}
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
					//restore_cursor_position = true;
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

			// ����̑I��
			if (weapon_selection == false)
			{
				// �J�[�\���ړ�
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


				if (weapon_number == weapon1_info.num && weapon1_info.level != 0)
				{
					// A�{�^���ŕ���̌���
					if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
					{
						weapon_selection = true;
						text_display = true;
						cursor_y = 420;
					}
				}
				else if (weapon2_info.num != none && weapon2_info.level_hierarchy != 0)
				{
					// A�{�^���ŕ���̌���
					if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
					{
						weapon_selection = true;
						text_display = true;
						cursor_y = 420;
					}
				}

				// B�{�^���ōs���I���ɖ߂�
				if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
				{
					action_number = levelup;
					weapon_number = weapon1_info.num;
					cursor_x = 300;
					cursor_y = 320;
					action_selection = false;
				}
			}
			else
			{
				// ���x�����Z�b�g
				
				// �J�[�\�������ʒu�i�������̈ʒu�j
				//cursor_x = 960;

				// �J�[�\���ړ�
				if (InputCtrl::GetStickRatio(L).x > 0.8 && interval >= 15)
				{
					//���X�e�B�b�N���E��
					interval = 0;
					cursor_x = 960;
					is_yes = false;
				}
				else if (InputCtrl::GetStickRatio(L).x < -0.8 && interval >= 15)
				{
					//���X�e�B�b�N������
					interval = 0;
					cursor_x = 580;
					is_yes = true;
				}

				if (weapon_number == weapon1_info.num)
				{
					// ����1
					// A�{�^���Ō���
					if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
					{
						cursor_y = 450;
						if (cursor_x == 580)
						{
							// �͂�
							// �|�C���g�ԋp�A���x����0��
							weapon->SetWeaponLevel(0);
							weapon_levelup->Weapon1LevelInit();
							if (weapon1_info.level_hierarchy >= 3)
							{
								weapon_levelup->SetLevelUpPoint(3);
							}
							else
							{
								weapon_levelup->SetLevelUpPoint(weapon1_info.level_hierarchy - 1);
							}

							weapon_number = weapon1_info.num;
							cursor_x = 580;
							cursor_y = 100;
							weapon_selection = false;
							text_display = false;

							// �����ݒ�
							Init(weapon, second_weapon, weapon_levelup);
						}
						else
						{
							// ������
							weapon_number = weapon1_info.num;
							cursor_x = 580;
							cursor_y = 100;
							weapon_selection = false;
							text_display = false;
						}
					}

				}
				else
				{
					// ����2
					// A�{�^���Ō���
					if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
					{
						cursor_y = 450;

						if (cursor_x == 580)
						{
							// �͂�
							// �|�C���g�ԋp�A���x����0��
							second_weapon->SetWeaponLevel(0);
							weapon_levelup->Weapon2LevelInit();
							if (weapon2_info.level_hierarchy >= 3)
							{
								weapon_levelup->SetLevelUpPoint(3);
							}
							else
							{
								weapon_levelup->SetLevelUpPoint(weapon2_info.level_hierarchy - 1);
							}

							weapon_number = weapon1_info.num;
							cursor_x = 580;
							cursor_y = 100;
							weapon_selection = false;
							text_display = false;

							// �����ݒ�
							Init(weapon, second_weapon, weapon_levelup);
						}
						else
						{
							// ������
							weapon_number = weapon1_info.num;
							cursor_x = 580;
							cursor_y = 100;
							weapon_selection = false;
							text_display = false;
						}
					}

				}

				// B�{�^���Ń��x�����Z�b�g�L�����Z��
				if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS)
				{
					// ����I���ɖ߂�
					weapon_number = weapon1_info.num;
					weapon_selection = false;
					text_display = false;

					// ����1�̏�ɃJ�[�\���ʒu��߂�
					cursor_x = 580;
					cursor_y = 100;
				}

			}
		
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
	//DrawFormatString(160, 30, 0x000000, "W1���x���K�w : %d", weapon1_level_hierarchy);
	//DrawFormatString(160, 50, 0x000000, "W2level (State): %d", weapon2_level);
	//DrawFormatString(160, 70, 0x000000, "W2���x���K�w : %d", weapon2_level_hierarchy);

	//DrawFormatString(1000, 20, 0x000000, "���jP�F%d", point);
	//DrawFormatString(0, 0, 0x000000, "action_number�F%d", action_number);
	//DrawFormatString(0, 20, 0x000000, "GetWeaponSelection�F%d", weapon_levelup->GetIsCloseLevelUp());
	//DrawFormatString(0, 40, 0x000000, "action_selection�F%d", action_selection);
	//DrawFormatString(0, 60, 0x000000, "weapon_selection�F%d", weapon_selection);
	//DrawFormatString(0, 80, 0x000000, "action_number�F%d", action_number);
	DrawFormatString(0, 100, 0x000000, "cursor_x�F%d", cursor_x);
	DrawFormatString(0, 120, 0x000000, "cursor_y�F%d", cursor_y);
	DrawFormatString(0, 140, 0xb00000, "�L�[�{�[�hB�F����");
	DrawFormatString(0, 160, 0xb00000, "A�{�^���F����");
	DrawFormatString(0, 180, 0xb00000, "B�{�^���F�L�����Z���E�߂�");
	DrawFormatString(0, 200, 0x000000, "weapon_number %d", weapon_number);

	if (action_selection == false)
	{
		// �J�[�\���摜
		DrawRotaGraph(cursor_x, cursor_y - 50, 0.08f, 0.0f, img_cursor, TRUE);

		//DrawBox(100, 400, 200, 450, 0xff0000, TRUE);

		// �s���I�����̉摜�A�e�L�X�g�̕\��
		SetFontSize(25);
		DrawFormatString(160, 300, 0x000000, "���x���A�b�v");
		DrawFormatString(760, 300, 0x000000, "���x�����Z�b�g");

		// �摜�̕\��
		if (action_number == levelup)
		{
			DrawRotaGraph(img_x, img_y , 0.08f, 0.0f, img_hammer, TRUE);
			DrawRotaGraph(img_x, img_y + 50, 0.08f, 0.0f, img_spark, TRUE);
		}
		else
		{
			DrawRotaGraph(img_x, img_y , 0.08f, 0.0f, img_sword, TRUE);
			DrawRotaGraph(img_x, img_y + 50, 0.08f, 0.0f, img_chooce, TRUE);
			//DrawRotaGraph(img_x, img_y + 100, 0.08f, 0.0f, img_arrow, TRUE);
		}

		// �ŏI�����ł���ꍇ
		if (weapon_levelup->GetWeapon1LevelHierarchy() == MAX_LEVEL_HIERARCHY || weapon_levelup->GetWeapon2LevelHierarchy() == MAX_LEVEL_HIERARCHY)
		{
			// �r�b�N���}�[�N
			DrawRotaGraph(img_x - 400, img_y + 140, 0.08f, 0.0f, img_exclamation_mark, TRUE);

		}
	
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
			// ���x���̐U�蒼�����̉摜�A�e�L�X�g�̕\��
			DrawFormatString(500, 100, 0x000000, "���x�����Z�b�g");

			// ����摜
			// �J�[�\��
			// �m�F����

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


			// ����I���J�[�\��
			if (weapon_selection == false)
			{
				DrawRotaGraph(cursor_x, cursor_y , 0.08f, 0.0f, img_cursor, TRUE);

				// ���x���A�b�v���܂����Ă��Ȃ��ꍇ
				if (weapon_number == weapon1_info.num)
				{
					DrawFormatString(100, 280, 0xff0000, "weapon1");

					if (weapon1_info.level_hierarchy == 0)
					{
						DrawFormatString(100, 300, 0xff0000, "����̃��x����0�ł�");
						DrawFormatString(100, 320, 0xff0000, "���Z�b�g�s��");
					}
				}
				else if (weapon_number == weapon2_info.num)
				{
					DrawFormatString(100, 280, 0x0000ff, "weapon2");

					if (weapon2_info.level_hierarchy == 0)
					{
					DrawFormatString(100, 300, 0x0000ff, "����̃��x����0�ł�");
					DrawFormatString(100, 320, 0x0000ff, "���Z�b�g�s��");
					}
				}
			}
			else
			{
				DrawRotaGraph(cursor_x, cursor_y, 0.08f, 0.0f, img_cursor, TRUE);
				
				if (text_display == true)
				{
					SetFontSize(20);
					DrawFormatString(500, 300, 0x000000, "����̃��x����0�ɂ���");
					DrawFormatString(550, 450, 0x000000, "�͂�");
					DrawFormatString(950, 450, 0x000000, "������");

					if (weapon_number == weapon1_info.num)
					{
						DrawFormatString(500, 280, 0xff0000, "weapon1");
						DrawFormatString(500, 350, 0x000000, "�ԋp�|�C���g�F%d", weapon1_info.level_hierarchy - 1);
					}
					else
					{
						DrawFormatString(500, 280, 0x0000ff, "weapon2");
						DrawFormatString(500, 350, 0x000000, "�ԋp�|�C���g�F%d", weapon2_info.level_hierarchy - 1);
					}
				}

			}

		}
	}


#ifdef _DEBUG	
	//// �K�C�h���C��
	//// �c
	//DrawLine(1280 / 2, 0, 1280 / 2, 720, 0xffff00);
	//DrawLine(1280 / 2 / 2, 0, 1280 / 2 / 2, 720, 0xff0000);
	//DrawLine(1280 / 2 / 2 + 1280 / 2, 0, 1280 / 2 / 2 + 1280 / 2, 720, 0x0000ff);
	//// ��
	//DrawLine(0, 720 / 2, 1280, 720 / 2, 0xffff00);
	//DrawLine(0, 720 / 2 / 2, 1280, 720 / 2 / 2, 0xff0000);
	//DrawLine(0, 720 / 2 / 2 + 720 / 2, 1280, 720 / 2 / 2 + 720 / 2, 0x0000ff);

#endif

}

void Blacksmith::Init(weapon* weapon, second_weapon* second_weapon, WeaponLevelUp* weapon_levelup)
{
	// ���݂̕��탌�x���̃Z�b�g
	weapon1_info.level = weapon->GetWeaponLevel();
	weapon2_info.level = second_weapon->GetWeaponLevel();

	// ���x���K�w�̃Z�b�g
	weapon1_info.level_hierarchy = weapon_levelup->GetWeapon1LevelHierarchy();
	weapon2_info.level_hierarchy = weapon_levelup->GetWeapon2LevelHierarchy();
}
