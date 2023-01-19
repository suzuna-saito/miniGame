#pragma once
#include "Object.h"
#include "game.h"

/*
* プレイヤーが行動できるエリア生成/処理/描画
*/
class Area :public Object
{
public:
    // コンストラクタ
    Area();
    // デストラクタ
    ~Area();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update(float _deltaTime)override;
    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw()override;

    static Vector2 mHitPos;        // エリアの当たり判定ポジション
    static Vector2 mHitSize;       // エリアの当たり判定サイズ

private:
    const int MAreaAdjustedDistance; // エリアとの押し戻しの際に少し距離を開けるための値
};