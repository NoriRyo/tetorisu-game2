#include "Field.h"
#include "SceneBase.h"
#include "Mino.h"
#include <Dxlib.h>

namespace
{
	constexpr int kLengthNum = 20;	//　フィールドの高さのマス
	constexpr int kSideNum = 10;	//　フィールドの横のマス

	constexpr int kFieldHeight = 50;	// フィールドの高さ位置
	constexpr int kFieldWidth = 200;	// フィールドの横位置

	constexpr int NotExist = 0;	// ミノが存在しない
	constexpr int Exist = 1;	// ミノが存在する
}

Field::Field() :
	m_MinoSize(20),		// ミノサイズ
	m_MinoNum(0),		// ミノ番号
	m_fallFlame(0),		// 落下速度
	m_TensPlaceNum(0),	// 十の位
	m_OnesPlaceNum(0),	// 一の位
	m_SwitchMinoFlame(60),
	m_IsRightPressBotton(false),
	m_IsLeftPressBotton(false),
	m_IsUpPressBotton(false),
	m_ColumnMinoNum(0),
	m_ExistColumnMino(false),
	m_BottomMino(false),
	m_FirstMino(true),
	m_ExistMinoNum(0),
	m_rota1(false),
	m_rota2(false),
	m_rota3(false),
	m_rota4(false),
	m_MinusMino(false),
	m_End(false)
{
	m_hBg = LoadGraph("Data/titleBg1.jpg");
	m_func = &Field::updateAppear;


	//　ミノのフィールド情報
	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_ActiveFieldNum[i][j] = NotExist;
		}
	}

	//　動いてるミノ情報
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_ActiveMinoNum[i][j] = NotExist;
		}
	}

	//　次のミノ情報
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_NextActiveMinoNum[i][j] = NotExist;
		}
	}

	//　フィールドの情報
	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_FieldNum[i][j] = NotExist;
		}
	}

	//　ミノが消えた時の処理
	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_VirtualFieldNum[i][j] = 0;
		}
	}

	mino = new Mino;
}

Field::~Field()
{
	delete mino;
	mino = nullptr;
}

void Field::init()
{
	m_MinoSize = 20;		// ミノサイズ
	m_MinoNum = 0;			// ミノ番号
	m_fallFlame = 0;
	m_TensPlaceNum = 0;	// 十の位
	m_OnesPlaceNum = 0;	// 一の位
	m_SwitchMinoFlame = 60;
	m_IsRightPressBotton = false;
	m_IsLeftPressBotton = false;
	m_IsUpPressBotton = false;
	m_ColumnMinoNum = 0;
	m_ExistColumnMino = false;
	m_BottomMino = false;
	m_FirstMino = true;
	m_ExistMinoNum = 0;
	m_rota1 = false;
	m_rota2 = false;
	m_rota3 = false;
	m_rota4 = false;
	m_MinusMino = false;
	m_End = false;

	m_hBg = LoadGraph("Data/titleBg1.jpg");
	m_func = &Field::updateAppear;

	//m_Collar = &Mino::SetMinoCollar;

	//　ミノのフィールド情報
	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_ActiveFieldNum[i][j] = NotExist;
		}
	}

	//　動いてるミノ情報
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_ActiveMinoNum[i][j] = NotExist;
		}
	}

	//　次のミノ情報
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_NextActiveMinoNum[i][j] = NotExist;
		}
	}

	//　フィールドの情報
	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_FieldNum[i][j] = NotExist;
		}
	}

	//　ミノが消えた時の処理
	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_VirtualFieldNum[i][j] = 0;
		}
	}

	mino = new Mino;
}

void Field::end()
{
}

SceneBase* Field::update()
{
	// 終了の処理
	if (m_End)
	{
		//　リスタート
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			init();
			m_End = false;
		}
	}
	if (!m_End)
	{
		m_TensPlaceNum = m_MinoNum / 10;	// 十の位
		m_OnesPlaceNum = m_MinoNum % 10;	// 一の位


		if (IsActive())
		{
			rotationMino();

			if (m_fallFlame >= 60 && m_SwitchMinoFlame == NotExist)
			{
				for (int i = 0; i < Column; i++)
				{
					for (int j = 0; j < Side; j++)
					{
						if (m_ActiveMinoNum[i][j] == Exist)
						{
							m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = NotExist;
						}
					}
				}

				m_MinoNum += 10;

				m_TensPlaceNum = m_MinoNum / 10;
				m_OnesPlaceNum = m_MinoNum % 10;

				m_fallFlame = 0;
			}

			else if (m_SwitchMinoFlame < 60)
			{
				(this->*m_func)();
			}

			m_TensPlaceNum = m_MinoNum / 10;	// 十の位
			m_OnesPlaceNum = m_MinoNum % 10;	// 一の位

			MoveMino();

			m_TensPlaceNum = m_MinoNum / 10;	// 十の位
			m_OnesPlaceNum = m_MinoNum % 10;	// 一の位

			for (int i = 0; i < Column; i++)
			{
				for (int j = 0; j < Side; j++)
				{
					if (m_ActiveMinoNum[i][j] == 1)
					{
						m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = Exist;
					}
				}
			}

			m_fallFlame++;
		}

		if (!IsActive())
		{
			m_SwitchMinoFlame = 0;

			// m_ActiveFieldNumが1でm_FieldNumが0のときm_FieldNumに1を代入する
			for (int i = 0; i < kLengthNum; i++)
			{
				for (int j = 0; j < kSideNum; j++)
				{
					if (m_ActiveFieldNum[i][j] == Exist && m_FieldNum[i][j] == NotExist)
					{
						m_FieldNum[i][j] = Exist;
					}
				}
			}

			// ミノが出現するところにミノがある場合
			if (m_FieldNum[0][4] == Exist || m_FieldNum[0][5] == Exist ||
				m_FieldNum[0][6] == Exist || m_FieldNum[0][7] == Exist)
			{
				m_End = true;
			}

			if (!m_End)
			{
				// ミノが横一列そろったときミノを消すフラグをtrueに
				for (int a = 0; a < 4; a++)
				{
					for (int i = 0; i < kLengthNum; i++)
					{
						if (m_ExistColumnMino)
						{
							break;
						}
						for (int j = 0; j < kSideNum; j++)
						{
							if (j == 0)
							{
								m_ColumnMinoNum = 0;
							}

							//　横一列にミノがあったらカウントする
							if (m_FieldNum[i][j] == Exist)
							{
								m_ColumnMinoNum++;
							}
							//　ミノがなかったらカウントを０にする
							else
							{
								m_ColumnMinoNum = 0;
								continue;
							}
							//　もしカウントが１０になったらその列のミノを消す
							if (m_ColumnMinoNum == 10)
							{
								for (int k = 0; k < kSideNum; k++)
								{
									m_FieldNum[i][k] = NotExist;
								}
								m_ExistColumnMino = true;
								m_ExistMinoNum = i;
							}

						}
					}

					// ミノが消えた時、消えたミノより上のミノを落とす処理
					if (m_ExistColumnMino)
					{
						for (int i = 0; i < kLengthNum; i++)
						{
							for (int j = 0; j < kSideNum; j++)
							{
								if (m_ExistMinoNum > i && m_FieldNum[i][j] == Exist)
								{
									m_VirtualFieldNum[i + 1][j] = 1;
								}

								if (m_ExistMinoNum < i && m_FieldNum[i][j] == Exist)
								{
									m_VirtualFieldNum[i][j] = 1;
								}
							}
						}

						for (int i = 0; i < kLengthNum; i++)
						{
							for (int j = 0; j < kSideNum; j++)
							{
								m_FieldNum[i][j] = m_VirtualFieldNum[i][j];
								m_VirtualFieldNum[i][j] = NotExist;
							}
						}
						m_ExistColumnMino = false;
					}
				}

				for (int i = 0; i < kLengthNum; i++)
				{
					for (int j = 0; j < kSideNum; j++)
					{
						m_ActiveFieldNum[i][j] = NotExist;
					}
				}

				m_rota1 = true;

				if (!m_FirstMino)
				{
					mino->SetMinoNow();
					mino->SetMino();
					for (int i = 0; i < Column; i++)
					{
						for (int j = 0; j < Side; j++)
						{
							m_ActiveMinoNum[i][j] = mino->GetMino1(i, j);
						}
					}
				}

				mino->NextUpdate();

				mino->NextSetMino();

				for (int i = 0; i < Column; i++)
				{
					for (int j = 0; j < Side; j++)
					{
						m_NextActiveMinoNum[i][j] = mino->NextGetMino(i, j);
					}
				}


				if (m_FirstMino)
				{
					mino->Update();

					mino->SetMino();

					for (int i = 0; i < Column; i++)
					{
						for (int j = 0; j < Side; j++)
						{
							m_ActiveMinoNum[i][j] = mino->GetMino1(i, j);
						}
					}
				}

				for (int i = 0; i < Column; i++)
				{
					for (int j = 0; j < Side; j++)
					{
						if (m_ActiveMinoNum[i][j] == 1)
						{
							m_ActiveFieldNum[i][j + 4] = Exist;
						}
					}
				}
				m_MinoNum = 4;
				m_FirstMino = false;
			}
		}
	}
	return this;
}

void Field::draw()
{
	// 背景の描写
	DrawGraph(0, 0, m_hBg, false);

	// ミノの色を取得
	m_MinoCollar = mino->m_MinoCollar;

	m_NextMinoCollar = mino->m_NextMinoCollar;

	//　フィールドの描写
	for (int i = -1; i <= kLengthNum; i++)
	{
		for (int j = -1; j <= kSideNum; j++)
		{
			if (i == kLengthNum || i == -1)
			{
				// 壁（上下）
				DrawBox(j * m_MinoSize + kFieldWidth, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + kFieldWidth, (i + 1) * m_MinoSize + kFieldHeight, GetColor(35, 59, 108), true);
			}
			if (j == -1 || j == kSideNum)
			{
				// 壁（サイド）
				DrawBox(j * m_MinoSize + kFieldWidth, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + kFieldWidth, (i + 1) * m_MinoSize + kFieldHeight, GetColor(35, 59, 108), true);
			}
		}
	}

	// nextブロックの描写
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			//　nextフィールドの背景描写
			DrawBox(j * m_MinoSize + 500, i * m_MinoSize + kFieldHeight,
				(j + 1) * m_MinoSize + 500, (i + 1) * m_MinoSize + kFieldHeight, GetColor(0, 0, 0), true);

			if (m_NextActiveMinoNum[i][j] == Exist)
			{
				// nextブロックの色
				DrawBox(j * m_MinoSize + 500, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + 500, (i + 1) * m_MinoSize + kFieldHeight, m_NextMinoCollar, true);
			}
			//　nextフィールドの線描写
			DrawBox(j * m_MinoSize + 500, i * m_MinoSize + kFieldHeight,
				(j + 1) * m_MinoSize + 500, (i + 1) * m_MinoSize + kFieldHeight, GetColor(0, 200, 0), false);
		}
	}


	//　メインブロックの描写
	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			if (m_FieldNum[i][j] == NotExist)
			{
				//　何もないマス(線)の描写
				DrawBox(j * m_MinoSize + kFieldWidth, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + kFieldWidth, (i + 1) * m_MinoSize + kFieldHeight, GetColor(105, 105, 105), false);
			}

			//　止まっているブロックの描写
			if (m_FieldNum[i][j] == Exist)
			{
				// ブロックの内側
				DrawBox(j * m_MinoSize + kFieldWidth, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + kFieldWidth, (i + 1) * m_MinoSize + kFieldHeight, GetColor(255, 255, 255), true);

				//　ブロックの外側
				DrawBox(j * m_MinoSize + kFieldWidth, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + kFieldWidth, (i + 1) * m_MinoSize + kFieldHeight, GetColor(0, 0, 0), false);
			}
			//　動いているブロックの描写
			if (m_ActiveFieldNum[i][j] == Exist)
			{
				// ブロックの内側
				DrawBox(j * m_MinoSize + kFieldWidth, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + kFieldWidth, (i + 1) * m_MinoSize + kFieldHeight, m_MinoCollar, true);

				//　ブロックの外側
				DrawBox(j * m_MinoSize + kFieldWidth, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + kFieldWidth, (i + 1) * m_MinoSize + kFieldHeight, GetColor(64, 64, 64), false);
			}
		}
	}

	if (m_End)
	{
		DrawString(460, 300, "ゲームオーバー", GetColor(0, 255, 0));

		DrawString(460, 200, "もう一度遊ぶ→SPACE", GetColor(0, 255, 0));
	}
}

void Field::updateAppear()
{
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		m_fallFlame += 15;
	}

	if (!CheckHitKey(KEY_INPUT_RIGHT))
	{
		m_IsRightPressBotton = false;
	}

	if (!CheckHitKey(KEY_INPUT_LEFT))
	{
		m_IsLeftPressBotton = false;
	}

	if (CheckHitKey(KEY_INPUT_RIGHT) && !m_IsRightPressBotton)
	{
		m_func = &Field::updateRight;
	}

	if (CheckHitKey(KEY_INPUT_LEFT) && !m_IsLeftPressBotton)
	{
		m_func = &Field::updateLeft;
	}

}

void Field::updateLeft()
{
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		m_fallFlame += 5;
	}

	if (!m_IsLeftPressBotton)
	{
		if (IsLeft())
		{
			m_MinusMino = true;
			m_MinoNum--;
		}

		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				if (m_ActiveMinoNum[i][j] == 1)
				{
					m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = NotExist;
				}
			}
		}
		//m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum] = 0;

		//m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum - 1] = 1;
	}
	m_IsLeftPressBotton = true;

	m_func = &Field::updateAppear;
}

void Field::updateRight()
{
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		m_fallFlame += 5;
	}

	if (!m_IsRightPressBotton)
	{
		if (IsRight())
		{
			m_MinusMino = false;
			m_MinoNum++;
		}

		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				if (m_ActiveMinoNum[i][j] == 1)
				{
					m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = NotExist;
				}
			}
		}

		//m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum] = 0;

		//m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum + 1] = 1;
	}

	m_IsRightPressBotton = true;

	//m_TensPlaceNum = m_MinoNum / 10;	// 十の位
	//m_OnesPlaceNum = m_MinoNum % 10;	// 一の位

	m_func = &Field::updateAppear;
}

// 動いているとき
bool Field::IsActive()
{
	if (m_FirstMino)
	{
		return false;
	}
	for (int i = 0; i < kLengthNum; i++)
	{
		if (m_BottomMino)
		{
			break;
		}

		for (int j = 0; j < kSideNum; j++)
		{
			if (m_ActiveFieldNum[kLengthNum - 1][j] == Exist)
			{
				m_BottomMino = true;
				break;
			}

			else if (m_ActiveFieldNum[i][j] == 1 && m_FieldNum[i + 1][j] == Exist)
			{
				m_BottomMino = true;
				break;
			}

			else
			{
				m_BottomMino = false;
			}
		}
	}

	if (m_BottomMino == true)
	{
		m_SwitchMinoFlame++;
	}

	if (m_BottomMino == false)
	{
		m_SwitchMinoFlame = 0;
	}

	if (m_SwitchMinoFlame >= 60)
	{
		m_BottomMino = false;
		return false;
	}
	return true;
}

bool Field::IsLeft()
{
	if (m_ActiveFieldNum[m_TensPlaceNum][0] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][0] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][0] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][0] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum] == Exist &&
		m_FieldNum[m_TensPlaceNum][m_OnesPlaceNum - 1] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum] == Exist &&
		m_FieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum - 1] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum] == Exist &&
		m_FieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum - 1] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum] == Exist &&
		m_FieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum - 1] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum + 1] == Exist &&
		m_FieldNum[m_TensPlaceNum][m_OnesPlaceNum] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 1] == Exist &&
		m_FieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 1] == Exist &&
		m_FieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 1] == Exist &&
		m_FieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum + 2] == Exist &&
		m_FieldNum[m_TensPlaceNum][m_OnesPlaceNum + 1] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 2] == Exist &&
		m_FieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 1] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 2] == Exist &&
		m_FieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 1] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 2] == Exist &&
		m_FieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 1] == Exist)
	{
		return false;
	}

	return true;
}

bool Field::IsRight()
{
	if (m_ActiveFieldNum[m_TensPlaceNum][9] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][9] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][9] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][9] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum + 3] == Exist &&
		m_FieldNum[m_TensPlaceNum][m_OnesPlaceNum + 4] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 3] == Exist &&
		m_FieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 4] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 3] == Exist &&
		m_FieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 4] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 3] == Exist &&
		m_FieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 4] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum + 2] == Exist &&
		m_FieldNum[m_TensPlaceNum][m_OnesPlaceNum + 3] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 2] == Exist &&
		m_FieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 3] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 2] == Exist &&
		m_FieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 3] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 2] == Exist &&
		m_FieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 3] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum + 1] == Exist &&
		m_FieldNum[m_TensPlaceNum][m_OnesPlaceNum + 2] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 1] == Exist &&
		m_FieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 2] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 1] == Exist &&
		m_FieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 2] == Exist)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 1] == Exist &&
		m_FieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 2] == Exist)
	{
		return false;
	}

	return true;
}

// 回転
void Field::rotationMino()
{
	if (CheckHitKey(KEY_INPUT_UP) && !m_IsUpPressBotton)
	{
		m_IsUpPressBotton = true;

		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = NotExist;
			}
		}

		if (m_rota1)
		{
			m_rota1 = false;
			m_rota2 = true;
			for (int i = 0; i < Column; i++)
			{
				for (int j = 0; j < Side; j++)
				{
					m_ActiveMinoNum[i][j] = mino->GetMino2(i, j);
				}
			}
		}

		else if (m_rota2)
		{
			m_rota2 = false;
			m_rota3 = true;
			for (int i = 0; i < Column; i++)
			{
				for (int j = 0; j < Side; j++)
				{
					m_ActiveMinoNum[i][j] = mino->GetMino3(i, j);
				}
			}
		}

		else if (m_rota3)
		{
			m_rota3 = false;
			m_rota4 = true;
			for (int i = 0; i < Column; i++)
			{
				for (int j = 0; j < Side; j++)
				{
					m_ActiveMinoNum[i][j] = mino->GetMino4(i, j);
				}
			}
		}

		else if (m_rota4)
		{
			m_rota4 = false;
			m_rota1 = true;
			for (int i = 0; i < Column; i++)
			{
				for (int j = 0; j < Side; j++)
				{
					m_ActiveMinoNum[i][j] = mino->GetMino1(i, j);
				}
			}
		}

		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				if (m_ActiveMinoNum[i][j] == Exist)
				{
					m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = Exist;
				}
			}
		}
	}
	else if (!CheckHitKey(KEY_INPUT_UP))
	{
		m_IsUpPressBotton = false;
	}
}

void Field::MoveMino()
{
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			if (m_ActiveMinoNum[i][j] == Exist)
			{
				m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = Exist;

				if (m_OnesPlaceNum + j >= 10 && !m_MinusMino)
				{
					m_MinoNum--;
				}

				if (m_FieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] == 1 && j >= 2)
				{
					m_MinoNum--;
				}

				for (int k = 0; k <= kLengthNum; k++)
				{
					if (m_ActiveFieldNum[k][0] == 1 && m_ActiveFieldNum[k + i][9] == 1 && m_MinusMino)
					{
						m_MinoNum++;
						break;
					}

					if (m_ActiveFieldNum[k + 1][0] == 1 && m_ActiveFieldNum[k + i][9] == 1 && m_MinusMino)
					{
						m_MinoNum++;
						break;
					}

					if (m_ActiveFieldNum[k + 2][0] == 1 && m_ActiveFieldNum[k + i][9] == 1 && m_MinusMino)
					{
						m_MinoNum++;
						break;
					}

					if (m_ActiveFieldNum[k + 3][0] == 1 && m_ActiveFieldNum[k + i][9] == 1 && m_MinusMino)
					{
						m_MinoNum++;
						break;
					}
				}

				if (m_FieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] == 1 && j < 2)
				{
					m_MinoNum++;
				}

				m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = NotExist;
			}
		}
	}
}
