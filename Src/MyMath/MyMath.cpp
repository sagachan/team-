#include <DxLib.h>
#include "MyMath.h"
#include <math.h>

// 点P(x1, y1)から点Q(x2, y2)までの距離を返す
float GetDistance(float x1, float y1, float x2, float y2)
{
	// 点Pから点Qまでの直線を斜辺とする直角三角形を作り、
	// ピタゴラスの定理から斜辺の長さを計算する。
	// ①まずは底辺の長さを計算する
	float a = x2 - x1;

	// ②高さを計算する
	float b = y2 - y1;

	// ③斜辺の2乗の値を計算する
	float double_c = a * a + b * b;

	// ④2乗の値なので平方根を計算して長さとする
	// 　平方根は<math.h>のsqrtf関数で取得できる
	return sqrtf(double_c);
}

//pos1からpos2までの距離を計算する
float GetDistance(VECTOR pos1, VECTOR pos2)
{
	return VecLong(VecCreate(pos1, pos2));
}


//変位ベクトルの作成
VECTOR VecCreate(VECTOR start, VECTOR end)
{
	VECTOR result;

	//各成分で「（終点）ー（始点）」をする
	result.x = end.x - start.x;
	result.y = end.y - start.y;
	result.z = end.z - start.z;

	return result;
}


//ベクトルの長さを求める
float VecLong(VECTOR vec)
{
	float vec_long = sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);

	return vec_long;
}


// ベクトルの足し算
VECTOR VecAdd(VECTOR vec1, VECTOR vec2)
{
	VECTOR result;

	// ①各成分を足し算する
	result.x = vec1.x + vec2.x;
	result.y = vec1.y + vec2.y;
	result.z = vec1.z + vec2.z;

	return result;
}


//ベクトルの減算（vec1からvec2を引く)
VECTOR VecSub(VECTOR vec1, VECTOR vec2)
{
	VECTOR result;

	//各成分を引き算する
	result.x = vec1.x - vec2.x;
	result.y = vec1.y - vec2.y;
	result.z = vec1.z - vec2.z;

	return result;
}


//ベクトルの正規化
VECTOR VecNormalize(VECTOR vec)
{
	VECTOR result;
	float vec_long = VecLong(vec);	//ベクトルの長さ

	//各成分の長さで割り正規化する
	result.x = vec.x / vec_long;
	result.y = vec.y / vec_long;
	result.z = vec.z / vec_long;

	return result;
}


//ベクトルのスカラー倍
VECTOR VecScale(VECTOR vec, float scale)
{
	VECTOR result;

	//各成分をスカラー倍する
	result.x = vec.x * scale;
	result.y = vec.y * scale;
	result.z = vec.z * scale;

	return result;
}


//ベクトルの内積
float VecDot(VECTOR vec1, VECTOR vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

//ベクトルの外積（２Ｄ）
float VecCross2D(VECTOR vec1, VECTOR vec2)
{
	return vec1.x * vec2.y - vec1.y * vec2.x;
}
//ベクトルの外積（３Ｄ）
VECTOR VecCross(VECTOR vec1, VECTOR vec2)
{
	VECTOR result;

	result.x = vec1.y * vec2.z - vec1.z * vec2.y;
	result.y = vec1.z * vec2.x - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;

	return result;
}


//回転値を０～２πの値にする
float RadianNormalize(float rad)
{
	float result = rad;
	if (result < 0.0f)
	{
		while (result < 0.0f)
		{
			result += DX_TWO_PI_F;
		}
	}
	else if (result >= DX_TWO_PI_F)
	{
		while (result > DX_TWO_PI_F)
		{
			result -= DX_TWO_PI_F;
		}
	}

	return result;
}