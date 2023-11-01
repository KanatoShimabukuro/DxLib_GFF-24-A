#pragma once

#define MOVE_RIGHT 0.1
#define MOVE_LEFT -0.1
#define MOVE_UP 0.1
#define MOVE_DOWN -0.1


class Player
{

private:
	int PlayerImg;
	int AimingImg;

	int PlayerX;
	int PlayerY;

	float AimingX;
	float AimingY;

	float Provisional_LStickX;
	float Provisional_LStickY;

	float Provisional_RStickX;
	float Provisional_RStickY;

	int Provisional_Abtn;

	float Additional_Value;
	float Additional_Value2;
	float Additional_Value3;

	float Avoidance;

	float MoveX;
	float MoveY;
	float MoveZ;

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
};
