#pragma once

#include "scene.h"

class Title :public Scene
{
private:

	//�摜�̓Ǎ��ϐ�
	int TitleImage;

	int g_MenuNumber;
	short PadStick;
	int cursor;
	int frameCounter;

	bool Ctrl;

public:
	Title();
	Scene* update() override;
	void draw() const override;

};