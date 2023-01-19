#pragma once
#include <vector>

class Mino
{
private:
	//�@�~�m�̌�
	static constexpr int Column = 4;
	//�@�~�m�̑�
	static constexpr int Side = 4;

public:
	Mino();

	virtual ~Mino();

	enum
	{
		ShapeI,
		ShapeJ,
		ShapeL,
		ShapeO,
		ShapeS,
		ShapeT,
		ShapeZ
	};

	void Update();

	void NextUpdate();

	void SetMinoNow();

	void SetMino();

	void NextSetMino();

	int GetMino1(int i, int j);

	int GetMino2(int i, int j);

	int GetMino3(int i, int j);

	int GetMino4(int i, int j);

	int NextGetMino(int i, int j);


	// �~�m�̐F
	int m_MinoCollar;
	// ���̃~�m�̐F
	int m_NextMinoCollar;


private:
	//�@�����_���~�m
	int m_RandMino;
	//�@���̃����_���~�m
	int m_NextRandMino;

	//�@�~�m�̌`
	int m_MinoShape;
	//�@���̃~�m�̌`
	int m_NextMinoShape;
	int m_Tetrimino[Column][Side];

};

