#pragma once
#include <cmath>
class Vector3
{
public:
	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};
		float member[3];
	};
	Vector3(float px, float py, float pz);
    Vector3();

    float operator[] (int index);
    float magnitude();
    Vector3 normalized();
    Vector3 operator+(const Vector3 &v2);
    Vector3 operator-(const Vector3 &v2);
    Vector3 operator*(const float scalar);
    void operator+=(const Vector3 &v2);
    void operator=(const Vector3 &v2);
	~Vector3();
};

