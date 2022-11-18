#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <Windows.h>

template<typename T>
struct Position {
	T x;
	T y;

	Position(T x, T y) : x(x), y(y) {}

	template<typename U>
	Position(const Position<U>& another) : x(static_cast<T>(another.x)), y(static_cast<T>(another.y)) {}

	size_t size() const { return (size_t)(x * y); }

	auto operator+(const Position& other) const
	{
		return Position{ this->x + other.x, this->y + other.y };
	}

	auto operator-(const Position& other) const
	{
		return Position{ this->x - other.x, this->y - other.y };
	}

	template<typename U>
	Position<T>& operator=(const Position<U>& other)
	{
		x = static_cast<T>(other.x); y = static_cast<T>(other.y);
		return *this;
	}

	Position operator*(float scale)
	{
		return Position{ static_cast<T>(x * scale), static_cast<T>(y * scale) };
	}

	Position operator/(float scale)
	{
		return this->operator*(1.0f / scale);
	}

	auto sqrtMagnitude() const
	{
		return (double)x * x + y * y;
	}

	auto magnitude() const
	{
		return sqrt(sqrtMagnitude());
	}

	auto unit() const
	{
		auto mag = static_cast<float>(this->magnitude());
		if (mag <= 0.5f) mag = 1.0f;
		return Position{ x, y } / mag;
	}

	auto moveForward(const Position& target, float speed)
	{
		Position pos (*this);
		auto dirUnit = (target - pos).unit();
		pos = pos + dirUnit * speed;
		return pos;
	}

	bool operator==(const Position& other);

	bool operator!=(const Position& other) const
	{
		return !this->operator==(other);
	}

	static Position<T> InvalidPosition;

	friend std::ostream& operator<<(std::ostream& os, const Position& pos)
	{
		os << "(" << pos.x << "," << pos.y << ")";
		return os;
	}
};

typedef Position<int> Dimension;

class Borland {

public:
	static void Initialize()
	{
		CONSOLE_CURSOR_INFO cci = { 0 };
		cci.dwSize = 25;
		cci.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
		SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	}

	static int WhereX()
	{
		CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
		return csbiInfo.dwCursorPosition.X;
	}
	static int WhereY()
	{
		CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
		return csbiInfo.dwCursorPosition.Y;
	}
	static void GotoXY(int x, int y)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _COORD{ (SHORT)x, (SHORT)y });
	}
	static void GotoXY(const Position<int>* pos)
	{
		if (!pos) return;
		GotoXY( (*pos).x, (*pos).y);
	}
	static void GotoXY(const Position<int>& pos)
	{
		GotoXY( pos.x, pos.y);
	}
};

#endif 
