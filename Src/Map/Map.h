#ifndef __MAP_H__
#define __MAP_H__

#define MAP_CHIP_1 "Data/can_chip1.png"


//#define MAP_PATH_SMALL ()

#define MAP_PATH_MEDIUM (64)
#define MAP_CHIP_NUM	(100)

#define MAP_PATH_LARGE ()
//#define MAP_HEIGHT ()
//#define MAP_WIDTH ()

enum MAP_KIND
{
	EMPTY,
	WOOD,
	ROCK,
	ITEM_MAX	//マップチップの種類
};


struct MAP_CHIP
{
	int handle;		//画像ハンドル
	int x, y;		//座標	
	bool isUse;		//使用フラグ
	MAP_KIND kind;	//これで判定した数値のマップチップをhandleに入れる
};

struct MAP_CHIP_SAVE
{
	int handle;		//画像ハンドル
	int x, y;		//座標	
	bool isUse;		//使用フラグ
	MAP_KIND kind;	//これで判定した数値のマップチップをhandleに入れる
};

int Getkind();

void InitMap();

void StepMap();

void DrawMap();

void FinMap();



#endif