#pragma once

class Player;
class GameUI;

class Rest
{
private:
	GameUI* ui;

	int interval;
	int cursor_num;


	int cursor_image;
	int bonfire_image;
	int button_image;

	bool is_select;
	bool is_ok;

public:
	//�R���X�g���N�^
	Rest(GameUI* ui);
	//�f�X�g���N�^
	~Rest();

	//�`��Ɋւ��邱�ƈȊO�̍X�V����������
	void update(Player* player, int& mode, int& stage);

	//�`��Ɋւ��邱�Ƃ̍X�V����������
	void draw()const;

	void Init();

};