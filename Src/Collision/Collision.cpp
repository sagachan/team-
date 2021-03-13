
#include "DxLib.h"
#include "Collision.h"

//矩形の当たり判定
bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh)
{
	//A…Rect1 or Rect2 or Rect3	B…MyRect		

	//当たり判定をココに書く		
	if (Bx < Ax + Aw &&
		Bx + Bw > Ax &&
		By + Bh > Ay &&
		By < Ay + Ah)
	{
		return true;
	}

	else
	{
		return false;
	}
}

//円の当たり判定
bool IsHitCircle(int x1, int y1, int r1, int x2, int y2, int r2)
{
	if ((r1 + r2)*(r1 + r2) > (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))
		return true;

	return false;
}