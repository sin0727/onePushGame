#include "Resource.h"
#include "Novice.h"


/* 初期化 */
int Image::makeblock = 0;
int Image::notmoveblock = 0;
int Image::thorn = 0;
int Image::tile = 0;
int Image::sky = 0;
int Image::coin = 0;
int Image::stageBlock = 0;
int Image::arme = 0;
int Image::targetcursor = 0;
int Image::ship = 0;
int Image::player = 0;



int Image::title = 0;
int Image::menu = 0;
int Image::cursol = 0;
int Image::stage_1 = 0;


int Image::tyutorial = 0;


Image::Image() {

}
Image::~Image() {

}
// 画像の読み込み
void Image::LoadGraph() {
	stageBlock = Novice::LoadTexture("./picter/stage/block0.png");
	makeblock = Novice::LoadTexture("./picter/stage/block1.png");
	notmoveblock = Novice::LoadTexture("./picter/stage/block2.png");
	thorn = Novice::LoadTexture("./picter/stage/block3.png");
	tile = Novice::LoadTexture("./picter/stage/block4.png");
	sky = Novice::LoadTexture("./picter/stage/sky.png");
	coin = Novice::LoadTexture("./picter/stage/coin.png");
	arme = Novice::LoadTexture("./picter/stage/arme.png");
	targetcursor = Novice::LoadTexture("./picter/stage/turgetcurrsol.png");
	ship = Novice::LoadTexture("./picter/stage/ship.png");
	player = Novice::LoadTexture("./picter/stage/mario.png");

	title = Novice::LoadTexture("./picter/desukutop.png");
	menu = Novice::LoadTexture("./picter/menu.png");
	cursol = Novice::LoadTexture("./picter/Red.png");
	stage_1 = Novice::LoadTexture("./picter/1.png");


	tyutorial = Novice::LoadTexture("./picter/tyutorial.png");



}

/* オーディオ */
//float Audio::name = 0.3f;
//int Audio::name;

//
//// オーディオの読み込み
//void Audio::LoadAudio() {
//	/* = Novice::LoadAudio(".//.mp3");*/
//
//}

//int Image::number[10] = {};
//int Image::crear = 0;
//int Image::gameover = 0;
/*crear = Novice::LoadTexture(".//.png");
	gameover = Novice::LoadTexture(".//.png");*/

	// 数字の読み込み
	/*number[0] = Novice::LoadTexture("./Images/UI/Number/Number0.png");
	number[1] = Novice::LoadTexture("./Images/UI/Number/Number1.png");
	number[2] = Novice::LoadTexture("./Images/UI/Number/Number2.png");
	number[3] = Novice::LoadTexture("./Images/UI/Number/Number3.png");
	number[4] = Novice::LoadTexture("./Images/UI/Number/Number4.png");
	number[5] = Novice::LoadTexture("./Images/UI/Number/Number5.png");
	number[6] = Novice::LoadTexture("./Images/UI/Number/Number6.png");
	number[7] = Novice::LoadTexture("./Images/UI/Number/Number7.png");
	number[8] = Novice::LoadTexture("./Images/UI/Number/Number8.png");
	number[9] = Novice::LoadTexture("./Images/UI/Number/Number9.png");*/