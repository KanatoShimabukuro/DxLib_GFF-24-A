#pragma once

class Player;
class GameUI;

class Rest
{
private:
	int cursor_interval;
	int interval;
	int select_interval;
	int cursor_num;
	int cursor_x;
	int anim_cnt;
	int bonfire_anim;

	int cursor_image;
	int bonfire_image[4];
	int button_image;

	int logo_dicision_image;
	int logo_rest_image;
	int logo_pray_image;

	bool is_select;
	bool is_ok;
	bool rest_buf_flg;			//�x�e�̃o�t��������H

public:
	//�R���X�g���N�^
	Rest();
	//�f�X�g���N�^
	~Rest();

	//�`��Ɋւ��邱�ƈȊO�̍X�V����������
	void update(Player* player, int& mode, int& stage, int& restCnt,int& hp);

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