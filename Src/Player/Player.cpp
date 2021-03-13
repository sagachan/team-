#include <DxLib.h>
#include "Player.h"
#include "../Screen/Screen.h"
#include "../MyMath/MyMath.h"
#include "../Input/Input.h"
#include "../Common.h"
#include "../Map/Map.h"

//�v���C���[�֘A�̃}�N����`
#define PLAYER_WIDTH		(64.0f)	//�v���C���[�̉���
#define PLAYER_HEIGHT		(64.0f)	//�v���C���[�̏c��
#define PLAYER_RADIUS		(32.0f)	//�v���C���[�̔��a

#define PLAYER_START_POS_X	(3182.0f)	//�v���C���[�̏����ʒu�i�w���W�j
#define PLAYER_START_POS_Y	(3084.0f)	//�v���C���[�̏����ʒu�i�x���W�j

#define PLAYER_WALK_SPD		(3.0f)		//���������̈ړ����x
#define PLAYER_RUN_SPD		(56.0f)		//���������̈ړ����x


//�v���C���[���
PlayerInfo playerInfo = { 0 };


//�v���C���[�̏�����
void InitPlayer()
{
	playerInfo.handle = 0;						//�摜�n���h��
	playerInfo.pos = { 0 };						//���W
	playerInfo.old_pos = { 0 };					//�ړ��O�̍��W
	playerInfo.move = { 0 };					//�ړ���
	playerInfo.isAlive = true;					//�����t���O
	playerInfo.state = PLAYER_STATE_IDLE;		//�X�e�[�^�X�i�n�߂́A�ҋ@��ԁj
	playerInfo.direction = PLAYER_DIR_UP;		//�v���C���[�̌����Ă�������i�n�߂́A��������Ă���j

	//�v���C���[�̉摜�ǂ݂���
	playerInfo.handle = LoadGraph("Data/Player/Player.png");

	//�v���C���[�̏����ʒu�ݒ�
	playerInfo.pos.x = PLAYER_START_POS_X;
	playerInfo.pos.y = PLAYER_START_POS_Y;
}

//�v���C���[�̒ʏ폈��
void StepPlayer()
{
	//�ړ��O�̍��W�̋L�^
	playerInfo.old_pos = playerInfo.pos;

	//�ړ��ʂ̃��Z�b�g
	playerInfo.move = { 0 };

	if (playerInfo.isAlive)
	{
		//�v���C���[�̏�Ԃ����Z�b�g�i����������ĂȂ��Ȃ�A�ҋ@��ԁj
		playerInfo.state = PLAYER_STATE_IDLE;

		//�v���C���[�̓��͏���
		StepPlayerInput();
	}

	//�ړ��ʂ̉��Z
	playerInfo.pos = VecAdd(playerInfo.pos, playerInfo.move);


	//--�v���C���[���}�b�v�O�ɂ͂ݏo���Ȃ��悤�ɂ��鏈��--//
	if (playerInfo.pos.x - PLAYER_RADIUS < 0)
		playerInfo.pos.x = 0 + PLAYER_RADIUS;
	else if (playerInfo.pos.x + PLAYER_RADIUS > MAP_WIDTH)
		playerInfo.pos.x = MAP_WIDTH - PLAYER_RADIUS;

	if (playerInfo.pos.y - PLAYER_RADIUS < 0)
		playerInfo.pos.y = 0 + PLAYER_RADIUS;
	else if (playerInfo.pos.y + PLAYER_RADIUS > MAP_HEIGHT)
		playerInfo.pos.y = MAP_HEIGHT - PLAYER_RADIUS;
}

//�v���C���[�̕`�揈��
void DrawPlayer()
{
	//�v���C���[�������Ă���Ȃ�`�悷��
	if (playerInfo.isAlive)
	{
		int current_index = playerInfo.animeInfo.currentAnimeIndex;
		PlayerAnimeKind anime_kind = playerInfo.animeInfo.currentAnimeKind;

		//�v���C���[�̃X�N���[�����W�����߂�
		int playerX = (int)(playerInfo.pos.x - GetScreenX());
		int playerY = (int)(playerInfo.pos.y - GetScreenY());

		DrawRotaGraph(playerX, playerY, 1.0, 0.0, playerInfo.animeInfo.handle[anime_kind][current_index], true);
	}
}

//�v���C���[�̌㏈��
void FinPlayer()
{
	DeleteGraph(playerInfo.handle);
	playerInfo.handle = 0;
}


//�v���C���[�̓��͏���
void StepPlayerInput()
{
	//�v���C���[�̈ړ����x
	float move_spd = PLAYER_WALK_SPD;	//�������̈ړ����x��ݒ�

	//SHIFT�L�[�������ꂽ��
	if (IsKeyDown(KEY_INPUT_RSHIFT) || IsKeyDown(KEY_INPUT_LSHIFT))
	{
		move_spd = PLAYER_RUN_SPD;	//���鎞�̈ړ����x��ݒ�
	}

	//�㉺���E�̃L�[�{�[�h�������ꂽ��
	if (IsKeyDown(KEY_INPUT_UP) || IsKeyDown(KEY_INPUT_DOWN)
		|| IsKeyDown(KEY_INPUT_LEFT) || IsKeyDown(KEY_INPUT_RIGHT))
	{
		if (IsKeyDown(KEY_INPUT_UP))
		{
			playerInfo.move.y = -move_spd;			//������̈ړ��ʂ�ݒ�
			playerInfo.direction = PLAYER_DIR_UP;	//�v���C���[����Ɍ�������
		}
		if (IsKeyDown(KEY_INPUT_DOWN))
		{
			playerInfo.move.y = move_spd;			//�������̈ړ��ʂ�ݒ�
			playerInfo.direction = PLAYER_DIR_DOWN;	//�v���C���[�����Ɍ�������
		}
		if (IsKeyDown(KEY_INPUT_LEFT))
		{
			playerInfo.move.x = -move_spd;			//�������̈ړ��ʂ�ݒ�
			playerInfo.direction = PLAYER_DIR_LEFT;	//�v���C���[�����Ɍ�������
		}
		if (IsKeyDown(KEY_INPUT_RIGHT))
		{
			playerInfo.move.x = move_spd;			//�E�����̈ړ��ʂ�ݒ�
			playerInfo.direction = PLAYER_DIR_RIGHT;//�v���C���[���E�Ɍ�������
		}

		playerInfo.state = PLAYER_STATE_WALK;	//������Ԃ�
	}

	//�u�P�v�L�[���������@���@�v���C���[�����̉\�Ȃ�
	if (IsKeyPush(KEY_INPUT_1) && CanCutPlayer())
	{
		playerInfo.state = PLAYER_STATE_CUT;	//���̏�Ԃ�
	}
}


//�v���C���[�����̏�Ԃ��ǂ���
bool IsCutPlayer()
{
	switch (playerInfo.state)
	{
	case PLAYER_STATE_CUT:
		return true;
	}

	return false;
}

//�v���C���[�����̉\���ǂ���
bool CanCutPlayer()
{
	//�v���C���[�̏�Ԃ����̏�ԈȊO�Ȃ田�̉\
	switch (playerInfo.state)
	{
	case PLAYER_STATE_CUT:
		return false;
	}

	return true;
}



//�v���C���[�̏��擾
PlayerInfo* GetPlayerInfo()
{
	return &playerInfo;
}