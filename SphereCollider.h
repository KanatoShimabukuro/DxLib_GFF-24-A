#pragma once
#include "DxLib.h"
#include"weapon.h"

struct Location
{
	float x;
	float y;
};

//struct Vector
//{
//	float x;
//	float y;
//};

struct DiffLocation
{
	float x;
	float y;
};

class SphereCollider
{
protected:
	Location location;	//���W
	DiffLocation diff;	//�v���C���[�̈ړ���
	Vector vector;		//�ړ���
	float radius;		//���a
public:
	SphereCollider();

	int CheckCollision(SphereCollider sphereCollider);

};

