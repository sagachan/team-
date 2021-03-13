#include <DxLib.h>
#include "BackGround.h"
#include "../Screen/Screen.h"

//�w�i�֘A�̃}�N����`
#define BG_PATH "Data/BackGround/BackGround.png"	//�ǂ̉摜�p�X


//�w�i���\����
struct BgInfo
{
	int handle;
	int x, y;
};

//�w�i���
BgInfo bgInfo = { 0 };


void InitBg()
{
	bgInfo.handle = 0;
	bgInfo.x = bgInfo.y = 0;

	bgInfo.handle = LoadGraph(BG_PATH);
}

void StepBg()
{	

}

void DrawBg()
{
	//�w�i�̃X�N���[�����W�����߂�
	int bg_X = bgInfo.x - (int)GetScreenX();
	int bg_Y = bgInfo.y - (int)GetScreenY();

	DrawGraph(bg_X, bg_Y, bgInfo.handle, true);
}

void FinBg()
{
	DeleteGraph(bgInfo.handle);
	bgInfo.handle = 0;
}

