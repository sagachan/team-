#ifndef __MYMATH_H__
#define __MYMATH_H__


//ベクトルの初期化マクロ定義
#define ZERO_VECTOR VGet(0.0f, 0.0f, 0.0f)


//２点間の距離を求める（２Ｄ）
float GetDistance(float x1, float y1, float x2, float y2);

//pos1からpos2までの距離を計算する
float GetDistance(VECTOR pos1, VECTOR pos2);

//変位ベクトルの作成
VECTOR VecCreate(VECTOR start, VECTOR end);

//ベクトルの長さを求める
float VecLong(VECTOR vec);

//ベクトルの加算
VECTOR VecAdd(VECTOR vec1, VECTOR vec2);

//ベクトルの減算
VECTOR VecSub(VECTOR vec1, VECTOR vec2);

//ベクトルの正規化
VECTOR VecNormalize(VECTOR vec);

//ベクトルのスカラー倍
VECTOR VecScale(VECTOR vec, float scale);

//ベクトルの内積
float VecDot(VECTOR vec1, VECTOR vec2);

//ベクトルの外積（２Ｄ）
float VecCross2D(VECTOR vec1, VECTOR vec2);
//ベクトルの外積（３Ｄ）
VECTOR VecCross(VECTOR vec1, VECTOR vec2);


//回転値を０～２πの値にする
float RadianNormalize(float rad);

#endif
