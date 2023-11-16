#pragma once
class Player;

#define d_r(_d) _d * (M_PI / 180)
#define r_d(_r) _r * (180 / M_PI)

#define INIT_COOLTIME_SWORD  120
#define INIT_COOLTIME_DAGGER  60
#define INIT_COOLTIME_GREATSWORD  210

#define INIT_ROTATION_SWORD  60.0f
#define INIT_ROTATION_DAGGER  60.0f
#define INIT_ROTATION_GREATSWORD  90.0f

#define INIT_DAMAGE_SWORD  7
#define INIT_DAMAGE_DAGGER  4
#define INIT_DAMAGE_GREATSWORD  25

#define AVOIDANCE_DAMAGE_RADIUS 100
#define MAX_THROW_DAGGER 64

struct Vector
{
	float x;
	float y;
	float length;
};

enum weapontype
{
	sword,
	dagger,
	greatSword,
	none = 99
};

struct Location
{
	float x;
	float y;
};

struct SwordSlash
{
	Location l;
	Vector v;
	bool flg;
	Location collsion1;
	Location collsion2;
};

struct ThrowDagger
{
	Location l;
	Vector v;
	bool flg;
	float relativeRot;
	float rot;
	Vector unit;
};


class weapon {
private:
	int weaponType;
	int weaponLevel;
	bool levelUpFlg;

	Location location;
	Vector playerVector;

	Vector weaponVec;
	Vector baseVec;
	Vector unitVec;

	float collisionX, collisionY;	//��]��̍��W�A�����蔻��Ɏg��
	Vector collisionVec;

	float rot;				//��]
	float relativeRot;		//�v���C���[�̃x�N�g���𒆐S�Ƃ�����]
	float maxRot;			//�ő�ǂꂭ�炢��]���邩
	float weaponAngle;
	float rotSpeed;

	int coolTime;	//�N�[���^�C�����v�Z����ϐ�
	int maxCoolTime;  //�N�[���^�C���̒l
	int maxCoolTimeTmp;  //�N�[���^�C���̒l
	bool isAttacking;	//�U�������ǂ���
	bool oldIsAttacking;	//�U�������ǂ���
	int damage;

	int sword_img;
	int dagger_img;
	int greatsword_img;

	//���@�v���C���[�̃X�e�[�^�X
	float P_speed;
	int   P_cooltime;
	float P_limit;

	//��Ԏa��
	SwordSlash swordSlash[10];
	int slash_img;
	int slashFlg;
	float slashRot;
	Location sl[100];

	//����
	int hitCnt;
	int fpsCnt;
	float heelAmount;

	//�����i�C�t
	ThrowDagger throwDagger[MAX_THROW_DAGGER];
	//��𒆂̃_���[�W
	bool avoidanceDamageFlg;

	float tmp, tmp1;
public:
	weapon();
	weapon(int type);
	~weapon();

	void Update(float cursorX, float cursorY, Location playerLocation, Player* player);
	void Draw() const;

	void SetWeaponType(int type);

	void LevelUpDebug(int num);
	void LevelState();

	bool WeaponCollision(Location enemyLocation, float radius);

	bool SpawnSwordSlash();
	void SwordSlashAnim();	//�ŏI�����P�̎a�����΂�

	void SwordLevel8(Player* player);


	bool SpawnThrowDagger(int num);
	void ThrowDaggerAnim();

	//���탌�x�����Z�b�g
	void SetWeaponLevel(int num) {
		weaponLevel = num;
		LevelState();
	}
	void SetCoolTime(float num, bool flg) {
		if (flg) {
			maxCoolTimeTmp = maxCoolTime;
			maxCoolTime = (int)maxCoolTime * num;
			coolTime = maxCoolTime;
		}
		else
		{
			maxCoolTime = maxCoolTimeTmp;
			LevelState();
		}
	}

	void SetHitCnt(bool flg) {
		if (flg) {
			hitCnt++;
		}
		else {
			hitCnt = 0;
		}
	}
	//���탌�x�����擾
	int GetWeaponLevel() { return weaponLevel; }

	bool GetLevelUpFlg() { return levelUpFlg; }
	int GetDamage() { return damage; }
	int GetWeaponType() { return weaponType; }
	bool GetIsAttacking() { return isAttacking; }
	bool GetOldIsAttacking() { return oldIsAttacking; }
};

