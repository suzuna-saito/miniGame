#include "Player.h"

Player::Player(std::vector<class Obstacle*> _obstacles , class Goal* _goal)
    : Object()
	, mObstacles(_obstacles)
	, mGoal(_goal)
	, MMaxHitTime(80)
	, mHitCount(0)
	, mHitFlag(false)
{
    // 基底クラス変数の設定
	mSize = { 70.0f,70.0f };	// サイズ
	mPos = { game::MWidth / 2.0f - mSize.x / 2.0f ,Area::mHitSize.y - mSize.y - 30.0f }; // ポジション（画面真ん中下にくる)
    mMoveSpeed = 500.0f;		// 移動速度

	// 初期ポジションの設定
	mInitPos = mPos;

	// 残機の生成
	new HP(this);
}

Player::~Player()
{
}

void Player::InputUpdate()
{
	// mMovePos（移動位置）を0に戻す。
	mMovePos = { 0.0f };

	// プレイヤーが点滅中（当たってから一定時間経過していなかったら）ぬける
	if (mHitCount != 0)
	{
		return;
	}

	// 左
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		mMovePos.x = mMoveSpeed;
	}
	// 右
	else if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		mMovePos.x = -mMoveSpeed;
	}
	// 上
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		mMovePos.y = -mMoveSpeed;
	}
	// 下
	else if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		mMovePos.y = mMoveSpeed;
	}
}

void Player::Update(float _deltaTime)
{
	// ポジションの更新
	// @@ Vector2の+=の演算子のオーバーライド作りたい
	mPos.x += mMovePos.x * _deltaTime;
	mPos.y += mMovePos.y * _deltaTime;

	// エリアとの当たり判定かつ、押し戻し処理
	AreaHitCheck(this);

	// 当たり判定
	// 無敵時間じゃないかつ、障害物に当たっていたらフラグをtrueにする
	if (mHitCount == 0)
	{
		for (auto obstacle : mObstacles)
		{
			if (HitCheck(this, obstacle))
			{
				mHitFlag = true;
				mPos = mInitPos;
				break;
			}
		}
	}
	else
	{
		// 障害物に当たっていない
		mHitFlag = false;
	}

	// 当たった瞬間または無敵時間中だったら
	if (mHitFlag || mHitCount != 0)
	{
		// 障害物に当たってからの時間をカウント
		++mHitCount;

		// カウントが最大経過時間を超えたらカウントを0に戻す
		if (mHitCount > MMaxHitTime)
		{
			mHitCount = 0;
		}
	}

	// ゴールまでたどりついたら現在のゲームタイプをクリアにする
	if (HitCheck(this, mGoal))
	{
		SceneBase::mNowGameType = SceneBase::NowGameType::eGameClear;
	}
}

void Player::Draw()
{
	// プレイヤーの描画
	// 障害物に当たった時は点滅させる
	if (mHitCount % 2 == 0)
	{
		DrawBoxAA(mPos.x, mPos.y, mPos.x + mSize.x, mPos.y + mSize.y, GetColor(50, 150, 255), TRUE);
	}
}
