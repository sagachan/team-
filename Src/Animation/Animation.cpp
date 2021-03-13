#include <DxLib.h>
#include "Animation.h"
#include "../Player/Player.h"
#include "../Common.h"


//アニメーションの個数（プレイヤー、敵などの全てのオブジェクトのアニメーション数）
int g_animation_num;



//プレイヤーのアニメ関連
//各アニメの画像ハンドル
const char player_anime_file_path[PLAYER_ANIME_KIND_NUM][256] =
{
	"Data/Player/Player_Idle.png",	//待機
	"Data/Player/Player_Walk.png",	//歩く
	"Data/Player/Player_Run.png",	//走る
	"Data/Player/Player_Cut.png",	//伐採
};
//各アニメの画像数
const int player_anime_img_num[PLAYER_ANIME_KIND_NUM] =
{
	3,		//待機
	3,		//歩く
	3,		//走る
	3,		//伐採
};
//各アニメの切り替え時間
const float player_anime_changeTime[PLAYER_ANIME_KIND_NUM] =
{
	0.2f,	//待機
	0.2f,	//歩く
	0.2f,	//走る
	0.2f,	//伐採
};
//各アニメのループフラグ
const bool player_anime_loop_flg[PLAYER_ANIME_KIND_NUM] =
{
	true,	//待機
	true,	//歩く
	true,	//走る
	false,	//伐採
};

//---アイテムや、それ以外のオブジェクトのアニメ関連はこの下に書く---//


//アニメーションの初期化
void InitAnimation()
{
	//プレイヤーのアニメーション情報初期化
	PlayerInfo* playerInfo = GetPlayerInfo();

	playerInfo->animeInfo.currentAnimeIndex = 0;	//現在のアニメーション番号
	playerInfo->animeInfo.currentAnimeTime = 0.0f;	//現在のアニメーション時間
	playerInfo->animeInfo.currentAnimeKind = PLAYER_ANIME_KIND_IDLE;	//芸材のアニメーションの種類
	for (int i = 0; i < PLAYER_ANIME_KIND_NUM; i++)
	{
		playerInfo->animeInfo.animeUseNum[i] = player_anime_img_num[i];			//アニメーションの使用画像数
		playerInfo->animeInfo.changeAnimeTime[i] = player_anime_changeTime[i];	//アニメーションの切り替え時間
		playerInfo->animeInfo.is_loop[i] = player_anime_loop_flg[i];			//ループするアニメかどうか
		playerInfo->animeInfo.is_end[i] = false;								//終了しているアニメかどうか
	}

	//---アイテムや、それ以外のオブジェクトなどのアニメーション情報の初期化はこの下に書く---//

}


//アニメーションの読み込み
void LoadAnimation()
{
	//プレイヤーのアニメーション読み込み
	PlayerInfo* playerInfo = GetPlayerInfo();
	for (int i = 0; i < PLAYER_ANIME_KIND_NUM; i++)
	{
		//画像の分割読み込み
		LoadDivGraph(player_anime_file_path[i], player_anime_img_num[i], player_anime_img_num[i], 1, 64, 64, playerInfo->animeInfo.handle[i]);
	}

}


//アニメーションの通常処理
void StepAnimation()
{
	//---プレイヤーのアニメーション更新処理---//
	PlayerInfo* playerInfo = GetPlayerInfo();
	for (int anime_index = 0; anime_index < PLAYER_ANIME_KIND_NUM; anime_index++)
	{
		//現在のプレイヤーのアニメーションではなかったら
		if (playerInfo->animeInfo.currentAnimeKind != anime_index)
			continue;

		//終了しているアニメーションは更新しない
		if (playerInfo->animeInfo.is_end[anime_index] == true)
			continue;

		//もし、アニメーション切り替え時間が経過したら
		if (playerInfo->animeInfo.changeAnimeTime[anime_index] >= playerInfo->animeInfo.changeAnimeTime[anime_index])
		{
			//現在のアニメ番号を進める
			playerInfo->animeInfo.currentAnimeIndex++;

			//もし、現在のアニメ番号が最後なら
			if (playerInfo->animeInfo.currentAnimeIndex >= playerInfo->animeInfo.animeUseNum[anime_index])
			{
				//ループするアニメなら
				if (playerInfo->animeInfo.is_loop[anime_index] == true)
				{
					playerInfo->animeInfo.currentAnimeIndex = 0;	//現在のアニメ番号を最初に戻す
				}
				//ループするアニメじゃないなら
				else
				{
					playerInfo->animeInfo.currentAnimeIndex--;	//最後のアニメ画像にして
					playerInfo->animeInfo.is_end[anime_index] = true;		//アニメの終了フラグを立てる
				}
			}
			//現在のアニメ時間をリセット
			playerInfo->animeInfo.currentAnimeTime = 0.0f;
		}
		else
		{
			//現在のアニメ時間を進める
			playerInfo->animeInfo.currentAnimeTime += 1.0f / FRAME_RATE;
		}
	}


	//---アイテムや、それ以外のオブジェクトのアニメーション更新処理はこの下に書く---//

}

//アニメーションの後処理
void FinAnimation()
{
	//プレイヤーのアニメーション画像の破棄
	PlayerInfo* playerInfo = GetPlayerInfo();
	for (int anime_index = 0; anime_index < PLAYER_ANIME_KIND_NUM; anime_index++)
	{
		for (int image_index = 0; image_index < PLAYER_ANIME_IMG_MAX_NUM; image_index++)
		{
			DeleteGraph(playerInfo->animeInfo.handle[anime_index][image_index]);
		}
	}

	//---アイテムや、それ以外のオブジェクトのアニメーション画像の破棄はこの下に書く---//

}