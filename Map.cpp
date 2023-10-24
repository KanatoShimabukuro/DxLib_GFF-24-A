#include "map.h"

Map::Map() {
	// �}�b�v�f�[�^����������
	for (int i = 0; i <= DATA_MAX; i++)
	{
		Mapdata[i] = 0;
		randnum[i] = 0;
	}

	// �}�b�v����(0:�퓬�A1:�����_���C�x���g�A2:�x�e�A3:�b�艮�A4:�{�X)
	Mapdata[8] = 1;


	randnum[0] = GetRand(1) + 1;
	for (int i = 0; i < randnum[0]; i++) {
		int r = GetRand(3) + 3;
		if (Mapdata[r] == 0) {
			Mapdata[r] = 2;
		}else continue;
	}

	randnum[1] = GetRand(2) + 2;
	for (int i = 0; i < randnum[1]; i++) {
		int r = GetRand(10) + 9;
		if (Mapdata[r] == 0) {
			Mapdata[r] = 2;
		}
		else continue;
	}
	Mapdata[20] = 2;


	randnum[2] = GetRand(1) + 1;
	for (int i = 0; i < randnum[2]; i++) {
		int r = GetRand(10) + 9;
		if (Mapdata[r] == 0) {
			Mapdata[r] = 3;
		}
		else continue;
	}


	Mapdata[21] = 4;
}
Map::~Map() {

}

Scene* Map::update() {

	return this;
};

void Map::draw() const {

	for (int i = 0; i <= DATA_MAX; i++)
	{
		DrawFormatString(10 * i + 10, 10, 0xffffff, "%d", i);
		DrawFormatString(10 * i + 10, 40, 0xffffff, "%d", Mapdata[i]);
		DrawFormatString(10 * i + 10, 60, 0xffffff, "%d", randnum[i]);
	}
	
}