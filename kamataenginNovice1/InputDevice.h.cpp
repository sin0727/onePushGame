#include "InputDevice.h.h"
#include <Novice.h>



/* ������ */
char Keyboard::keys[] = {};
char Keyboard::pre_Keys[] = {};

// �X�V����
void Keyboard::Update() {
	GetState();
}

// �L�[��Ԃ̎擾
void Keyboard::GetState() {
	// �L�[���͏�Ԃ̎擾
	memcpy(pre_Keys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}