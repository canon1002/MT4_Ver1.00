#include <Novice.h>
#include "./Quaternion.h"
#include"./Class/MathTool.h"
#include "./Class/M4x4/Matrix4x4Funk.h"

const char kWindowTitle[] = "MT4 Basic_01_01 LE2B_24";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Quaternion rotation0 = MakeRotateAxisAngleQuaternion({ 0.71f,0.71f,0.0f }, 0.3f);
	Quaternion rotation1 = MakeRotateAxisAngleQuaternion({ 0.71f,0.0f,0.71f }, 3.141592f);
	
	Quaternion interpolate0 = Slerp(rotation0, rotation1, 0.0f);
	Quaternion interpolate1 = Slerp(rotation0, rotation1, 0.3f);
	Quaternion interpolate2 = Slerp(rotation0, rotation1, 0.5f);
	Quaternion interpolate3 = Slerp(rotation0, rotation1, 0.7f);
	Quaternion interpolate4 = Slerp(rotation0, rotation1, 1.0f);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		QuaternionScreenPrintf(0, 10, interpolate0, "interpolate0, Slerp(rotation0, rotation1, 0.0f)");
		QuaternionScreenPrintf(0, 30, interpolate1, "interpolate1, Slerp(rotation0, rotation1, 0.3f)");
		QuaternionScreenPrintf(0, 50, interpolate2, "interpolate2, Slerp(rotation0, rotation1, 0.5f)");
		QuaternionScreenPrintf(0, 70, interpolate3, "interpolate3, Slerp(rotation0, rotation1, 0.7f)");
		QuaternionScreenPrintf(0, 90, interpolate4, "interpolate4, Slerp(rotation0, rotation1, 1.0f)");
		
	
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
