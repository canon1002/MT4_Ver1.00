#pragma once
#include"Class/M4x4/Matrix4x4Funk.h"
#include"Class/MathTool.h"

struct Quaternion
{
	float x, y, z, w;

	Quaternion operator*=(float f) {
		Quaternion q0{};
		q0.x = this->x * f;
		q0.y = this->y * f;
		q0.z = this->z * f;
		q0.w = this->w * f;
		return q0;
	}

	Quaternion operator*(Quaternion other) {
		Quaternion q0{};
		q0.x = this->x * other.x;
		q0.y = this->y * other.y;
		q0.z = this->z * other.z;
		q0.w = this->w * other.w;
		return q0;
	}
};

Quaternion Multiply(Quaternion q1, Quaternion q2);
Quaternion Inverse(Quaternion q);
Quaternion IdentityQuaternion();
Quaternion Normalize(Quaternion q);
Quaternion Conjugate(Quaternion q);
float Norm(Quaternion q);
Quaternion Slerp(const Quaternion& q0, const Quaternion& q1, float t);
float QDot(const Quaternion& q0, const Quaternion& q1);

// 任意回転軸を表すQuaternionの作成
Quaternion MakeRotateAxisAngleQuaternion(const Vector3& axis, float angle);
// ベクトルをQuaternionで回転させた結果のベクトルを求める
Vector3 RotateVector(const Vector3& v, const Quaternion& q);
// Quaternionから回転行列を求める
Matrix4x4 MakeRotateMatrix(const Quaternion& q);


void QuaternionScreenPrintf(int x, int y, Quaternion& vector, const char* label);