#pragma once
#include "SphereCollider.h"

class EnemyBase :public SphereCollider
{
private:
	
protected:
	int img;			//�摜�i�[�p�ϐ�
	int hp;				//�G��HP
	int damage;			//�v���C���[�ɗ^����_���[�W
	int damageStopCnt;	//�_���[�W�X�g�b�v�p�̃J�E���g�ϐ�
	int respawnPosition;//���X�|�[������ꏊ

	bool playerHitFlg;	//�v���C���[�ɓ���������TRUE��Ԃ�

	bool HitFlg;
public:
	EnemyBase();

	//�v���C���[�܂ł̋��������߂�
	float PlayerLoad_X(float location_x);//X���W��ł̃v���C���[�܂ł̋���
	float PlayerLoad_Y(float location_y);//Y���W��ł̃v���C���[�܂ł̋���
	//���K��
	float Normalization_X(float location_x, float location_y);//X���W��ł̃v���C���[�܂ł̋����𐳋K��
	float Normalization_Y(float location_x, float location_y);//Y���W��ł̃v���C���[�܂ł̋����𐳋K��

	//���X�|�[���ʒu��ݒ肷��
	void SetRespawnPoint();

	int SetGetRand(int min, int max);
};