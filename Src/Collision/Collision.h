
#ifndef __COLLISION_H__
#define __COLLISION_H__

//��`�̓����蔻��̃v���g�^�C�v�錾
bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh);

//�~�̓����蔻��̃v���g�^�C�v�錾
bool IsHitCircle(int x1, int y1, int r1, int x2, int y2, int r2);

#endif