#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../Animation/Animation.h"


//プレイヤーの状態
enum PLAYER_STATE
{
	PLAYER_STATE_IDLE = 0,	//待機
	PLAYER_STATE_WALK,		//歩く
	PLAYER_STATE_RUN,		//走る
	PLAYER_STATE_CUT,		//伐採
};

//プレイヤーの向いている方向
enum PLAYER_DIRECTION
{
	PLAYER_DIR_UP,		//上
	PLAYER_DIR_DOWN,	//下
	PLAYER_DIR_LEFT,	//左
	PLAYER_DIR_RIGHT,	//右
};

//プレイヤー情報構造体
struct PlayerInfo
{
	int handle;							//画像ハンドル
	VECTOR pos;							//座標
	VECTOR old_pos;						//移動前の座標
	VECTOR move;						//移動量
	bool isAlive;						//生存フラグ
	PLAYER_STATE state;					//ステータス
	PLAYER_DIRECTION direction;			//プレイヤーの向いている方向
	PlayerAnimeInfo animeInfo;			//アニメーション情報
};

//プレイヤーの初期化
void InitPlayer();

//プレイヤーの通常処理
void StepPlayer();

//プレイヤーの描画処理
void DrawPlayer();

//プレイヤーの後処理
void FinPlayer();


//プレイヤーの入力処理
void StepPlayerInput();


//プレイヤーが伐採状態かどうか
bool IsCutPlayer();

//プレイヤーが伐採可能かどうか
bool CanCutPlayer();


//プレイヤーの情報取得
PlayerInfo* GetPlayerInfo();

#endif