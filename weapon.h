#pragma once

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



class weapon {
private:
	int weaponType;



	Vector weaponVec;
	Vector baseVec;

	float collisionX, collisionY;	//��]��̍��W�A�����蔻��Ɏg��

	float rot;				//��]
	float relativeRot;		//�v���C���[�̃x�N�g���𒆐S�Ƃ�����]
	float maxRot;			//�ő�ǂꂭ�炢��]���邩

	int coolTime;	//�N�[���^�C��
	bool isAttacking;	//�U�������ǂ���

public:
	weapon();
	weapon(int type);
	~weapon();

	void Update();
	void Draw() const;

	void SetWeaponType(int type);
};

