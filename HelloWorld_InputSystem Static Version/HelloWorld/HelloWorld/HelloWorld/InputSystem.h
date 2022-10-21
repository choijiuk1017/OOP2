#pragma once
#include <conio.h>
#include "Utils.h"

using namespace std;

class InputSystem
{
	static int Key;
	static int Minor;

public:
	
	static void ReadEveryFrame() {
		Key = -1; Minor = -1;

		if (!_kbhit()) return;

		Key = _getch();

		Borland::GotoXY(0, 23);
		printf("key is %c   %x %d\n", Key, Key, Key);		

		switch (Key) {
		case 224: // left/right/up/down arrow key
			Minor = _getch();
			printf("minor is %c   %x %d\n", Minor, Minor, Minor);
			break;
		case 0: // F1, F2 ...
			Minor = _getch();
			printf("minor is %c   %x %d\n", Minor, Minor, Minor);
			break;
		default:
			printf("                        ");
			break;
		}

	}

	static auto GetKey(int key)
	{
		return (Key != -1 && Key == key);
	}

	static auto GetKey(int key, int minor)
	{
		return (Key != -1 && Minor != -1 && 
			Key == key && Minor == minor);
	}


};

