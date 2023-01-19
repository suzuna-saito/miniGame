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
	// �f���^�^�C���𐧌�
	if (mDeltaTime >= 0.10f)
	{
		mDeltaTime = 0.10f;
	}

	mBeforeTickCount = GetNowCount();
}

void Fps::Wait()
{
	int aiu = GetNowCount();
	// ���ݒl��1�t���[���ɂ����鎞�Ԃ𒴂���܂ŌJ��Ԃ�
	while (GetNowCount() < mBeforeTickCount + MOneFrameTickCount);
}