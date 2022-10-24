#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include "GameObject.h"
#include "Utils.h"
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"
#include "InputSystem.h"

#define WiNDOW_INPUT_TEST 

using namespace std;


HANDLE hStdin;
DWORD fdwSaveOldMode;

VOID ErrorExit(LPCSTR);
VOID KeyEventProc(KEY_EVENT_RECORD);
VOID MouseEventProc(MOUSE_EVENT_RECORD);
VOID ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);

int main()
{

	Screen screen(20, 81);
    InputSystem input;

	Player player{ 2, 4, screen, input};
	Enemy enemy1{ rand() % 80, rand() % 20, screen, input };
   
	while (1)
	{
		screen.clear();
		input.ReadEveryFrame();

		screen.draw(player.getPos(), player.getShape());
		screen.draw(enemy1.getPos(), enemy1.getShape());

		screen.render();
		
		
		player.update();
		enemy1.update();
	}

	return 0;
}
