#pragma once

// キー状態管理クラス
class Keyboard {

public:
	static char keys[256];		// キー状態取得用
	static char pre_Keys[256];	// 前フレームで押されていたキーの取得用
public:
	// 更新処理
	static void Update();

	// キー状態の取得
	static void GetState();
};