#include "Quaternion.h"


Quaternion Multiply(Quaternion q1, Quaternion q2) {
	return {
		Cross({q1.x,q1.y,q1.z },{q2.x,q2.y,q2.z }).x + q2.w * q1.x + q1.w * q2.x,
		Cross({q1.x,q1.y,q1.z },{q2.x,q2.y,q2.z }).y + q2.w * q1.y + q1.w * q2.y,
		Cross({q1.x,q1.y,q1.z },{q2.x,q2.y,q2.z }).z + q2.w * q1.z + q1.w * q2.z,
		(q1.w * q2.w) - Dot({q1.x,q1.y,q1.z },{q2.x,q2.y,q2.z })
	};
}

Quaternion Inverse(Quaternion q) {
	return{
		Conjugate(q).x / (Norm(q) * Norm(q)),
		Conjugate(q).y / (Norm(q) * Norm(q)),
		Conjugate(q).z / (Norm(q) * Norm(q)),
		Conjugate(q).w / (Norm(q) * Norm(q)),
	};
}

Quaternion IdentityQuaternion() {
	return{
	0.0f,0.0f,0.0f,1.0f
	};
}

Quaternion Normalize(Quaternion q) {
	return{
		q.x / Norm(q),
		q.y / Norm(q),
		q.z / Norm(q),
		q.w / Norm(q),
	};
}

Quaternion Conjugate(Quaternion q) {
	return{
		-q.x,
		-q.y,
		-q.z,
		q.w,
	};
}

float Norm(Quaternion q) {
	return{
		std::sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w)
	};
}

// 任意回転軸を表すQuaternionの作成
Quaternion MakeRotateAxisAngleQuaternion(const Vector3& axis, float angle) {
	Quaternion result;
	result.x = axis.x * sinf(angle / 2.0f);
	result.y = axis.y * sinf(angle / 2.0f);
	result.z = axis.z * sinf(angle / 2.0f);
	result.w = cosf(angle / 2.0f);
	return result;
}

// ベクトルをQuaternionで回転させた結果のベクトルを求める
Vector3 RotateVector(const Vector3& v, const Quaternion& q) {
	Quaternion r = { v.x,v.y,v.z,0 };
	Quaternion rotate = Multiply(Multiply(q, r), Inverse(q));
	Vector3 result = { rotate.x,rotate.y, rotate.z };
	return result;
}

// Quaternionから回転行列を求める
Matrix4x4 MakeRotateMatrix(const Quaternion& q) {
	float x = q.x, y = q.y, z = q.z, w = q.w;
	float xx = x * x, yy = y * y, zz = z * z, ww = w * w;

	Matrix4x4 result{
		ww + xx - yy - zz,			2 * ((x * y) + (w * z)),	2 * ((x * z) - (w * y)),	0,
		2 * ((x * y) - (w * z)),	ww - xx + yy - zz,			2 * ((y * z) + (w * x)),	0,
		2 * ((x * z) + (w * y)),	2 * ((y * z) - (w * x)),	ww - xx - yy + zz,			0,
		0,							0,							0,							1
	};

	return result;
}


void QuaternionScreenPrintf(int x, int y, Quaternion& vector, const char* label) {

	// ラベルの表示
	Novice::ScreenPrintf(x + 480, y, "%s", label);

	// 3次元ベクトルの表示
	Novice::ScreenPrintf(x, y, "%6.02f", vector.x);
	Novice::ScreenPrintf(x + 80, y, "%6.02f", vector.y);
	Novice::ScreenPrintf(x + 160, y, "%6.02f", vector.z);
	Novice::ScreenPrintf(x + 240, y, "%6.02f", vector.w);

}