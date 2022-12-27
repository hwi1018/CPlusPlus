#pragma once
#include<iostream>

using namespace std;

class Point
{
private:
	int xPos, yPos;
public:
	Point(int x, int y)
	{
		this->xPos = x;
		this->yPos = y;
	}
	
	void ShowPointInfo() const
	{
		cout << "[" << xPos << ", " << yPos << "]" << endl;
	}
};

class Circle
{
private:
	int radius;
	Point center;
public:
	Circle(int x, int y, int r) :center(x, y)
	{
		radius = r;
	}
	void ShowCircleInfo() const
	{
		cout << "radius : " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle SmallRing;
	Circle BigRing;
public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2):SmallRing(x1,y1,r1),BigRing(x2,y2,r2) //¸â¹ö ÀÌ´Ï¼È¶óÀÌÁî
	{
	}
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		SmallRing.ShowCircleInfo();
		cout << "Outer Circle Info..." << endl;
		BigRing.ShowCircleInfo();
	}
};