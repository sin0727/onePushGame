#pragma once

#include <random>
#include "Vector2.h"

// ŒvZƒNƒ‰ƒX
class Calc {
public:

	// ãŒÀ‚Æ‰ºŒÀ‚ğİ’è‚·‚é
	static int Clamp(int value, int min, int max);
	static float Clamp(float value, float min, float max);

	// ‹éŒ`“¯m‚Ì“–‚½‚è”»’è‚ğ‚Æ‚é
	static bool HasCollidedBoxAndBox(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

	// ˆø”‰E‹l‚ß‚Å•`‰æ‚·‚é
	/*static void DrawNum(int num, int pos_x, int pos_y, int space_char, float scale_x, float scale_y, float angle, unsigned int color);*/

};
