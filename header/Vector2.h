#pragma once

#include "Common.h"

class Vector2 {
public:
	Vector2(const Scalar _x = 0, const Scalar _y = 0);
	// Properties.
	Scalar LengthSquare() const;
	Scalar Length() const;
	void Normalize();
	Vector2 Normalized() const;
	// Vector operations.
	Scalar Dot(const Vector2 &_other) const;
	Scalar Cross(const Vector2 &_other) const;
	// Data range information.
	Scalar Min() const;
	int MinIndex() const;
	Scalar Max() const;
	int MaxIndex() const;
	// Operators.
	Vector2 operator - () const;
	Vector2 operator + (const Vector2 &_other) const;
	Vector2 operator - (const Vector2 &_other) const;
	Vector2 operator * (const Scalar _value) const;
	Vector2 operator * (const Vector2 &_other) const;
	Vector2 operator / (const Scalar _value) const;
	Vector2 operator / (const Vector2 &_other) const;
	void operator += (const Vector2 &_other);
	void operator -= (const Vector2 &_other);
	void operator *= (const Scalar _value);
	void operator *= (const Vector2 &_other);
	void operator /= (const Scalar _value);
	void operator /= (const Vector2 &_other);
public:
	Scalar x, y;
};

std::ostream &operator << (std::ostream &_stream, const Vector2 &_vector);
Vector2 operator * (const Scalar _value, const Vector2 &_vector);
Vector2 Min(const Vector2 &_vector_1, const Vector2 &_vector_2);
Vector2 Max(const Vector2 &_vector_1, const Vector2 &_vector_2);
