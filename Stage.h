#pragma once

class Stage {

private:
	int StageX;
	int StageY;
	int StageImg;

public:
	Stage();
	~Stage();

	void update(GameScene* gameScene);

	//�`�揈��
	void draw() const;


};