#pragma once

// �L�[��ԊǗ��N���X
class Keyboard {

public:
	static char keys[256];		// �L�[��Ԏ擾�p
	static char pre_Keys[256];	// �O�t���[���ŉ�����Ă����L�[�̎擾�p
public:
	// �X�V����
	static void Update();

	// �L�[��Ԃ̎擾
	static void GetState();
};