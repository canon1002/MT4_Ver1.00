#include "./Class/M4x4/Matrix4x4Funk.h"
#include <Novice.h>
#include <cmath>
#include <cassert>

/// 行列の和を返す関数
Matrix4x4 Add(Matrix4x4 m1, Matrix4x4 m2) {

	return Matrix4x4{
		m1.m[0][0] + m2.m[0][0],m1.m[0][1] + m2.m[0][1],m1.m[0][2] + m2.m[0][2],0,
		m1.m[1][0] + m2.m[1][0],m1.m[1][1] + m2.m[1][1],m1.m[1][2] + m2.m[1][2],0,
		m1.m[2][0] + m2.m[2][0],m1.m[2][1] + m2.m[2][1],m1.m[2][2] + m2.m[2][2],0,
		0,0,0,1
	};

}

/// 行列の差を返す関数
Matrix4x4 Subtract(Matrix4x4 m1, Matrix4x4 m2) {

	return Matrix4x4{
		m1.m[0][0] - m2.m[0][0],m1.m[0][1] - m2.m[0][1],m1.m[0][2] - m2.m[0][2],m1.m[0][3] - m2.m[0][3],
		m1.m[1][0] - m2.m[1][0],m1.m[1][1] - m2.m[1][1],m1.m[1][2] - m2.m[1][2],m1.m[1][3] - m2.m[1][3],
		m1.m[2][0] - m2.m[2][0],m1.m[2][1] - m2.m[2][1],m1.m[2][2] - m2.m[2][2],m1.m[2][3] - m2.m[2][3],
		m1.m[3][0] - m2.m[3][0],m1.m[3][1] - m2.m[3][1],m1.m[3][2] - m2.m[3][2],m1.m[3][3] - m2.m[3][3],
	};

}

/// 行列の積を返す関数
Matrix4x4 Multiply(Matrix4x4 m1, Matrix4x4 m2) {

	return Matrix4x4{
	m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0],
	m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1],
	m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2],
	m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3],

	m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0],
	m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1],
	m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2],
	m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3],

	m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0],
	m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1],
	m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2],
	m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3],

	m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0],
	m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1],
	m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2],
	m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3],
	};

}

/// 逆行列を作成する
Matrix4x4 Inverse(Matrix4x4 m) {

	float im = (
		(m.m[0][0] * m.m[1][1] * m.m[2][2] * m.m[3][3]) + (m.m[0][0] * m.m[1][2] * m.m[2][3] * m.m[3][1]) + (m.m[0][0] * m.m[1][3] * m.m[2][1] * m.m[3][2]) -
		(m.m[0][0] * m.m[1][3] * m.m[2][2] * m.m[3][1]) - (m.m[0][0] * m.m[1][2] * m.m[2][1] * m.m[3][3]) - (m.m[0][0] * m.m[1][1] * m.m[2][3] * m.m[3][2]) -
		(m.m[0][1] * m.m[1][0] * m.m[2][2] * m.m[3][3]) - (m.m[0][2] * m.m[1][0] * m.m[2][3] * m.m[3][1]) - (m.m[0][3] * m.m[1][0] * m.m[2][1] * m.m[3][2]) +
		(m.m[0][3] * m.m[1][0] * m.m[2][2] * m.m[3][1]) + (m.m[0][2] * m.m[1][0] * m.m[2][1] * m.m[3][3]) + (m.m[0][1] * m.m[1][0] * m.m[2][3] * m.m[3][2]) +
		(m.m[0][1] * m.m[1][2] * m.m[2][0] * m.m[3][3]) + (m.m[0][2] * m.m[1][3] * m.m[2][0] * m.m[3][1]) + (m.m[0][3] * m.m[1][1] * m.m[2][0] * m.m[3][2]) -
		(m.m[0][3] * m.m[1][2] * m.m[2][0] * m.m[3][1]) - (m.m[0][2] * m.m[1][1] * m.m[2][0] * m.m[3][3]) - (m.m[0][1] * m.m[1][3] * m.m[2][0] * m.m[3][2]) -
		(m.m[0][1] * m.m[1][2] * m.m[2][3] * m.m[3][0]) - (m.m[0][2] * m.m[1][3] * m.m[2][1] * m.m[3][0]) - (m.m[0][3] * m.m[1][1] * m.m[2][2] * m.m[3][0]) +
		(m.m[0][3] * m.m[1][2] * m.m[2][1] * m.m[3][0]) + (m.m[0][2] * m.m[1][1] * m.m[2][3] * m.m[3][0]) + (m.m[0][1] * m.m[1][3] * m.m[2][2] * m.m[3][0])
		);

	return Matrix4x4{

		(1 / im) * ((m.m[1][1] * m.m[2][2] * m.m[3][3]) + (m.m[1][2] * m.m[2][3] * m.m[3][1]) + (m.m[1][3] * m.m[2][1] * m.m[3][2]) -
					(m.m[1][3] * m.m[2][2] * m.m[3][1]) - (m.m[1][2] * m.m[2][1] * m.m[3][3]) - (m.m[1][1] * m.m[2][3] * m.m[3][2])),
		(1 / im) * (-(m.m[0][1] * m.m[2][2] * m.m[3][3]) - (m.m[0][2] * m.m[2][3] * m.m[3][1]) - (m.m[0][3] * m.m[2][1] * m.m[3][2]) +
					(m.m[0][3] * m.m[2][2] * m.m[3][1]) + (m.m[0][2] * m.m[2][1] * m.m[3][3]) + (m.m[0][1] * m.m[2][3] * m.m[3][2])),
		(1 / im) * ((m.m[0][1] * m.m[1][2] * m.m[3][3]) + (m.m[0][2] * m.m[1][3] * m.m[3][1]) + (m.m[0][3] * m.m[1][1] * m.m[3][2]) -
					(m.m[0][3] * m.m[1][2] * m.m[3][1]) - (m.m[0][2] * m.m[1][1] * m.m[3][3]) - (m.m[0][1] * m.m[1][3] * m.m[3][2])),
		(1 / im) * (-(m.m[0][1] * m.m[1][2] * m.m[2][3]) - (m.m[0][2] * m.m[1][3] * m.m[2][1]) - (m.m[0][3] * m.m[1][1] * m.m[2][2]) +
					(m.m[0][3] * m.m[1][2] * m.m[2][1]) + (m.m[0][2] * m.m[1][1] * m.m[2][3]) + (m.m[0][1] * m.m[1][3] * m.m[2][2])),

		(1 / im) * (-(m.m[1][0] * m.m[2][2] * m.m[3][3]) - (m.m[1][2] * m.m[2][3] * m.m[3][0]) - (m.m[1][3] * m.m[2][0] * m.m[3][2]) +
					(m.m[1][3] * m.m[2][2] * m.m[3][0]) + (m.m[1][2] * m.m[2][0] * m.m[3][3]) + (m.m[1][0] * m.m[2][3] * m.m[3][2])),
		(1 / im) * ((m.m[0][0] * m.m[2][2] * m.m[3][3]) + (m.m[0][2] * m.m[2][3] * m.m[3][0]) + (m.m[0][3] * m.m[2][0] * m.m[3][2]) -
					(m.m[0][3] * m.m[2][2] * m.m[3][0]) - (m.m[0][2] * m.m[2][0] * m.m[3][3]) - (m.m[0][0] * m.m[2][3] * m.m[3][2])),
		(1 / im) * (-(m.m[0][0] * m.m[1][2] * m.m[3][3]) - (m.m[0][2] * m.m[1][3] * m.m[3][0]) - (m.m[0][3] * m.m[1][0] * m.m[3][2]) +
					(m.m[0][3] * m.m[1][2] * m.m[3][0]) + (m.m[0][2] * m.m[1][0] * m.m[3][3]) + (m.m[0][0] * m.m[1][3] * m.m[3][2])) ,
		(1 / im) * ((m.m[0][0] * m.m[1][2] * m.m[2][3]) + (m.m[0][2] * m.m[1][3] * m.m[2][0]) + (m.m[0][3] * m.m[1][0] * m.m[2][2]) -
					(m.m[0][3] * m.m[1][2] * m.m[2][0]) - (m.m[0][2] * m.m[1][0] * m.m[2][3]) - (m.m[0][0] * m.m[1][3] * m.m[2][2])),

		(1 / im) * ((m.m[1][0] * m.m[2][1] * m.m[3][3]) + (m.m[1][1] * m.m[2][3] * m.m[3][0]) + (m.m[1][3] * m.m[2][0] * m.m[3][1]) -
					(m.m[1][3] * m.m[2][1] * m.m[3][0]) - (m.m[1][1] * m.m[2][0] * m.m[3][3]) - (m.m[1][0] * m.m[2][3] * m.m[3][1])),
		(1 / im) * (-(m.m[0][0] * m.m[2][1] * m.m[3][3]) - (m.m[0][1] * m.m[2][3] * m.m[3][0]) - (m.m[0][3] * m.m[2][0] * m.m[3][1]) +
					(m.m[0][3] * m.m[2][1] * m.m[3][0]) + (m.m[0][1] * m.m[2][0] * m.m[3][3]) + (m.m[0][0] * m.m[2][3] * m.m[3][1])),
		(1 / im) * ((m.m[0][0] * m.m[1][1] * m.m[3][3]) + (m.m[0][1] * m.m[1][3] * m.m[3][0]) + (m.m[0][3] * m.m[1][0] * m.m[3][1]) -
					(m.m[0][3] * m.m[1][1] * m.m[3][0]) - (m.m[0][1] * m.m[1][0] * m.m[3][3]) - (m.m[0][0] * m.m[1][3] * m.m[3][1])),
		(1 / im) * (-(m.m[0][0] * m.m[1][1] * m.m[2][3]) - (m.m[0][1] * m.m[1][3] * m.m[2][0]) - (m.m[0][3] * m.m[1][0] * m.m[2][1]) +
					(m.m[0][3] * m.m[1][1] * m.m[2][0]) + (m.m[0][1] * m.m[1][0] * m.m[2][3]) + (m.m[0][0] * m.m[1][3] * m.m[2][1])),

		(1 / im) * (-(m.m[1][0] * m.m[2][1] * m.m[3][2]) - (m.m[1][1] * m.m[2][2] * m.m[3][0]) - (m.m[1][2] * m.m[2][0] * m.m[3][1]) +
					(m.m[1][2] * m.m[2][1] * m.m[3][0]) + (m.m[1][1] * m.m[2][0] * m.m[3][2]) + (m.m[1][0] * m.m[2][2] * m.m[3][1])),
		(1 / im) * ((m.m[0][0] * m.m[2][1] * m.m[3][2]) + (m.m[0][1] * m.m[2][2] * m.m[3][0]) + (m.m[0][2] * m.m[2][0] * m.m[3][1]) -
					(m.m[0][2] * m.m[2][1] * m.m[3][0]) - (m.m[0][1] * m.m[2][0] * m.m[3][2]) - (m.m[0][0] * m.m[2][2] * m.m[3][1])),
		(1 / im) * (-(m.m[0][0] * m.m[1][1] * m.m[3][2]) - (m.m[0][1] * m.m[1][2] * m.m[3][0]) - (m.m[0][2] * m.m[1][0] * m.m[3][1]) +
					(m.m[0][2] * m.m[1][1] * m.m[3][0]) + (m.m[0][1] * m.m[1][0] * m.m[3][2]) + (m.m[0][0] * m.m[1][2] * m.m[3][1])),
		(1 / im) * ((m.m[0][0] * m.m[1][1] * m.m[2][2]) + (m.m[0][1] * m.m[1][2] * m.m[2][0]) + (m.m[0][2] * m.m[1][0] * m.m[2][1]) -
					(m.m[0][2] * m.m[1][1] * m.m[2][0]) - (m.m[0][1] * m.m[1][0] * m.m[2][2]) - (m.m[0][0] * m.m[1][2] * m.m[2][1])),

	};

}

/// 転置行列の計算
Matrix4x4 Transpose(Matrix4x4 m) {

	return Matrix4x4{
		m.m[0][0],m.m[1][0],m.m[2][0],m.m[3][0],
		m.m[0][1],m.m[1][1],m.m[2][1],m.m[3][1],
		m.m[0][2],m.m[1][2],m.m[2][2],m.m[3][2],
		m.m[0][3],m.m[1][3],m.m[2][3],m.m[3][3]
	};

}

/// 単位行列の作成
Matrix4x4 MakeIdentity() {

	return Matrix4x4{
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1,
	};

}


/// 平行移動行列の作成
Matrix4x4 MakeTranslateMatrix(const Vector3 translate) {

	return Matrix4x4{
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		translate.x,translate.y,translate.z,1
	};

}

/// 拡大縮小行列の作成
Matrix4x4 MakeScaleMatrix(const Vector3 scale) {

	return Matrix4x4{
		scale.x,0,0,0,
		0,scale.y,0,0,
		0,0,scale.z,0,
		0,0,0,1,
	};

}


/// 回転行列の作成(X軸周り：YZ平面)
Matrix4x4 MakeRoatateXMatrix(float rad) {

	return Matrix4x4{
		1,0,0,0,
		0,std::cos(rad),std::sin(rad), 0,
		0,-std::sin(rad),std::cos(rad),0,
		0,0,0,1,
	};

}

/// 回転行列の作成(Y軸周り：XZ平面)
Matrix4x4 MakeRoatateYMatrix(float rad) {

	return Matrix4x4{
		std::cos(rad),0,-std::sin(rad),0,
		0,1,0,0,
		std::sin(rad),0,std::cos(rad),0,
		0,0,0,1,
	};

}

/// 回転行列の作成(Z軸周り：XY平面)
Matrix4x4 MakeRoatateZMatrix(float rad) {

	return Matrix4x4{
		std::cos(rad),std::sin(rad),0,0,
		-std::sin(rad),std::cos(rad),0,0,
		0,0,1,0,
		0,0,0,1,
	};

}


/// 座標変換
Vector3 Transform(const Vector3& v, const Matrix4x4& m) {
	Vector3 result = {};
	result.x = v.x * m.m[0][0] + v.y * m.m[1][0] + v.z * m.m[2][0] + 1.0f * m.m[3][0];
	result.y = v.x * m.m[0][1] + v.y * m.m[1][1] + v.z * m.m[2][1] + 1.0f * m.m[3][1];
	result.z = v.x * m.m[0][2] + v.y * m.m[1][2] + v.z * m.m[2][2] + 1.0f * m.m[3][2];
	float w = v.x * m.m[0][3] + v.y * m.m[1][3] + v.z * m.m[2][3] + 1.0f * m.m[3][3];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;
	return result;
}

/// アフィン行列の作成
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {

	// 回転行列を作成
	Matrix4x4 rotateXMatrix = MakeRoatateXMatrix(rotate.x);
	Matrix4x4 rotateYMatrix = MakeRoatateYMatrix(rotate.y);
	Matrix4x4 rotateZMatrix = MakeRoatateZMatrix(rotate.z);
	Matrix4x4 rotateXYZMatrix = Multiply(rotateXMatrix, Multiply(rotateYMatrix, rotateZMatrix));

	return Matrix4x4{
		scale.x * rotateXYZMatrix.m[0][0],	scale.x * rotateXYZMatrix.m[0][1],	scale.x * rotateXYZMatrix.m[0][2],0,
		scale.y * rotateXYZMatrix.m[1][0],	scale.y * rotateXYZMatrix.m[1][1],	scale.y * rotateXYZMatrix.m[1][2],0,
		scale.z * rotateXYZMatrix.m[2][0],	scale.z * rotateXYZMatrix.m[2][1],	scale.z * rotateXYZMatrix.m[2][2],0,
		translate.x,						translate.y,						translate.z,					  1
	};

}


/// 透視投影行列の作成
Matrix4x4 MakePerspectiveMatrix(float fovY, float aspectRatio, float nearClip, float farClip) {

	return Matrix4x4{
	(1 / aspectRatio) * (1 / std::tan(fovY / 2)),0,0,0,
	0,(1 / std::tan(fovY / 2)),0,0,
	0,0,farClip / (farClip - nearClip),1,
	0,0,nearClip / (nearClip - farClip),1
	};

}

/// 正射影行列の作成
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip) {

	return Matrix4x4{
		2 / (right - left),0,0,0,
		0,2 / (top - bottom),0,0,
		0,0,1 / (farClip - nearClip),0,
		(left + right) / (left - right),(top + bottom) / (bottom - top),nearClip / (nearClip - farClip),1
	};

}

/// ビューポート変換行列の作成
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth) {

	// minD <= maxD でなければ実行しない
	assert(minDepth <= maxDepth);
	return Matrix4x4{
		width / 2,0,0,0,
		0,-height / 2,0,0,
		0,0,maxDepth - minDepth,0,
		left + (width / 2),top + (height / 2),minDepth,1
	};

}

Matrix4x4 MakeAxisAngle(Vector3 Axis, float Angle) {

	// 拡大縮小を行う Scale = S
  	float cosTheta = cosf(Angle);
	// rcosθ
	Matrix4x4 s = {
		cosTheta,0,0,0,
		0,cosTheta,0,0,
		0,0,cosTheta,0,
		0,0,0,1
	};

	// ベクトル射影を行う　Proj = P
	// (1-cosθ)projnr
	// =(r・n)n →　内積を行う
	Matrix4x4 s2 = {
		1-cosTheta,0,0,0,
		0,1-cosTheta,0,0,
		0,0,1-cosTheta,0,
		0,0,0,1
	};
	Matrix4x4 tnn{
		Axis.x * Axis.x,	Axis.x * Axis.y,	Axis.x * Axis.z,	0.0f,
		Axis.x * Axis.y,	Axis.y * Axis.y,	Axis.y * Axis.z,	0.0f,
		Axis.x * Axis.z,	Axis.y * Axis.z,	Axis.z * Axis.z,	0.0f,
		0.0f,				0.0f,				0.0f,				1.0f
	};
	Matrix4x4 p = Multiply(s2, tnn);

	// クロス積を行う　Cross = C
	// rcosθ
	Matrix4x4 c = {
		0,			(-sinf(Angle)) * -Axis.z,	(-sinf(Angle))* Axis.y,		0,
		(-sinf(Angle))* Axis.z,		0,			(-sinf(Angle)) * -Axis.x,	0,
		(-sinf(Angle)) * -Axis.y,	(-sinf(Angle))* Axis.x,		0,			0,
		0,			0,			0,			1,
	};
	

	// ベクトルを足し合わせる
	// 結果を返す
	return Add(s, Add(p, c));

}

Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to) {
	Matrix4x4 result = MakeIdentity();

	// クロス積
	const Vector3 c = {
		(from.y * to.z) - (from.z * to.y),
		(from.z * to.x) - (from.x * to.z),
		(from.x * to.y) - (from.y * to.x)
	};
	// 長さ
	const float cLength = sqrt((c.x * c.x) + (c.y * c.y) + (c.z * c.z));

	Vector3 n;
	if (from.x == -to.x && from.y == -to.y && from.z == -to.z) {
		n = { from.y,-from.x,0 };
	}
	else {
		// 正規化
		n.x = c.x / cLength;
		n.y = c.y / cLength;
		n.z = c.z / cLength;
	}

	// 角度
	const float cosT = from.x * to.x + from.y * to.y + from.z * to.z;
	const float sinT = cLength;

	result = {
		(n.x * n.x) * (1 - cosT) + cosT,        (n.x * n.y) * (1 - cosT) + n.z * sinT,    (n.x * n.z) * (1 - cosT) - n.y * sinT,    0,
		(n.x * n.y) * (1 - cosT) - n.z * sinT,    (n.y * n.y) * (1 - cosT) + cosT,        (n.y * n.z) * (1 - cosT) + n.x * sinT,    0,
		(n.x * n.z) * (1 - cosT) + n.y * sinT,    (n.z * n.y) * (1 - cosT) - n.x * sinT,    (n.z * n.z) * (1 - cosT) + cosT,        0,
		0,                                        0,                                        0,                                        1,
	};

	return result;
}

/// 描画関数 ///


/// 4x4行列の数値表示
void MatrixScreenPrintf(int x, int y, Matrix4x4& matrix, const char* label) {

	// ラベルの表示
	Novice::ScreenPrintf(x, y, "%s", label);

	// 行列の数値を表示

	// Y座標操作
	for (int h = 0; h < 4; h++) {
		// X座標操作
		for (int w = 0; w < 4; w++) {

			Novice::ScreenPrintf(x + 80 * w, (y + 20 * h) + 20, "%6.03f", matrix.m[h][w]);

		}
	}

}

/// 3次元ベクトルの数値表示
	/// <summary>
void VectorScreenPrintf(int x, int y, Vector3& vector, const char* label) {

	// ラベルの表示
	Novice::ScreenPrintf(x, y, "%s", label);

	// 3次元ベクトルの表示
	Novice::ScreenPrintf(x, y + 20, "%6.02f", vector.x);
	Novice::ScreenPrintf(x + 80, y + 20, "%6.02f", vector.y);
	Novice::ScreenPrintf(x + 160, y + 20, "%6.02f", vector.z);

}