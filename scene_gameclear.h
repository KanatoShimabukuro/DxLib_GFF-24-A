#pragma once

#include "scene.h"

// ���U���g�Ŏg�p�\��
class weapon;								// �ŏ��̕���
class second_weapon;						// ��ڂ̕���
class Map;									// �}�b�v

class GameClearScene : public Scene
{
private:
	// �摜�p�ϐ�
	int img_gameclear;					// �Q�[���N���A�i�����j
	int img_crown;						// ����
	int img_grail;						// ���t
	int img_player;						// �v���C���[
	int img_button_a;					// A�{�^��
	int img_background;					// �w�i
	int img_logo_result;

	// �t�F�[�h���o
	int value;						// �s�����x

	int result_info[11];			// ���U���g��ʂɓn��������A�}�b�v���

public:
	GameClearScene(weapon* weapon1, second_weapon* weapon2, Map* map);
	~GameClearScene();

	// �X�V
	Scene* update() override;

	// �`��
	void draw() const override;

};
