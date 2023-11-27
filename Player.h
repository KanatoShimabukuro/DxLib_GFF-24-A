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
	int PlayerImg;
	int AimingImg;
	int KaihiImg;

	//PlayerLocation
	int PlayerX;
	int PlayerY;

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
	float Additional_Value3;
	float Avoidance;

	//�ړ���
	float MoveX;
	float MoveY;
	float MoveZ;

	//�v���C���[�̗̑�
	float Player_HP;

	int fps;
	int CoolTime_fps;
	int Second;

	//�J�����p
	StageArray lefttop;
	StageArray rightbottom;
	bool camera_flg_top_bottom;
	bool camera_flg_left_right;

	bool is_hit;			//�U�����󂯂����ǂ���
	int PlayerTestImg;

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
	static void SetAvoidance_limit(float value);
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
};