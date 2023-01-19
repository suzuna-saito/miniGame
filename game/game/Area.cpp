#include "Area.h"

// 静的メンバ変数の初期化
Object::Vector2 Area::mHitPos = { 0.0f };   // エリアの当たり判定ポジション
Object::Vector2 Area::mHitSize = { 0.0f };  // エリアの当たり判定

Area::Area()
    : Object()
    , MAreaAdjustedDistance(10.0f)
{
    // 基底クラス変数の設定
    mPos = { 300.0f,50.0f };                                     // エリアの左上頂点ポジション
    mSize = { game::MWidth - mPos.x,game::MHeight - mPos.y };    // エリアのサイズ

    mHitPos = { mPos.x + MAreaAdjustedDistance,mPos.y + MAreaAdjustedDistance };
    mHitSize = { mSize.x - MAreaAdjustedDistance,mSize.y - MAreaAdjustedDistance };
}

Area::~Area()
{
}

void Area::Update(float _deltaTime)
{
}

void Area::Draw()
{
    // エリアの描画
    DrawBox(mPos.x, mPos.y, mSize.x, mSize.y, GetColor(40, 40, 40), TRUE);      // 灰色の塗りつぶしエリア
    DrawBox(mPos.x, mPos.y, mSize.x, mSize.y, GetColor(255, 255, 255), FALSE);  // エリアをかこっている白い線

    mHitPos = { mPos.x + MAreaAdjustedDistance,mPos.y + MAreaAdjustedDistance };
    mHitSize = { mSize.x - MAreaAdjustedDistance,mSize.y - MAreaAdjustedDistance };
}