#include <DxLib.h>
#include "Screen.h"
#include "../Player/Player.h"
#include "../Common.h"

//スクリーン座標宣言
float screenX = 0;
float screenY = 0;


//スクリーンの通常処理
void StepScreen()
{
	//プレイヤー情報を取得
	PlayerInfo* playerInfo = GetPlayerInfo();

	//プレイヤーを中心に
	//スクリーン座標を求める
	screenX = playerInfo->pos.x - WINDOW_WIDTH / 2;
	screenY = playerInfo->pos.y - WINDOW_HEIGHT / 2;


	//---スクリーンのワールド座標がマップ外に出ないようにする処理---//
	//横幅がマップ外にはみ出た時
	if (screenX < 0)
		screenX = 0;
	else if (screenX + WINDOW_WIDTH > MAP_WIDTH)
		screenX = MAP_WIDTH - WINDOW_WIDTH;
	//縦幅がマップ外にはみ出た時
	if (screenY < 0)
		screenY = 0;
	else if (screenY + WINDOW_HEIGHT > MAP_HEIGHT)
		screenY = MAP_HEIGHT - WINDOW_HEIGHT;
}

//スクリーンのワールドＸ座標取得
float GetScreenX()
{
	return screenX;
}

//スクリーンのワールドＹ座標取得
float GetScreenY()
{
	return screenY;
}
