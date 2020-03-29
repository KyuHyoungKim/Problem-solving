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

	A.Display();
	B.Display();
	C.Display();
	return 0;
}