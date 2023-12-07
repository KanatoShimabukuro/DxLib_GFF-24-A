#pragma once
#include "weapon.h"

#define INIT_COOLTIME_SPEAR  80
#define INIT_COOLTIME_FRAIL  120
#define INIT_COOLTIME_BOOK  60

#define INIT_COOLTIME_BOOK_LEVEL7 300

#define INIT_ROTATION_SPEAR  60.0f
#define INIT_ROTATION_FRAIL  60.0f
#define INIT_ROTATION_BOOK  90.0f

#define INIT_DAMAGE_SPEAR 10
#define INIT_DAMAGE_FRAIL 10
#define INIT_DAMAGE_BOOK  5


#define SPEAR_MAX_MOVE 23.0f
#define MAX_BULLETS_NUM 512

#define FRAIL_RADIUS 30
#define FRAIL_RADIUS_LEVEL8 45



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
	//level8�p
	float rot;				//��]
	float relativeRot;		//�v���C���[�̃x�N�g���𒆐S�Ƃ�����]
	float distance;
};

struct Thunder
{
	Location l;
	bool flg;
	//int img[5];	//�A�j���[�V�����̖�����
	int fps = 0;
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
	Vector playerVector;

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

	int spear_img;
	int frail_img;
	int book_img;
	int bullet_img;
	int ironball_img;
	int barrier_img;
	int attackbuf_img;
	int crack_img;
	int thunder_img[5];
	int arrow_img;
	int cooltime_img;


	float tmp, tmp1;


	float spear_move_cnt;
	Vector spear_move;
	Location spearlocation;
	Thunder thunder[64];
	float thunderRadius;
	float thunderDamage;

	float frailRadius;
	float frailRadiusBase;
	Vector frailVec;
	Location frailLcation;
	Location frailLcationCursor;
	float frailLength;
	float frailLengthCursor;
	bool isFrailAttacking;
	float frailRate;
	//������̑������t���C���̓����蔻��
	Location frailLocation1;
	Vector frailVec1;
	Location frailLocation2;
	Vector frailVec2;
	float level7FrailRot;
	bool level7FrailFlg;
	float frailDistance;
	float level8FrailRadius;

	Vector book_move;
	Bullet bullets[MAX_BULLETS_NUM];
	bool barrierFlg;
	

	float attackBufRate;

	int Bullet_speed;

	float P_aiming_radiusX;
	float P_aiming_radiusY;

	int totalDamage;
	bool soundFlg;

public:
	second_weapon();
	second_weapon(int type);
	~second_weapon();

	void Update(float cursorX, float cursorY, Location playerLocation, Vector playerVec, Player* player);
	void Draw() const;

	void SetWeaponType(int type);

	void LevelUpDebug(int num);
	void LevelState();

	bool WeaponCollision(Location enemyLocation, float radius);


	bool SpearAnim();
	bool SpearThunder();	//�����~��܂ŁA�U��؂����^�C�~���O��true
	bool SpearThunderCollision(Location enemyLocation, float radius);	//���̓����蔻��

	void SpawnBookBullets(int num);
	void MoveBookBullet();


	bool FrailAnim();
	bool ThreeFrailAnim();

	//�����łǂ�����Ăяo���ꂽ���w�肷��(0,second_weapon.cpp 1,scene_game.cpp)
	void InitWeapon(int type);

	//���탌�x�����Z�b�g
	void SetWeaponLevel(int num) {
		weaponLevel = num;
		LevelState();
	}

	void SetThunderLocation(Location l) {
		for (int i = 0; i < 64; i++){
			if (!thunder[i].flg) {
				thunder[i].fps = 0;
				thunder[i].l = l;
				thunder[i].flg = true;
				break;
			}
		}
	}

	void SetBarrierFlg(bool f) {
		barrierFlg = f;
	}
	//���탌�x�����擾
	int GetWeaponLevel() { return weaponLevel; }

	bool GetLevelUpFlg() { return levelUpFlg; }
	int GetDamage() { return damage; }
	int GetWeaponType() { return weaponType; }
	int GetCoolTime() { return coolTime; }
	bool GetBarrierFlg() { return barrierFlg; }

	float GetThunderDamage() { return thunderDamage; }
	float GetAttackBufRate() { return attackBufRate; }


	// �ǉ��@�t���C���̏Ə�
	float GetP_aiming_radiusX() { return P_aiming_radiusX; }
	float GetP_aiming_radiusY() { return P_aiming_radiusY; }

	float GetFrailRadius() { return frailRadius; }
	int GetBullet_speed() { return Bullet_speed; }

	// ���x���A�b�v��ʂŎg�p
	int GetMaxCoolTime() { return maxCoolTime; }
	float GetMaxRot() { return maxRot; }

	int GetTotalDamage() { return totalDamage; }
	void AddTotalDamage();
	void AddTotalDamageThunder();
};

