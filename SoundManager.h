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

	//BGM�̍Đ��ʒu��ݒ肷��
	//���Đ��ʒu���~���b�P�ʂŕύX����
	static void SetSoundBGMPosition(LONGLONG time, const char* fileName);

	//���ׂĂ�BGM�̍Đ��ʒu��ݒ肷��
	//���Đ��ʒu���~���b�P�ʂŕύX����
	static void SetSoundBGMsPosition(LONGLONG time);

	//SE�̍Đ��ʒu��ݒ肷��
	//���Đ��ʒu���~���b�P�ʂŕύX����
	static void SetSoundSEPosition(LONGLONG time, const char* fileName);

	//���ׂĂ�SE�̍Đ��ʒu��ݒ肷��
	//���Đ��ʒu���~���b�P�ʂŕύX����
	static void SetSoundSEsPosition(LONGLONG time);

	//BGM���Đ�����
	//���f�t�H���g�̍Đ��`���̓��[�v�A�Đ��ʒu�͍Ō�Ɏ~�߂��Ƃ��납�A�Đ��ʒu���w�肵���Ƃ��납��
	static void PlaySoundBGM(const char* fileName, int playType = DX_PLAYTYPE_LOOP, int topPositionFlag = FALSE);

	//SE���Đ�����
	//��isSingleUnit��true�Ȃ特���d�˂Ȃ��Afalse�Ȃ特���d�˂�A�f�t�H���g��true
	//���f�t�H���g�̍Đ��`���̓o�b�N�A�Đ��ʒu�͐擪����
	static void PlaySoundSE(const char* fileName, bool isSingleUnit = true, int playType = DX_PLAYTYPE_BACK, int topPositionFlag = TRUE);

	//BGM���~����
	static void StopSoundBGM(const char* fileName);

	//���ׂĂ�BGM���~����
	static void StopSoundBGMs();

	//SE���~����
	static void StopSoundSE(const char* fileName);

	//���ׂĂ�SE���~����
	static void StopSoundSEs();
};

