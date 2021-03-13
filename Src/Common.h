#ifndef __COMMON_H__
#define __COMMON_H__

//�E�B���h�E�̕��E����
#define WINDOW_HEIGHT  (720)
#define WINDOW_WIDTH (1280)

//�}�b�v�̕��E����
#define MAP_WIDTH	(6400)
#define MAP_HEIGHT	(6400)

//�ݒ�t���[�����[�g
#define FRAME_RATE	(60)

//1�t���[���̎��� (�~���b)
#define FRAME_TIME (1000 / FRAME_RATE)

//�t���[�����[�g���
struct FrameRateInfo
{
	int currentTime;	//���݂̎���
	int lastFrameTime;	//�O��̃t���[�����s���̎���
	int count;			//�t���[���J�E���g�p
	int calcFpsTime;	//FPS���v�Z��������
	float fps;			//�v������FPS�i�\���p�j
};

#endif

