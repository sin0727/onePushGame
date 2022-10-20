#pragma once

// ウィンドウの大きさとポジション
enum class WindowSize {
	WIN_MAX_X = 960,
	WIN_MAX_Y = 640,
	WIN_POS_X = 0,
	WIN_POS_Y = 0,
	POS_MAX_X = 960,
	POS_MAX_Y = 640,
};

// チップサイズと最大数
enum class chipSize {
	CELLX = 32,
	CELLY = 32,
	STAGE_MAX_X = 960 / 32,
	STAGE_MAX_Y = 640 / 32,
};

// シーンの種類
enum class SceneType {
	title,
	menu,
	game,
	game_over,
	goal,
};

enum class SelectType {
	tutorial,
	stage1,
};

enum class StageType {
	tutorial1,
	game_stage1,
	tutorial2,
};

// ブロックの種類とアイテム
enum class Tile : int {
	Stageblock,
	Makeblock,
	Notmoveblock,
	Thorn,
	Tile,
	Coin,

	MAX_TYPE,
};

// キャラの種類
enum class Item : int {
	/*road = (int)Tile::MAX_TYPE,*/
	player,
	ship,
	arrme,
	armesize = 96,

	MAX_TYPE,
};
