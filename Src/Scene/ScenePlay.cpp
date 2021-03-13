
#include "DxLib.h"
#include "Scene.h"
#include "ScenePlay.h"
#include "SceneTitle.h"
#include "../Collision/Collision.h"
#include "../Common.h"
#include "../Input/Input.h"
#include "../Screen/Screen.h"
#include "../BackGround/BackGround.h"
#include "../Player/Player.h"
#include "../Map/Map.h"




//プレイシーン初期化
void InitPlay()
{

	//背景初期化
	InitBg();

	//マップ初期化
	InitMap;

	//プレイヤー初期化
	InitPlayer();


	//アニメーションの初期化
	InitAnimation();
	//アニメーションの読み込み
	LoadAnimation();


	//プレイループへ
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}


//プレイシーン通常処理
void StepPlay()
{

	//背景通常処理
	StepBg();

	//マップ通常処理
	StepMap();

	//プレイヤーの通常処理
	StepPlayer();

	//スクリーンの通常処理
	StepScreen();
	
	//アニメーションの通常処理
	StepAnimation();

}

//プレイシーン描画処理
void DrawPlay()
{
	//背景描画処理
	DrawBg();

	//マップ描画処理
	DrawMap();

	//プレイヤー描画処理
	DrawPlayer();

	PlayerInfo* playerInfo = GetPlayerInfo();
	//プレイヤーの座標確認用
	DrawFormatString(10, 10, GetColor(255, 255, 255),
		"プレイヤーのワールド座標 : ( x , y ) = ( %d , %d )", (int)playerInfo->pos.x, (int)playerInfo->pos.y);
}


//プレイ後処理
void FinPlay()
{
	//背景の後処理
	FinBg();

	//マップの後処理
	FinMap();

	//プレイヤーの後処理
	FinPlayer();


	//アニメーションの後処理
	FinAnimation();
}

