#include <DxLib.h>
#include "BackGround.h"
#include "../Screen/Screen.h"

//背景関連のマクロ定義
#define BG_PATH "Data/BackGround/BackGround.png"	//壁の画像パス


//背景情報構造体
struct BgInfo
{
	int handle;
	int x, y;
};

//背景情報
BgInfo bgInfo = { 0 };


void InitBg()
{
	bgInfo.handle = 0;
	bgInfo.x = bgInfo.y = 0;

	bgInfo.handle = LoadGraph(BG_PATH);
}

void StepBg()
{	

}

void DrawBg()
{
	//背景のスクリーン座標を求める
	int bg_X = bgInfo.x - (int)GetScreenX();
	int bg_Y = bgInfo.y - (int)GetScreenY();

	DrawGraph(bg_X, bg_Y, bgInfo.handle, true);
}

void FinBg()
{
	DeleteGraph(bgInfo.handle);
	bgInfo.handle = 0;
}

