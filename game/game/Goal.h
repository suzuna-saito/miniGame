#pragma once
#include "Object.h"
#include "game.h"

/*
* ゴールを生成/処理/描画
*/
class Goal :public Object
{
public:
    // コンストラクタ
    Goal();
    // デストラクタ
    ~Goal();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update(float _deltaTime)override;
    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw()override;

private:
    const int MMaxAlpha;    // α値の最大値
    const int MMinAlpha;    // α値の最小値
    int mNowAlpha;          // 現在のα値
    int mAddAlpha;          // α値の増加値
};