
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




//�v���C�V�[��������
void InitPlay()
{

	//�w�i������
	InitBg();

	//�}�b�v������
	InitMap;

	//�v���C���[������
	InitPlayer();


	//�A�j���[�V�����̏�����
	InitAnimation();
	//�A�j���[�V�����̓ǂݍ���
	LoadAnimation();


	//�v���C���[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
}


//�v���C�V�[���ʏ폈��
void StepPlay()
{

	//�w�i�ʏ폈��
	StepBg();

	//�}�b�v�ʏ폈��
	StepMap();

	//�v���C���[�̒ʏ폈��
	StepPlayer();

	//�X�N���[���̒ʏ폈��
	StepScreen();
	
	//�A�j���[�V�����̒ʏ폈��
	StepAnimation();

}

//�v���C�V�[���`�揈��
void DrawPlay()
{
	//�w�i�`�揈��
	DrawBg();

	//�}�b�v�`�揈��
	DrawMap();

	//�v���C���[�`�揈��
	DrawPlayer();

	PlayerInfo* playerInfo = GetPlayerInfo();
	//�v���C���[�̍��W�m�F�p
	DrawFormatString(10, 10, GetColor(255, 255, 255),
		"�v���C���[�̃��[���h���W : ( x , y ) = ( %d , %d )", (int)playerInfo->pos.x, (int)playerInfo->pos.y);
}


//�v���C�㏈��
void FinPlay()
{
	//�w�i�̌㏈��
	FinBg();

	//�}�b�v�̌㏈��
	FinMap();

	//�v���C���[�̌㏈��
	FinPlayer();


	//�A�j���[�V�����̌㏈��
	FinAnimation();
}

