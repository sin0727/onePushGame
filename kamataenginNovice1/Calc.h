#pragma once

#include <random>
#include "Vector2.h"

// �v�Z�N���X
class Calc {
public:

	// ����Ɖ�����ݒ肷��
	static int Clamp(int value, int min, int max);
	static float Clamp(float value, float min, float max);

	// ��`���m�̓����蔻����Ƃ�
	static bool HasCollidedBoxAndBox(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

	// �����E�l�߂ŕ`�悷��
	/*static void DrawNum(int num, int pos_x, int pos_y, int space_char, float scale_x, float scale_y, float angle, unsigned int color);*/

};
