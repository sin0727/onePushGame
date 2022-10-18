#include <random>
#include <time.h>
#include "Calc.h"
#include <Novice.h>
#include "Resource.h"

// ����Ɖ�����ݒ肷��
int Calc::Clamp(int value, int min, int max) {
	if (value < min)return min;
	if (value > max)return max;
	return value;
}
float Calc::Clamp(float value, float min, float max) {
	if (value < min)return min;
	if (value > max)return max;
	return value;
}

// ��`���m�̓����蔻������
bool Calc::HasCollidedBoxAndBox(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {

	/* �ϐ����̕⑫
	*
	* L == Left
	* R == Right
	* T == Top
	* B == Bottom
	* H == Horizontal
	* V == Vertical
	*
	*/

	// �������̓����蔻��p
	int HLT1 = x1;
	int HRT1 = x1 + w1;
	int HLT2 = x2;
	int HRT2 = x2 + w2;

	//  �c�����̓����蔻��p
	int VLT1 = y1;
	int VLB1 = y1 + h1;
	int VLT2 = y2;
	int VLB2 = y2 + h2;

	if (HRT1 < HLT2)
		return false;
	if (HLT1 > HRT2)
		return false;
	if (VLB1 < VLT2)
		return false;
	if (VLT1 > VLB2)
		return false;

	return true;
}

// ���l�̕`��
//void Calc::DrawNum(int num, int pos_x, int pos_y, int space_char, float scale_x, float scale_y, float angle, unsigned int color) {
//	int i = 0;
//	while (num >= 10) {
//		Novice::DrawSprite(
//			pos_x - (i * space_char),
//			pos_y,
//			Image::number[num % 10],
//			scale_x,
//			scale_y,
//			angle,
//			color);
//		i++;	// ���[�v�񐔂𑝂₷
//		num *= 0.1f;	// �ꌅ�����炷
//	}
//	if (num >= 0) {
//		Novice::DrawSprite(
//			pos_x - (i * space_char),
//			pos_y,
//			Image::number[num % 10],
//			scale_x,
//			scale_y,
//			angle,
//			color);
//	}
//}