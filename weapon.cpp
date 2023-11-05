#include "weapon.h"
#include "inputCtrl.h"
#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
//#include "SphereCollider.h"


#define d_r(_d) _d * (M_PI / 180)
#define r_d(_r) _r * (180 / M_PI)


weapon::weapon()
{
	weaponType = none;
	baseVec = { 80,0,80 };
	relativeRot = 90.0f;		//����ɂ���ĕς���
	maxRot = 90.0f;
	coolTime = 20;
	isAttacking = false;
	weaponLevel = 0;
	levelUpFlg = false;

	tmp = 0;

	location = { 640.360 };

	sword_img = LoadGraph("resources/images/sword_longsword_brown.png");
	dagger_img = LoadGraph("resources/images/sword_shortsword_brown.png");
	greatsword_img = LoadGraph("resources/images/tsurugi_bronze_blue.png");
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

void weapon::Update(float cursorX, float cursorY, Location playerLocation)
{
	location = playerLocation;
	//debug
	//x y length�@�ɂ̓v���C���[�ƃJ�[�\���̃x�N�g��������
	/*float x = InputCtrl::GetMouseCursor().x - 640;
	float y = InputCtrl::GetMouseCursor().y - 360;*/


	float x = cursorX - location.x; //kk
	float y = cursorY - location.y;	//kk
	float length = sqrt((x) * (x) + (y) * (y));


	float innerProduct = ((x) * baseVec.x) + ((y) * baseVec.y);
	if (!isAttacking) {
		weaponAngle = acos(innerProduct / (length * baseVec.length));
		if (y > 0) {
			weaponAngle = (M_PI - weaponAngle);
			weaponAngle += M_PI;
		}
	}
	

	//���폊�L���Ȃ�
	if (weaponType != none) {
		//�N�[���^�C����
		if (!(isAttacking) && --coolTime <= 0) {
			isAttacking = true;
			coolTime = maxCoolTime;
		}

		//�U����
		if (isAttacking) {

			if (relativeRot < - maxRot) {
				relativeRot = maxRot;
				isAttacking = false;
			}
			rot = -1 * (weaponAngle - (d_r(relativeRot)));

			//��]���̕���̍��W
			collisionX = (baseVec.x * cos((rot)) - baseVec.y * sin((rot))) + location.x;	//kk
			collisionY = (baseVec.x * sin((rot)) + baseVec.y * cos((rot))) + location.y;	//kk

			//��]���̕���̃x�N�g��
			collisionVec.x = collisionX - location.x;	//kk
			collisionVec.y = collisionY - location.y;	//kk
			collisionVec.length = sqrt((collisionVec.x) * (collisionVec.x) + (collisionVec.y) * (collisionVec.y));

			//��]
			relativeRot -= 4.0f;


			//�P�ʃx�N�g��
			unitVec.x = collisionVec.x / collisionVec.length;
			unitVec.y = collisionVec.y / collisionVec.length;
			unitVec.length = sqrt((unitVec.x) * (unitVec.x) + (unitVec.y) * (unitVec.y));
			
		}

	}

	

	//���x���A�b�v�f�o�b�O
	/*if (levelUpFlg) {
		if (InputCtrl::GetKeyState(KEY_INPUT_L) == PRESS) {
			levelUpFlg = false;
		}

		if (InputCtrl::GetKeyState(KEY_INPUT_0) == PRESS) {
			weaponLevel = 0;
			LevelState();

		}else if (InputCtrl::GetKeyState(KEY_INPUT_1) == PRESS) {
			weaponLevel = 1;
			LevelState();

		}else if (InputCtrl::GetKeyState(KEY_INPUT_2) == PRESS) {
			weaponLevel = 2;
			LevelState();

		}else if (InputCtrl::GetKeyState(KEY_INPUT_3) == PRESS) {
			weaponLevel = 3;
			LevelState();

		}else if (InputCtrl::GetKeyState(KEY_INPUT_4) == PRESS) {
			weaponLevel = 4;
			LevelState();

		}else if (InputCtrl::GetKeyState(KEY_INPUT_5) == PRESS) {
			weaponLevel = 5;
			LevelState();

		}else if (InputCtrl::GetKeyState(KEY_INPUT_6) == PRESS) {
			weaponLevel = 6;
			LevelState();

		}else if (InputCtrl::GetKeyState(KEY_INPUT_7) == PRESS) {
			weaponLevel = 7;
			LevelState();

		}else if (InputCtrl::GetKeyState(KEY_INPUT_8) == PRESS) {
			weaponLevel = 8;
			LevelState();

		}

	}
	else if (InputCtrl::GetKeyState(KEY_INPUT_L) == PRESS) {
		levelUpFlg = true;
	}*/
}

void weapon::Draw() const
{
	//����`��	//kk
	if (isAttacking) {
		switch (weaponType)
		{
		case sword:
			DrawRotaGraph2(location.x, location.y, 0, 500, 0.16, rot + (M_PI / 4), sword_img, TRUE, TRUE);
			break;
		case dagger:
			DrawRotaGraph2(location.x, location.y, -50, 550, 0.1, rot + (M_PI / 4), dagger_img, TRUE, TRUE);
			break;
		case greatSword:
			DrawRotaGraph2(location.x, location.y, 0, 500, 0.2, rot + (M_PI / 4), greatsword_img, TRUE, TRUE);
			break;
		default:
			break;
		}
	}




	//debug
	int x = InputCtrl::GetMouseCursor().x;
	int y = InputCtrl::GetMouseCursor().y;

	/*DrawFormatString(0, 0, 0xffffff, "����^�C�v %d 1,�Ў茕 2,�Z�� 3,�匕 100,�Ȃ�", weaponType+1);
	DrawFormatString(0, 30, 0xffffff, "���탌�x�� %d", weaponLevel);
	DrawFormatString(0, 60, 0xffffff, "�N�[���^�C���@%d", maxCoolTime);
	DrawFormatString(0, 90, 0xffffff, "�N�[���^�C���J�E���g�@%d", coolTime);
	DrawFormatString(0, 120, 0xffffff, "�U���͈� %f", maxRot);
	DrawFormatString(0, 150, 0xffffff, "�_���[�W %d", damage);*/
	//DrawFormatString(0, 180, 0xffffff, "�P�ʃx�N�g��X %f", unitVec.x);
	//DrawFormatString(0, 210, 0xffffff, "�P�ʃx�N�g��Y %f", unitVec.y);
	//DrawFormatString(0, 240, 0xffffff, "�P�ʃx�N�g�� %f", unitVec.length);


	//kk
	if (isAttacking) {
		/*DrawCircle(collisionX, collisionY, 3, 0xff0000, TRUE);
		DrawLine(location.x, location.y, collisionX, collisionY, 0xffffff);*/
	}
	

	//DrawCircle(640, 360, 3, 0xff0000, TRUE);
	/*if (tmp == 0) {
		DrawCircle(680, 310, 10, 0xff0000, TRUE);
	}*/

	/*if (levelUpFlg) {
		DrawFormatString(450, 60, 0xffffff, "��������x���A�b�v���܂��B���x������͂��Ă�������.(0~8)");
		DrawFormatString(450, 90, 0xffffff, "���탌�x�� :: %d     L�L�[�ŕ���",weaponLevel);
	}
	else {
		DrawFormatString(450, 60, 0xffffff, "L�L�[�Ń��x���A�b�v���j���[���J��");
	}*/


	
}

void weapon::SetWeaponType(int type)
{
	weaponType = type;
	LevelState();
	/*switch (weaponType)
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
	}*/
}

void weapon::LevelUpDebug(int num)
{
	weaponLevel = num;
	switch (weaponLevel)
	{
	case 0:
		

		break;
	case 1:
		

		break;
	case 2:
		

		break;
	case 3:
		

		break;
	case 4:
		

		break;
	case 5:
		

		break;
	case 6:
		

		break;
	case 7:
		

		break;
	/*case 8:
		weaponLevel++;*/

		break;
	default:
		break;
	}

}

void weapon::LevelState()
{
	switch (weaponLevel)
	{
	case 0:
		switch (weaponType)
		{
		case sword:
			baseVec = { 100,0,100 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 70,0,70 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 120,0,120 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_GREATSWORD;
			damage = INIT_DAMAGE_GREATSWORD;
			break;
		}

		break;
	case 1:
		switch (weaponType)
		{
		case sword:
			baseVec = { 100,0,100 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.9f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 70,0,70 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.9f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 120,0,120 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_GREATSWORD * 0.9f;
			damage = INIT_DAMAGE_GREATSWORD;
			break;
		}

		break;
	case 2:
		switch (weaponType)
		{
		case sword:
			baseVec = { 100,0,100 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.8f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 70,0,70 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.8f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 120,0,120 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_GREATSWORD * 0.8f;
			damage = INIT_DAMAGE_GREATSWORD;
			break;
		}

		break;
	case 3:
		switch (weaponType)
		{
		case sword:
			baseVec = { 100,0,100 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.7f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 70,0,70 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.7f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 120,0,120 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_GREATSWORD * 0.7f;
			damage = INIT_DAMAGE_GREATSWORD;
			break;
		}

		break;
	case 4:
		switch (weaponType)
		{
		case sword:
			baseVec = { 100,0,100 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.7f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 70,0,70 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.7f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 120,0,120 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_GREATSWORD * 0.7f;
			damage = INIT_DAMAGE_GREATSWORD;
			break;
		}

		break;
	case 5:
		switch (weaponType)
		{
		case sword:
			baseVec = { 100,0,100 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.6f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 70,0,70 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.6f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 120,0,120 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_GREATSWORD * 0.6f;
			damage = INIT_DAMAGE_GREATSWORD;
			break;
		}

		break;
	case 6:
		switch (weaponType)
		{
		case sword:
			baseVec = { 100,0,100 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.5f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 70,0,70 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.5f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 120,0,120 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_GREATSWORD * 0.5f;
			damage = INIT_DAMAGE_GREATSWORD;
			break;
		}

		break;
	case 7:
		switch (weaponType)
		{
		case sword:
			baseVec = { 100,0,100 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.4f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 70,0,70 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.4f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 120,0,120 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_GREATSWORD * 0.4f;
			damage = INIT_DAMAGE_GREATSWORD;
			break;
		}

		break;
	case 8:
		switch (weaponType)
		{
		case sword:
			baseVec = { 100,0,100 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.3f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 70,0,70 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.1f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 120,0,120 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_GREATSWORD * 0.3f;
			damage = INIT_DAMAGE_GREATSWORD;
			break;
		}

		break;
	default:
		break;
	}
	coolTime = maxCoolTime;
}

bool weapon::WeaponCollision(Location enemyLocation, float radius)
{
	Location weaponCollisionLocation;

	if (isAttacking) {

		for (int i = 0; i < (baseVec.length / 10) + 1; i++) {
			weaponCollisionLocation.x = location.x + unitVec.x * (i * 10);		//�v���C���[���W�{�P�ʃx�N�g�������a	//kk
			weaponCollisionLocation.y = location.y + unitVec.y * (i * 10);			//kk

			float tmp_x = weaponCollisionLocation.x - enemyLocation.x;
			float tmp_y = weaponCollisionLocation.y - enemyLocation.y;
			float tmp_length = sqrt(tmp_x * tmp_x + tmp_y * tmp_y);

			if (tmp_length < radius + 10) {
				return true;
			}
		}
	}

	return false;
}

//��]�̌���
//r: �p�x(���W�A��)
//x : ����X���W
//y : ����Y���W

//X = x * cos(r) - y * sin(r)
//Y = x * sin(r) + y * cos(r)