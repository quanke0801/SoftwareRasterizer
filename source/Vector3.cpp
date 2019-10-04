#include "Vector3.h"

Vector3::Vector3(const Scalar _x, const Scalar _y, const Scalar _z):
		x(_x),
		y(_y),
		z(_z) {
}

Scalar Vector3::LengthSquare() const {
	return this->x * this->x + this->y * this->y + this->z * this->z;
}

Scalar Vector3::Length() const {
	return std::sqrt(this->LengthSquare());
}

void Vector3::Normalize() {
	auto length = this->Length();
	this->x /= length;
	this->y /= length;
	this->z /= length;
}

Vector3 Vector3::Normalized() const {
	Vector3 normalized(this->x, this->y, this->z);
	normalized.Normalize();
	return normalized;
}

Scalar Vector3::Dot(const Vector3 &_other) const {
	return this->x * _other.x + this->y * _other.y + this->z * _other.z;
}

Vector3 Vector3::Cross(const Vector3 &_other) const {
	auto cross_x = this->y * _other.z - this->z * _other.y;
	auto cross_y = this->z * _other.x - this->x * _other.z;
	auto cross_z = this->x * _other.y - this->y * _other.x;
	return Vector3(cross_x, cross_y, cross_z);
}

Scalar Vector3::Min() const {
	return this->x < this->y ? (this->x < this->z ? this->x : this->z) : (this->y < this->z ? this->y : this->z);
}

int Vector3::MinIndex() const {
	return this->x < this->y ? (this->x < this->z ? 0 : 2) : (this->y < this->z ? 1 : 2);
}

Scalar Vector3::Max() const {
	return this->x < this->y ? (this->y < this->z ? this->z : this->y) : (this->x < this->z ? this->z : this->x);
}

int Vector3::MaxIndex() const {
	return this->x < this->y ? (this->y < this->z ? 2 : 1) : (this->x < this->z ? 2 : 0);
}

Vector3 Vector3::operator - () const {
	return Vector3(-this->x, -this->y, -this->z);
}

Vector3 Vector3::operator + (const Vector3 &_other) const {
	return Vector3(this->x + _other.x, this->y + _other.y, this->z + _other.z);
}

Vector3 Vector3::operator - (const Vector3 &_other) const {
	return Vector3(this->x - _other.x, this->y - _other.y, this->z - _other.z);
}

Vector3 Vector3::operator * (const Scalar _value) const {
	return Vector3(this->x * _value, this->y * _value, this->z * _value);
}

Vector3 Vector3::operator * (const Vector3 &_other) const {
	return Vector3(this->x * _other.x, this->y * _other.y, this->z * _other.z);
}

Vector3 Vector3::operator / (const Scalar _value) const {
	return Vector3(this->x / _value, this->y / _value, this->z / _value);
}

Vector3 Vector3::operator / (const Vector3 &_other) const {
	return Vector3(this->x / _other.x, this->y / _other.y, this->z / _other.z);
}

void Vector3::operator += (const Vector3 &_other) {
	this->x += _other.x;
	this->y += _other.y;
	this->z += _other.z;
}

void Vector3::operator -= (const Vector3 &_other) {
	this->x -= _other.x;
	this->y -= _other.y;
	this->z -= _other.z;
}

void Vector3::operator *= (const Scalar _value) {
	this->x *= _value;
	this->y *= _value;
	this->z *= _value;
}

void Vector3::operator *= (const Vector3 &_other) {
	this->x *= _other.x;
	this->y *= _other.y;
	this->z *= _other.z;
}

void Vector3::operator /= (const Scalar _value) {
	this->x /= _value;
	this->y /= _value;
	this->z /= _value;
}

void Vector3::operator /= (const Vector3 &_other) {
	this->x /= _other.x;
	this->y /= _other.y;
	this->z /= _other.z;
}

std::ostream &operator << (std::ostream &_stream, const Vector3 &_vector) {
	_stream << "(" << _vector.x << ", " << _vector.y << ", " << _vector.z << ")";
	return _stream;
}

Vector3 operator * (const Scalar _value, const Vector3 &_vector) {
	return Vector3(_value * _vector.x, _value * _vector.y, _value * _vector.z);
}

Vector3 Min(const Vector3 &_vector_1, const Vector3 &_vector_2) {
	return Vector3(_vector_1.x < _vector_2.x ? _vector_1.x : _vector_2.x, _vector_1.y < _vector_2.y ? _vector_1.y : _vector_2.y, _vector_1.z < _vector_2.z ? _vector_1.z : _vector_2.z);
}

Vector3 Max(const Vector3 &_vector_1, const Vector3 &_vector_2) {
	return Vector3(_vector_1.x < _vector_2.x ? _vector_2.x : _vector_1.x, _vector_1.y < _vector_2.y ? _vector_2.y : _vector_1.y, _vector_1.z < _vector_2.z ? _vector_2.z : _vector_1.z);
}

void Print(const Vector3 &_v) {
	printf("(%f, %f, %f)", _v.x, _v.y, _v.z);
}
