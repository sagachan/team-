#include <DxLib.h>
#include "Player.h"
#include "../Screen/Screen.h"
#include "../MyMath/MyMath.h"
#include "../Input/Input.h"
#include "../Common.h"
#include "../Map/Map.h"

//プレイヤー関連のマクロ定義
#define PLAYER_WIDTH		(64.0f)	//プレイヤーの横幅
#define PLAYER_HEIGHT		(64.0f)	//プレイヤーの縦幅
#define PLAYER_RADIUS		(32.0f)	//プレイヤーの半径

#define PLAYER_START_POS_X	(3182.0f)	//プレイヤーの初期位置（Ｘ座標）
#define PLAYER_START_POS_Y	(3084.0f)	//プレイヤーの初期位置（Ｙ座標）

#define PLAYER_WALK_SPD		(3.0f)		//歩いた時の移動速度
#define PLAYER_RUN_SPD		(56.0f)		//走った時の移動速度


//プレイヤー情報
PlayerInfo playerInfo = { 0 };


//プレイヤーの初期化
void InitPlayer()
{
	playerInfo.handle = 0;						//画像ハンドル
	playerInfo.pos = { 0 };						//座標
	playerInfo.old_pos = { 0 };					//移動前の座標
	playerInfo.move = { 0 };					//移動量
	playerInfo.isAlive = true;					//生存フラグ
	playerInfo.state = PLAYER_STATE_IDLE;		//ステータス（始めは、待機状態）
	playerInfo.direction = PLAYER_DIR_UP;		//プレイヤーの向いている方向（始めは、上を向いている）

	//プレイヤーの画像読みこみ
	playerInfo.handle = LoadGraph("Data/Player/Player.png");

	//プレイヤーの初期位置設定
	playerInfo.pos.x = PLAYER_START_POS_X;
	playerInfo.pos.y = PLAYER_START_POS_Y;
}

//プレイヤーの通常処理
void StepPlayer()
{
	//移動前の座標の記録
	playerInfo.old_pos = playerInfo.pos;

	//移動量のリセット
	playerInfo.move = { 0 };

	if (playerInfo.isAlive)
	{
		//プレイヤーの状態をリセット（何も押されてないなら、待機状態）
		playerInfo.state = PLAYER_STATE_IDLE;

		//プレイヤーの入力処理
		StepPlayerInput();
	}

	//移動量の加算
	playerInfo.pos = VecAdd(playerInfo.pos, playerInfo.move);


	//--プレイヤーがマップ外にはみ出さないようにする処理--//
	if (playerInfo.pos.x - PLAYER_RADIUS < 0)
		playerInfo.pos.x = 0 + PLAYER_RADIUS;
	else if (playerInfo.pos.x + PLAYER_RADIUS > MAP_WIDTH)
		playerInfo.pos.x = MAP_WIDTH - PLAYER_RADIUS;

	if (playerInfo.pos.y - PLAYER_RADIUS < 0)
		playerInfo.pos.y = 0 + PLAYER_RADIUS;
	else if (playerInfo.pos.y + PLAYER_RADIUS > MAP_HEIGHT)
		playerInfo.pos.y = MAP_HEIGHT - PLAYER_RADIUS;
}

//プレイヤーの描画処理
void DrawPlayer()
{
	//プレイヤーが生きているなら描画する
	if (playerInfo.isAlive)
	{
		int current_index = playerInfo.animeInfo.currentAnimeIndex;
		PlayerAnimeKind anime_kind = playerInfo.animeInfo.currentAnimeKind;

		//プレイヤーのスクリーン座標を求める
		int playerX = (int)(playerInfo.pos.x - GetScreenX());
		int playerY = (int)(playerInfo.pos.y - GetScreenY());

		DrawRotaGraph(playerX, playerY, 1.0, 0.0, playerInfo.animeInfo.handle[anime_kind][current_index], true);
	}
}

//プレイヤーの後処理
void FinPlayer()
{
	DeleteGraph(playerInfo.handle);
	playerInfo.handle = 0;
}


//プレイヤーの入力処理
void StepPlayerInput()
{
	//プレイヤーの移動速度
	float move_spd = PLAYER_WALK_SPD;	//歩く時の移動速度を設定

	//SHIFTキーが押されたら
	if (IsKeyDown(KEY_INPUT_RSHIFT) || IsKeyDown(KEY_INPUT_LSHIFT))
	{
		move_spd = PLAYER_RUN_SPD;	//走る時の移動速度を設定
	}

	//上下左右のキーボードが押されたら
	if (IsKeyDown(KEY_INPUT_UP) || IsKeyDown(KEY_INPUT_DOWN)
		|| IsKeyDown(KEY_INPUT_LEFT) || IsKeyDown(KEY_INPUT_RIGHT))
	{
		if (IsKeyDown(KEY_INPUT_UP))
		{
			playerInfo.move.y = -move_spd;			//上方向の移動量を設定
			playerInfo.direction = PLAYER_DIR_UP;	//プレイヤーを上に向かせる
		}
		if (IsKeyDown(KEY_INPUT_DOWN))
		{
			playerInfo.move.y = move_spd;			//下方向の移動量を設定
			playerInfo.direction = PLAYER_DIR_DOWN;	//プレイヤーを下に向かせる
		}
		if (IsKeyDown(KEY_INPUT_LEFT))
		{
			playerInfo.move.x = -move_spd;			//左方向の移動量を設定
			playerInfo.direction = PLAYER_DIR_LEFT;	//プレイヤーを左に向かせる
		}
		if (IsKeyDown(KEY_INPUT_RIGHT))
		{
			playerInfo.move.x = move_spd;			//右方向の移動量を設定
			playerInfo.direction = PLAYER_DIR_RIGHT;//プレイヤーを右に向かせる
		}

		playerInfo.state = PLAYER_STATE_WALK;	//歩き状態へ
	}

	//「１」キーを押した　かつ　プレイヤーが伐採可能なら
	if (IsKeyPush(KEY_INPUT_1) && CanCutPlayer())
	{
		playerInfo.state = PLAYER_STATE_CUT;	//伐採状態へ
	}
}


//プレイヤーが伐採状態かどうか
bool IsCutPlayer()
{
	switch (playerInfo.state)
	{
	case PLAYER_STATE_CUT:
		return true;
	}

	return false;
}

//プレイヤーが伐採可能かどうか
bool CanCutPlayer()
{
	//プレイヤーの状態が伐採状態以外なら伐採可能
	switch (playerInfo.state)
	{
	case PLAYER_STATE_CUT:
		return false;
	}

	return true;
}



//プレイヤーの情報取得
PlayerInfo* GetPlayerInfo()
{
	return &playerInfo;
}