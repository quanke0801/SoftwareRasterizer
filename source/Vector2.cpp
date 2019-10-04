#include "Vector2.h"

Vector2::Vector2(const Scalar _x, const Scalar _y):
		x(_x),
		y(_y) {
}

Scalar Vector2::LengthSquare() const {
	return this->x * this->x + this->y * this->y;
}

Scalar Vector2::Length() const {
	return std::sqrt(this->LengthSquare());
}

void Vector2::Normalize() {
	auto length = this->Length();
	this->x /= length;
	this->y /= length;
}

Vector2 Vector2::Normalized() const {
	Vector2 normalized(this->x, this->y);
	normalized.Normalize();
	return normalized;
}

Scalar Vector2::Dot(const Vector2 &_other) const {
	return this->x * _other.x + this->y * _other.y;
}

Scalar Vector2::Cross(const Vector2 &_other) const {
	return this->x * _other.y - this->y * _other.x;
}

Scalar Vector2::Min() const {
	return this->x < this->y ? this->x : this->y;
}

int Vector2::MinIndex() const {
	return this->x < this->y ? 0 : 1;
}

Scalar Vector2::Max() const {
	return this->x < this->y ? this->y : this->x;
}

int Vector2::MaxIndex() const {
	return this->x < this->y ? 1 : 0;
}

Vector2 Vector2::operator - () const {
	return Vector2(-this->x, -this->y);
}

Vector2 Vector2::operator + (const Vector2 &_other) const {
	return Vector2(this->x + _other.x, this->y + _other.y);
}

Vector2 Vector2::operator - (const Vector2 &_other) const {
	return Vector2(this->x - _other.x, this->y - _other.y);
}

Vector2 Vector2::operator * (const Scalar _value) const {
	return Vector2(this->x * _value, this->y * _value);
}

Vector2 Vector2::operator * (const Vector2 &_other) const {
	return Vector2(this->x * _other.x, this->y * _other.y);
}

Vector2 Vector2::operator / (const Scalar _value) const {
	return Vector2(this->x / _value, this->y / _value);
}

Vector2 Vector2::operator / (const Vector2 &_other) const {
	return Vector2(this->x / _other.x, this->y / _other.y);
}

void Vector2::operator += (const Vector2 &_other) {
	this->x += _other.x;
	this->y += _other.y;
}

void Vector2::operator -= (const Vector2 &_other) {
	this->x -= _other.x;
	this->y -= _other.y;
}

void Vector2::operator *= (const Scalar _value) {
	this->x *= _value;
	this->y *= _value;
}

void Vector2::operator *= (const Vector2 &_other) {
	this->x *= _other.x;
	this->y *= _other.y;
}

void Vector2::operator /= (const Scalar _value) {
	this->x /= _value;
	this->y /= _value;
}

void Vector2::operator /= (const Vector2 &_other) {
	this->x /= _other.x;
	this->y /= _other.y;
}

std::ostream &operator << (std::ostream &_stream, const Vector2 &_vector) {
	_stream << "(" << _vector.x << ", " << _vector.y << ")";
	return _stream;
}

Vector2 operator * (const Scalar _value, const Vector2 &_vector) {
	return Vector2(_value * _vector.x, _value * _vector.y);
}

Vector2 Min(const Vector2 &_vector_1, const Vector2 &_vector_2) {
	return Vector2(_vector_1.x < _vector_2.x ? _vector_1.x : _vector_2.x, _vector_1.y < _vector_2.y ? _vector_1.y : _vector_2.y);
}

Vector2 Max(const Vector2 &_vector_1, const Vector2 &_vector_2) {
	return Vector2(_vector_1.x < _vector_2.x ? _vector_2.x : _vector_1.x, _vector_1.y < _vector_2.y ? _vector_2.y : _vector_1.y);
}
