
#include <iostream>
using namespace std;

void CountUp(int& n);
void Change(int& n);
void SwapPointer(int* pt1, int* pt2);
int main()
{
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;

	cout << *ptr1 << " " << *ptr2 << endl;
	SwapPointer(ptr1, ptr2);
	cout << *ptr1 << " " << *ptr2 << endl;

	return 0;
}

//문제 1
void CountUp(int& n)
{
	n++;
}

//문제2 int형 변수의 부호를 바꿈
void Change(int& n)
{
	n = ~n;
	n += 1;
}

//문제3 SwapPointer 만들기
void SwapPointer(int* pt1, int* pt2)
{
	int temp = *pt1;
	*pt1 = *pt2;
	*pt2 = temp;
}