#include "Fps.h"

Fps::Fps()
	: MSetFps(60)
	, MOneFrameTickCount(1000 / MSetFps)
	, mBeforeTickCount(0)
	, mDeltaTime(0)
{
}

void Fps::Update()
{
	Wait();

	mDeltaTime = (GetNowCount() - mBeforeTickCount) / 1000.0f;
	// デルタタイムを制御
	if (mDeltaTime >= 0.10f)
	{
		mDeltaTime = 0.10f;
	}

	mBeforeTickCount = GetNowCount();
}

void Fps::Wait()
{
	int aiu = GetNowCount();
	// 現在値が1フレームにかける時間を超えるまで繰り返す
	while (GetNowCount() < mBeforeTickCount + MOneFrameTickCount);
}