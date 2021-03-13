#ifndef __ANIMATION_H__
#define __ANIMATION_H__

//�v���C���[�̃A�j���̒��ōő�̉摜���i��j�����c�R���A���́c�T���̏ꍇ�́A�ő�̉摜���́u�T�v
#define PLAYER_ANIME_IMG_MAX_NUM	(3)


//�I�u�W�F�N�g�̎��
enum OBJECT_TYPE
{
	OBJECT_TYPE_PLAYER = 0,	//�v���C���[
	OBJECT_TYPE_ITEM,		//�A�C�e��
};

//�v���C���[�̃A�j�����
enum PlayerAnimeKind
{
	PLAYER_ANIME_KIND_IDLE = 0,	//�ҋ@
	PLAYER_ANIME_KIND_WALK,		//����
	PLAYER_ANIME_KIND_RUN,		//����
	PLAYER_ANIME_KIND_CUT,		//����

	PLAYER_ANIME_KIND_NUM,		//�A�j����ސ�
};

//�A�j���[�V�������\����
struct PlayerAnimeInfo
{
	int handle[PLAYER_ANIME_KIND_NUM][PLAYER_ANIME_IMG_MAX_NUM];	//�摜�n���h��
	int animeUseNum[PLAYER_ANIME_KIND_NUM];							//�A�j���[�V�����̎g�p�摜��
	float currentAnimeTime;											//���݂̃A�j���[�V��������
	float changeAnimeTime[PLAYER_ANIME_KIND_NUM];					//�A�j���[�V�����̐؂�ւ�����
	int currentAnimeIndex;											//���݂̃A�j���[�V�����ԍ�

	bool is_loop[PLAYER_ANIME_KIND_NUM];							//���[�v����A�j���[�V�������ǂ���
	bool is_end[PLAYER_ANIME_KIND_NUM];								//�I�����Ă���A�j���[�V�������ǂ���

	PlayerAnimeKind currentAnimeKind;								//���݂̃A�j���[�V�����̎��
};


//�A�j���[�V�����̏�����
void InitAnimation();

//�A�j���[�V�����̓ǂݍ���
void LoadAnimation();

//�A�j���[�V�����̒ʏ폈��
void StepAnimation();

//�A�j���[�V�����̌㏈��
void FinAnimation();


#endif