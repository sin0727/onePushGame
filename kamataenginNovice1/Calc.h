#pragma once

#include <random>
#include "Vector2.h"

// 計算クラス
class Calc {
public:

	// 上限と下限を設定する
	static int Clamp(int value, int min, int max);
	static float Clamp(float value, float min, float max);

	// 矩形同士の当たり判定をとる
	static bool HasCollidedBoxAndBox(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

	// 引数右詰めで描画する
	/*static void DrawNum(int num, int pos_x, int pos_y, int space_char, float scale_x, float scale_y, float angle, unsigned int color);*/

};
