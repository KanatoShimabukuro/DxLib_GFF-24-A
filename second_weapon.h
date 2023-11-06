#pragma once
#include "weapon.h"

#define SPEAR_MAX_MOVE 180.0f
#define MAX_BULLETS_NUM 100

enum second_weapon_type
{
	spear,
	frail,
	book,
};

struct Bullet
{
	Vector v;
	Location l;
	bool flg;
};

class second_weapon
{
private:
	int weaponType;
	int weaponLevel;
	bool levelUpFlg;

	Location location;

	Vector weaponVec;
	Vector baseVec;
	Vector unitVec;

	float collisionX, collisionY;	//��]��̍��W�A�����蔻��Ɏg��
	Vector collisionVec;

	float rot;				//��]
	float relativeRot;		//�v���C���[�̃x�N�g���𒆐S�Ƃ�����]
	float maxRot;			//�ő�ǂꂭ�炢��]���邩
	float weaponAngle;

	int coolTime;	//�N�[���^�C�����v�Z����ϐ�
	int maxCoolTime;  //�N�[���^�C���̒l
	bool isAttacking;	//�U�������ǂ���
	int damage;

	int sword_img;
	int dagger_img;
	int greatsword_img;


	float tmp, tmp1;


	float spear_move_cnt;
	Vector spear_move;

	Vector book_move;
	Bullet bullets[MAX_BULLETS_NUM];

public:
	second_weapon();
	second_weapon(int type);
	~second_weapon();

	void Update(float cursorX, float cursorY, Location playerLocation);
	void Draw() const;

	void SetWeaponType(int type);

	void LevelUpDebug(int num);
	void LevelState();

	bool WeaponCollision(Location enemyLocation, float radius);


	void SpawnBookBullets();
	void MoveBookBullet();

	//���탌�x�����Z�b�g
	void SetWeaponLevel(int num) {
		weaponLevel = num;
		LevelState();
	}
	//���탌�x�����擾
	int GetWeaponLevel() { return weaponLevel; }

	bool GetLevelUpFlg() { return levelUpFlg; }
	int GetDamage() { return damage; }
	int GetWeaponType() { return weaponType; }
};

