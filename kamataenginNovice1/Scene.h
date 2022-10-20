#pragma once

#include "Stage.h"

// シーン
class Scene {
public:
	int scene = (int)SceneType::title;	// シーンの種類
	/*Stage* stage = new Stage;*/	// ステージのインスタンス化
	int animation_index1 = 0;
	int animation_index2 = 0;
	int frame = 0;
	int tyutorialseen = 0;
	int crearframe = 0;
	int gameoverframe = 0;
	bool is_reset = false;

	int select = 0;
	int curx = 200;
	int cury = 300;
	int tyutorialx = 200;
	int tyutorialy = 200;
	int stage1x = 400;
	int stage1y = 200;
	int gamestage = 0;
public:
	Scene();
	~Scene();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

	// titleの更新処理
	void UpdateTitle();

	//// Menuの更新処理
	void UpdateMenu();

	// crearの更新処理
	void Updatecrear();

	// gameoverの更新処理
	void Updategameover();

	// titleの描画
	void DrawTitle();

	//// Menuの描画
	void DrawMenu();

	// crearの描画
	void Drawcrear();

	// gameoverの描画
	void Drawgameover();

	void startcount();
};