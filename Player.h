#pragma once

class Player
{

private:
	int PlayerImg;

	int PlayerX;
	int PlayerY;

public:

	Player();
	~Player();

	void update(GameScene* gameScene);

	//�`�揈��
	void draw() const;
};
