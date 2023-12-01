#pragma once
#include<DxLib.h>

class SoundManager
{
private:
	static SoundManager* manager;			//�I�u�W�F�N�g

	std::map<std::string, int>bgm;			//�A�z�z��bgm
	std::map<std::string, int>se;			//�A�z�z��se
public:
	//�R���X�g���N�^
	SoundManager() {};

	//�f�X�g���N�^
	~SoundManager() {};

	//SoundManager�̍쐬
	static void CreateSoundManager();

	//SoundManager�̍폜
	static void DeleteSoundManager();

	//�A�z�z��Ɋi�[���ꂽ�T�E���h�n���h�����擾����
	static int GetBGMHandle(const char* fileName) { return manager->bgm[fileName]; }

	//�T�E���h�n���h����BGM��ݒ肷��
	//��fileName�ɂ̓t�@�C���̖��O��������Ă�������
	static void SetBGM(const char* fileName);

	//�T�E���h�n���h����SE��ݒ肷��
	//��fileName�ɂ̓t�@�C���̖��O��������Ă�������
	static void SetSE(const char* fileName);

	//BGM�̉��ʂ�ݒ肷��
	static void SetVolumeBGM(const char* fileName, const int volume);

	//SE�̉��ʂ�ݒ肷��
	static void SetvolumeSE(const char* fileName, const int volume);

	//���ׂĂ�BGM�̉��ʂ�ݒ肷��
	static void SetVolumeBGMs(const int volume);

	//���ׂĂ�SE�̉��ʂ�ݒ肷��
	static void SetVolumeSEs(const int volume);

	//BGM���Đ�����
	//���f�t�H���g�̍Đ��`���̓��[�v�A�Đ��ʒu�͐擪����
	static void PlaySoundBGM(const char* fileName, int playType = DX_PLAYTYPE_LOOP, int topPositionFlag = TRUE);

	//SE���Đ�����
	//���f�t�H���g�̍Đ��`���̓o�b�N�A�Đ��ʒu�͐擪����
	static void PlaySoundSE(const char* fileName, int playType = DX_PLAYTYPE_BACK, int topPositionFlag = TRUE);

	//BGM���~����
	static void StopSoundBGM(const char* fileName);

	//���ׂĂ�BGM���~����
	static void StopSoundBGMs();

	//SE���~����
	static void StopSoundSE(const char* fileName);

	//���ׂĂ�SE���~����
	static void StopSoundSEs();
};

