#pragma once

#include "Enum.h"
#include "Resource.h"

// ステージクラス
class Stage {
public:
	int selctStage = 0;

	enum e_Type
	{
		e_空,
		e_地面,
		e_落とせる,
		e_動かせない,
		e_プレイヤー,
		e_アーム,
		e_コイン,
		e_針,
		e_エネミー,
		
	};


	enum e_Ani
	{
		e_Normal,
		e_Walk1,
		e_Walk2,
		e_Jump,
		e_End,
		e_dfg,
		e_df,
		e_Ani_Total,
	};


	////ジャンプ状態の列挙体定義
	enum e_Jump
	{
		地面に着地,
		ジャンプ中,
		落下中,
	};

	struct
	{
		int Typ[(int)chipSize::STAGE_MAX_X][(int)chipSize::STAGE_MAX_Y];
		int Typ_Exp[(int)WindowSize::POS_MAX_X][(int)WindowSize::POS_MAX_Y];

	}Blo;

	

	int STAGE_TOTAL;
	int STAGE_WIDTH;
	int STAGE_HEIGHT;


	bool change = false;
	int changecount = 2;

	//プレイヤー

	struct
	{
		struct
		{
			int x = 210;
			int y = (int)WindowSize::POS_MAX_Y - 5 * (int)chipSize::CELLX;
			int prex = 0;
			int prey = 0;
			int Yin = (int)WindowSize::POS_MAX_Y - 3 * (int)chipSize::CELLY;
			int X_Sta;
		}Pos;

		struct
		{
			int le_up = 0;
			int ri_up = 0;
			int le_do = 0;

			int ri_do = 0;
		}In;

		struct
		{
			int le_up = 0;
			int ri_up = 0;
			int le_do = 0;
			int ri_do = 0;
		}Out;

	}Player;

	//プレイヤー移動
	const int Movx = (int)chipSize::CELLX / 10;
	int Movy = 0;
	const int Movy_max = (int)chipSize::CELLY * 2;

	int Sta_PosX = 0;


	struct
	{
		bool Xpl = 0;
		bool Xmi = 0;
		bool Jum = 0;
		bool Rev = 0;
	}Fla;


	int cou = 0;
	double T = 0.0;
	const double T_k = 10.0;


	//アーム
	struct
	{
		struct
		{
			int x = 790;
			int y = (int)WindowSize::POS_MAX_Y - 20 * (int)chipSize::CELLY;
			int prex = 0;
			int prey = 0;
			int Yin = (int)WindowSize::POS_MAX_Y - 3 * (int)chipSize::CELLY;
			int X_Sta;
		}Pos;

		struct
		{
			int le_up = 0;
			int ri_up = 0;
			int le_do = 0;

			int ri_do = 0;
		}In;

		struct
		{
			int le_up = 0;
			int ri_up = 0;
			int le_do = 0;
			int ri_do = 0;
		}Out;

	}Arme;

	//アーム移動
	const int Movx2 = (int)chipSize::CELLX / 8;

	//戻り
	const int Movx3 = (int)chipSize::CELLX / 11;
	//下移動
	const int Movy2 = (int)chipSize::CELLY / 10;
	const int Movy3 = (int)chipSize::CELLY / 12;

	int Sta_PosX2 = 0;

	struct
	{
		bool Xpl = 0;
		bool Xmi = 0;
		bool Ydw = 0;
		bool Yup = 0;
	}Fla2;


	int cou2 = 0;
	double T2 = 0.0;
	const double T_k2 = 10.0;

	bool arme = true;
	bool rturn = false;
	bool rterunback = false;
	bool armecath = false;
	bool armecathmove = false;
	bool armelost = false;
	int backmovecount = 0;
	int armecount = 240;

	//ボックス
	int boxx = 590;
	int boxy = (int)WindowSize::POS_MAX_Y - 5 * (int)chipSize::CELLY;

	int ArmeSize = 96;
	int boxx2 = 590;
	int boxy2 = (int)WindowSize::POS_MAX_Y - 6 * (int)chipSize::CELLY;
	int boxx2pre = 0;
	int boxy2pre = 0;
	int boxx2cath = 0;
	int boxy2cath = 0;
	bool dust = true;
	//コイン
	int coinx = 800;
	int coiny = (int)WindowSize::POS_MAX_Y - 5 * (int)chipSize::CELLY;

	/*int Typ[(int)chipSize::STAGE_MAX_X][(int)chipSize::STAGE_MAX_Y];
	int Typ_fd[(int)WindowSize::POS_MAX_X][(int)WindowSize::POS_MAX_Y];*/



	//ジャンプフラグ
	int Jump;

	//ジャンプ開始時のy座標記録
	int Jump_Ymem;

	//カウンタ
	int Cou;

public:
	Stage();
	~Stage();

	// 更新処理
	void Update();

	// 更新処理
	void Updatetyutorial();

	// 初期化処理
	void Init();

	// 描画処理
	void Draw();
	
	//ステージ処理
	void StagetyutorialInit();

	//ゲームエンド処理
	/*void Game_End();*/

	//ゲーム描写
	void stageDraw();

	//ゲームアクション出力
	void gameOut();

	//アクション計算
	void gameCal();

	//プレイヤーおよび初期化処理
	void cha();
};

Stage stage;