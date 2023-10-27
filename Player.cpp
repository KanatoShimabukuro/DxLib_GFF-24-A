#include "main.h"
#include "Player.h"

float Player::MovingX;
float Player::MovingY;

Player::Player() {

	if (PlayerImg = LoadGraph("resources/images/yusya_red.png")) {}
	if (AimingImg = LoadGraph("resources/images/mark_maru.png")) {}

	PlayerX = 640;
	PlayerY = 360;

	AimingX = 300.0;
	AimingY = 300.0;

	Provisional_LStickX = 0.0;
	Provisional_LStickY = 0.0;

	Provisional_RStickX = 0.0;
	Provisional_RStickY = 0.0;

	Provisional_Abtn = 0;

	Additional_Value = 10.0;
	Additional_Value2 = 2.0;
	Additional_Value3 = 500.0;

	Avoidance = 0.0;

	MoveX = 0.0;
	MoveY = 0.0;
	MoveZ = 0.0;

	MovingX = 0.0;
	MovingY = 0.0;
}

Player::~Player() {

	DeleteGraph(PlayerImg);
	DeleteGraph(AimingImg);
}

void Player::update() {

	//���X�e�B�b�N
	Provisional_LStickX = InputCtrl::GetStickRatio(L).x;
	Provisional_LStickY = InputCtrl::GetStickRatio(L).y;

	//�E�X�e�B�b�N
	Provisional_RStickX = InputCtrl::GetStickRatio(R).x;
	Provisional_RStickY = InputCtrl::GetStickRatio(R).y;

	//A�{�^��
	Provisional_Abtn = InputCtrl::GetButtonState(XINPUT_BUTTON_A);

	//����@A�{�^��
	if (Provisional_Abtn == PRESS) {
		MoveZ = Additional_Value3 * Provisional_LStickX;
		//MovingX = MovingX + MoveZ;
		MovingY = MovingY + MoveZ;
	}

	//�Ə��@�E�X�e�B�b�N
	//��
	if (Provisional_RStickX > MOVE_RIGHT) {

		AimingX = AimingX + Additional_Value * Provisional_RStickX;
	}
	else if (Provisional_RStickX < MOVE_LEFT) {

		AimingX = AimingX + Additional_Value * Provisional_RStickX;
	}

	//�c
	if (Provisional_RStickY > MOVE_UP) {

		AimingY = AimingY - Additional_Value * Provisional_RStickY;
	}
	else if (Provisional_RStickY < MOVE_DOWN) {

		AimingY = AimingY - Additional_Value * Provisional_RStickY;

	}

	//�ړ��@���X�e�B�b�N
	//��
	if (Provisional_LStickX > MOVE_RIGHT) {
		MoveX = Additional_Value2 * Provisional_LStickX;
		MovingX = MovingX - MoveX;
	}
	else if (Provisional_LStickX < MOVE_LEFT) {
		MoveX = Additional_Value2 * Provisional_LStickX;
		MovingX = MovingX - MoveX;
	}

	//�c
	if (Provisional_LStickY < MOVE_DOWN) {

		MoveY = -1 * Additional_Value2 * Provisional_LStickY;
		MovingY = MovingY - MoveY;

	}else if (Provisional_LStickY > MOVE_UP) {

		MoveY = -1 * Additional_Value2 * Provisional_LStickY;
		MovingY = MovingY - MoveY;

	}
}

void Player::draw()const {

	//���X�e�B�b�N
	DrawFormatString(0, 300, GetColor(255, 0, 0), "LStick:�c���l %0.1f", Provisional_LStickY);
	DrawFormatString(0, 320, GetColor(255, 0, 0), "MoveY %0.1f", MoveY);

	//�E�X�e�B�b�N
	DrawFormatString(0, 340, GetColor(255, 0, 0), "RStick:�c���l %0.1f", Provisional_RStickY);
	DrawFormatString(0, 360, GetColor(255, 0, 0), "RStick:�����l %0.1f", Provisional_RStickX);

	//A�{�^��
	DrawFormatString(0, 380, GetColor(255, 0, 0), "Abtn: %d", Provisional_Abtn);

	//DrawFormatString(0, 380, GetColor(255, 255, 255), "RStick:�c���l %0.1f", InputCtrl::GetStickState(R).x);
	//DrawFormatString(0, 400, GetColor(255, 255, 255), "RStick:�����l %0.1f", InputCtrl::GetStickState(R).y);

	//DrawGraph(0, 300, PlayerImg, TRUE);

	DrawRotaGraph(AimingX - 25, AimingY - 25, 0.10f, 0.01, AimingImg, TRUE);

	DrawRotaGraph(PlayerX, PlayerY, 0.10f, 0.01, PlayerImg, TRUE);
}

int Player::Player_AimingX() {

	return AimingX;
}

int Player::Player_AimingY() {

	return AimingY;
}

int Player::Player_MoveX() {

	return MoveX;
}

int Player::Player_MoveY() {

	return MoveY;
}

int Player::Player_MovingX() {

	return MovingX;
}

int Player::Player_MovingY() {

	return MovingY;
}
