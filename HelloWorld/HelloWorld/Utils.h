#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <string>
#include <cstdarg>
#include <Windows.h>

template<typename T>
struct Position {
	T x;
	T y;

	Position(T x, T y) : x(x), y(y) {}

	template<typename U>
	Position(const Position<U>& another) : x((T)another.x), y((T)another.y) {}

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
	auto& operator=(const Position<U>& other)
	{
		x = static_cast<T>(other.x); y = static_cast<T>(other.y);
		return *this;
	}

	auto operator*(float scale)
	{
		return Position{ x * scale, y * scale };
	}

	auto operator/(float scale)
	{
		return this->operator*(1.f / scale);
	}

	auto sqrtMagnitude() const
	{
		return x * x + y * y;
	}

	auto magnitude() const
	{
		return sqrt(sqrtMagnitude());
	}

	auto unit() const
	{
		return Position{ x, y } / this->magnitude();
	}

	auto moveForward(const Position& target, float speed)
	{
		Position pos (*this);
		auto dirUnit = (target - pos).unit();
		pos = pos + dirUnit * speed;
		return pos;
	}

	bool operator==(const Position& other);

	auto operator!=(const Position& other) 
	{
		return !this->operator==(other);
	}

	static Position<T> InvalidPosition;

	friend auto& operator<<(std::ostream& os, const Position& pos)
	{
		os << "(" << pos.x << "," << pos.y << ")";
		return os;
	}
};

typedef Position<int> Dimension;

class Borland {

	static Position<int> CurrentPos;
	static unsigned int MaxWidth;
	static unsigned int MaxHeight;

public:
	static void Initialize(unsigned int n_cols)
	{
		CONSOLE_CURSOR_INFO cci = { 0 };
		cci.dwSize = 25;
		cci.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
		SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);

		MaxWidth = n_cols;
		MaxHeight = 10;
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
	static void printf(const char* fmt, ...)
	{
		static char cleaningBuffer[100+1];

		GotoXY(CurrentPos.x, 30 + (CurrentPos.y % 10) );
		memset(cleaningBuffer, ' ', 100);
		cleaningBuffer[100] = NULL;
		::printf("%s\r[%7d] ", cleaningBuffer,  CurrentPos.y);

		va_list args;
		va_start(args, fmt);
		vprintf(fmt, args);
		va_end(args);

		CurrentPos.y++;
	}
};

#endif 
