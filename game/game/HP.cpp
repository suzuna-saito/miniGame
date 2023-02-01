#include "HP.h"

HP::HP(Player* _owner)
	: Object()
	, MFontHandle(CreateFontToHandle("Bookshelf Symbol 7",80,5, DX_FONTTYPE_ANTIALIASING)) // 書式、サイズ、太さ
	, MDrawDistance(100)
	, mPlayer(_owner)
	, mHP(3)
{
	// 基底クラス変数の設定
	mPos = Area::mHitPos;    // ポジション
}

HP::~HP()
{
}

void HP::Update(float _deltaTime)
{
	// プレイヤーが障害物に当たった瞬間残基を減らす
	if (mPlayer->GetHitFlag())
	{
		--mHP;
	}

	// HPが0になったらゲームオーバーにする
	if (mHP == 0)
	{
		SceneBase::mNowGameType = SceneBase::NowGameType::eGameOver;
	}
}

void HP::Draw()
{
	// 残基の描画
	for (int i = 0; i < mHP; ++i)
	{
		// wって書いてるけどこれはハートです
		DrawStringToHandle((int)mPos.x + MDrawDistance * i, (int)mPos.y,
			"w", GetColor(255, 255, 255), MFontHandle);
	}
}