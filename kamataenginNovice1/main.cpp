#include <Novice.h>
//#include "Stage.h"
#include "InputDevice.h.h"
//#include "Resource.h"
#include "Scene.h"

//#include "Particle.h"


const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1440, 900);


	// インスタンス化
	Scene* scene = new Scene;


	// 画像の読み込み
	Image::LoadGraph();



	// 音声の読み込み
		/*Audio::LoadAudio();

		Novice::PlayAudio(Audio::title, 1, Audio::bgm_volume);*/
		// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		if (scene == nullptr) scene = new Scene;



		// インプットデバイスの更新処理
		Keyboard::Update();

		// 更新処理
		scene->Update();

		// 描画処理
		scene->Draw();

		if (scene->is_reset == true) if (scene != nullptr) { delete scene; scene = nullptr; }

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (Keyboard::pre_Keys[DIK_ESCAPE] == 0 && Keyboard::keys[DIK_ESCAPE] != 0) {
			break;
		}
	}


	// デリート処理
	if (scene != nullptr) delete scene;


	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
