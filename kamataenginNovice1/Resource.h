#pragma once

// �摜�N���X
class Image {
public:
	static int stageBlock;
	static int makeblock;
	static int notmoveblock;
	static int thorn;
	static int tile;
	static int sky;
	static int coin;
	static int arme;
	static int targetcursor;
	static int ship;
	static int player;



	static int title;
	static int menu;
	static int cursol;
	static int stage_1;
	static int tyutorial;

public:
	Image();
	~Image();

	// �摜�̓ǂݍ���
	static void LoadGraph();
};

// �I�[�f�B�I�N���X
//class Audio {
//public:
//	/*static float name;
//
//	static int name;*/
//
//public:
//	static void LoadAudio();
//};




/*static int crear;
	static int gameover;*/

	/*static int number[10];*/