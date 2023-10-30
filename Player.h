#pragma once

#define MOVE_RIGHT 0.1
#define MOVE_LEFT -0.1
#define MOVE_UP 0.1
#define MOVE_DOWN -0.1


class Player
{
private:
	//�摜�p�ϐ�
	int PlayerImg;
	int AimingImg;

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
	int Player_HP;

public:

	static float MovingX;
	static float MovingY;

	Player();
	~Player();

	void update();

	//�`�揈��
	void draw() const;

	int Player_AimingX();
	int Player_AimingY();

	float Player_MoveX();
	float Player_MoveY();

	static float Player_MovingX();
	static float Player_MovingY();

	int GetPlayer_HP();
	void SetPlayer_HP(int value);
};