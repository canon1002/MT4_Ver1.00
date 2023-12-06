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


void QuaternionScreenPrintf(int x, int y, Quaternion& vector, const char* label) {

	// ラベルの表示
	Novice::ScreenPrintf(x + 480, y, "%s", label);

	// 3次元ベクトルの表示
	Novice::ScreenPrintf(x, y, "%6.02f", vector.x);
	Novice::ScreenPrintf(x + 80, y, "%6.02f", vector.y);
	Novice::ScreenPrintf(x + 160, y, "%6.02f", vector.z);
	Novice::ScreenPrintf(x + 240, y, "%6.02f", vector.w);

}