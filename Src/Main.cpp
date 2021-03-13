
#include <DxLib.h>
#include "Collision/Collision.h"
#include "Scene/Scene.h"
#include "Scene/ScenePlay.h"
#include "Scene/SceneTitle.h"
#include "Input/Input.h"
#include "Common.h"
#include "BackGround/BackGround.h"

//現在のシーンID
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;

FrameRateInfo frameRateInfo;

void CalcFPS();

void DrawFPS();

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);

	//DXライブラリの初期化
	if(DxLib_Init() == -1)
	{
		return -1;
	}

	//ウィンドウサイズを変更
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	//描画するスクリーンを設定
	SetDrawScreen(DX_SCREEN_BACK);

	//入力制御初期化
	InitInput();
	

	//=============================================================================
	//ゲームメインループ
	while(ProcessMessage() != -1)
	{
		Sleep(1);

		//現在の時間を取得
		frameRateInfo.currentTime = GetNowCount();

		//最初のループなら
		//現在の時間を、FPSの計算をした時間に設定
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}

		//現在の時間が、前回のフレーム時より
		//1000/60ミリ秒以上経過していたら処理を実行する
		if (frameRateInfo.currentTime - frameRateInfo.lastFrameTime >= FRAME_TIME)
		{
			//フレーム実行時の時間を更新
			frameRateInfo.lastFrameTime = frameRateInfo.currentTime;

			//フレーム数をカウント
			frameRateInfo.count++;

			if (IsKeyPush(KEY_INPUT_ESCAPE) == 1)
			{
				//エスケープキーが押されたら終了
				break;
			}

			//画面に表示されたものを初期化（１ループの１度だけ行う）
			ClearDrawScreen();

			//入力制御ステップ
			StepInput();


			//シーンIDによって処理の振り分け
			switch (g_CurrentSceneID)
			{
			//****タイトルシーン****//
			case SCENE_ID_INIT_TITLE:
			{
				//タイトル初期化
				InitTitle();
			}
			break;

			case SCENE_ID_LOOP_TITLE:
			{
				//タイトル通常処理
				StepTitle();

				//タイトル描画処理
				DrawTitle();
			}
			break;

			case SCENE_ID_FIN_TITLE:
			{
				//タイトル後処理
				FinTitle();
			}
			break;

			//****プレイシーン****//
			case SCENE_ID_INIT_PLAY:
			{
				//プレイ初期化
				InitPlay();
			}

			case SCENE_ID_LOOP_PLAY:
			{
				//プレイ通常処理
				StepPlay();

				//プレイ描画処理
				DrawPlay();

			}//SCNE_ID_PLAY終わりの括弧
			break;

			case SCENE_ID_FIN_PLAY:
			{
				//プレイ後処理
				FinPlay();
			}
			break;

			//****クリアシーン****//
			case SCENE_ID_INIT_CLEAR:
			{
				//クリア初期化
				/*InitClear();*/
			}
			break;

			case SCENE_ID_LOOP_CLEAR:
			{
				//クリア通常処理
				/*StepClear();*/

				//クリア描画処理
				/*DrawClear();*/
			}//SCENE_ID_CLEAR終わりの括弧
			break;

			case SCENE_ID_FIN_CLEAR:
			{
				//クリア後処理
				/*FinClear();*/
			}
			break;

			//****ゲームオーバーシーン****//
			case SCENE_ID_INIT_GAMEOVER:
			{
				//ゲームオーバー初期化
				/*InitGameOver();*/
			}
			break;

			case SCENE_ID_LOOP_GAMEOVER:
			{
				//ゲームオーバー通常処理
			/*	StepGameOver();*/

				//ゲームオーバー描画処理
				/*DrawGameOver();*/
			}//SCENE_ID_GAMEOVER終わりの括弧
			break;

			case SCENE_ID_FIN_GAMEOVER:
			{
				//ゲームオーバー後処理
				/*FinGameOver();*/
			}
			break;

			}

			//FPS計算
			CalcFPS();

			//FPS表示
			DrawFPS();

			//フリップ関数（ループの終わりに１度だけ行う）
			ScreenFlip();

		}//フレームレートのif文終わり

	}//メインループ終わり

	//最後に１回だけやる処理をここに書く
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}


//FPS計算
void CalcFPS()
{
	//前回のFPSを計算した時間からの経過時間を求める
	int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;

	//前回のFPSを計算した時間から
	//１秒以上経過していたらFPSを計算する
	if (difTime > 1000)
	{
		//フレーム回数をミリ秒に合わせる
		//小数まで出したいのでfloatにキャスト
		float frameCount = (float)(frameRateInfo.count * 1000.0f);

		//FPSを求める
		//理想の数値は 60000 / 1000 で 60 となる
		frameRateInfo.fps = frameCount / difTime;

		//フレームレートカウントをクリア
		frameRateInfo.count = 0;

		//FPSを計算した時間を更新
		frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
	}
}

//FPS表示（デバッグ用）
void DrawFPS()
{
	unsigned int color = GetColor(255, 30, 30);
	DrawFormatString(1150, 690, color, "FPS[%.2f]", frameRateInfo.fps);
}