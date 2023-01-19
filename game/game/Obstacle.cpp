#include "Obstacle.h"
#include "Area.h"

Obstacle::Obstacle(const int _num)
{
    // 基底クラス変数の設定
    mSize = { 50.0f , 50.0f };                                // サイズ
    mPos = { Area::mHitPos.x , 300.0f + (200.0f * _num) };    // ポジション(エリアの左はじ)
    mMoveSpeed = 700.0f;                                      // 移動スピード

    // 生成ナンバーが奇数だったらポジションと移動値を逆にする
    if (_num % 2)
    {
        mPos.x = Area::mHitSize.x - mSize.x;
        mMoveSpeed *= -1;
    }
}

Obstacle::~Obstacle()
{
}

void Obstacle::Update(float _deltaTime)
{
    // ポジションを横に移動させる
    mPos.x += mMoveSpeed* _deltaTime;

    // エリアに当たったら移動方向を逆にする
    if (AreaHitCheck(this))
    {
        mMoveSpeed *= -1;
    }
}

void Obstacle::Draw()
{
    // 障害物の描画
    DrawBoxAA(mPos.x, mPos.y, mPos.x + mSize.x, mPos.y + mSize.y, GetColor(255, 150, 50), FALSE);
}