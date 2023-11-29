#include <Novice.h>

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

	Vector3 from0 = Nomalize(Vector3{ 1.0f,0.7f,0.5f });
	Vector3 to0 = Scalar(-1.0f, from0);
	Vector3 from1 = Nomalize(Vector3{ -0.6f,0.9f,0.2f });
	Vector3 to1 = Nomalize(Vector3{ 0.4f,0.7f,-0.5f });

	Matrix4x4 rotateMatrix0 = Matrix4x4Funk::DirectionToDirection(
		Nomalize(Vector3{ 1.0f,0.0f,0.0f }), Nomalize(Vector3{ -1.0f,0.0f,0.0f }));
	Matrix4x4 rotateMatrix1 = Matrix4x4Funk::DirectionToDirection(from0, to0);
	Matrix4x4 rotateMatrix2 = Matrix4x4Funk::DirectionToDirection(from1, to1);


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

		Matrix4x4Funk::MatrixScreenPrintf(10, 10, rotateMatrix0, "rotateMatrix");
		Matrix4x4Funk::MatrixScreenPrintf(10, 160, rotateMatrix1, "rotateMatrix1");
		Matrix4x4Funk::MatrixScreenPrintf(10, 310, rotateMatrix2, "rotateMatrix2");

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
