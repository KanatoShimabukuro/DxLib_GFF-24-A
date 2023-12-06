#pragma once

class Player;
class GameUI;

class Rest
{
private:
	GameUI* ui;

	int cursor_interval;
	int interval;
	int cursor_num;
	int cursor_x;

	int cursor_image;
	int bonfire_image;
	int button_image;

	bool is_select;
	bool is_ok;
	bool rest_buf_flg;			//�x�e�̃o�t��������H

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

	//rest_buf_flg���擾����
	bool GetRestBufFlg()
	{
		return rest_buf_flg;
	}

	//rest_buf_flg��ݒ肷��
	void SetRestBufFlg(const bool flg)
	{
		rest_buf_flg = flg;
	}

};