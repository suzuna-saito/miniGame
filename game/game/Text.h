#pragma once
#include "Object.h"
#include "SceneBase.h"

class Text :public Object
{
public:
    // コンストラクタ
    Text();
    // デストラクタ
    ~Text();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update(float _deltaTime)override;
    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw()override;

private:
    const char* mText;
};