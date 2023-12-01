#include"main.h"

SoundManager* SoundManager::manager = nullptr;

void SoundManager::CreateSoundManager()
{
	//�I�u�W�F�N�g���쐬����Ă��Ȃ��Ȃ�I�u�W�F�N�g���쐬����
	if (manager == nullptr)
	{
		manager = new SoundManager();
	}
}

void SoundManager::DeleteSoundManager()
{
	InitSoundMem();
	delete manager;
	manager = nullptr;
}

void SoundManager::SetBGM(const char* fileName)
{
	//���[�J���ϐ�iterator��fileName�L�[�̌������ʂ���
	auto iterator = manager->bgm.find(string(fileName));

	//�ݒ肳��Ă��Ȃ��ꍇ
	if (iterator == manager->bgm.end())
	{
		//�t�@�C���̃p�X
		string filePath;
		filePath = "resources/sounds/BGM/" + string(fileName) + ".wav";

		//�L�[��BGM��ǂ݂���
		manager->bgm[fileName] = LoadSoundMem(filePath.c_str());
	}
}

void SoundManager::SetSE(const char* fileName)
{
	//���[�J���ϐ�iterator��fileName�L�[�̌������ʂ���
	auto iterator = manager->se.find(string(fileName));

	//�ݒ肳��Ă��Ȃ��ꍇ
	if (iterator == manager->se.end())
	{
		//�t�@�C���̃p�X
		string filePath;
		filePath = "resources/sounds/SE/" + string(fileName) + ".wav";

		//�L�[��SE��ǂ݂���
		manager->se[fileName] = LoadSoundMem(filePath.c_str());
	}
}

void SoundManager::SetVolumeBGM(const char* fileName, const int volume)
{
	ChangeVolumeSoundMem(255 * volume / 100, manager->bgm[fileName]);
}

void SoundManager::SetvolumeSE(const char* fileName, const int volume)
{
	ChangeVolumeSoundMem(255 * volume / 100, manager->se[fileName]);
}

void SoundManager::SetVolumeBGMs(const int volume)
{	
	for (auto iterator = manager->bgm.begin(); iterator != manager->bgm.end(); ++iterator)
	{
		ChangeVolumeSoundMem(255 * volume / 100, manager->bgm[iterator->first]);
	}
}

void SoundManager::SetVolumeSEs(const int volume)
{
	for (auto iterator = manager->se.begin(); iterator != manager->se.end(); ++iterator)
	{
		ChangeVolumeSoundMem(255 * volume / 100, manager->se[iterator->first]);
	}
}

void SoundManager::PlaySoundBGM(const char* fileName, int playType, int topPositionFlag)
{
	if (!CheckSoundMem(manager->bgm[fileName]))
	{
		PlaySoundMem(manager->bgm[fileName], playType, topPositionFlag);
	}
}

void SoundManager::PlaySoundSE(const char* fileName, int playType, int topPositionFlag)
{
	if (!CheckSoundMem(manager->se[fileName]))
	{
		PlaySoundMem(manager->se[fileName], playType, topPositionFlag);
	}
}

void SoundManager::StopSoundBGM(const char* fileName)
{
	StopSoundMem(manager->bgm[fileName]);
}

void SoundManager::StopSoundSE(const char* fileName)
{
	StopSoundMem(manager->se[fileName]);
}
