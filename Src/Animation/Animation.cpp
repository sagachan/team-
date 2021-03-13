#include <DxLib.h>
#include "Animation.h"
#include "../Player/Player.h"
#include "../Common.h"


//�A�j���[�V�����̌��i�v���C���[�A�G�Ȃǂ̑S�ẴI�u�W�F�N�g�̃A�j���[�V�������j
int g_animation_num;



//�v���C���[�̃A�j���֘A
//�e�A�j���̉摜�n���h��
const char player_anime_file_path[PLAYER_ANIME_KIND_NUM][256] =
{
	"Data/Player/Player_Idle.png",	//�ҋ@
	"Data/Player/Player_Walk.png",	//����
	"Data/Player/Player_Run.png",	//����
	"Data/Player/Player_Cut.png",	//����
};
//�e�A�j���̉摜��
const int player_anime_img_num[PLAYER_ANIME_KIND_NUM] =
{
	3,		//�ҋ@
	3,		//����
	3,		//����
	3,		//����
};
//�e�A�j���̐؂�ւ�����
const float player_anime_changeTime[PLAYER_ANIME_KIND_NUM] =
{
	0.2f,	//�ҋ@
	0.2f,	//����
	0.2f,	//����
	0.2f,	//����
};
//�e�A�j���̃��[�v�t���O
const bool player_anime_loop_flg[PLAYER_ANIME_KIND_NUM] =
{
	true,	//�ҋ@
	true,	//����
	true,	//����
	false,	//����
};

//---�A�C�e����A����ȊO�̃I�u�W�F�N�g�̃A�j���֘A�͂��̉��ɏ���---//


//�A�j���[�V�����̏�����
void InitAnimation()
{
	//�v���C���[�̃A�j���[�V������񏉊���
	PlayerInfo* playerInfo = GetPlayerInfo();

	playerInfo->animeInfo.currentAnimeIndex = 0;	//���݂̃A�j���[�V�����ԍ�
	playerInfo->animeInfo.currentAnimeTime = 0.0f;	//���݂̃A�j���[�V��������
	playerInfo->animeInfo.currentAnimeKind = PLAYER_ANIME_KIND_IDLE;	//�|�ނ̃A�j���[�V�����̎��
	for (int i = 0; i < PLAYER_ANIME_KIND_NUM; i++)
	{
		playerInfo->animeInfo.animeUseNum[i] = player_anime_img_num[i];			//�A�j���[�V�����̎g�p�摜��
		playerInfo->animeInfo.changeAnimeTime[i] = player_anime_changeTime[i];	//�A�j���[�V�����̐؂�ւ�����
		playerInfo->animeInfo.is_loop[i] = player_anime_loop_flg[i];			//���[�v����A�j�����ǂ���
		playerInfo->animeInfo.is_end[i] = false;								//�I�����Ă���A�j�����ǂ���
	}

	//---�A�C�e����A����ȊO�̃I�u�W�F�N�g�Ȃǂ̃A�j���[�V�������̏������͂��̉��ɏ���---//

}


//�A�j���[�V�����̓ǂݍ���
void LoadAnimation()
{
	//�v���C���[�̃A�j���[�V�����ǂݍ���
	PlayerInfo* playerInfo = GetPlayerInfo();
	for (int i = 0; i < PLAYER_ANIME_KIND_NUM; i++)
	{
		//�摜�̕����ǂݍ���
		LoadDivGraph(player_anime_file_path[i], player_anime_img_num[i], player_anime_img_num[i], 1, 64, 64, playerInfo->animeInfo.handle[i]);
	}

}


//�A�j���[�V�����̒ʏ폈��
void StepAnimation()
{
	//---�v���C���[�̃A�j���[�V�����X�V����---//
	PlayerInfo* playerInfo = GetPlayerInfo();
	for (int anime_index = 0; anime_index < PLAYER_ANIME_KIND_NUM; anime_index++)
	{
		//���݂̃v���C���[�̃A�j���[�V�����ł͂Ȃ�������
		if (playerInfo->animeInfo.currentAnimeKind != anime_index)
			continue;

		//�I�����Ă���A�j���[�V�����͍X�V���Ȃ�
		if (playerInfo->animeInfo.is_end[anime_index] == true)
			continue;

		//�����A�A�j���[�V�����؂�ւ����Ԃ��o�߂�����
		if (playerInfo->animeInfo.changeAnimeTime[anime_index] >= playerInfo->animeInfo.changeAnimeTime[anime_index])
		{
			//���݂̃A�j���ԍ���i�߂�
			playerInfo->animeInfo.currentAnimeIndex++;

			//�����A���݂̃A�j���ԍ����Ō�Ȃ�
			if (playerInfo->animeInfo.currentAnimeIndex >= playerInfo->animeInfo.animeUseNum[anime_index])
			{
				//���[�v����A�j���Ȃ�
				if (playerInfo->animeInfo.is_loop[anime_index] == true)
				{
					playerInfo->animeInfo.currentAnimeIndex = 0;	//���݂̃A�j���ԍ����ŏ��ɖ߂�
				}
				//���[�v����A�j������Ȃ��Ȃ�
				else
				{
					playerInfo->animeInfo.currentAnimeIndex--;	//�Ō�̃A�j���摜�ɂ���
					playerInfo->animeInfo.is_end[anime_index] = true;		//�A�j���̏I���t���O�𗧂Ă�
				}
			}
			//���݂̃A�j�����Ԃ����Z�b�g
			playerInfo->animeInfo.currentAnimeTime = 0.0f;
		}
		else
		{
			//���݂̃A�j�����Ԃ�i�߂�
			playerInfo->animeInfo.currentAnimeTime += 1.0f / FRAME_RATE;
		}
	}


	//---�A�C�e����A����ȊO�̃I�u�W�F�N�g�̃A�j���[�V�����X�V�����͂��̉��ɏ���---//

}

//�A�j���[�V�����̌㏈��
void FinAnimation()
{
	//�v���C���[�̃A�j���[�V�����摜�̔j��
	PlayerInfo* playerInfo = GetPlayerInfo();
	for (int anime_index = 0; anime_index < PLAYER_ANIME_KIND_NUM; anime_index++)
	{
		for (int image_index = 0; image_index < PLAYER_ANIME_IMG_MAX_NUM; image_index++)
		{
			DeleteGraph(playerInfo->animeInfo.handle[anime_index][image_index]);
		}
	}

	//---�A�C�e����A����ȊO�̃I�u�W�F�N�g�̃A�j���[�V�����摜�̔j���͂��̉��ɏ���---//

}