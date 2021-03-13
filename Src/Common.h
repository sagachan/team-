#ifndef __COMMON_H__
#define __COMMON_H__

//ウィンドウの幅・高さ
#define WINDOW_HEIGHT  (720)
#define WINDOW_WIDTH (1280)

//マップの幅・高さ
#define MAP_WIDTH	(6400)
#define MAP_HEIGHT	(6400)

//設定フレームレート
#define FRAME_RATE	(60)

//1フレームの時間 (ミリ秒)
#define FRAME_TIME (1000 / FRAME_RATE)

//フレームレート情報
struct FrameRateInfo
{
	int currentTime;	//現在の時間
	int lastFrameTime;	//前回のフレーム実行時の時間
	int count;			//フレームカウント用
	int calcFpsTime;	//FPSを計算した時間
	float fps;			//計測したFPS（表示用）
};

#endif

