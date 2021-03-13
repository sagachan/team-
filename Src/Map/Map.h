#ifndef __MAP_H__
#define __MAP_H__

#define MAP_CHIP_1 "Data/can_chip1.png"


//#define MAP_PATH_SMALL ()

#define MAP_PATH_MEDIUM (64)
#define MAP_CHIP_NUM	(100)

#define MAP_PATH_LARGE ()
//#define MAP_HEIGHT ()
//#define MAP_WIDTH ()

enum MAP_KIND
{
	EMPTY,
	WOOD,
	ROCK,
	ITEM_MAX	//�}�b�v�`�b�v�̎��
};


struct MAP_CHIP
{
	int handle;		//�摜�n���h��
	int x, y;		//���W	
	bool isUse;		//�g�p�t���O
	MAP_KIND kind;	//����Ŕ��肵�����l�̃}�b�v�`�b�v��handle�ɓ����
};

struct MAP_CHIP_SAVE
{
	int handle;		//�摜�n���h��
	int x, y;		//���W	
	bool isUse;		//�g�p�t���O
	MAP_KIND kind;	//����Ŕ��肵�����l�̃}�b�v�`�b�v��handle�ɓ����
};

int Getkind();

void InitMap();

void StepMap();

void DrawMap();

void FinMap();



#endif