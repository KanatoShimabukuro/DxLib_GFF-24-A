#pragma once
#include"SphereCollider.h"
#include "Stage.h"

#define MOVE_RIGHT 0.2
#define MOVE_LEFT -0.2
#define MOVE_UP 0.2
#define MOVE_DOWN -0.2

#define Speed 1.5f
#define Upper_Limit 13.0f
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
	float Additional_Value2;
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

public:

	static float MovingX;
	static float MovingY;

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