#include "Field.h"
#include "SceneBase.h"
#include "Mino.h"
#include <Dxlib.h>

namespace
{
	constexpr int kLengthNum = 20;	//�@�t�B�[���h�̍����̃}�X
	constexpr int kSideNum = 10;	//�@�t�B�[���h�̉��̃}�X

	constexpr int kFieldHeight = 50;	// �t�B�[���h�̍����ʒu
	constexpr int kFieldWidth = 200;	// �t�B�[���h�̉��ʒu

	constexpr int NotExist = 0;	// �~�m�����݂��Ȃ�
	constexpr int Exist = 1;	// �~�m�����݂���
}

Field::Field() :
	m_MinoSize(20),		// �~�m�T�C�Y
	m_MinoNum(0),		// �~�m�ԍ�
	m_fallFlame(0),		// �������x
	m_TensPlaceNum(0),	// �\�̈�
	m_OnesPlaceNum(0),	// ��̈�
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


	//�@�~�m�̃t�B�[���h���
	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_ActiveFieldNum[i][j] = NotExist;
		}
	}

	//�@�����Ă�~�m���
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_ActiveMinoNum[i][j] = NotExist;
		}
	}

	//�@���̃~�m���
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_NextActiveMinoNum[i][j] = NotExist;
		}
	}

	//�@�t�B�[���h�̏��
	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_FieldNum[i][j] = NotExist;
		}
	}

	//�@�~�m�����������̏���
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
	m_MinoSize = 20;		// �~�m�T�C�Y
	m_MinoNum = 0;			// �~�m�ԍ�
	m_fallFlame = 0;
	m_TensPlaceNum = 0;	// �\�̈�
	m_OnesPlaceNum = 0;	// ��̈�
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

	//�@�~�m�̃t�B�[���h���
	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_ActiveFieldNum[i][j] = NotExist;
		}
	}

	//�@�����Ă�~�m���
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_ActiveMinoNum[i][j] = NotExist;
		}
	}

	//�@���̃~�m���
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_NextActiveMinoNum[i][j] = NotExist;
		}
	}

	//�@�t�B�[���h�̏��
	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_FieldNum[i][j] = NotExist;
		}
	}

	//�@�~�m�����������̏���
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
	// �I���̏���
	if (m_End)
	{
		//�@���X�^�[�g
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			init();
			m_End = false;
		}
	}
	if (!m_End)
	{
		m_TensPlaceNum = m_MinoNum / 10;	// �\�̈�
		m_OnesPlaceNum = m_MinoNum % 10;	// ��̈�


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

			m_TensPlaceNum = m_MinoNum / 10;	// �\�̈�
			m_OnesPlaceNum = m_MinoNum % 10;	// ��̈�

			MoveMino();

			m_TensPlaceNum = m_MinoNum / 10;	// �\�̈�
			m_OnesPlaceNum = m_MinoNum % 10;	// ��̈�

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

			// m_ActiveFieldNum��1��m_FieldNum��0�̂Ƃ�m_FieldNum��1��������
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

			// �~�m���o������Ƃ���Ƀ~�m������ꍇ
			if (m_FieldNum[0][4] == Exist || m_FieldNum[0][5] == Exist ||
				m_FieldNum[0][6] == Exist || m_FieldNum[0][7] == Exist)
			{
				m_End = true;
			}

			if (!m_End)
			{
				// �~�m������񂻂�����Ƃ��~�m�������t���O��true��
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

							//�@�����Ƀ~�m����������J�E���g����
							if (m_FieldNum[i][j] == Exist)
							{
								m_ColumnMinoNum++;
							}
							//�@�~�m���Ȃ�������J�E���g���O�ɂ���
							else
							{
								m_ColumnMinoNum = 0;
								continue;
							}
							//�@�����J�E���g���P�O�ɂȂ����炻�̗�̃~�m������
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

					// �~�m�����������A�������~�m����̃~�m�𗎂Ƃ�����
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
	// �w�i�̕`��
	DrawGraph(0, 0, m_hBg, false);

	// �~�m�̐F���擾
	m_MinoCollar = mino->m_MinoCollar;

	m_NextMinoCollar = mino->m_NextMinoCollar;

	//�@�t�B�[���h�̕`��
	for (int i = -1; i <= kLengthNum; i++)
	{
		for (int j = -1; j <= kSideNum; j++)
		{
			if (i == kLengthNum || i == -1)
			{
				// �ǁi�㉺�j
				DrawBox(j * m_MinoSize + kFieldWidth, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + kFieldWidth, (i + 1) * m_MinoSize + kFieldHeight, GetColor(35, 59, 108), true);
			}
			if (j == -1 || j == kSideNum)
			{
				// �ǁi�T�C�h�j
				DrawBox(j * m_MinoSize + kFieldWidth, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + kFieldWidth, (i + 1) * m_MinoSize + kFieldHeight, GetColor(35, 59, 108), true);
			}
		}
	}

	// next�u���b�N�̕`��
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			//�@next�t�B�[���h�̔w�i�`��
			DrawBox(j * m_MinoSize + 500, i * m_MinoSize + kFieldHeight,
				(j + 1) * m_MinoSize + 500, (i + 1) * m_MinoSize + kFieldHeight, GetColor(0, 0, 0), true);

			if (m_NextActiveMinoNum[i][j] == Exist)
			{
				// next�u���b�N�̐F
				DrawBox(j * m_MinoSize + 500, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + 500, (i + 1) * m_MinoSize + kFieldHeight, m_NextMinoCollar, true);
			}
			//�@next�t�B�[���h�̐��`��
			DrawBox(j * m_MinoSize + 500, i * m_MinoSize + kFieldHeight,
				(j + 1) * m_MinoSize + 500, (i + 1) * m_MinoSize + kFieldHeight, GetColor(0, 200, 0), false);
		}
	}


	//�@���C���u���b�N�̕`��
	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			if (m_FieldNum[i][j] == NotExist)
			{
				//�@�����Ȃ��}�X(��)�̕`��
				DrawBox(j * m_MinoSize + kFieldWidth, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + kFieldWidth, (i + 1) * m_MinoSize + kFieldHeight, GetColor(105, 105, 105), false);
			}

			//�@�~�܂��Ă���u���b�N�̕`��
			if (m_FieldNum[i][j] == Exist)
			{
				// �u���b�N�̓���
				DrawBox(j * m_MinoSize + kFieldWidth, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + kFieldWidth, (i + 1) * m_MinoSize + kFieldHeight, GetColor(255, 255, 255), true);

				//�@�u���b�N�̊O��
				DrawBox(j * m_MinoSize + kFieldWidth, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + kFieldWidth, (i + 1) * m_MinoSize + kFieldHeight, GetColor(0, 0, 0), false);
			}
			//�@�����Ă���u���b�N�̕`��
			if (m_ActiveFieldNum[i][j] == Exist)
			{
				// �u���b�N�̓���
				DrawBox(j * m_MinoSize + kFieldWidth, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + kFieldWidth, (i + 1) * m_MinoSize + kFieldHeight, m_MinoCollar, true);

				//�@�u���b�N�̊O��
				DrawBox(j * m_MinoSize + kFieldWidth, i * m_MinoSize + kFieldHeight,
					(j + 1) * m_MinoSize + kFieldWidth, (i + 1) * m_MinoSize + kFieldHeight, GetColor(64, 64, 64), false);
			}
		}
	}

	if (m_End)
	{
		DrawString(460, 300, "�Q�[���I�[�o�[", GetColor(0, 255, 0));

		DrawString(460, 200, "������x�V�ԁ�SPACE", GetColor(0, 255, 0));
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

	//m_TensPlaceNum = m_MinoNum / 10;	// �\�̈�
	//m_OnesPlaceNum = m_MinoNum % 10;	// ��̈�

	m_func = &Field::updateAppear;
}

// �����Ă���Ƃ�
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

// ��]
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
