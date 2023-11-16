//#include "map.h"
#include "main.h"

Map::Map(GameUI* ui) {

	// �A�C�R���ʒu���f�t�H���g�ɃZ�b�g
	for (int i = 0; i < DATA_MAX; i++)
	{
		icon_loc[i][0] = icon_loc_def[i][0];
		icon_loc[i][1] = icon_loc_def[i][1];
	}

	this->ui = ui;
	rest = new Rest(ui);

	// �A�C�R���ړ�����������
	icon_vec = 0;
	cursor_pos = 0;
	cursor_loc = 0;
	move_cool = 0;
	cursor_move = FALSE;
	now_stage = DATA_MAX - 1;

	is_map_mode = true;

	is_rest = false;
	is_show_rest = false;

	// �摜�Ǎ�
	if (battle_img == 0) battle_img = (LoadGraph("resources/images/skeleton.png"));
	if (event_img == 0) event_img = (LoadGraph("resources/images/event.png"));
	if (rest_img == 0) rest_img = (LoadGraph("resources/images/rest.png"));
	if (anvil_img == 0) anvil_img = (LoadGraph("resources/images/anvil.png"));
	if (boss_img == 0) boss_img = (LoadGraph("resources/images/boss.png"));
	if (icon_back_img == 0) icon_back_img = (LoadGraph("resources/images/icon_back.png"));
	if (map_cursor == 0) map_cursor = (LoadGraph("resources/images/map_cursor.png"));
}
Map::~Map() {
	DeleteGraph(battle_img);
	DeleteGraph(event_img);
	DeleteGraph(rest_img);
	DeleteGraph(anvil_img);
	DeleteGraph(boss_img);
	DeleteGraph(map_cursor);
	delete rest;
}

int Map::update(int& mode, bool& weapon_selected) {

	// �A�C�R���ړ��������Z�b�g
	icon_vec = 0;


	// �J�[�\���ړ�(L�X�e�B�b�N)
	if (move_cool <= 0) {
		if (InputCtrl::GetStickRatio(L).x >= 0.3) {
			if (cursor_pos + 1 <= 2 && next_stage[now_stage][cursor_pos + 1] != -1) {
				cursor_pos++;
				cursor_loc = next_stage[now_stage][cursor_pos];
				move_cool = 15;
			}
			else {
				cursor_pos = 0;
				cursor_loc = next_stage[now_stage][cursor_pos];
				move_cool = 15;
			}
			cursor_move = TRUE;
		}
		else if (InputCtrl::GetStickRatio(L).x <= -0.3) {
			if (cursor_pos - 1 >= 0) {
				cursor_pos--;
				cursor_loc = next_stage[now_stage][cursor_pos];
				move_cool = 15;
			}
			else {
				for (int i = 2; i > 0; i--) {
					if (next_stage[now_stage][i] != -1) {
						cursor_pos = i;
						cursor_loc = next_stage[now_stage][cursor_pos];
						move_cool = 15;
						break;
					}
				}
			}
			cursor_move = TRUE;
		}
	}
	else if(InputCtrl::GetStickRatio(L).x < 0.3 && InputCtrl::GetStickRatio(L).x > -0.3){
		move_cool = 0;
	}
	else { move_cool--; }

	// �J�[�\���ړ��ŃJ�[�\������ʓ��Ɏ��܂�悤�ɂ���
	if (cursor_move == TRUE) {
		if (icon_loc[cursor_loc][1] <= 50) {
			icon_vec = 10;
		}
		else if (icon_loc[cursor_loc][1] >= SCREEN_HEIGHT - 100) {
			icon_vec = -10;
		}
	}


	// �X�N���[��(R�X�e�B�b�N)
	if (InputCtrl::GetStickRatio(R).y >= 0.2 || InputCtrl::GetStickRatio(R).y <= -0.2)
	{
		icon_vec = 0;
		cursor_move = FALSE;
		// ��X�N���[��
		if (icon_loc[DATA_MAX - 1][1] < 50) {
			if (InputCtrl::GetStickRatio(R).y >= 0.2 && InputCtrl::GetStickRatio(R).y < 0.5) {
				icon_vec = 1;
			}
			else if (InputCtrl::GetStickRatio(R).y >= 0.5 && InputCtrl::GetStickRatio(R).y < 0.8) {
				icon_vec = 3;
			}
			else if (InputCtrl::GetStickRatio(R).y >= 0.8) {
				icon_vec = 5;
			}
		}
		// ���X�N���[��
		if (icon_loc[1][1] > SCREEN_HEIGHT - 100) {
			if (InputCtrl::GetStickRatio(R).y <= -0.2 && InputCtrl::GetStickRatio(R).y > -0.5) {
				icon_vec = -1;
			}
			else if (InputCtrl::GetStickRatio(R).y <= -0.5 && InputCtrl::GetStickRatio(R).y > -0.8) {
				icon_vec = -3;
			}
			else if (InputCtrl::GetStickRatio(R).y <= -0.8) {
				icon_vec = -5;
			}
		}
	}

	// �A�C�R���ړ�����
	for (int i = 0; i < DATA_MAX; i++)
	{
		icon_loc[i][1] = icon_loc[i][1] + icon_vec;
	}

	// A�{�^���ŃJ�[�\���̃X�e�[�W�ɑJ��
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS || InputCtrl::GetKeyState(KEY_INPUT_RETURN) == PRESS) {

		if(weapon_selected) mode = GameSceneMode::main;
		else mode = GameSceneMode::weaponSelect;

		//is_map_mode = false;
		now_stage = cursor_loc;

		switch (MapDeta[cursor_pos])
		{
		case 0:
			return 1; //new GameScene;
			break;
		case 1:
			return 2; //new DebugScene;
			break;
		case 2:
			if (is_rest != true)
			{
				//����Ӗ����Ȃ��A�Q�[�����C�����ɕύX
				Player* player = new Player();
				rest->update(player,is_rest);
				is_show_rest = true;
				if (is_rest)
				{
					delete player;
					player = nullptr;
				}
			}
			is_show_rest = false;
			is_rest = false;		//���͉��x�ł�
			break;
		case 3:
			return 3; //new DebugScene;
			break;
		case 4:
			return 4; //new DebugScene;
			break;
		default:
			break;
		}
	}

	return 0;
};

void Map::draw() const {
	if (is_show_rest)
	{
		rest->draw();
	}
	else
	{
		int log_i = 0; // stage_log�p�ϐ�
		for (int i = 0; i < DATA_MAX; i++)
		{
			// �f�o�b�N�\��
			DrawFormatString(10, 30, 0xffff00, "�����f�[�^");
			DrawFormatString(10 * i + 10, 50, 0xffffff, "%d", MapDeta[i]);
			DrawFormatString(10, 680, 0xffffff, "A�{�^���ŃJ�[�\���̃X�e�[�W��");

			// �X�e�[�W�Ԃ̃��C��
			for (int j = 0; next_stage[i][j] > 0 && j <= 2; j++) {
				int next_loc = next_stage[i][j];
				if (stage_log[log_i] == i && stage_log[log_i + 1] == next_loc) {
					DrawLine(icon_loc[i][0] + 25, icon_loc[i][1] + 25,
						icon_loc[next_loc][0] + 25, icon_loc[next_loc][1] + 25, 0xaa0000);
					log_i++;
				} else {
					DrawLine(icon_loc[i][0] + 25, icon_loc[i][1] + 25,
						icon_loc[next_loc][0] + 25, icon_loc[next_loc][1] + 25, 0xffffff);
				}
			}
			DrawGraph(icon_loc[i][0] - 5, icon_loc[i][1] - 5, icon_back_img, TRUE);
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
		}
		// �J�[�\���\��
		DrawGraph(icon_loc[cursor_loc][0] - 5, icon_loc[cursor_loc][1] - 5, map_cursor, TRUE);
	}
}

void Map::ResetStage() {

	// �}�b�v�f�[�^����������
	for (int i = 0; i < DATA_MAX; i++)
	{
		MapDeta[i] = 0;
		if (sizeof(stage_log) / sizeof(stage_log[0]) > i) {
			stage_log[i] = -1;
		}
	}


	// �}�b�v����(0:�퓬�A1:�����_���C�x���g�A2:�x�e�A3:�b�艮�A4:�{�X)
	// �������e(�X�e�[�W�͈�)(�X�e�[�W��) 

	// �����_���C�x���g(st8�Œ�)
	MapDeta[8] = 1;

	// �x�e1(st3-7)(1-2)
	RandNum[0] = GetRand(1) + 1;
	for (int i = 0; i < RandNum[0];) {
		int r = GetRand(4) + 3;
		if (MapDeta[r] == 0) {
			MapDeta[r] = 2;
			i++;
		}
		else continue;
	}
	// �x�e2(st9-19)(2-3)
	RandNum[1] = GetRand(1) + 2;
	for (int i = 0; i < RandNum[1];) {
		int r = GetRand(11) + 9;
		// ���ύX(0�Ȃ�)�ύX
		if (MapDeta[r] == 0) {
			MapDeta[r] = 2;
			i++;
		}
		else continue;
	}
	// �x�e3(st20�Œ�)
	MapDeta[20] = 2;

	// �b�艮(st16-19)(1)
	RandNum[2] = 1;
	for (int i = 0; i < RandNum[2];) {
		int r = GetRand(4) + 16;
		if (MapDeta[r] == 0) {
			MapDeta[r] = 3;
			i++;
		}
		else continue;
	}

	// �{�X(st21�Œ�)
	MapDeta[21] = 4;
}