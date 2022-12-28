#include <iostream>
#include <vector>
#include <string>
//#include "Base.h";

using namespace std;

void Swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

int main(int argc, char* argv[])
{
	int a = 10;
	int b = 20;
	cout << a << " " << b << endl;
	Swap(a, b);
	cout << a << " " << b << endl;
	return 0;
}

