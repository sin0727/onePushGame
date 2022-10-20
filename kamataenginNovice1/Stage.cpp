#include "Stage.h"
#include <Novice.h>
#include "Calc.h"
#include "InputDevice.h.h"
#include "Resource.h"



//#include "Enum.h"

Stage::Stage() {
	Init();

}
Stage::~Stage() {

}

// 更新処理
void Stage::Updatetyutorial() {
	StagetyutorialInit();
	gameOut();
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



//ステージ処理
void Stage::StagetyutorialInit() {
	FILE* fp_stage_1_1;
	fp_stage_1_1 = fopen("./picter/stage/tyutorial.txt", "r");

	//ファイル書き出し
	FILE* fp_block_exp;
	fp_block_exp = fopen("./picter/stage/tyutorial_exp.txt", "w");

	for (int y = 0; y < (int)chipSize::STAGE_MAX_Y; y = y + 1)
	{
		for (int x = 0; x < (int)chipSize::STAGE_MAX_X; x = x + 1)
		{
			(void)fscanf(fp_stage_1_1, "%d", &Blo.Typ[x][y]);


		}
	}

	for (int y = 0; y < (int)chipSize::STAGE_MAX_Y; y = y + 1)
	{
		for (int x = 0; x < (int)chipSize::STAGE_MAX_X; x = x + 1)
		{
			int ins = Blo.Typ[x][y];
			fprintf(fp_block_exp, "(%d,%d)\n", x, y);
			for (int ye = 0; ye < (int)chipSize::CELLY; ye = ye + 1)
			{
				for (int xe = 0; xe < (int)chipSize::CELLX; xe = xe + 1)
				{
					Blo.Typ_Exp[x * (int)chipSize::CELLX + xe][y * (int)chipSize::CELLY + ye] = ins;
					fprintf(fp_block_exp, "%d", Blo.Typ_Exp[x * (int)chipSize::CELLX + xe][y * (int)chipSize::CELLX + ye]);
				}
				fprintf(fp_block_exp, "\n");
			}
		}
	}
	fclose(fp_stage_1_1);
	fclose(fp_block_exp);
}

//ゲーム描写
void Stage::stageDraw()
{
	int pic = 0;
	for (int x = 0; x < (int)chipSize::STAGE_MAX_X; x = x + 1)
	{
		for (int y = 0; y < (int)chipSize::STAGE_MAX_Y; y = y + 1)
		{
			switch (Blo.Typ[x][y])
			{
			case 0:
				
				break;
			case 1:
				pic = Image::stageBlock;
				break;
			case 2:
				
				break;
			case 3:
				pic = Image::notmoveblock;
				break;
			case 4:

				break;
			case 5:
				
				break;
			}
			Novice::DrawSprite((int)chipSize::CELLX * x + Sta_PosX, (int)chipSize::CELLY * y, pic, 1.0f, 1.0f, 0.0f, WHITE);
			//((int)chipSize::CELLX * x /*+*/ /**PosX*/, (int)chipSize::CELLY * y, pic, TRUE);
		}

	}
}
	
void Stage::gameOut()
{
	gameCal();
	cha();
}

void Stage::gameCal() 
{
	//アーム
	if (change == false) {
		if (arme == true)
		{
			//移動処理
			if (Keyboard::pre_Keys[DIK_A] != 0)
			{
				Fla2.Xmi = 1;
			}

			if (Fla2.Xmi == 1)
			{
				if (Arme.Pos.x > 120)
				{
					Arme.Pos.x = Arme.Pos.x - Movx2;
				}
			}

			//下移動
			if (Keyboard::pre_Keys[DIK_SPACE] != 0 && Fla2.Yup == 0 && rturn == false)
			{
				Fla2.Ydw = 1;
			}
		}

		if (Fla2.Ydw == 1)
		{
			arme = false;
			Arme.Pos.y = Arme.Pos.y + Movy2;
		}

		if (Arme.Pos.y > 416 || armecath == true && rturn == false)
		{
			Fla2.Ydw = 0;
			Fla2.Yup = 1;
		}

		//上移動
		if (Fla2.Yup == 1)
		{
			Arme.Pos.y = Arme.Pos.y - Movy3;
		}

		//リターン
		if (Arme.Pos.y < (int)WindowSize::POS_MAX_Y - 20 * (int)chipSize::CELLY && arme == false && rterunback == false)
		{
			/*armecath = false;*/ //バグ処理
			Fla2.Xpl = 0;
			Fla2.Yup = 0;
			rturn = true;
		}


		if (armecath == true && Arme.Pos.y < (int)WindowSize::POS_MAX_Y - 20 * (int)chipSize::CELLY)
		{
			rturn = true;
		}




		if (Arme.Pos.x > 120 && rturn == true && arme == false)
		{
			Arme.Pos.x = Arme.Pos.x - Movx3;
		}

		if (rturn == true && Keyboard::pre_Keys[DIK_SPACE] != 0)
		{
			armecath = false;
			armelost = true;
		}

		if (Arme.Pos.x <= 120 && arme == false)
		{
			if (armecath == true)
			{
				armelost = true;
			}
			armecath = false;
			++backmovecount;
			rturn = false;
			rterunback = true;

		}

		////バックリターン

		if (backmovecount > 180 && arme == false)
		{
			Arme.Pos.x = Arme.Pos.x + Movx3;
		}

		if (Arme.Pos.x >= 790 && rterunback == true)
		{
			armelost = false;
			rturn = false;
			rterunback = false;
			arme = true;
			backmovecount = 0;
			--changecount;
		}


		//当たり判定
		Arme.Out.le_up = Blo.Typ_Exp[Arme.Pos.X_Sta][Arme.Pos.y - 1];
		Arme.Out.ri_up = Blo.Typ_Exp[Arme.Pos.X_Sta + (int)chipSize::CELLX - 1][Arme.Pos.y - 1];
		Arme.Out.le_do = Blo.Typ_Exp[Arme.Pos.X_Sta][Arme.Pos.y + (int)chipSize::CELLX];
		Arme.Out.ri_do = Blo.Typ_Exp[Arme.Pos.X_Sta + (int)chipSize::CELLX - 1][Arme.Pos.y + (int)chipSize::CELLY];

		Arme.In.le_up = Blo.Typ_Exp[Arme.Pos.X_Sta][Arme.Pos.y];
		Arme.In.ri_up = Blo.Typ_Exp[Arme.Pos.X_Sta + (int)chipSize::CELLX - 1][Arme.Pos.y];
		Arme.In.le_do = Blo.Typ_Exp[Arme.Pos.X_Sta][Arme.Pos.y + (int)chipSize::CELLY - 1];
		Arme.In.ri_do = Blo.Typ_Exp[Arme.Pos.X_Sta + (int)chipSize::CELLX - 1][Arme.Pos.y + (int)chipSize::CELLY - 1];


	}

	//チェンジ
	if (changecount == 0)
	{
		change = true;
	}

	if (change == true) {
		//プレイヤー移動処理
		if (Keyboard::pre_Keys[DIK_D] != 0) { Fla.Xpl = 1; }
		else if (Keyboard::pre_Keys[DIK_A] != 0) { Fla.Xmi = 1; }

		if (Keyboard::pre_Keys[DIK_W] == 1)
		{
			Fla.Jum = 1;
			Player.Pos.Yin = Player.Pos.y;
		}


		if (Fla.Xpl == 1)
		{
			if (Sta_PosX == 0 || Sta_PosX == -(int)WindowSize::POS_MAX_X + (int)WindowSize::WIN_MAX_X)
			{
				Player.Pos.x = Player.Pos.x + Movx;
			}
			/*if (Player.Pos.x == WIN_MAX_X / 2)
			{
				Sta_PosX = Sta_PosX - Movx;
				Arme.Pos.x = Arme.Pos.x - Movx;
				boxx = boxx - Movx;
				boxx2 = boxx2 - Movx;
			}*/
		}

		else if (Fla.Xmi == 1)
		{
			if (Sta_PosX == 0 || Sta_PosX == -(int)WindowSize::POS_MAX_X + (int)WindowSize::WIN_MAX_X)
			{
				Player.Pos.x = Player.Pos.x - Movx;
			}
			/*if (Player.Pos.x == WIN_MAX_X / 2)
			{
				Sta_PosX = Sta_PosX + Movx;
				Arme.Pos.x = Arme.Pos.x + Movx;
				boxx = boxx + Movx;
				boxx2 = boxx2 + Movx;
			}*/
		}

		Player.Pos.X_Sta = Player.Pos.x + abs(Sta_PosX);

		//ジャンプ処理
		if (Fla.Rev == 0 && Fla.Jum == 1)
		{
			cou = cou + 1;
			T = T_k * ((double)cou / 60.0);

			Movy = (int)(pow(T, 2.0));
			for (int y = 1; y <= Movy; y = y + 1)
			{
				Player.Pos.y = Player.Pos.y - 1;
				Player.Out.le_up = Blo.Typ_Exp[Player.Pos.X_Sta][Player.Pos.y - 1];
				Player.Out.ri_up = Blo.Typ_Exp[Player.Pos.X_Sta + (int)chipSize::CELLX - 1][Player.Pos.y - 1];
				if (Movy_max == Player.Pos.Yin - Player.Pos.y || Player.Out.le_up != 0 || Player.Out.ri_up != 0)
				{
					Player.Pos.y = Player.Pos.y + 1;
					Fla.Rev = 1;
					cou = 0;
					break;
				}
			}
		}

		//下移動処理
		else if ((Fla.Rev == 1 && Fla.Jum == 1) || Player.Out.ri_do == 0 && Player.Out.le_do == 0)
		{
			cou = cou + 1;
			T = T_k * ((double)cou / 60.0);

			Movy = (int)(pow(T, 2.0));
			for (int y = 1; y <= Movy; y = y + 1)
			{

				Player.Pos.y = Player.Pos.y + 1;
				//すり抜け防止
				Player.Out.le_do = Blo.Typ_Exp[Player.Pos.X_Sta][Player.Pos.y + (int)chipSize::CELLY];
				Player.Out.ri_do = Blo.Typ_Exp[Player.Pos.X_Sta + (int)chipSize::CELLX - 1][Player.Pos.y + (int)chipSize::CELLY];

				if (Player.Out.le_do != 0 || Player.Out.ri_do != 0)
				{
					Player.Pos.y = Player.Pos.y - 1;
					Player.Pos.Yin = Player.Pos.y;
					Fla.Jum = 0;
					Fla.Rev = 0;
					Movy = 0;
					cou = 0;
					break;
				}
			}
		}

		//当たり判定
		Player.Out.le_up = Blo.Typ_Exp[Player.Pos.X_Sta][Player.Pos.y - 1];
		Player.Out.ri_up = Blo.Typ_Exp[Player.Pos.X_Sta + (int)chipSize::CELLX - 1][Player.Pos.y - 1];
		Player.Out.le_do = Blo.Typ_Exp[Player.Pos.X_Sta][Player.Pos.y + (int)chipSize::CELLY];
		Player.Out.ri_do = Blo.Typ_Exp[Player.Pos.X_Sta + (int)chipSize::CELLX - 1][Player.Pos.y + (int)chipSize::CELLY];


		Player.In.le_up = Blo.Typ_Exp[Player.Pos.X_Sta][Player.Pos.y];
		Player.In.ri_up = Blo.Typ_Exp[Player.Pos.X_Sta + (int)chipSize::CELLX - 1][Player.Pos.y];
		Player.In.le_do = Blo.Typ_Exp[Player.Pos.X_Sta][Player.Pos.y + (int)chipSize::CELLY - 1];
		Player.In.ri_do = Blo.Typ_Exp[Player.Pos.X_Sta + (int)chipSize::CELLX - 1][Player.Pos.y + (int)chipSize::CELLY - 1];

		if (Player.In.ri_up != 0 || Player.In.ri_do != 0)
		{
			if (Sta_PosX == 0 || Sta_PosX == -(int)WindowSize::POS_MAX_X + (int)WindowSize::WIN_MAX_X)
			{
				Player.Pos.x = Player.Pos.x - Movx;
			}
			if (Player.Pos.x == (int)WindowSize::WIN_MAX_X / 2)
			{
				Sta_PosX = Sta_PosX + Movx;
			}
		}

		else if (Player.In.le_up != 0 || Player.In.le_do != 0)
		{
			if (Sta_PosX == 0 || Sta_PosX == -(int)WindowSize::POS_MAX_X + (int)WindowSize::WIN_MAX_X)
			{
				Player.Pos.x = Player.Pos.x + Movx;
			}
			if (Player.Pos.x == (int)WindowSize::WIN_MAX_X / 2)
			{
				Sta_PosX = Sta_PosX - Movx;
			}
		}
	}

	//ボックスとアームアクション
	/*if (armecount < 120)
	{
		Fla2.Ydw = 0;
		Fla2.Yup = 1;
	}
	else if (armecount < 50)
	{
		Fla2.Ydw = 0;
		Fla2.Yup = 0;
	}
	--armecount;*/
	if (armecath == true)
	{
		boxx2 = boxx2cath;
		boxy2 = boxy2cath;
	}

	if (armelost == true)
	{
		boxy2 += Movy2;
	}

	if (boxy2 > (int)WindowSize::POS_MAX_Y - 5 * (int)chipSize::CELLY && boxx2 < 200)
	{
		dust = false;
	}

	if (boxy2 > 482)
	{
		boxy2 = 482;
	}

	//プレイヤーとボックスの当たり判定
	if (Calc::HasCollidedBoxAndBox(Player.Pos.x, Player.Pos.y, (int)chipSize::CELLX, (int)chipSize::CELLY, boxx, boxy, (int)chipSize::CELLX, (int)chipSize::CELLY) == true) {
		Player.Pos.x = Player.Pos.prex;
		Player.Pos.y = Player.Pos.prey;
	}

	if (dust == true)
	{
		if (Calc::HasCollidedBoxAndBox(Player.Pos.x, Player.Pos.y, (int)chipSize::CELLX, (int)chipSize::CELLY, boxx2, boxy2, (int)chipSize::CELLX, (int)chipSize::CELLY) == true) {
			Player.Pos.x = Player.Pos.prex;
			Player.Pos.y = Player.Pos.prey;
		}
	}
	//アームとボックス
	if (Calc::HasCollidedBoxAndBox(Arme.Pos.x, Arme.Pos.y, ArmeSize, ArmeSize, boxx, boxy, (int)chipSize::CELLX, (int)chipSize::CELLY) == true) {
		Arme.Pos.x = Arme.Pos.prex;
		Arme.Pos.y = Arme.Pos.prey;
		Fla2.Ydw = 0;
		Fla2.Yup = 1;
	}

	if (Calc::HasCollidedBoxAndBox(Arme.Pos.x, Arme.Pos.y, ArmeSize, ArmeSize, boxx2, boxy2, (int)chipSize::CELLX, (int)chipSize::CELLY) == true)
	{
		//if (/*Arme.Pos.y < POS_MAX_Y - 20 * CELL && arme == false &&*/ rturn == true)
		//{
		//	/*Arme.Pos.x = Arme.Pos.prex;
		//	Arme.Pos.y = Arme.Pos.prey;*/
		//}


		armecath = true;
	}

	//ボックス　ボックス
	/*if (Calc::HasCollidedBoxAndBox(boxx2, boxy2, CELL, CELL, boxx, boxy, CELL, CELL) == true) {
		boxx2 = boxx2pre;
		boxy2 = boxy2pre;
	}*/

	///クリア
	if (Player.Pos.x >= coinx)
	{
		change = false;
		changecount = 1;
		Player.Pos.x = 210;
		Player.Pos.y = (int)WindowSize::POS_MAX_Y - 5 * (int)chipSize::CELLY;
		boxx2 = 590;
		boxy2 = (int)WindowSize::POS_MAX_Y - 6 * (int)chipSize::CELLY;
	}
}

void Stage::cha()
{
	Novice::DrawSprite(Player.Pos.x, Player.Pos.y, Image::player, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(Arme.Pos.x, Arme.Pos.y, Image::arme, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(boxx, boxy, Image::makeblock, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(coinx, coiny, Image::coin, 1.0f, 1.0f, 0.0f, WHITE);
	/*DrawBox(boxx, boxy, boxx + (int)chipSize::CELLX, boxy + (int)chipSize::CELLY, GetColor(0, 0, 0), TRUE);
	DrawBox(boxx2, boxy2, boxx2 + (int)chipSize::CELLX, boxy2 + (int)chipSize::CELLY, GetColor(0, 0, 255), dust);
	DrawCircle(coinx, coiny, 20, GetColor(255, 255, 255), TRUE);*/
	Fla.Xpl = 0;
	Fla.Xmi = 0;
	Fla2.Xpl = 0;
	Fla2.Xmi = 0;
	Player.Pos.prex = Player.Pos.x;
	Player.Pos.prey = Player.Pos.y;
	Arme.Pos.prex = Arme.Pos.x;
	Arme.Pos.prey = Arme.Pos.y;
	boxx2cath = Arme.Pos.x + (int)chipSize::CELLX;
	boxy2cath = Arme.Pos.y + ArmeSize;
	boxx2pre = boxx2;
	boxy2pre = boxy2;
	dust = TRUE;
}
