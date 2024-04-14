#include <iostream>
#include <sstream>
#include <cmath>
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CMUgraphicsLib\auxil.h"	




void DrawIceCream(window& w, color c, int rx, int ry, int size)
{

	int ConeWidth = size;
	int ConeHeight = 2 * size;
	int radius = size / 2;

	int icecreamheight = ConeHeight + radius;
	int icecreamwidth = ConeWidth;
	int minX = icecreamwidth;
	int maxX = w.GetWidth() - icecreamwidth;
	int minY = icecreamheight;
	int maxY = w.GetHeight() - icecreamheight;

	rx = max(min(rx, maxX), minX);
	ry = max(min(ry, maxY), minY);

	w.SetPen(ROSYBROWN, 5);
	w.SetBrush(BEIGE);
	w.DrawCircle(rx, ry - ConeHeight, radius, FILLED);

	w.SetPen(ROSYBROWN, 5);
	w.SetBrush(BROWN);
	int XaxisLeftPoint = rx - (ConeWidth / 2);
	int XaxisRightPoint = rx + (ConeWidth / 2);
	int YaxisLeft_RightPoint = ry - ConeHeight;
	w.DrawTriangle(XaxisLeftPoint, YaxisLeft_RightPoint, rx, ry, XaxisRightPoint, YaxisLeft_RightPoint);



}



int main() {
	int hight, width, sh, sw;
	hight = 700;
	width = 1400;
	sh = 20;
	sw = 20;

	window w(width, hight, sw, sh);

	w.ChangeTitle("CPP Mini Project");

	w.SetPen(GRAY, 2);
	w.DrawLine(0, hight - 50, width, hight - 50);

	w.SetFont(15, PLAIN, BY_NAME, "Arial");
	w.DrawString(w.GetWidth() / 2 - 100, w.GetHeight() - 70, "Click mouse to continue...");

	w.SetPen(BLACK, 70);
	w.SetFont(15, BOLD, BY_NAME, "Arial");
	w.DrawString(15 + 170, w.GetHeight() - 40, "press (i) to draw ice cream ||");
	w.DrawString(15 + 1100, w.GetHeight() - 40, "press (q) to clear Screen ||");


	int rx, ry, size,length;

	POINT upLeft;

	char key;
	do {
		w.WaitKeyPress(key);

		size = rand() % hight / 10;
		rx = 2 * size + rand() % (width - 2 * size - 2 * size + 1);
		ry = 2 * size + rand() % (hight - 50 - 5 * size  + 1);

		if (key == 'q' || key == 'Q')
		{
			w.FlushKeyQueue();
			w.FlushMouseQueue();
			w.SetPen(WHITE, 5);
			w.SetBrush(WHITE);
			w.DrawRectangle(0, 0, width, hight, FILLED);

			w.SetPen(GRAY, 2);
			w.DrawLine(0, hight - 50, width, hight - 50);

			w.SetPen(BLACK, 70);
			w.SetFont(15, BOLD, BY_NAME, "Arial");
			w.DrawString(15 + 170, w.GetHeight() - 40, "press (i) to draw ice cream ||");
			w.DrawString(15 + 1100, w.GetHeight() - 40, "press (q) to clear Screen ||");

		}
		else if (key == 'i' || key == 'I')
		{
			w.FlushKeyQueue();
			w.FlushMouseQueue();
			DrawIceCream(w, BROWN, rx, ry, size);
		}
	} while (key != 'e');

	return 0;




}