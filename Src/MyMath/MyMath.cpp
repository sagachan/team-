#include <DxLib.h>
#include "MyMath.h"
#include <math.h>

// �_P(x1, y1)����_Q(x2, y2)�܂ł̋�����Ԃ�
float GetDistance(float x1, float y1, float x2, float y2)
{
	// �_P����_Q�܂ł̒������ΕӂƂ��钼�p�O�p�`�����A
	// �s�^�S���X�̒藝����Εӂ̒������v�Z����B
	// �@�܂��͒�ӂ̒������v�Z����
	float a = x2 - x1;

	// �A�������v�Z����
	float b = y2 - y1;

	// �B�Εӂ�2��̒l���v�Z����
	float double_c = a * a + b * b;

	// �C2��̒l�Ȃ̂ŕ��������v�Z���Ē����Ƃ���
	// �@��������<math.h>��sqrtf�֐��Ŏ擾�ł���
	return sqrtf(double_c);
}

//pos1����pos2�܂ł̋������v�Z����
float GetDistance(VECTOR pos1, VECTOR pos2)
{
	return VecLong(VecCreate(pos1, pos2));
}


//�ψʃx�N�g���̍쐬
VECTOR VecCreate(VECTOR start, VECTOR end)
{
	VECTOR result;

	//�e�����Łu�i�I�_�j�[�i�n�_�j�v������
	result.x = end.x - start.x;
	result.y = end.y - start.y;
	result.z = end.z - start.z;

	return result;
}


//�x�N�g���̒��������߂�
float VecLong(VECTOR vec)
{
	float vec_long = sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);

	return vec_long;
}


// �x�N�g���̑����Z
VECTOR VecAdd(VECTOR vec1, VECTOR vec2)
{
	VECTOR result;

	// �@�e�����𑫂��Z����
	result.x = vec1.x + vec2.x;
	result.y = vec1.y + vec2.y;
	result.z = vec1.z + vec2.z;

	return result;
}


//�x�N�g���̌��Z�ivec1����vec2������)
VECTOR VecSub(VECTOR vec1, VECTOR vec2)
{
	VECTOR result;

	//�e�����������Z����
	result.x = vec1.x - vec2.x;
	result.y = vec1.y - vec2.y;
	result.z = vec1.z - vec2.z;

	return result;
}


//�x�N�g���̐��K��
VECTOR VecNormalize(VECTOR vec)
{
	VECTOR result;
	float vec_long = VecLong(vec);	//�x�N�g���̒���

	//�e�����̒����Ŋ��萳�K������
	result.x = vec.x / vec_long;
	result.y = vec.y / vec_long;
	result.z = vec.z / vec_long;

	return result;
}


//�x�N�g���̃X�J���[�{
VECTOR VecScale(VECTOR vec, float scale)
{
	VECTOR result;

	//�e�������X�J���[�{����
	result.x = vec.x * scale;
	result.y = vec.y * scale;
	result.z = vec.z * scale;

	return result;
}


//�x�N�g���̓���
float VecDot(VECTOR vec1, VECTOR vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

//�x�N�g���̊O�ρi�Q�c�j
float VecCross2D(VECTOR vec1, VECTOR vec2)
{
	return vec1.x * vec2.y - vec1.y * vec2.x;
}
//�x�N�g���̊O�ρi�R�c�j
VECTOR VecCross(VECTOR vec1, VECTOR vec2)
{
	VECTOR result;

	result.x = vec1.y * vec2.z - vec1.z * vec2.y;
	result.y = vec1.z * vec2.x - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;

	return result;
}


//��]�l���O�`�Q�΂̒l�ɂ���
float RadianNormalize(float rad)
{
	float result = rad;
	if (result < 0.0f)
	{
		while (result < 0.0f)
		{
			result += DX_TWO_PI_F;
		}
	}
	else if (result >= DX_TWO_PI_F)
	{
		while (result > DX_TWO_PI_F)
		{
			result -= DX_TWO_PI_F;
		}
	}

	return result;
}