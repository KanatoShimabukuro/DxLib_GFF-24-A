#pragma once

class Player;

class Rest
{
private:
	int interval;
	int cursor_num;


	int cursor_image;
	int bonfire_image;

public:
	//�R���X�g���N�^
	Rest();
	//�f�X�g���N�^
	~Rest();

	//�`��Ɋւ��邱�ƈȊO�̍X�V����������
	void update(Player* player, bool& flg);

	//�`��Ɋւ��邱�Ƃ̍X�V����������
	void draw()const;

};