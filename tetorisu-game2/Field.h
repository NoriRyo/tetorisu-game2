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

	bool IsLeft();	//　左

	bool IsRight();	//　右

	void rotationMino();	//　回転

	void MoveMino();		//　動き

	//bool columnExist();
private:
	void updateAppear();	// 登場
	void updateLeft();		// 左に移動
	void updateRight();		// 右に移動

private:
	// 背景
	int m_hBg;

	// フィールドサイズ
	int m_MinoSize;

	// 今動いているミノのフィールド情報（0,1）
	int m_ActiveFieldNum[23][10];

	// 今動いているミノの情報（0,1）
	int m_ActiveMinoNum[Column][Side];

	// 次に動くミノの情報（0,1）
	int m_NextActiveMinoNum[Column][Side];

	// フィールドの情報（0,1）
	int m_FieldNum[20][10];

	// ミノが消えた時の置き換え
	int m_VirtualFieldNum[20][10];

	// テトリミノ番号
	int m_MinoNum;
	// テトリミノの十の位の番号
	int m_TensPlaceNum;
	// テトリミノの一の位の番号
	int m_OnesPlaceNum;

	// テトリミノの落ちる速度
	int m_fallFlame;

	// テトリミノが切り替わる時間
	int m_SwitchMinoFlame;

	bool m_IsRightPressBotton;	// 右ボタン
	bool m_IsLeftPressBotton;	// 左ボタン
	bool m_IsUpPressBotton;		// 上ボタン

	// 横一列のミノの数
	int m_ColumnMinoNum;

	// 横一列にすべてミノが存在するかどうか
	bool m_ExistColumnMino;

	// アクティブミノの下にミノが存在するとき
	bool m_BottomMino;

	// 最初に出されるミノのとき
	bool m_FirstMino;

	// 何列目のミノがそろったか
	int m_ExistMinoNum;

	// 何回目の回転か
	bool m_rota1;	//　1回目
	bool m_rota2;	//　2回目
	bool m_rota3;	//　3回目
	bool m_rota4;	//　4回目

	// ミノの色
	int m_MinoCollar;
	// 次のミノの色
	int m_NextMinoCollar;

	bool m_MinusMino;	//　マイナスミノ

	bool m_End;		// 終了

	// update処理メンバ関数ポインタ
	void(Field::* m_func)();

	Mino* mino;
};

