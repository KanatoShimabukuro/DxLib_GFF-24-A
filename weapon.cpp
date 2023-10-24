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
	relativeRot = 90.0f;		//武器によって変える
	maxRot = 90.0f;
	coolTime = 20;
	isAttacking = false;
	weaponLevel = 0;
	levelUpFlg = false;
}

weapon::weapon(int type)
{
	//使うか不明
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
	//x y length　にはプレイヤーとカーソルのベクトルを入れる
	float x = InputCtrl::GetMouseCursor().x - 640;
	float y = InputCtrl::GetMouseCursor().y - 360;
	float length = sqrt((x) * (x) + (y) * (y));

	float innerProduct = ((x) * baseVec.x) + ((y) * baseVec.y);
	float angle = acos(innerProduct / (length * baseVec.length));
	if (y > 0) {
		angle = (M_PI - angle);
		angle += M_PI;
	}

	//武器所有中なら
	if (weaponType != none) {
		//クールタイム中
		if (!(isAttacking) && --coolTime <= 0) {
			isAttacking = true;
			coolTime = maxCoolTime;
		}

		//攻撃中
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

	


	if (levelUpFlg) {
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
	}
}

void weapon::Draw() const
{
	//debug
	int x = InputCtrl::GetMouseCursor().x;
	int y = InputCtrl::GetMouseCursor().y;

	DrawFormatString(0, 0, 0xffffff, "武器タイプ %d 1,片手剣 2,短剣 3,大剣 100,なし", weaponType+1);
	DrawFormatString(0, 30, 0xffffff, "武器レベル %d", weaponLevel);
	DrawFormatString(0, 60, 0xffffff, "クールタイム　%d", maxCoolTime);
	DrawFormatString(0, 90, 0xffffff, "クールタイムカウント　%d", coolTime);
	DrawFormatString(0, 120, 0xffffff, "攻撃範囲 %f", maxRot);
	DrawFormatString(0, 150, 0xffffff, "ダメージ %d", damage);



	if (isAttacking) {
		DrawCircle(collisionX, collisionY, 3, 0xff0000, TRUE);
		DrawLine(640, 360, collisionX, collisionY, 0xffffff);
	}
	

	DrawCircle(640, 360, 3, 0xff0000, TRUE);

	if (levelUpFlg) {
		DrawFormatString(450, 60, 0xffffff, "武器をレベルアップします。レベルを入力してください.(0~8)");
		DrawFormatString(450, 90, 0xffffff, "武器レベル :: %d     Lキーで閉じる",weaponLevel);
	}
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
			baseVec = { 80,0,80 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 50,0,50 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 100,0,100 };
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
			baseVec = { 80,0,80 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.9f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 50,0,50 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.9f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 100,0,100 };
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
			baseVec = { 80,0,80 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.8f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 50,0,50 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.8f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 100,0,100 };
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
			baseVec = { 80,0,80 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.7f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 50,0,50 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.7f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 100,0,100 };
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
			baseVec = { 80,0,80 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.7f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 50,0,50 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.7f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 100,0,100 };
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
			baseVec = { 80,0,80 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.6f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 50,0,50 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.6f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 100,0,100 };
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
			baseVec = { 80,0,80 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.5f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 50,0,50 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.5f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 100,0,100 };
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
			baseVec = { 80,0,80 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.4f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 50,0,50 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.4f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 100,0,100 };
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
			baseVec = { 80,0,80 };
			maxRot = INIT_ROTATION_SWORD;
			maxCoolTime = INIT_COOLTIME_SWORD * 0.3f;
			damage = INIT_DAMAGE_SWORD;
			break;

		case dagger:
			baseVec = { 50,0,50 };
			maxRot = INIT_ROTATION_DAGGER;
			maxCoolTime = INIT_COOLTIME_DAGGER * 0.1f;
			damage = INIT_DAMAGE_DAGGER;
			break;

		case greatSword:
			baseVec = { 100,0,100 };
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

//回転の公式
//r: 角度(ラジアン)
//x : 元のX座標
//y : 元のY座標

//X = x * cos(r) - y * sin(r)
//Y = x * sin(r) + y * cos(r)