#pragma once
#include "Object.h"

/*
* 障害物生成/処理/描画
*/
class Obstacle :public Object
{
public:
    // コンストラクタ
    Obstacle(const int _num);
    // デストラクタ
    ~Obstacle();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update(float _deltaTime)override;
    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw()override;
};