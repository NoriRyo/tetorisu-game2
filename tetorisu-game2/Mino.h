#pragma once
#include <vector>

class Mino
{
private:
	//　ミノの桁
	static constexpr int Column = 4;
	//　ミノの側
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


	// ミノの色
	int m_MinoCollar;
	// 次のミノの色
	int m_NextMinoCollar;


private:
	//　ランダムミノ
	int m_RandMino;
	//　次のランダムミノ
	int m_NextRandMino;

	//　ミノの形
	int m_MinoShape;
	//　次のミノの形
	int m_NextMinoShape;
	int m_Tetrimino[Column][Side];

};

