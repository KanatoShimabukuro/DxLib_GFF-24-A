

#include "main.h"
#include "map_temp.h"

map_temp::map_temp() {
	// �}�b�v�f�[�^����������
	for (int i = 0; i <= DATA_MAX; i++)
	{
		MapDeta[i] = 0;
	}


	// �}�b�v����(0:�퓬�A1:�����_���C�x���g�A2:�x�e�A3:�b�艮�A4:�{�X)
	// �������e(�X�e�[�W�͈�)(�X�e�[�W��) 

	// �����_���C�x���g(st7�Œ�)
	MapDeta[7] = 1;

	// �x�e1(st3-6)(1-2)
	RandNum[0] = GetRand(1) + 1;
	for (int i = 0; i < RandNum[0];) {
		int r = GetRand(3) + 3;
		// ���ύX(0�Ȃ�)�ύX
		if (MapDeta[r] == 0) {
			MapDeta[r] = 2;
			i++;
		}
		else continue;
	}
	// �x�e2(st8-18)(2-3)
	RandNum[1] = GetRand(1) + 2;
	for (int i = 0; i < RandNum[1];) {
		int r = GetRand(11) + 8;
		// ���ύX(0�Ȃ�)�ύX
		if (MapDeta[r] == 0) {
			MapDeta[r] = 2;
			i++;
		}
		else continue;
	}
	// �x�e3(st19�Œ�)
	MapDeta[19] = 2;

	// �b�艮(st14-18)(1)
	RandNum[2] = 1;
	for (int i = 0; i < RandNum[2];) {
		int r = GetRand(5) + 14;
		// ���ύX(0�Ȃ�)�ύX
		if (MapDeta[r] == 0) {
			MapDeta[r] = 3;
			i++;
		}
		else continue;
	}

	// �{�X(st20�Œ�)
	MapDeta[20] = 4;

	// �A�C�R���ʒu���f�t�H���g�ɃZ�b�g
	for (int i = 0; i < DATA_MAX; i++)
	{
		icon_loc[i][0] = icon_loc_def[i][0];
		icon_loc[i][1] = icon_loc_def[i][1];
		icon_loc_change[i][0] = icon_loc_def[i][0];
		icon_loc_change[i][1] = icon_loc_def[i][1];
	}

	// �ړ��ʏ���������
	icon_vec = 0;
	total_vec = 0;
	change_icon = 0;
	change_icon_tab = 0;

	// �摜�Ǎ�
	if (battle_img == 0) battle_img = (LoadGraph("resources/images/skeleton.png"));
	if (event_img == 0) event_img = (LoadGraph("resources/images/event.png"));
	if (rest_img == 0) rest_img = (LoadGraph("resources/images/rest.png"));
	if (anvil_img == 0) anvil_img = (LoadGraph("resources/images/anvil.png"));
	if (boss_img == 0) boss_img = (LoadGraph("resources/images/boss.png"));
	if (map_cursor == 0) map_cursor = (LoadGraph("resources/images/map_cursor.png"));
}
map_temp::~map_temp() {
	DeleteGraph(battle_img);
	DeleteGraph(event_img);
	DeleteGraph(rest_img);
	DeleteGraph(anvil_img);
	DeleteGraph(boss_img);
	DeleteGraph(map_cursor);
}

Scene* map_temp::update() {

	// �A�C�R���ړ��������Z�b�g
	icon_vec = 0;

	// �X�N���[��
	if (InputCtrl::GetStickRatio(L).y >= 0.2 || InputCtrl::GetStickRatio(L).y <= -0.2)
	{
		// ��X�N���[��
		if (icon_loc[20][1] < 50) {
			if (InputCtrl::GetStickRatio(L).y >= 0.2 && InputCtrl::GetStickRatio(L).y < 0.5) {
				icon_vec = 1;
			}
			else if (InputCtrl::GetStickRatio(L).y >= 0.5 && InputCtrl::GetStickRatio(L).y < 0.8) {
				icon_vec = 3;
			}
			else if (InputCtrl::GetStickRatio(L).y >= 0.8) {
				icon_vec = 5;
			}
		}
		// ���X�N���[��
		if (icon_loc[0][1] > SCREEN_HEIGHT - 100) {
			if (InputCtrl::GetStickRatio(L).y <= -0.2 && InputCtrl::GetStickRatio(L).y > -0.5) {
				icon_vec = -1;
			}
			else if (InputCtrl::GetStickRatio(L).y <= -0.5 && InputCtrl::GetStickRatio(L).y > -0.8) {
				icon_vec = -3;
			}
			else if (InputCtrl::GetStickRatio(L).y <= -0.8) {
				icon_vec = -5;
			}
		}
	}

	// �A�C�R���ړ�����
	for (int i = 0; i < DATA_MAX; i++)
	{
		icon_loc[i][1] = icon_loc[i][1] + icon_vec;
	}

	// �����ړ��ʉ��Z
	total_vec = total_vec + icon_vec;

	if (InputCtrl::GetKeyState(KEY_INPUT_0) == PRESS) {
		change_icon = change_icon_tab * 10 + 0;
	}
	if (InputCtrl::GetKeyState(KEY_INPUT_1) == PRESS) {
		change_icon = change_icon_tab * 10 + 1;
	}
	if (InputCtrl::GetKeyState(KEY_INPUT_2) == PRESS) {
		change_icon = change_icon_tab * 10 + 2;
	}
	if (InputCtrl::GetKeyState(KEY_INPUT_3) == PRESS) {
		change_icon = change_icon_tab * 10 + 3;
	}
	if (InputCtrl::GetKeyState(KEY_INPUT_4) == PRESS) {
		change_icon = change_icon_tab * 10 + 4;
	}
	if (InputCtrl::GetKeyState(KEY_INPUT_5) == PRESS) {
		change_icon = change_icon_tab * 10 + 5;
	}
	if (InputCtrl::GetKeyState(KEY_INPUT_6) == PRESS) {
		change_icon = change_icon_tab * 10 + 6;
	}
	if (InputCtrl::GetKeyState(KEY_INPUT_7) == PRESS) {
		change_icon = change_icon_tab * 10 + 7;
	}
	if (InputCtrl::GetKeyState(KEY_INPUT_8) == PRESS) {
		change_icon = change_icon_tab * 10 + 8;
	}
	if (InputCtrl::GetKeyState(KEY_INPUT_9) == PRESS) {
		change_icon = change_icon_tab * 10 + 9;
	}
	if (InputCtrl::GetKeyState(KEY_INPUT_TAB) == PRESS) {
		if (DATA_MAX - 1 > (change_icon_tab + 1) * 10) {
			change_icon_tab++;
			change_icon = 10 + change_icon;
		}
		else {
			change_icon_tab = 0;
			change_icon = change_icon % 10;
		}
	}

	if (InputCtrl::GetKeyState(KEY_INPUT_UP) == PRESS) {
		icon_loc[change_icon][1] = icon_loc[change_icon][1] - 10;
		icon_loc_change[change_icon][1] = icon_loc_change[change_icon][1] - 10;
	}
	if (InputCtrl::GetKeyState(KEY_INPUT_DOWN) == PRESS) {
		icon_loc[change_icon][1] = icon_loc[change_icon][1] + 10;
		icon_loc_change[change_icon][1] = icon_loc_change[change_icon][1] + 10;
	}
	if (InputCtrl::GetKeyState(KEY_INPUT_LEFT) == PRESS) {
		icon_loc[change_icon][0] = icon_loc[change_icon][0] - 10;
		icon_loc_change[change_icon][0] = icon_loc_change[change_icon][0] - 10;
	}
	if (InputCtrl::GetKeyState(KEY_INPUT_RIGHT) == PRESS) {
		icon_loc[change_icon][0] = icon_loc[change_icon][0] + 10;
		icon_loc_change[change_icon][0] = icon_loc_change[change_icon][0] + 10;
	}

	// B��DebugScene
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_B) == PRESS) {
		return new DebugScene;
	}

	return this;
};

void map_temp::draw() const {

	for (int i = 0; i < DATA_MAX; i++)
	{
		// �f�o�b�N�\��
		DrawFormatString(10, 30, 0xffff00, "�����f�[�^");
		DrawFormatString(10 * i + 10, 50, 0xffffff, "%d", MapDeta[i]);
		DrawFormatString(10, 700, 0xffffff, "B�{�^����DebugScene");

		// �X�e�[�W�Ԃ̃��C��
		for (int j = 0; next_stage[i][j] > 0 && j <= 2; j++)
		{
			int next_loc = next_stage[i][j];

			DrawLine(icon_loc[i][0] + 25, icon_loc[i][1] + 25,
				icon_loc[next_loc][0] + 25, icon_loc[next_loc][1] + 25, 0xffffff);
		}

		// �A�C�R���\��
		switch (MapDeta[i]) {
		case 0:
			DrawGraph(icon_loc[i][0], icon_loc[i][1], battle_img, TRUE);
			break;
		case 1:
			DrawGraph(icon_loc[i][0], icon_loc[i][1], event_img, TRUE);
			break;
		case 2:
			DrawGraph(icon_loc[i][0], icon_loc[i][1], rest_img, TRUE);
			break;
		case 3:
			DrawGraph(icon_loc[i][0], icon_loc[i][1], anvil_img, TRUE);
			break;
		case 4:
			DrawGraph(icon_loc[i][0], icon_loc[i][1], boss_img, TRUE);
			break;
		default:
			break;
		}
		DrawFormatString(icon_loc[i][0], icon_loc[i][1], 0x00ff00, "%d", i);
		DrawFormatString(icon_loc[i][0] - 45, icon_loc[i][1] + 50, 0x007000, "(x:%d , y:%d)", icon_loc_change[i][0], icon_loc_change[i][1]);
	}
	DrawFormatString(0, 480, 0x00ff00, "(x:%d , y:%d)", icon_loc_change[change_icon][0], icon_loc_change[change_icon][1]);
	SetFontSize(16);
	DrawFormatString(0, 370, 0xffffff, "TAB:%d0�`%d9", change_icon_tab, change_icon_tab);
	SetFontSize(64);
	DrawFormatString(20, 400, 0xffffff, "%d", change_icon);

	// �r���`��(100��)
	//for (int i = -20; i <= 20; i++)
	//{
	//	DrawLine(-2000, 100 * i + total_vec, 2000, 100 * i + total_vec, 0xffffff); // x���W
	//	DrawLine(100 * i, -2000 + total_vec, 100 * i, 2000 + total_vec, 0xffffff); // y���W
	//}
}
