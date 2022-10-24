#pragma once
#include <conio.h>
#include "Utils.h"

using namespace std;

enum class KeyState
{
	Idle,
	Pressed,
	Stay,
	Released

};
typedef KeyState MouseState;

class InputSystem
{
	KeyState keys[256];
	HANDLE hStdin;
	DWORD fdwSaveOldMode;
	INPUT_RECORD irInBuf[128];

	MouseState mouse[2];
	COORD mousePosition;


	VOID ErrorExit(LPCSTR lpszMessage)
	{
		fprintf(stderr, "%s\n", lpszMessage);

		// Restore input mode on exit.

		SetConsoleMode(hStdin, fdwSaveOldMode);

		ExitProcess(0);
	}

	VOID KeyEventProc(KEY_EVENT_RECORD ker)
	{
		switch (keys[ker.wVirtualKeyCode & 0xff])
		{
		case KeyState::Idle:
			if (ker.bKeyDown == TRUE)
			{
				keys[ker.wVirtualKeyCode] = KeyState::Pressed;
			}
			break;

		case KeyState::Pressed:
			if (ker.bKeyDown == FALSE)
			{
				keys[ker.wVirtualKeyCode] == KeyState::Released;
			}

			break;

		case KeyState::Stay:
			if (ker.bKeyDown == FALSE)
			{
				keys[ker.wVirtualKeyCode] == KeyState::Released;
			}

			break;

		case KeyState::Released:
			keys[ker.wVirtualKeyCode] == KeyState::Idle;
			break;
		}
	}
	VOID MouseEventProc(MOUSE_EVENT_RECORD mer)
	{
#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif
		Borland::GotoXY(0, 30);
		printf("Mouse event: ");

		switch (mer.dwEventFlags)
		{
		case 0:

			if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				mouse[0] = MouseState::Pressed;
				mousePosition = mer.dwMousePosition;
				printf("left button press \n");
			}
			else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
			{
				mouse[1] = MouseState::Pressed;
				mousePosition = mer.dwMousePosition;
				printf("right button press \n");
			}
			else
			{
				printf("button press\n");
			}
			break;
		case DOUBLE_CLICK:
			printf("double click\n");
			break;
		case MOUSE_HWHEELED:
			printf("horizontal mouse wheel\n");
			break;
		case MOUSE_MOVED:
			mousePosition = mer.dwMousePosition;
			printf("mouse moved\n");
			break;
		case MOUSE_WHEELED:
			printf("vertical mouse wheel\n");
			break;
		default:
			printf("unknown\n");
			break;
		}
	}

public:
	InputSystem()  {
		
		DWORD  fdwMode;
		for (int i = 0; i < 256; i++)
		{
			keys[i] = KeyState::Idle;
		}

		mouse[0] = MouseState::Idle;
		mouse[1] = MouseState::Idle;
		mousePosition = { 0, 0 };

		memset(irInBuf, 0, sizeof(INPUT_RECORD) * 128);

		hStdin = GetStdHandle(STD_INPUT_HANDLE);
		if (hStdin == INVALID_HANDLE_VALUE)
			ErrorExit("GetStdHandle");

		// Save the current input mode, to be restored on exit.

		if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
			ErrorExit("GetConsoleMode");

		// Enable the window and mouse input events.

		fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
		if (!SetConsoleMode(hStdin, fdwMode))
			ErrorExit("SetConsoleMode");

		// Loop to read and handle the next 100 input events.

		
	}

	virtual  ~InputSystem()
	{
		SetConsoleMode(hStdin, fdwSaveOldMode);
	}

	void ReadEveryFrame() {
		
		DWORD cNumRead = 0;
		Borland::GotoXY(0, 25);

		if (GetNumberOfConsoleInputEvents(hStdin, &cNumRead) == 0)
		{
			printf("Input Reading Failure %d\n",GetLastError());
			return;
		}

		for (int i = 0; i < 256; i++)
		{
			switch (keys[i])
			{
			case KeyState::Released:
				keys[i] = KeyState::Idle;
				break;

			case KeyState::Pressed:
				keys[i] = KeyState::Stay;
				break;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			switch (mouse[i])
			{
			case MouseState::Pressed:
				mouse[i] = MouseState::Stay;
				break;
			case MouseState::Stay:
				mouse[i] = MouseState::Released;
				break;
			case MouseState::Released:
				mouse[i] = MouseState::Idle;
				break;
			}

		}
		if (cNumRead == 0)
		{
			
			printf("cNumRead = %d(no event)\n", cNumRead);
			return;
		}

		printf("cNumRead = %d(no event)\n", cNumRead);
		if (!ReadConsoleInput(
			hStdin,  
			irInBuf,
			128,
			&cNumRead))
		{
			ErrorExit("ReadConsoleInput");
		}

		

		for (int i = 0; i < (int)cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT:
				KeyEventProc(irInBuf[i].Event.KeyEvent);
				break;

			case MOUSE_EVENT:
				MouseEventProc(irInBuf[i].Event.MouseEvent);
				break;
			}
		}
	}

	auto getKeyDown(WORD keyCode)
	{
		Borland::GotoXY(0, 26);
		printf("key state down [%x]", keys[keyCode & 0x00ff]);
		return keys[keyCode & 0xff] == KeyState::Pressed;
	}

	auto getKey(WORD keyCode)
	{
		printf("key state stay [%x]", keys[keyCode & 0x00ff]);
		return keys[keyCode & 0xff] == KeyState::Pressed||
			keys[keyCode & 0xff] == KeyState::Stay||
			keys[keyCode & 0xff] == KeyState::Released;
	}

	auto getKeyUp(WORD keyCode)
	{
		printf("key state up [%x]", keys[keyCode & 0x00ff]);
		return keys[keyCode & 0xff] == KeyState::Released;
	}

	auto getMouseButton(int button)
	{
		printf("mouse state [%x]\n", mouse[button]);
		return mouse[button] == MouseState::Pressed ||
			mouse[button] == MouseState::Stay ||
			mouse[button] == MouseState::Released;
	}

	auto getMouseButtonDown(int button)
	{
		printf("mouse state [%x]\n", mouse[button]);
		return mouse[button] == MouseState::Pressed;

	}

	auto getMouseButtonUp(int button)
	{
		printf("mouse state [%x]\n", mouse[button]);
		return mouse[button] == MouseState::Released;
	}

	Position getMousePosition()
	{
		return{ mousePosition.X, mousePosition.Y };
	}
};


