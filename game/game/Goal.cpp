#include "Goal.h"

Goal::Goal()
    : Object()
    , MMaxAlpha(255)
    , MMinAlpha(150)
    , mNowAlpha(255)
    , mAddAlpha(2)
{
    // 基底クラス変数の設定
    mSize = { 70.0f,70.0f };	// サイズ
    mPos = { game::MWidth / 2.0f - mSize.x / 2.0f ,Area::mHitPos.y + 30.0f };			// ポジション（画面真ん中にくる)
}

Goal::~Goal()
{
}

void Goal::Update(float _deltaTime)
{
    // 現在のα値が最大値より大きくなるか、最小値より小さくなった時
    if (mNowAlpha >= MMaxAlpha || mNowAlpha <= MMinAlpha)
    {
        // 増加値の符号を反対にする
        mAddAlpha *= -1;
    }

    mNowAlpha += mAddAlpha;
}

void Goal::Draw()
{
    // 描画ブレンドモードをαブレンドにする
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, mNowAlpha);
    DrawBoxAA(mPos.x, mPos.y, mPos.x + mSize.x, mPos.y + mSize.y, GetColor(50, 150, 255), TRUE);

    // 描画ブレンドモードをノーブレンドにする
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
