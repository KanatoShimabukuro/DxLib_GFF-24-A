#pragma once

#include "scene.h"

class Title :public Scene
{
private:

	//�摜�̓Ǎ��ϐ�
	int TitleImage;

	int g_MenuNumber;
	int cursor;
	int g_MenuY;
public:
	Title();
	Scene* update() override;
	void draw() const override;

};