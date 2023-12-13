#pragma once

class Player;
class GameUI;

class Rest
{
private:
	int cursor_interval;			//�J�[�\���̃C���^�[�o��
	int scene_interval;				//�V�[���̃C���^�[�o��
	int select_interval;			//����̃C���^�[�o��
	int cursor_num;					//�J�[�\���ԍ�
	int cursor_x;					//�J�[�\���̂����W
	int anim_cnt;					//�A�j���[�V�����̐؂�ւ��J�E���g
	int bonfire_anim;				//���΂̃A�j���[�V�����ԍ�

	int cursor_image;				//�J�[�\���̉摜
	int bonfire_image[4];			//���΂̉摜
	int button_image;				//�{�^���̉摜

	int logo_dicision_image;		//����̃��S�摜
	int logo_rest_image;			//�x�e����̃��S�摜
	int logo_pray_image;			//�F��̃��S�摜
	int logo_cure_image;			//�񕜂̃��S�摜
	int logo_buf_image;				//�o�t�̃��S�摜

	bool is_select;					//���肵���H
	bool rest_buf_flg;				//�x�e�̃o�t��������H

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