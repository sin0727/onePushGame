#include "InputDevice.h.h"
#include <Novice.h>



/* 初期化 */
char Keyboard::keys[] = {};
char Keyboard::pre_Keys[] = {};

// 更新処理
void Keyboard::Update() {
	GetState();
}

// キー状態の取得
void Keyboard::GetState() {
	// キー入力状態の取得
	memcpy(pre_Keys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}