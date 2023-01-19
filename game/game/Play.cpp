#include "Play.h"

Play::Play()
    : SceneBase(SceneBase::Scene::ePlay)
{
}

Play::~Play()
{
}

SceneBase::Scene Play::Update()
{
	// シーン遷移条件(エンターを押すと遷移（仮）)
	if (mSceneTransitionFlag)
	{
		// 条件を満たしていたらリザルトシーンを生成してそのポインタを返す
		return Scene::eResult;
	}

	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return mIsSceneTag;
}
