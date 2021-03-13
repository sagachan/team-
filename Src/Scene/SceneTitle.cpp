
#include "DxLib.h"
#include "Scene.h"
#include "SceneTitle.h"

//�^�C�g���w�i�摜�̃p�X
#define BG_TITLE_PATH		"Data/TETRIS_Title.png"

//�^�C�g���摜�̃n���h��
int bgTitleHandle;


//�^�C�g��������
void InitTitle()
{
	//�^�C�g���w�i������
	bgTitleHandle = LoadGraph(BG_TITLE_PATH);

	//�^�C�g�����[�v��
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;
}

//�^�C�g���ʏ폈��
void StepTitle()
{
	//Enter�L�[�������ꂽ�Ȃ�
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		//�^�C�g���㏈���ֈړ�
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

//�^�C�g���`�揈��
void DrawTitle()
{
	//�^�C�g���摜�\��
	DrawGraph(0, 0, bgTitleHandle, true);
}

//�^�C�g���㏈��
void FinTitle()
{
	//�^�C�g���摜�j��
	DeleteGraph(bgTitleHandle);

	//�^�C�g���̌�̓v���C��
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}