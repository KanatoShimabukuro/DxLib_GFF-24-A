#include "map.h"

Map::Map() {
	// �}�b�v�f�[�^����������
	for (int i = 0; i <= DATA_MAX; i++)
	{
		Mapdata[i] = 0;
		randnum[i] = 0;
	}

	// �}�b�v����(0:�퓬�A1:�����_���C�x���g�A2:�x�e�A3:�b�艮�A4:�{�X)
	Mapdata[7] = 1;


	randnum[0] = GetRand(1) + 1;
	for (int i = 0; i < randnum[0]; i++) {
		int r = GetRand(3) + 3;
		if (Mapdata[r] == 0) {
			Mapdata[r] = 2;
		}else continue;
	}

	randnum[1] = GetRand(1) + 2;
	for (int i = 0; i < randnum[1]; i++) {
		int r = GetRand(10) + 9;
		if (Mapdata[r] == 0) {
			Mapdata[r] = 2;
		}
		else continue;
	}
	Mapdata[19] = 2;


	randnum[2] = GetRand(1) + 1;
	for (int i = 0; i < randnum[2]; i++) {
		int r = GetRand(10) + 9;
		if (Mapdata[r] == 0) {
			Mapdata[r] = 3;
		}
		else continue;
	}


	Mapdata[20] = 4;


	// �摜�Ǎ�
	if (battle_img == 0) battle_img = (LoadGraph("resources/images/skeleton.png"));
	if (event_img == 0) event_img = (LoadGraph("resources/images/event.png"));
	if (rest_img == 0) rest_img = (LoadGraph("resources/images/rest.png"));
	if (anvil_img == 0) anvil_img = (LoadGraph("resources/images/anvil.png"));
	if (boss_img == 0) boss_img = (LoadGraph("resources/images/boss.png"));
}
Map::~Map() {

}

Scene* Map::update() {

	return this;
};

void Map::draw() const {

	for (int i = 0; i < DATA_MAX; i++)
	{
		DrawFormatString(10 * i + 10, 20, 0xffffff, "%d", Mapdata[i]);


		// �X�e�[�W�Ԃ̃��C��
		for (int j = 0; next_stage[i][j] != 0 && j <= 2; j++)
		{
			int next_loc = next_stage[i][j];

			DrawLine(icon_loc[i][0] + 25, icon_loc[i][1] + 25,
				icon_loc[next_loc][0] + 25, icon_loc[next_loc][1] + 25, 0xffffff);
		}

		// �A�C�R���\��
		switch (Mapdata[i]) {
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

	}
	
}