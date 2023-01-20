#pragma once
#include "DxLib.h"
#include <vector>
#include <map>

/*
* 入力関係の処理
*/
class InputKey
{
private:
	// コンストラクタ
	InputKey();
	// デストラクタ
	~InputKey() {};

public:
	// 入力状態
	enum class InputState :unsigned char
	{
		eNone,			// 押してない
		ePushMoment,	// 押した瞬間
		ePushing,		// 押してる
	};

	// インスタンスを作成する
	static void CreateInstance();
	// インスタンスを削除する
	static void DeleteInstance();

	// フレーム毎の処理(tmpの更新)
	static void TmpKeyUpdate();

	/// <summary>
	/// 入力状態を調べる
	/// </summary>
	/// <param name="_key">入力状態を調べたいキー</param>
	/// <returns>入力状態を返す</returns>
	static InputState CheckInput(int _key);

private:
	static InputKey* mInputKey;	// InputKeyの実体

	std::vector<int> mUseKey;	// ゲーム中使用したキー
	std::map<int, int> mTmp;	// ゲーム中に使用したキーの入力状態を保持
};