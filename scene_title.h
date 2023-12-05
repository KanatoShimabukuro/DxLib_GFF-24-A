#pragma once

#include "scene.h"
#define TITLEINTERVAL 15
#define TITLECURSOR 4

#define TITLE_MOVE_DOWN -0.5f
#define TITLE_MOVE_UP 0.5f

#define TITLE_STAR_BRIGHT_COLOR1 -2.0f
#define TITLE_STAR_BRIGHT_COLOR2 1.5f

#define TITLE_SELECT_MG /*0.4*/ 0.1


class Title :public Scene
{
private:

	//�摜�̓Ǎ��p�ϐ�
	int TitleImage;
	int Titlelogo;
	int Titlelogo_white;

	int Title_Background_Img[2];
	int Title_SkyStar_Img;

	int Title_Start_Img;
	int Title_Help_Img;
	int Title_Credit_Img;
	int Title_End_Img;

	int Title_Cosol_sword_Img;
	int Title_Cosol_greatsword_Img;
	int Title_Cosol_shortsword_Img;

	//�Z���N�g�{��
	double Title_Select_magnification;
	double Title_Cosor_sword_Angle;
	double Title_Cosor_greatsword_Angle;
	double Title_Cosor_shortsword_Angle;

	//���W�n
	float logo_white_x, logo_white_y;
	float logo_move_x, logo_move_y;
	int	  Title_Star_x[8], Title_Star_y[8];
	int Title_Cosor_greatsword_x;
	int Title_Cosor_greatsword_y;

	//�t���O�n
	bool logo_location_y_flg;
	bool Title_Select_mg_flg;
	bool Title_Anim_flg;
	bool Title_FadeOut_flg;
	bool Title_FadeIn_flg;
	bool Title_select_flg;
	bool Title_Cursor_Flg;
	bool Title_logo_Anim_End_Flg;

	//fps�n
	int Title_Animation_fps;

	//�J�E���^
	int Star_Anim_Count;
	int Title_Star_rand_Count;

	//����
	int Title_Star_rand;

	//�f�o�b�O�p�}�E�X�|�C���^
	int Title_Debug_Mousepoint_x;
	int Title_Debug_Mousepoint_y;

	//�F
	int Title_Star_Anim_Color_red;
	int Title_Star_Anim_Color_green;
	int Title_Star_Anim_Color_blue;

	int g_MenuNumber;
	//�J�[�\���摜�ǂݍ��ݗp�ϐ�
	int cursor;
	int g_MenuY;
	//�^�C�g���J�[�\���i�X�e�B�b�N�j����p�̕ϐ�
	int TitleInterval;

public:
	//�R���X�g���N�^
	Title();
	~Title();
	//�X�V
	Scene* update() override;
	//�`��
	void draw() const override;

	//�^�C�g�����S�A�j���[�V����
	void Title_logo_Animation();

	//���̃����_������
	void Title_Star_Rands(int rands_x, int rands_y, int rands1_x, int rands1_y);

	//���̃t�F�[�h�A�E�g�֐�
	void Title_Star_FadeOut();

	//���̃t�F�[�h�C���֐�
	void Title_Star_FadeIn();

	//�^�C�g���̃Z���N�g�A�j���[�V����
	void Title_Select_Anim();

	//�^�C�g���̃J�[�\���A�j���[�V����
	void Title_Cursor_Anim();
};