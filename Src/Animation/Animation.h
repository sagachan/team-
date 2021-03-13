#ifndef __ANIMATION_H__
#define __ANIMATION_H__

//プレイヤーのアニメの中で最大の画像数（例）歩き…３枚、伐採…５枚の場合は、最大の画像数は「５」
#define PLAYER_ANIME_IMG_MAX_NUM	(3)


//オブジェクトの種類
enum OBJECT_TYPE
{
	OBJECT_TYPE_PLAYER = 0,	//プレイヤー
	OBJECT_TYPE_ITEM,		//アイテム
};

//プレイヤーのアニメ種類
enum PlayerAnimeKind
{
	PLAYER_ANIME_KIND_IDLE = 0,	//待機
	PLAYER_ANIME_KIND_WALK,		//歩く
	PLAYER_ANIME_KIND_RUN,		//走る
	PLAYER_ANIME_KIND_CUT,		//伐採

	PLAYER_ANIME_KIND_NUM,		//アニメ種類数
};

//アニメーション情報構造体
struct PlayerAnimeInfo
{
	int handle[PLAYER_ANIME_KIND_NUM][PLAYER_ANIME_IMG_MAX_NUM];	//画像ハンドル
	int animeUseNum[PLAYER_ANIME_KIND_NUM];							//アニメーションの使用画像数
	float currentAnimeTime;											//現在のアニメーション時間
	float changeAnimeTime[PLAYER_ANIME_KIND_NUM];					//アニメーションの切り替え時間
	int currentAnimeIndex;											//現在のアニメーション番号

	bool is_loop[PLAYER_ANIME_KIND_NUM];							//ループするアニメーションかどうか
	bool is_end[PLAYER_ANIME_KIND_NUM];								//終了しているアニメーションかどうか

	PlayerAnimeKind currentAnimeKind;								//現在のアニメーションの種類
};


//アニメーションの初期化
void InitAnimation();

//アニメーションの読み込み
void LoadAnimation();

//アニメーションの通常処理
void StepAnimation();

//アニメーションの後処理
void FinAnimation();


#endif