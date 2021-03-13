#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../Animation/Animation.h"


//�v���C���[�̏��
enum PLAYER_STATE
{
	PLAYER_STATE_IDLE = 0,	//�ҋ@
	PLAYER_STATE_WALK,		//����
	PLAYER_STATE_RUN,		//����
	PLAYER_STATE_CUT,		//����
};

//�v���C���[�̌����Ă������
enum PLAYER_DIRECTION
{
	PLAYER_DIR_UP,		//��
	PLAYER_DIR_DOWN,	//��
	PLAYER_DIR_LEFT,	//��
	PLAYER_DIR_RIGHT,	//�E
};

//�v���C���[���\����
struct PlayerInfo
{
	int handle;							//�摜�n���h��
	VECTOR pos;							//���W
	VECTOR old_pos;						//�ړ��O�̍��W
	VECTOR move;						//�ړ���
	bool isAlive;						//�����t���O
	PLAYER_STATE state;					//�X�e�[�^�X
	PLAYER_DIRECTION direction;			//�v���C���[�̌����Ă������
	PlayerAnimeInfo animeInfo;			//�A�j���[�V�������
};

//�v���C���[�̏�����
void InitPlayer();

//�v���C���[�̒ʏ폈��
void StepPlayer();

//�v���C���[�̕`�揈��
void DrawPlayer();

//�v���C���[�̌㏈��
void FinPlayer();


//�v���C���[�̓��͏���
void StepPlayerInput();


//�v���C���[�����̏�Ԃ��ǂ���
bool IsCutPlayer();

//�v���C���[�����̉\���ǂ���
bool CanCutPlayer();


//�v���C���[�̏��擾
PlayerInfo* GetPlayerInfo();

#endif