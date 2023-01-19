#include "Mino.h"
#include<Dxlib.h>

Mino::Mino() :
	m_RandMino(0),
	m_NextRandMino(0),
	m_MinoShape(0),
	m_NextMinoShape(0)
{
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_Tetrimino[i][j] = 0;
		}
	}
}

Mino::~Mino()
{

}

void Mino::Update()
{
	m_RandMino = GetRand(7 - 1);	// —”
}

void Mino::NextUpdate()
{
	m_NextRandMino = GetRand(7 - 1);
}

void Mino::SetMinoNow()
{
	m_RandMino = m_NextRandMino;
}

void Mino::SetMino()
{
	switch (m_RandMino)
	{
	case 0:
		m_MinoShape = ShapeI;
		m_MinoCollar = GetColor(0, 191, 255);
		break;
	case 1:
		m_MinoShape = ShapeJ;
		m_MinoCollar = GetColor(75, 0, 130);
		break;
	case 2:
		m_MinoShape = ShapeL;
		m_MinoCollar = GetColor(255, 69, 0);
		break;
	case 3:
		m_MinoShape = ShapeO;
		m_MinoCollar = GetColor(255, 255, 0);
		break;
	case 4:
		m_MinoShape = ShapeS;
		m_MinoCollar = GetColor(0, 128, 0);
		break;
	case 5:
		m_MinoShape = ShapeT;
		m_MinoCollar = GetColor(255, 0, 255);
		break;
	case 6:
		m_MinoShape = ShapeZ;
		m_MinoCollar = GetColor(220, 20, 60);
		break;
	default:
		break;
	}
}


void Mino::NextSetMino()
{
	switch (m_NextRandMino)
	{
	case 0:
		m_NextMinoShape = ShapeI;
		m_NextMinoCollar = GetColor(0, 191, 255);
		break;
	case 1:
		m_NextMinoShape = ShapeJ;
		m_NextMinoCollar = GetColor(75, 0, 130);
		break;
	case 2:
		m_NextMinoShape = ShapeL;
		m_NextMinoCollar = GetColor(255, 69, 0);
		break;
	case 3:
		m_NextMinoShape = ShapeO;
		m_NextMinoCollar = GetColor(255, 255, 0);
		break;
	case 4:
		m_NextMinoShape = ShapeS;
		m_NextMinoCollar = GetColor(0, 128, 0);
		break;
	case 5:
		m_NextMinoShape = ShapeT;
		m_NextMinoCollar = GetColor(255, 0, 255);
		break;
	case 6:
		m_NextMinoShape = ShapeZ;
		m_NextMinoCollar = GetColor(220, 20, 60);
		break;
	default:
		break;
	}
}

int Mino::GetMino1(int i, int j)
{
	if (m_MinoShape == ShapeI)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 1;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeJ)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 1;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 0;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeL)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeO)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeS)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 1;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 1;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeT)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeZ)
	{
		m_Tetrimino[0][0] = 1;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	return m_Tetrimino[i][j];
}

int Mino::GetMino2(int i, int j)
{
	if (m_MinoShape == ShapeI)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 1;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 1;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeJ)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 1;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeL)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 1;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeO)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeS)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeT)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 1;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeZ)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 1;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}
	return m_Tetrimino[i][j];
}

int Mino::GetMino3(int i, int j)
{
	if (m_MinoShape == ShapeI)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 1;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 0;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 1;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeJ)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 1;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeL)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 1;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 0;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeO)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeS)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 1;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 1;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeT)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 1;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeZ)
	{
		m_Tetrimino[0][0] = 1;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}
	return m_Tetrimino[i][j];
}

int Mino::GetMino4(int i, int j)
{
	if (m_MinoShape == ShapeI)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 0;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 1;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 1;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeJ)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 1;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeL)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 1;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 1;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeO)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeS)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeT)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 1;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoShape == ShapeZ)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 1;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}
	return m_Tetrimino[i][j];
}

int Mino::NextGetMino(int i, int j)
{
	if (m_NextMinoShape == ShapeI)
	{
		//m_MinoShapes = ShapeI;
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 1;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_NextMinoShape == ShapeJ)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 1;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 0;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_NextMinoShape == ShapeL)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_NextMinoShape == ShapeO)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_NextMinoShape == ShapeS)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 1;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_NextMinoShape == ShapeT)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_NextMinoShape == ShapeZ)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 1;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	return m_Tetrimino[i][j];
}
