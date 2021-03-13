#include <DxLib.h>
#include "Screen.h"
#include "../Player/Player.h"
#include "../Common.h"

//�X�N���[�����W�錾
float screenX = 0;
float screenY = 0;


//�X�N���[���̒ʏ폈��
void StepScreen()
{
	//�v���C���[�����擾
	PlayerInfo* playerInfo = GetPlayerInfo();

	//�v���C���[�𒆐S��
	//�X�N���[�����W�����߂�
	screenX = playerInfo->pos.x - WINDOW_WIDTH / 2;
	screenY = playerInfo->pos.y - WINDOW_HEIGHT / 2;


	//---�X�N���[���̃��[���h���W���}�b�v�O�ɏo�Ȃ��悤�ɂ��鏈��---//
	//�������}�b�v�O�ɂ͂ݏo����
	if (screenX < 0)
		screenX = 0;
	else if (screenX + WINDOW_WIDTH > MAP_WIDTH)
		screenX = MAP_WIDTH - WINDOW_WIDTH;
	//�c�����}�b�v�O�ɂ͂ݏo����
	if (screenY < 0)
		screenY = 0;
	else if (screenY + WINDOW_HEIGHT > MAP_HEIGHT)
		screenY = MAP_HEIGHT - WINDOW_HEIGHT;
}

//�X�N���[���̃��[���h�w���W�擾
float GetScreenX()
{
	return screenX;
}

//�X�N���[���̃��[���h�x���W�擾
float GetScreenY()
{
	return screenY;
}
