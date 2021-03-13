
#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

//タイトル背景画像のパス
#define BG_TITLE_PATH		"Data/TETRIS_Title.png"

//タイトル画像のハンドル
int bgTitleHandle;


//タイトル初期化
void InitTitle()
{
	//タイトル背景初期化
	bgTitleHandle = LoadGraph(BG_TITLE_PATH);

	//タイトルループへ
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//タイトル通常処理
void StepTitle()
{
	//Enterキーが押されたなら
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		//タイトル後処理へ移動
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

//タイトル描画処理
void DrawTitle()
{
	//タイトル画像表示
	DrawGraph(0, 0, bgTitleHandle, true);
}

//タイトル後処理
void FinTitle()
{
	//タイトル画像破棄
	DeleteGraph(bgTitleHandle);

	//タイトルの後はプレイへ
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}