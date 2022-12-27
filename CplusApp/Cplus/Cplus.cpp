
#include <iostream>
using namespace std;

typedef struct {
	int xPos;
	int yPos;
}Point;

void CountUp(int& n);
void Change(int& n);
void SwapPointer(int* pt1, int* pt2);
char* MakeStrAdr(int len);
Point& PntAddr(const Point& p1, const Point& p2);

int main()
{
	Point* pnt = new Point;
	pnt->xPos = 20;
	pnt->yPos = 100;

	Point* pnt2 = new Point;
	pnt2->xPos = 50;
	pnt2->yPos = 20;

	Point& ref = PntAddr(*pnt, *pnt2);
	cout << ref.xPos << " " << ref.yPos << endl;

	return 0;
}

Point& PntAddr(const Point& p1, const Point& p2)
{
	Point* pnt = new Point;
	pnt->xPos = p1.xPos + p2.xPos;
	pnt->yPos = p1.yPos + p2.yPos;

	return *pnt;
}

//���� 1
void CountUp(int& n)
{
	n++;
}

//����2 int�� ������ ��ȣ�� �ٲ�
void Change(int& n)
{
	n = ~n;
	n += 1;
}

//����3 SwapPointer �����
void SwapPointer(int* pt1, int* pt2)
{
	int temp = *pt1;
	*pt1 = *pt2;
	*pt2 = temp;
}

//new �Ҵ�

char* MakeStrAdr(int len)
{
	char* str = new char[len];

	return str;
}

