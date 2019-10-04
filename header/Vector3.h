#pragma once

#include "Common.h"

class Vector3 {
public:
	Vector3(const Scalar _x = 0, const Scalar _y = 0, const Scalar _z = 0);
	// Properties.
	Scalar LengthSquare() const;
	Scalar Length() const;
	void Normalize();
	Vector3 Normalized() const;
	// Vector operations.
	Scalar Dot(const Vector3 &_other) const;
	Vector3 Cross(const Vector3 &_other) const;
	// Data range information.
	Scalar Min() const;
	int MinIndex() const;
	Scalar Max() const;
	int MaxIndex() const;
	// Operators.
	Vector3 operator - () const;
	Vector3 operator + (const Vector3 &_other) const;
	Vector3 operator - (const Vector3 &_other) const;
	Vector3 operator * (const Scalar _value) const;
	Vector3 operator * (const Vector3 &_other) const;
	Vector3 operator / (const Scalar _value) const;
	Vector3 operator / (const Vector3 &_other) const;
	void operator += (const Vector3 &_other);
	void operator -= (const Vector3 &_other);
	void operator *= (const Scalar _value);
	void operator *= (const Vector3 &_other);
	void operator /= (const Scalar _value);
	void operator /= (const Vector3 &_other);
public:
	Scalar x, y, z;
};

std::ostream &operator << (std::ostream &_stream, const Vector3 &_vector);
Vector3 operator * (const Scalar _value, const Vector3 &_vector);
Vector3 Min(const Vector3 &_vector_1, const Vector3 &_vector_2);
Vector3 Max(const Vector3 &_vector_1, const Vector3 &_vector_2);

void Print(const Vector3 &_v);
