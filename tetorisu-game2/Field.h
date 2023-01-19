#pragma once

#include "SceneBase.h"

class Mino;

class Field : public SceneBase
{
private:
	static constexpr int Column = 4;
	static constexpr int Side = 4;
public:
	Field();

	virtual ~Field();

	virtual void init()override;

	virtual void end()override;

	virtual SceneBase* update()override;

	virtual void draw()override;

	bool IsActive();

	bool IsLeft();	//�@��

	bool IsRight();	//�@�E

	void rotationMino();	//�@��]

	void MoveMino();		//�@����

	//bool columnExist();
private:
	void updateAppear();	// �o��
	void updateLeft();		// ���Ɉړ�
	void updateRight();		// �E�Ɉړ�

private:
	// �w�i
	int m_hBg;

	// �t�B�[���h�T�C�Y
	int m_MinoSize;

	// �������Ă���~�m�̃t�B�[���h���i0,1�j
	int m_ActiveFieldNum[23][10];

	// �������Ă���~�m�̏��i0,1�j
	int m_ActiveMinoNum[Column][Side];

	// ���ɓ����~�m�̏��i0,1�j
	int m_NextActiveMinoNum[Column][Side];

	// �t�B�[���h�̏��i0,1�j
	int m_FieldNum[20][10];

	// �~�m�����������̒u������
	int m_VirtualFieldNum[20][10];

	// �e�g���~�m�ԍ�
	int m_MinoNum;
	// �e�g���~�m�̏\�̈ʂ̔ԍ�
	int m_TensPlaceNum;
	// �e�g���~�m�̈�̈ʂ̔ԍ�
	int m_OnesPlaceNum;

	// �e�g���~�m�̗����鑬�x
	int m_fallFlame;

	// �e�g���~�m���؂�ւ�鎞��
	int m_SwitchMinoFlame;

	bool m_IsRightPressBotton;	// �E�{�^��
	bool m_IsLeftPressBotton;	// ���{�^��
	bool m_IsUpPressBotton;		// ��{�^��

	// �����̃~�m�̐�
	int m_ColumnMinoNum;

	// �����ɂ��ׂă~�m�����݂��邩�ǂ���
	bool m_ExistColumnMino;

	// �A�N�e�B�u�~�m�̉��Ƀ~�m�����݂���Ƃ�
	bool m_BottomMino;

	// �ŏ��ɏo�����~�m�̂Ƃ�
	bool m_FirstMino;

	// ����ڂ̃~�m�����������
	int m_ExistMinoNum;

	// ����ڂ̉�]��
	bool m_rota1;	//�@1���
	bool m_rota2;	//�@2���
	bool m_rota3;	//�@3���
	bool m_rota4;	//�@4���

	// �~�m�̐F
	int m_MinoCollar;
	// ���̃~�m�̐F
	int m_NextMinoCollar;

	bool m_MinusMino;	//�@�}�C�i�X�~�m

	bool m_End;		// �I��

	// update���������o�֐��|�C���^
	void(Field::* m_func)();

	Mino* mino;
};
