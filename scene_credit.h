#pragma once

#include "scene.h"

class Credit : public Scene
{
private:
	//�摜�ǂݍ��ݗp�̕ϐ�
	int CreditImage;
	//�N���W�b�g���[���p�̕ϐ�
	int g_WaitTime;
	int g_PosY;

	int Credit_Mouse_x;
	int Credit_Mouse_y;

public:
	//�R���X�g���N�^
	Credit();
	~Credit();
	//�X�V
	Scene* update()override;
	//�`��
	void draw()const override;
};

