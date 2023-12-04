#pragma once
#include"SphereCollider.h"
#include "Stage.h"

#define MOVE_RIGHT 0.2
#define MOVE_LEFT -0.2
#define MOVE_UP 0.2
#define MOVE_DOWN -0.2

#define Speed 1.5f
#define Upper_Limit 20.0f
#define Initial_Value 0.0f

#define MAX_HP 100.f

class Player :public SphereCollider
{
private:
	//�摜�p�ϐ�
	int PlayerArrayImg[3];
	int PlayerImg;
	int AimingImg;
	int KaihiImg;
	int TurnFlg;
	int P_Cnt;
	bool MovingFlg;

	//PlayerLocation
	int PlayerX;
	int PlayerY;

	//�c���p�O��̍��W�i�[�p�ϐ�
	float Previous_AfterImage_locationX;
	float Previous_AfterImage_locationY;

	//�Ə�
	float AimingX;
	float AimingY;
	float X = 0.0;
	float Y = 0.0;

	//�� �~�^��
	float Angle;
	float rd;
	
	//���X�e�B�b�N
	float Provisional_LStickX;
	float Provisional_LStickY;

	//�E�X�e�B�b�N
	float Provisional_RStickX;
	float Provisional_RStickY;

	// A�{�^��
	int Provisional_Abtn;
	bool A_value;
	bool CoolTime;
	bool Avoidance_Flg;

	//�@���Z�l
	float Additional_Value;
	Vector Additional_Value3;
	float Avoidance;

	//�ړ���
	float MoveX;
	float MoveY;
	float MoveZ;

	//�v���C���[�̗̑�
	float Player_HP;
	float MaxPlayer_hp;

	int fps;
	int CoolTime_fps;
	int Second;
	int p_CoolTimeCounter;
	int Animation_fps;

	//�J�����p
	StageArray lefttop;
	StageArray rightbottom;
	bool camera_flg_top_bottom;
	bool camera_flg_left_right;

	//SE�p
	int SE_playermove;
	int SE_playeravoidance;

	bool is_hit;			//�U�����󂯂����ǂ���
	int PlayerTestImg;

	//���
	Vector relativeCursorLocation;
	Vector unitRelativeCursorLocation;
	bool firstAvoidanceFlg = false;
	int AvoidanceCnt = 0;
	Location avoidanceLocation[64];//����c��
	int afterimageNum;

public:

	static float MovingX;
	static float MovingY;
	static float Additional_Value2;
	static float Aiming_RadiusX;
	static float Aiming_RadiusY;
	static float   Cool_Limit;
	static float Upper_speed;

	//�q�b�g�N�[���_�E��
	static int Hit_cooltime;

	Player();
	~Player();

	void update();

	//�`�揈��
	void draw() const;

	void Player_Move();
	void Player_Aim();
	void Player_Avoidance();
	void Player_CoolTime();
	void Player_Camera();
	void Player_Move_Animation();

	//�Ə��̊֐� X Y ��߂�l�ŕԂ�
	int Player_AimingX();
	int Player_AimingY();

	//�v���C���[�̃q�b�g�N�[���^�C��
	static int Player_invincible(int value);

	//�Ə��̔��a��Ԃ�
	static void SetPlayer_RadiusX(float value);
	static void SetPlayer_RadiusY(float value);
	float GetPlayer_RadiusX();
	float GetPlayer_RadiusY();

	//����̈ړ��X�s�[�h
	static void SetPlayer_Upperlimit(float value);
	float GetPlayer_Upperlimit();

	//����̃N�[���_�E������
	static void SetAvoidance_limit(int value);
	float GetAvoidance_limit();

	//�v���C���[�̈ړ����x
	static void SetPlayer_Speed(float value);
	float GetPlayer_Speed();

	//�v���C���[�̈ړ��� X Y ��Ԃ�
	float Player_MoveX();
	float Player_MoveY();

	//�v���C���[�̍��W��Ԃ� X Y
	static float Player_MovingX();
	static float Player_MovingY();

	// �v���C���[�̗̑͂�Ԃ�
	float GetPlayer_HP();

	bool GetPlayer_Avoidance();

	// �v���C���[�̗̑͂�����
	void SetPlayer_HP(float value);
	
	//�v���C���[��HP���Z�b�g
	void SetPlayerHP(float value);


	//is_hit���擾����
	bool GetIsHit()
	{
		return is_hit;
	}

	//is_hit��ݒ肷��
	void SetIsHit(const bool flg)
	{
		is_hit = flg;
	}

	Location Player_Location();

	//�X�e�[�W�̍���ƉE�����擾
	void SetLeftTop(StageArray sa) {
		lefttop = sa;
	}
	void SetRightBottom(StageArray sa) {
		rightbottom = sa;
	}

	int GetCoolTimeCounter() {
		return p_CoolTimeCounter;
	}

	//�v���C���[�̗̑͂̏���l
	float GetMaxPlayer_hp() {
		return MaxPlayer_hp;
	}
};