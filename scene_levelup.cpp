#include "scene_levelup.h"

WeaponLevelUp::WeaponLevelUp()
{
	test = 0;
}

WeaponLevelUp::~WeaponLevelUp()
{

}

// �X�V
void WeaponLevelUp::update()
{
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_Y) == PRESS)
	{
		test++;
	}

}

// �`��
void WeaponLevelUp::draw() const
{
	DrawBox(0, 0, 960, 600, 0xa0a0a0, TRUE);
	SetFontSize(30);
	DrawFormatString(100, 300, 0x000000, "���x���A�b�v");
	DrawFormatString(0, 0, 0x000000, "test : %d", test);

}
