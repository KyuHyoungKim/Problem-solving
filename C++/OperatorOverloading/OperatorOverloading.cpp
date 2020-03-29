#include <iostream>

class Point
{
	int x;
	int y;

public:
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	Point operator + (Point& p)
	{
		int xReturn = x, yReturn = y;
		xReturn = x + p.x;
		yReturn = y + p.y;
		return Point(xReturn, yReturn);
	}
	Point operator + (int n)
	{
		Point RetPoint = Point(x + n, y + n);
		return RetPoint;
	}
	void Display()
	{	
		printf("%d %d\n", this->x, this->y);
	}
};

int main(void)
{
	Point A(1, 3);
	Point B(5, 10);
	Point C = A + B;
	Point D = A + 3;
	A.Display();
	B.Display();
	C.Display();
	D.Display();
	return 0;
}