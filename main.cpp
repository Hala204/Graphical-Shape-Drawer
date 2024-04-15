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





void DrawRocket(window& w, color c, int rx, int ry, int size)
{
	int windowWidth = w.GetWidth();
	int windowHeight = w.GetHeight();
	ry = 1 * size + rand() % (windowHeight - 50 - 5 * size + 1);

	int NoseConeWidth = size;
	int NoseConeHeight = NoseConeWidth;
	int RectHeight = 4 * size;

	int XaxisLeftPoint = rx - (NoseConeWidth / 2);
	int XaxisRightPoint = rx + (NoseConeWidth / 2);
	int YaxisLeft_RightPoint = ry + NoseConeHeight;
	int RectYaxisBottomRightPoint = YaxisLeft_RightPoint + RectHeight;

	XaxisLeftPoint = max(0, min(XaxisLeftPoint, windowWidth));
	XaxisRightPoint = max(0, min(XaxisRightPoint, windowWidth));
	YaxisLeft_RightPoint = max(0, min(YaxisLeft_RightPoint, windowHeight));
	RectYaxisBottomRightPoint = max(0, min(RectYaxisBottomRightPoint, windowHeight));

	w.SetPen(BLACK, 5);
	w.SetBrush(RED);
	w.DrawTriangle(XaxisLeftPoint, YaxisLeft_RightPoint, rx, ry, XaxisRightPoint, YaxisLeft_RightPoint);

	w.SetPen(BLACK, 5);
	w.SetBrush(GREY);
	w.DrawRectangle(XaxisLeftPoint, YaxisLeft_RightPoint, XaxisRightPoint, RectYaxisBottomRightPoint, FILLED);

	w.SetPen(BLACK, 5);
	w.SetBrush(RED);
	int NewTriangleBaseAboveXaxis1 = XaxisRightPoint;  //The Point above
	int NewTriangleBaseAboveYaxis1 = RectYaxisBottomRightPoint - size - 25;  //The Point above
	int NewTriangleBaseBelowXaxis1 = XaxisRightPoint;  //The point below
	int NewTriangleBaseBelowYaxis1 = RectYaxisBottomRightPoint - 25; //The point below
	int NewTriangleNoseConeXaxis1 = XaxisRightPoint + (2 * size);
	int NewTriangleNoseConeYaxis1 = RectYaxisBottomRightPoint - 25;
	w.DrawTriangle(NewTriangleBaseAboveXaxis1, NewTriangleBaseAboveYaxis1, NewTriangleNoseConeXaxis1, NewTriangleNoseConeYaxis1, NewTriangleBaseBelowXaxis1, NewTriangleBaseBelowYaxis1, FILLED);

	w.SetPen(BLACK, 5);
	w.SetBrush(RED);
	int NewTriangleBaseAboveXaxis2 = XaxisLeftPoint;  //The Point above
	int NewTriangleBaseAboveYaxis2 = RectYaxisBottomRightPoint - size - 25;  //The Point above
	int NewTriangleBaseBelowXaxis2 = XaxisLeftPoint;  //The point below
	int NewTriangleBaseBelowYaxis2 = RectYaxisBottomRightPoint - 25; //The point below
	int NewTriangleNoseConeXaxis2 = XaxisLeftPoint - (2 * size);
	int NewTriangleNoseConeYaxis2 = RectYaxisBottomRightPoint - 25;
	w.DrawTriangle(NewTriangleBaseAboveXaxis2, NewTriangleBaseAboveYaxis2, NewTriangleNoseConeXaxis2, NewTriangleNoseConeYaxis2, NewTriangleBaseBelowXaxis2, NewTriangleBaseBelowYaxis2, FILLED);
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
	w.DrawString(15 + 380, w.GetHeight() - 40, "press (r) to draw rocket ||");
	w.DrawString(15 + 1100, w.GetHeight() - 40, "press (q) to clear Screen ||");


	int rx, ry, size, length;

	POINT upLeft;

	char key;
	do {
		w.WaitKeyPress(key);

		size = rand() % hight / 10;
		rx = 2 * size + rand() % (width - 2 * size - 2 * size + 1);
		ry = 2 * size + rand() % (hight - 50 - 5 * size + 1);

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
			w.DrawString(15 + 380, w.GetHeight() - 40, "press (r) to draw rocket ||");
			w.DrawString(15 + 1100, w.GetHeight() - 40, "press (q) to clear Screen ||");

		}
		else if (key == 'i' || key == 'I')
		{
			w.FlushKeyQueue();
			w.FlushMouseQueue();
			DrawIceCream(w, BROWN, rx, ry, size);
		}
		else if (key == 'r' || key == 'R')
		{
			w.FlushKeyQueue();
			w.FlushMouseQueue();
			DrawRocket(w, RED, rx, ry, size);
		}
		
	} while (key != 'e');

	return 0;




}