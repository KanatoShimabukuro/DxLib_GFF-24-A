#pragma once

class Player
{

private:
	int PlayerImg;

	int PlayerX;
	int PlayerY;

	float Provisional_LStickX;
	float Provisional_LStickY;

public:

	Player();
	~Player();

	void update();

	//�`�揈��
	void draw() const;

	int Player_LStickY();
	int Player_LStickX();
};
