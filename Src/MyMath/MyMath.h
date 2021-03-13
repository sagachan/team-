#ifndef __MYMATH_H__
#define __MYMATH_H__


//�x�N�g���̏������}�N����`
#define ZERO_VECTOR VGet(0.0f, 0.0f, 0.0f)


//�Q�_�Ԃ̋��������߂�i�Q�c�j
float GetDistance(float x1, float y1, float x2, float y2);

//pos1����pos2�܂ł̋������v�Z����
float GetDistance(VECTOR pos1, VECTOR pos2);

//�ψʃx�N�g���̍쐬
VECTOR VecCreate(VECTOR start, VECTOR end);

//�x�N�g���̒��������߂�
float VecLong(VECTOR vec);

//�x�N�g���̉��Z
VECTOR VecAdd(VECTOR vec1, VECTOR vec2);

//�x�N�g���̌��Z
VECTOR VecSub(VECTOR vec1, VECTOR vec2);

//�x�N�g���̐��K��
VECTOR VecNormalize(VECTOR vec);

//�x�N�g���̃X�J���[�{
VECTOR VecScale(VECTOR vec, float scale);

//�x�N�g���̓���
float VecDot(VECTOR vec1, VECTOR vec2);

//�x�N�g���̊O�ρi�Q�c�j
float VecCross2D(VECTOR vec1, VECTOR vec2);
//�x�N�g���̊O�ρi�R�c�j
VECTOR VecCross(VECTOR vec1, VECTOR vec2);


//��]�l���O�`�Q�΂̒l�ɂ���
float RadianNormalize(float rad);

#endif
