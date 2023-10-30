#include "scene_levelup.h"

WeaponLevelUp::WeaponLevelUp()
{
	test = 0;
	initial_cursor_position = 0;
}

WeaponLevelUp::~WeaponLevelUp()
{

}

// �X�V
void WeaponLevelUp::update()
{
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
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
	SetFontSize(20);
	DrawFormatString(0, 0, 0x000000, "X�{�^���F����");
	DrawFormatString(0, 20, 0x000000, "A�{�^���F���Z");
	DrawFormatString(0, 40, 0x000000, "test : %d", test);

}
