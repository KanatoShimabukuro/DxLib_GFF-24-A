#include "weapon.h"
#include "inputCtrl.h"
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

#define d_r(_d) _d * (M_PI / 180)
#define r_d(_r) _r * (180 / M_PI)


weapon::weapon()
{
	weaponType = none;
	baseVec = { 80,0,80 };
	relativeRot = 90.0f;		//����ɂ���ĕς���
	maxRot = 90.0f;
	coolTime = 120;
	isAttacking = false;
}

weapon::weapon(int type)
{
	//�g�����s��
	weaponType = type;
	switch (weaponType)
	{
	case sword:
		baseVec = { 80,0,80 };
		break;

	case dagger:
		baseVec = { 50,0,50 };
		break;

	case greatSword:
		baseVec = { 100,0,100 };
		break;
	}
}

weapon::~weapon()
{
}

void weapon::Update()
{
	//debug
	//x y length�@�ɂ̓v���C���[�ƃJ�[�\���̃x�N�g��������
	float x = InputCtrl::GetMouseCursor().x - 640;
	float y = InputCtrl::GetMouseCursor().y - 360;
	float length = sqrt((x) * (x) + (y) * (y));

	float innerProduct = ((x) * baseVec.x) + ((y) * baseVec.y);
	float angle = acos(innerProduct / (length * baseVec.length));
	if (y > 0) {
		angle = (M_PI - angle);
		angle += M_PI;
	}

	//���폊�L���Ȃ�
	if (weaponType != none) {
		//�N�[���^�C����
		if (!(isAttacking) && --coolTime <= 0) {
			isAttacking = true;
			coolTime = 120;
		}

		//�U����
		if (isAttacking) {

			if (relativeRot < - maxRot) {
				relativeRot = maxRot;
				isAttacking = false;
			}
			rot = -1 * (angle - (d_r(relativeRot)));

			collisionX = (baseVec.x * cos((rot)) - baseVec.y * sin((rot))) + 640;
			collisionY = (baseVec.x * sin((rot)) + baseVec.y * cos((rot))) + 360;

			relativeRot -= 4.0f;
		}

	}
}

void weapon::Draw() const
{
	//debug
	int x = InputCtrl::GetMouseCursor().x;
	int y = InputCtrl::GetMouseCursor().y;

	DrawFormatString(0, 0, 0xffffff, "%d", x);
	DrawFormatString(0, 30, 0xffffff, "%f", baseVec.x);
	DrawFormatString(0, 60, 0xffffff, "%f", baseVec.y);
	DrawFormatString(0, 90, 0xffffff, "%f", rot);

	if (isAttacking) {
		DrawCircle(collisionX, collisionY, 3, 0xff0000, TRUE);
		DrawLine(640, 360, collisionX, collisionY, 0xffffff);
	}
	

	DrawCircle(640, 360, 3, 0xff0000, TRUE);
}

void weapon::SetWeaponType(int type)
{
	weaponType = type;
	switch (weaponType)
	{
	case sword:
		baseVec = { 80,0,80 };
		maxRot = 60.0f;
		break;

	case dagger:
		baseVec = { 50,0,50 };
		maxRot = 60.0f;
		break;

	case greatSword:
		baseVec = { 100,0,100 };
		maxRot = 90.0f;
		break;
	}
}

//��]�̌���
//r: �p�x(���W�A��)
//x : ����X���W
//y : ����Y���W

//X = x * cos(r) - y * sin(r)
//Y = x * sin(r) + y * cos(r)