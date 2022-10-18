#include "Stage.h"
#include "Novice.h"
#include "Calc.h"
#include "InputDevice.h.h"
#include "Resource.h"


Stage::Stage() {
	Init();

}
Stage::~Stage() {

}

// 更新処理
void Stage::Updatetyutorial() {
	StagetyutorialInit();
}

	// 更新処理
void Stage::Update() {

}

// 初期化処理
void Stage::Init() {

}

// 描画処理
void Stage::Draw() {
	Novice::DrawSprite(0, 0, Image::sky, 1.0f, 1.0f, 0.0f, WHITE);
	stageDraw();
}

//ブロック初期化
void Stage::Block_Ini(Ract* b) //ポインタ取得
{
	b->x = 0;   //x座標　　　　//参照渡し
	b->y = 0;   //y座標
	b->w = 0;   //幅
	b->t = e_Type::e_空;   //厚み
	b->k = 0;   //種類
	b->r = 0.;   //回転角度

	for (int i = 0; i < e_Ani::e_Ani_Total; i = i + 1)
	{
		b->p[i].p = 0;    //写真のハンドル
		b->p[i].w = 0;    //写真の幅
		b->p[i].t = 0;    //写真の厚み
	}

	b->a = e_Ani::e_Normal;  //アニメーション
	b->d = FALSE;  //向き
	b->j = 0;  //ジャンプカウンタ
	b->c = FALSE;  //キャラクターか否か(動くか否か)
}

//ステージ処理
void Stage::StagetyutorialInit() {

	//ファイル取得
	char name[] = { "./picter/stage/tyutorial.txt" };
	FILE* fp = NULL;
	errno_t error = fopen_s(&fp, name, "r");

	if (error == NULL && fp != NULL)
	{
		fscanf_s(fp, "%d\n", &STAGE_TOTAL);
		fscanf_s(fp, "%d\n", &STAGE_WIDTH);
		fscanf_s(fp, "%d\n", &STAGE_HEIGHT);

		stagemake = new Text * [STAGE_WIDTH];
		for (int i = 0; i < STAGE_WIDTH; i = i + 1)
		{
			stagemake[i] = new Text[STAGE_HEIGHT];
		}

		for (int y = 0; y < STAGE_HEIGHT; y = y + 1)
		{
			for (int x = 0; x < STAGE_WIDTH; x = x + 1)
			{
				fscanf_s(fp, "%d\n", &stagemake[x][y].k);
				stagemake[x][y].x = x;
				stagemake[x][y].y = y;
			}
		}

		//ファイルを閉じる
		fclose(fp);
	}


	//メモリ確保
	Block = new Ract[STAGE_TOTAL];
	//TextからRactに変換、テキストの情報を一次元配列に格納
	int i = 0;
	for (int y = 0; y < STAGE_HEIGHT; y = y + 1)
	{
		for (int x = 0; x < STAGE_WIDTH; x = x + 1)
		{
			//ブロック無しのとき
			if (stagemake[x][y].k == e_Type::e_空)
			{
				//ブロック初期化
				Block_Ini(&Block[i]);
			}
			else
			{
				switch (stagemake[x][y].k)

				{
				case e_Type::e_地面:

					Block[i].p[0].p = Image::stageBlock;

					//向き
					Block[i].d = FALSE;
					//キャラか否か
					Block[i].c = FALSE;

					break;

				case e_Type::e_落とせる:
					Block[i].p[0].p = Image::stageBlock;
					/*Block[i].p0 = ;*/

					Block[i].d = FALSE;
					Block[i].c = FALSE;

					break;
				case e_Type::e_動かせない:
					Block[i].p[0].p = Image::stageBlock;
					/*Block[i].p0 = ;*/

					Block[i].d = FALSE;
					Block[i].c = FALSE;

					break;
				case e_Type::e_針:
					Block[i].p[0].p = Image::stageBlock;
					/*Block[i].p0 = ;*/

					Block[i].d = FALSE;
					Block[i].c = FALSE;

					break;
				case e_Type::e_コイン:
					Block[i].p[0].p = Image::stageBlock;
					/*Block[i].p0 = ;*/

					Block[i].d = FALSE;
					Block[i].c = FALSE;

					break;

				case e_Type::e_エネミー:
					Block[i].p[0].p = Image::stageBlock;
					/*Block[i].p0 = ;*/

					Block[i].d = FALSE;
					Block[i].c = FALSE;

					break;

				case e_Type::e_プレイヤー:
					Block[i].p[0].p = Image::stageBlock;
					/*Block[i].p0 = ;*/

					Block[i].d = FALSE;
					Block[i].c = TRUE;

					break;
				case e_Type::e_アーム:
					Block[i].p[0].p = Image::stageBlock;
					/*Block[i].p0 = ;*/

					Block[i].d = FALSE;
					Block[i].c = TRUE;

					break;

				/*case e_Type::e_:

					Block[i].p[e_Ani::e_Normal].p = LoadGraph("./supermario/mario.png");
					Block[i].p[e_Ani::e_Walk1].p = LoadGraph("./supermario/mariowalk.png");
					Block[i].p[e_Ani::e_Walk2].p = LoadGraph("./supermario/mariowalk2.png");
					Block[i].p[e_Ani::e_Jump].p = LoadGraph("./supermario/mariozyanpu.png");
					Block[i].p[e_Ani::e_End].p = LoadGraph("./supermario/sky.png");


					Block[i].d = FALSE;

					Block[i].c = TRUE;

					break;*/
				}

				////ブロック写真から厚みと幅取得
				//GetGraphSize(Block[i].p[0].p, &Block[i].p[0].w, &Block[i].p[0].t);
				////ブロックの幅と厚みを代入
				//Block[i].w = Block[i].p[0].w;
				//Block[i].t = Block[i].p[0].t;
				
				Block[i].w = 32/*(int)chipSize::CELLX*/;
				Block[i].t = 32/*(int)chipSize::CELLY*/;

				//ブロックの座標.種類.回転角度.ジャンプカウンタを代入
				Block[i].x = stagemake[x][y].x * 50;
				Block[i].y = stagemake[x][y].y * 50;
				Block[i].k = stagemake[x][y].k;
				Block[i].r = 0;
				Block[i].j = 0;
				Block[i].a = e_Ani::e_Normal;
			}

			//ループカウンタ
			i = i + 1;
		}
	}

	//メモリ解放(Text型　Stage)
	for (int i = 0; i < STAGE_WIDTH; i = i + 1)
	{
		delete[] stagemake[i];
	}
	delete[] stagemake;


	//ジャンプ時の変数初期化
	Jump = e_Jump::地面に着地;

	//カウンタ
	Cou = 0;

}

//ゲーム描写
void Stage::stageDraw()
{
	/*int pic = 0;
	for (int x = 0; x < (int)chipSize::STAGE_MAX_X; x = x + 1)
	{
		for (int y = 0; y < (int)chipSize::STAGE_MAX_Y; y = y + 1)
		{
			switch (Typ[x][y])
			{
			case 0:
				
				break;
			case 1:
				pic = Image::stageBlock;
				break;
			case 2:
				pic = Image::makeblock;
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			}
			Novice::DrawSprite((int)chipSize::CELLX * x, (int)chipSize::CELLX * y, pic, 1.0f, 1.0f, 0.0f, WHITE);
		}
	}*/

	//ブロック描写
	for (int i = 0; i < STAGE_TOTAL; i = i + 1)
	{

		//マリオ描写
		if (Block[i].k == e_Type::e_プレイヤー)
		{

			switch (Player->d)
			{
			case FALSE: //右方向を向く


				break;

			case TRUE: //左方向を向く


				break;
			}
		}

		//マリオ以外の描写
		else if (Block[i].k != e_Type::e_空)
		{
			switch (Block[i].d)
			{
			case FALSE: //右方向を向く
				Novice::DrawSprite(Block[i].x, Block[i].y, Block[i].p[0].p, 1.0f, 1.0f, 0.0f, WHITE);
				
				break;
				//左方向を向く
			case TRUE:
				Novice::DrawSprite(Block[i].x, Block[i].y, Block[i].p[0].p, 1.0f, 1.0f, 0.0f, WHITE);
				
				break;
			}
		}
	}
}
	





	

//ゲーム終了時の処理を行う関数
//void Stage::Game_End()
//{
//	//メモリ解放(Block)
//	delete[] Block;
//
//	//ゲーム初期化
//	StagetyutorialInit();
//}


