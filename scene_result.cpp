#include "main.h"

ResultScene::ResultScene(int result_info[11])
{
	// �摜�Ǎ�
	img_button_a = LoadGraph("resources/images/button_a01.png");

	// �}�b�v�A�C�R���Ǎ��p�ϐ�
	img_battle = LoadGraph("resources/images/skeleton.png");
	img_event = LoadGraph("resources/images/event.png");
	img_rest = LoadGraph("resources/images/rest.png");
	img_anvil = LoadGraph("resources/images/anvil.png");
	img_boss = LoadGraph("resources/images/boss.png");

	//����̉摜�Ǎ�
	img_sword = LoadGraph("resources/images/����/�Ў茕.png");
	img_dagger = LoadGraph("resources/images/����/�Z��.png");
	img_great_sword = LoadGraph("resources/images/����/�匕.png");
	img_question_mark = LoadGraph("resources/images/mark_question.png");
	img_spear = LoadGraph("resources/images/����/��.png");
	img_frail = LoadGraph("resources/images/����/�t���C��.png");
	img_book = LoadGraph("resources/images/����/�{.png");

	// �ϐ��̏�����
	value = 180;

	// ����1
	weapon1_info.type = result_info[0];
	weapon1_info.level = result_info[1];
	weapon1_info.damage = result_info[2];

	// ����2
	weapon2_info.type = result_info[3];
	weapon2_info.level = result_info[4];
	weapon2_info.damage = result_info[5];

	// �}�b�v���
	map_info.battle_count = result_info[6];
	map_info.event_count = result_info[7];
	map_info.rest_count = result_info[8];
	map_info.anvil_count = result_info[9];
	map_info.boss_count = result_info[10];
}

ResultScene::~ResultScene()
{

}

Scene* ResultScene::update()
{
	// �u�����h���[�h�̃p�����[�^
	if (value > 0)
	{
		value--;
	}
	else
	{
		value = 0;
	}

	// �^�C�g���֑J��
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS)
	{
		SoundManager::StopSoundBGMs();
		return new Title;
	}

	return this;
}

void ResultScene::draw() const
{
	// �w�i�F
	DrawBox(0, 0, 1280, 720, 0xa0a0a0, TRUE);

	// �摜�\��
	DrawRotaGraph(1150, 690, 0.2f, 0.0f, img_button_a, TRUE);

	// �e�L�X�g�\��
	SetFontSize(60);
	DrawFormatString(550, 10, 0x000000, "RESULT");
	SetFontSize(20);
	DrawFormatString(1180, 680, 0x000000, "TITLE");

	DrawFormatString(10, 50, 0x000000, "�k���}�b�v");

	// �}�b�v���
	DrawRotaGraph(150, 150, 1.0f, 0.0f, img_battle, TRUE);
	DrawRotaGraph(150, 250, 1.0f, 0.0f, img_event, TRUE);
	DrawRotaGraph(150, 350, 1.0f, 0.0f, img_rest, TRUE);
	DrawRotaGraph(150, 450, 1.0f, 0.0f, img_anvil, TRUE);
	DrawRotaGraph(150, 550, 1.0f, 0.0f, img_boss, TRUE);

	SetFontSize(30);
	DrawFormatString(200, 135, 0x000000, "�~ %d",map_info.battle_count);
	DrawFormatString(200, 235, 0x000000, "�~ %d",map_info.event_count);
	DrawFormatString(200, 335, 0x000000, "�~ %d",map_info.event_count);
	DrawFormatString(200, 435, 0x000000, "�~ %d",map_info.anvil_count);
	DrawFormatString(200, 535, 0x000000, "�~ %d",map_info.boss_count);

	// ����1���\��
	DrawFormatString(850, 200, 0x000000, "Lv�D               %d", weapon1_info.level);
	DrawFormatString(850, 250, 0x000000, "���_���[�W    %7d", weapon1_info.damage);

	// ����2���\��
	DrawFormatString(850, 450, 0x000000, "Lv�D               %d", weapon2_info.level);
	DrawFormatString(850, 500, 0x000000, "���_���[�W    %7d", weapon2_info.damage);

	switch (weapon1_info.type)
	{
	case 0:			// �Ў茕
		DrawRotaGraph(750, 215, 0.2f, 0.0f, img_sword, TRUE);
		DrawFormatString(850, 150, 0x000000, "�Ў茕");
		break;
	case 1:		// �Z��
		DrawRotaGraph(750, 215, 0.2f, 0.0f, img_dagger, TRUE);
		DrawFormatString(850, 150, 0x000000, "�Z��");
		break;
	case 2:	// �匕
		DrawRotaGraph(750, 215, 0.2f, 0.0f, img_great_sword, TRUE);
		DrawFormatString(850, 150, 0x000000, "�匕");
		break;
	default:
		DrawRotaGraph(750, 215, 0.15f, 0.0f, img_question_mark, TRUE);
		DrawFormatString(850, 150, 0x000000, "���킪����܂���");
		break;
	}

	// ����2�̉摜
	switch (weapon2_info.type)
	{
	case 0:			// ��
		DrawRotaGraph(750, 470, 0.2f, 0.0f, img_spear, TRUE);
		DrawFormatString(850, 400, 0x000000, "��");
		break;
	case 1:			// �t���C��
		DrawRotaGraph(750, 470, 0.2f, 0.0f, img_frail, TRUE);
		DrawFormatString(850, 400, 0x000000, "�t���C��");
		break;
	case 2:			// ������
		DrawRotaGraph(750, 470, 0.2f, 0.0f, img_book, TRUE);
		DrawFormatString(850, 400, 0x000000, "������");
		break;
	default:
		DrawRotaGraph(750, 470, 0.15f, 0.0f, img_question_mark, TRUE);
		DrawFormatString(850, 400, 0x000000, "���킪����܂���");
		break;
	}

	//�t�F�[�h�̐ݒ�
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, value);

	//���œh��Ԃ�
	DrawBox(0, 0, 1280, 720, 0x000000, TRUE);

	//�f�t�H���g�ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


#ifdef _DEBUG
	DrawFormatString(0, 0, 0xffffff, "�J�[�\���ʒu: %d - %d", InputCtrl::GetMouseCursor().x, InputCtrl::GetMouseCursor().y);
#endif
}