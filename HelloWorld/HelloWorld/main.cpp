
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "GameObject.h"
#include "Utils.h"
#include "Screen.h"
#include "Vector2.h"
#include "InputSystem.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main()
{
	Vector2<int> pos;
	Vector2<int> pos1;

	Vector2<float> fPos;



	pos.set(10, 20);

	
	Vector2<int> pos2(30, 40);

	Vector2<int> pos3;



	pos3 = pos2;



	Vector2<int> pos4;

	pos = pos4 = pos3;

	pos = pos3 + pos2;

	pos = pos3 - pos2;

	int scale = 3;

	Vector2<int> newPos = pos1 + pos2 * scale;
	

	
	float div = 3;
	pos = pos3 / 3;


	
	Vector2<int> pos5 = scale * (pos1 + pos2);

	
	pos5.reset();

	pos5 = 0;

	pos3 = pos5;
	
	pos5 = Vector2<int>::zero;



	cout << pos5;



	cin >> pos5;



	double sz = pos5.magnitude(); // sqrt(x*x + y*y)



	double sqredSize = pos5.sqrMagnitude();  // x* x + y * y



	Vector2<double> dPos = pos;
	

	return 0;

}