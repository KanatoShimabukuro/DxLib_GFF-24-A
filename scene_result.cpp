#include "scene_result.h"

ResultScene::ResultScene()
{
	// �摜�Ǎ�
	img_button_a = LoadGraph("resources/images/button_a01.png");

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

	// �e�X�g
	fp = NULL;
	for (int i = 0; i < 2; i++)
	{
		sample[i] = { 0 };
	}
	is_fopen = false;

}

ResultScene::~ResultScene()
{

}

Scene* ResultScene::update()
{
	// �e�X�g
	// �t�@�C���ǂݍ���
	fopen_s(&fp, "resources/dat/test.txt", "r");

	if (fp)
	{
		is_fopen = true;
		for (int i = 0; i < 2; i++)
		{
			int dammy = fscanf_s(fp, "%1d %1d %07d", &sample[i].type, &sample[i].level, &sample[i].damage);
		}
		//�t�@�C���N���[�Y
		fclose(fp);
	}

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

	//DrawFormatString(700, 200, 0x000000, "����UI�P");
	//DrawFormatString(850, 150, 0x000000, "���햼�P");
	//DrawFormatString(850, 200, 0x000000, "Lv.              0");
	//DrawFormatString(850, 250, 0x000000, "���_���[�W��      100000");

	//DrawFormatString(700, 450, 0x000000, "����UI�Q");
	//DrawFormatString(850, 400, 0x000000, "���햼�Q");
	//DrawFormatString(850, 450, 0x000000, "Lv.              0");
	//DrawFormatString(850, 500, 0x000000, "���_���[�W��      100000");

	if (is_fopen == false)
	{
		DrawFormatString(600, 50, 0xff0000, "error");

	}
	else
	{
		/*DrawFormatString(700, 200, 0x000000, "����UI�P  %d", sample[0].type);
		DrawFormatString(850, 150, 0x000000, "���햼�P  %d", sample[0].type);*/
		SetFontSize(25);
		DrawFormatString(850, 200, 0x000000, "Lv.              %d", sample[0].level);
		DrawFormatString(850, 250, 0x000000, "���_���[�W��      %7d", sample[0].damage);

		/*DrawFormatString(700, 450, 0x000000, "����UI�Q  %d", sample[1].type);
		DrawFormatString(850, 400, 0x000000, "���햼�Q  %d", sample[1].type);*/
		SetFontSize(25);
		DrawFormatString(850, 450, 0x000000, "Lv.              %d", sample[1].level);
		DrawFormatString(850, 500, 0x000000, "���_���[�W��      %7d", sample[1].damage);
	}

	switch (sample[0].type)
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
	switch (sample[1].type)
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
