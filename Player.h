#pragma once
#include"SphereCollider.h"

#define MOVE_RIGHT 0.1
#define MOVE_LEFT -0.1
#define MOVE_UP 0.1
#define MOVE_DOWN -0.1


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
	int GetPlayer_Avoidance();

	// �v���C���[�̗̑͂�����
	void SetPlayer_HP(float value);
};