#pragma once

#include "scene.h"
#define TITLEINTERVAL 15
#define TITLECURSOR 4

class Title :public Scene
{
private:

	//�摜�̓Ǎ��p�ϐ�
	int TitleImage;
	int Titlelogo;
	int Titlelogo_white;

	int g_MenuNumber;
	//�J�[�\���摜�ǂݍ��ݗp�ϐ�
	int cursor;
	int g_MenuY;
	//�^�C�g���J�[�\���i�X�e�B�b�N�j����p�̕ϐ�
	int TitleInterval;

public:
	//�R���X�g���N�^
	Title();
	~Title();
	//�X�V
	Scene* update() override;
	//�`��
	void draw() const override;

};