#include "InputKey.h"

// 自身のインスタンスの初期化
InputKey* InputKey::mInputKey = nullptr;

InputKey::InputKey()
{
}

void InputKey::CreateInstance()
{
    // InputKeyを生成していなかったら
    if (mInputKey == nullptr)
    {
        mInputKey = new InputKey();  // インスタンスを生成
    }
}

void InputKey::DeleteInstance()
{
    if (mInputKey != nullptr)
    {
        delete mInputKey;                // 削除
        mInputKey = nullptr;
    }
}

void InputKey::TmpKeyUpdate()
{
    // ゲーム中に使用したキーすべて調べる
    for (auto key : mInputKey->mUseKey)
    {
        // 特定のキーが押されていたら1、押されてなければ0が入る
        mInputKey->mTmp[key] = CheckHitKey(key);
    }
}

InputKey::InputState InputKey::CheckInput(int _key)
{
    // 引数のキーの現在の入力状態を調べる
    int nowHitKey = CheckHitKey(_key);

    if (nowHitKey == 1)
    {
        printf("");
    }

    // コンテナの中に対象のキーがあるかを探す
    auto iter = std::find(mInputKey->mUseKey.begin(), mInputKey->mUseKey.end(), _key);
    // 対象のキーが無ければ
    if (iter == mInputKey->mUseKey.end())
    {
        // コンテナに対象のキーを追加
        mInputKey->mUseKey.emplace_back(_key);
        // キーが押されていたら
        if (nowHitKey == 1)
        {
            // ステートを押した瞬間にする
            return InputState::ePushMoment;

        }
    }
    // 対象のキーがあれば
    else
    {
        // 対象のキーが前フレームで押されてなければかつ、現在押していれば
        if (mInputKey->mTmp[_key] == 0 && nowHitKey == 1)
        {
            // ステートを押した瞬間にする
            return InputState::ePushMoment;
        }
        // 対象のキーが前フレームで押されていてかつ、現在押していれば
        else if(mInputKey->mTmp[_key] == 1 && nowHitKey == 1)
        {
            // ステートを押してるにする
            return InputState::ePushing;
        }
        else
        {
            // ステートを押していないにする
            return InputState::eNone;
        }
    }
}
