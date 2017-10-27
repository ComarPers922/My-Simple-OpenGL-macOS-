#include "Vector3.h"



Vector3::Vector3(float px, float py, float pz): x(px), y(py), z(pz)
{

}

Vector3::Vector3(): x(0), y(0), z(0)
{

}

float Vector3::magnitude()
{
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vector3 Vector3::operator+(const Vector3 &v2)
{
    return Vector3(x + v2.x, y + v2.y, z + v2.z);
}
Vector3 Vector3::operator -(const Vector3 &v2)
{
    return Vector3(x - v2.x, y - v2.y, z - v2.z);
}

void Vector3::operator=(const Vector3 &v2)
{
    this->x = v2.x;
    this->y = v2.y;
    this->z = v2.z;
}

void Vector3::operator+=(const Vector3 &v2)
{
    this->x += v2.x;
    this->y += v2.y;
    this->z += v2.z;
}

float Vector3::operator[](const int index)
{
    return this->member[index];
}
Vector3 Vector3::normalized()
{
    float length = this->magnitude();
    return Vector3(x / length, y / length, z / length);
}

Vector3 Vector3::operator*(const float scalar)
{
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3::~Vector3()
{
}
