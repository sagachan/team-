
#include <DxLib.h>
#include "Collision/Collision.h"
#include "Scene/Scene.h"
#include "Scene/ScenePlay.h"
#include "Scene/SceneTitle.h"
#include "Input/Input.h"
#include "Common.h"
#include "BackGround/BackGround.h"

//���݂̃V�[��ID
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;

FrameRateInfo frameRateInfo;

void CalcFPS();

void DrawFPS();

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	//DX���C�u�����̏�����
	if(DxLib_Init() == -1)
	{
		return -1;
	}

	//�E�B���h�E�T�C�Y��ύX
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);

	//�`�悷��X�N���[����ݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	//���͐��䏉����
	InitInput();
	

	//=============================================================================
	//�Q�[�����C�����[�v
	while(ProcessMessage() != -1)
	{
		Sleep(1);

		//���݂̎��Ԃ��擾
		frameRateInfo.currentTime = GetNowCount();

		//�ŏ��̃��[�v�Ȃ�
		//���݂̎��Ԃ��AFPS�̌v�Z���������Ԃɐݒ�
		if (frameRateInfo.calcFpsTime == 0.0f)
		{
			frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
			frameRateInfo.fps = (float)FRAME_RATE;
		}

		//���݂̎��Ԃ��A�O��̃t���[�������
		//1000/60�~���b�ȏ�o�߂��Ă����珈�������s����
		if (frameRateInfo.currentTime - frameRateInfo.lastFrameTime >= FRAME_TIME)
		{
			//�t���[�����s���̎��Ԃ��X�V
			frameRateInfo.lastFrameTime = frameRateInfo.currentTime;

			//�t���[�������J�E���g
			frameRateInfo.count++;

			if (IsKeyPush(KEY_INPUT_ESCAPE) == 1)
			{
				//�G�X�P�[�v�L�[�������ꂽ��I��
				break;
			}

			//��ʂɕ\�����ꂽ���̂��������i�P���[�v�̂P�x�����s���j
			ClearDrawScreen();

			//���͐���X�e�b�v
			StepInput();


			//�V�[��ID�ɂ���ď����̐U�蕪��
			switch (g_CurrentSceneID)
			{
			//****�^�C�g���V�[��****//
			case SCENE_ID_INIT_TITLE:
			{
				//�^�C�g��������
				InitTitle();
			}
			break;

			case SCENE_ID_LOOP_TITLE:
			{
				//�^�C�g���ʏ폈��
				StepTitle();

				//�^�C�g���`�揈��
				DrawTitle();
			}
			break;

			case SCENE_ID_FIN_TITLE:
			{
				//�^�C�g���㏈��
				FinTitle();
			}
			break;

			//****�v���C�V�[��****//
			case SCENE_ID_INIT_PLAY:
			{
				//�v���C������
				InitPlay();
			}

			case SCENE_ID_LOOP_PLAY:
			{
				//�v���C�ʏ폈��
				StepPlay();

				//�v���C�`�揈��
				DrawPlay();

			}//SCNE_ID_PLAY�I���̊���
			break;

			case SCENE_ID_FIN_PLAY:
			{
				//�v���C�㏈��
				FinPlay();
			}
			break;

			//****�N���A�V�[��****//
			case SCENE_ID_INIT_CLEAR:
			{
				//�N���A������
				/*InitClear();*/
			}
			break;

			case SCENE_ID_LOOP_CLEAR:
			{
				//�N���A�ʏ폈��
				/*StepClear();*/

				//�N���A�`�揈��
				/*DrawClear();*/
			}//SCENE_ID_CLEAR�I���̊���
			break;

			case SCENE_ID_FIN_CLEAR:
			{
				//�N���A�㏈��
				/*FinClear();*/
			}
			break;

			//****�Q�[���I�[�o�[�V�[��****//
			case SCENE_ID_INIT_GAMEOVER:
			{
				//�Q�[���I�[�o�[������
				/*InitGameOver();*/
			}
			break;

			case SCENE_ID_LOOP_GAMEOVER:
			{
				//�Q�[���I�[�o�[�ʏ폈��
			/*	StepGameOver();*/

				//�Q�[���I�[�o�[�`�揈��
				/*DrawGameOver();*/
			}//SCENE_ID_GAMEOVER�I���̊���
			break;

			case SCENE_ID_FIN_GAMEOVER:
			{
				//�Q�[���I�[�o�[�㏈��
				/*FinGameOver();*/
			}
			break;

			}

			//FPS�v�Z
			CalcFPS();

			//FPS�\��
			DrawFPS();

			//�t���b�v�֐��i���[�v�̏I���ɂP�x�����s���j
			ScreenFlip();

		}//�t���[�����[�g��if���I���

	}//���C�����[�v�I���

	//�Ō�ɂP�񂾂���鏈���������ɏ���
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}


//FPS�v�Z
void CalcFPS()
{
	//�O���FPS���v�Z�������Ԃ���̌o�ߎ��Ԃ����߂�
	int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;

	//�O���FPS���v�Z�������Ԃ���
	//�P�b�ȏ�o�߂��Ă�����FPS���v�Z����
	if (difTime > 1000)
	{
		//�t���[���񐔂��~���b�ɍ��킹��
		//�����܂ŏo�������̂�float�ɃL���X�g
		float frameCount = (float)(frameRateInfo.count * 1000.0f);

		//FPS�����߂�
		//���z�̐��l�� 60000 / 1000 �� 60 �ƂȂ�
		frameRateInfo.fps = frameCount / difTime;

		//�t���[�����[�g�J�E���g���N���A
		frameRateInfo.count = 0;

		//FPS���v�Z�������Ԃ��X�V
		frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
	}
}

//FPS�\���i�f�o�b�O�p�j
void DrawFPS()
{
	unsigned int color = GetColor(255, 30, 30);
	DrawFormatString(1150, 690, color, "FPS[%.2f]", frameRateInfo.fps);
}