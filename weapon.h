#pragma once
#define INIT_COOLTIME_SWORD  150
#define INIT_COOLTIME_DAGGER  60
#define INIT_COOLTIME_GREATSWORD  300

#define INIT_ROTATION_SWORD  60.0f
#define INIT_ROTATION_DAGGER  60.0f
#define INIT_ROTATION_GREATSWORD  90.0f

#define INIT_DAMAGE_SWORD  7
#define INIT_DAMAGE_DAGGER  4
#define INIT_DAMAGE_GREATSWORD  25

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

struct Location;

class weapon {
private:
	int weaponType;
	int weaponLevel;
	bool levelUpFlg;


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
public:
	weapon();
	weapon(int type);
	~weapon();

	void Update(float cursorX, float cursorY);
	void Draw() const;

	void SetWeaponType(int type);

	void LevelUpDebug(int num);
	void LevelState();

	bool WeaponCollision(Location enemyLocation, float radius);

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

