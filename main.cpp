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

	Quaternion q1 = { 2.0f,3.0f,4.0f,1.0f };
	Quaternion q2 = { 1.0f,3.0f,5.0f,2.0f };
	Quaternion identity = IdentityQuaternion();
	Quaternion conj = Conjugate(q1);
	Quaternion inv = Inverse(q1);
	Quaternion normal = Normalize(q1);
	Quaternion mul1 = Multiply(q1, q2);
	Quaternion mul2 = Multiply(q2, q1);
	float norm = Norm(q1);

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

		int y = 10;
		QuaternionScreenPrintf(10, y,identity, "Identity");
		y += 20;
		QuaternionScreenPrintf(10, y,conj, "Conjugate");
		y += 20;
		QuaternionScreenPrintf(10, y,inv, "Inverse");
		y += 20;
		QuaternionScreenPrintf(10, y,normal, "Normalize");
		y += 20;
		QuaternionScreenPrintf(10, y,mul1, "Multiply(q1,q2)");
		y += 20;
		QuaternionScreenPrintf(10, y,mul2, "Multiply(q2,q1)");
		y += 20;
		Novice::ScreenPrintf(20, y,"%3.2f",norm);
		Novice::ScreenPrintf(480, y,"Norm");
	
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
