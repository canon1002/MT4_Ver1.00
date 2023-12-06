#pragma once
#include"Class/M4x4/Matrix4x4Funk.h"
#include"Class/MathTool.h"

struct Quaternion
{
	float x, y, z, w;
};

Quaternion Multiply(Quaternion q1, Quaternion q2);
Quaternion Inverse(Quaternion q);
Quaternion IdentityQuaternion();
Quaternion Normalize(Quaternion q);
Quaternion Conjugate(Quaternion q);
float Norm(Quaternion q);
void QuaternionScreenPrintf(int x, int y, Quaternion& vector, const char* label);