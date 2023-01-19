#include "DxLib.h"
#include "game.h"
#include "SceneTitle.h"
#include "Field.h"
#include "Pad.h"


namespace
{
	// �\�����镶����
	const char* const kTitleText = "�e�g���X";
	const char* const kGuideText = "1�{�^��( Z )�������Ă�������";
	// ������_��
	constexpr int kTextDispFrame = 50;
	constexpr int kTextHideFrame = 15;

	// �����F
	const int kTitleFontColor = GetColor(255, 0, 0);

	const int kFontColor = GetColor(255, 255, 255);

}

void SceneTitle::init()
{
	m_textBlinkFrame = 0;
	SetFontSize(32);

	m_hBg = LoadGraph("Data/titleBg1.jpg");
}

void SceneTitle::end()
{
	SetFontSize(16);
}

SceneBase* SceneTitle::update()
{
	/// �f�o�b�N�p ///
	//return (new Field);

	if (isFading())
	{
		bool isOut = isFadingOut();
		SceneBase::updateFade();
		// �t�F�[�h�A�E�g�I�����ɃV�[���؂�ւ�
		if (!isFading() && isOut)
		{
			return (new Field);
		}
	}
	// �e�L�X�g�̓_��
	m_textBlinkFrame++;
	if (m_textBlinkFrame >= kTextDispFrame + kTextHideFrame)
	{
		m_textBlinkFrame = 0;
	}
	if (!isFading())
	{
		if (CheckHitKey(KEY_INPUT_Z))
		{
			// �t�F�[�h�A�E�g�J�n
			startFadeOut();
		}
	}
	return this;
}

void SceneTitle::draw()
{
	// �w�i�̕`��
	DrawGraph(0, 0, m_hBg, false);

	//�@�^�C�g���̕`��
	int width = GetDrawStringWidth(kTitleText, static_cast<int>(strlen(kTitleText)));
	DrawString(Game::kScreenWidth / 2 - width / 2, 160, kTitleText, kTitleFontColor);

	//�@�K�C�h�̕`��
	if (m_textBlinkFrame < kTextDispFrame)
	{
		width = GetDrawStringWidth(kGuideText, static_cast<int>(strlen(kGuideText)));
		DrawString(Game::kScreenWidth / 2 - width / 2, 280, kGuideText, kFontColor);
	}

	SceneBase::drawFade();
}