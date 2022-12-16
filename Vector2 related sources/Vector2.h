#pragma once

#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
class Vector2;

template<typename T>
class Vector2
{
	T x;
	T y;

public:
	Vector2(T x, T y) : x(x), y(y) {}
	Vector2() : x((T)0), y((T)0) {}

	T X() const { return x; }
	T Y() const { return y; }

	template<typename U>
	Vector2(const Vector2<U>& other) 
		: Vector2{ static_cast<T>(other.X()), static_cast<T>(other.Y()) } 
	{}


	void set(T x, T y) { this->x = x; this->y = y; }

	Vector2 operator+(const Vector2& other) const {
		return Vector2{ this->x + other.x, this->y + other.y };
	}

	template<typename U>
	Vector2 operator*(U scale) const {
		return Vector2{ static_cast<T>(this->x * scale), static_cast<T>(this->y * scale) };
	}

	Vector2 operator*(const Vector2& other) const {
		return Vector2{ this->x * other.x, this->y * other.y };
	}

	template<typename U>
	Vector2 operator/(U scale) const {
		return Vector2{ static_cast<T>(this->x / scale), static_cast<T>(this->y / scale) };
	}

	Vector2 operator-(const Vector2& other) const {
		return Vector2{ this->x - other.x, this->y - other.y };
	}
	

	template<typename U>
	friend Vector2 operator*(U scale, const Vector2& other) {
		return other.operator*<U>(scale);
	}


	void reset() { set(0, 0); }


	template<typename U>
	Vector2& operator=(U factor) {
		set(factor, factor);
		return *this; // chaining
	}


	friend ostream& operator<<(ostream& os, const Vector2& v) {
		os << "(" << v.x << "," << v.y << ")";
		return os;
	}

	friend istream& operator>>(istream& is, Vector2& v) {
		is >> v.x >> v.y;
		return is;
	}

	auto sqrMagnitude() const {
		return this->x * this->x + this->y * this->y;
	}

	auto magnitude() const {
		return sqrt(this->sqrMagnitude());
	}

	static Vector2<T> zero;
	static Vector2<T> one;
};