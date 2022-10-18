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
		e_針,
		e_コイン,
		e_エネミー,
		e_プレイヤー,
		e_アーム,
	};


	enum e_Ani
	{
		e_Normal,
		e_Walk1,
		e_Walk2,
		e_Jump,
		e_End,
		e_Ani_Total,
	};


	////ジャンプ状態の列挙体定義
	enum e_Jump
	{
		地面に着地,
		ジャンプ中,
		落下中,
	};

	struct Pic
	{
		int p;
		int w;
		int t;
	};


	struct Ract
	{
		int x;
		int y;
		int w;
		int t;
		int k;
		double r;
		Pic p[e_Ani::e_Ani_Total];
		int a;
		bool d;
		int j;
		bool c;
	};


	struct Text
	{
		int k;
		int x;
		int y;
	};

	//ブロック二次元配列
	Text** stagemake;


	int STAGE_TOTAL;
	int STAGE_WIDTH;
	int STAGE_HEIGHT;


	//一次元配列
	Ract* Block;

	//プレイヤーのアドレス
	Ract* Player;

	//アームのアドレス
	Ract* arme;

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
	void Game_End();

	//ゲーム描写
	void stageDraw(/*int* PosX*/);

	//ブロック初期化
	void Block_Ini(Ract* b);
};