#pragma once

#include<iostream>
#include<cmath>

using namespace std;
template<typename T>

class Vector2
{
	T x;
	T y;

public:
	Vector2(T x, T y) : x(x), y(y) {} //다음 기능 제공 안함
	//Vector2(const T& x, const T& y) : x(x), y(y) {}
	Vector2() : Vector2((T)0, (T)0) {};
	Vector2(const Vector2& other) = default; //컴파일러가 만들면 쓰겠음

	~Vector2(){}

	T X() const { return x; }
	T Y() const { return y; }

	template<typename U>
	Vector2(const Vector2<U>& other)
		: Vector2{ static_cast<T>(other.X()), static_cast<T>(other.Y()) }
	{}


	void set(T x, T y)
	{
		this->x = x;
		this->y = y;
	}

	//연산자 오퍼레이터
	//새로운 정보 생성
	//복사 생성자 함수 호출
	auto operator+(const Vector2& other) const
	{
		return Vector2(this->x + other.x, this->y + other.y);
	}

	auto operator-(const Vector2& other) const
	{
		return this ->operator+(other.operator*<int> (-1));
	}
	
	//U라는 자료형을 만듦
	//자료형이 다르지만 기능적으로 같은 코드는 템플릿 이용
	template<typename U>
	auto operator*(U scale) const
	{
		//U -> T
		return Vector2 (static_cast<T>(this->x * scale), static_cast<T>(this->y * scale));
	}

	template<typename U>
	auto operator/ (U scale) const
	{
		return Vector2(static_cast<T>(this->x / scale), static_cast<T>(this->y / scale));
	}

	template<typename U>
	friend auto operator*(U scale, const Vector2& other)
	{
		return other.operator*<U>(scale);
	}

	template<typename U>
	auto& operator = (U factor)
	{
		set(factor, factor);
		return *this; //chaining
	}

	friend ostream& operator << (ostream& os, Vector2 pos)
	{
		os << "(" << pos.x << pos.y << ")";
		return os;
	}

	friend istream& operator >>(istream& is, Vector2& v)
	{
		is >> v.x >> v.y;
		return is;
	}

	void reset() { set(0, 0); }

	auto sqrMagnitude() const {
		return this->x * this->x + this->y * this->y;
	}

	auto magnitude() const {
		return sqrt(this->sqrMagnitude());
	}

	static Vector2 zero;
	static Vector2 one;
};

