#include "Title.h"

Title::Title()
	: SceneBase(SceneBase::Scene::eTitle)
{
}

Title::~Title()
{
}

SceneBase::Scene Title::Update()
{
	// 遷移フラグが上がっていたら
	if (mSceneTransitionFlag)
	{
		// 条件を満たしていたらプレイシーンを生成してそのポインタを返す
		return Scene::ePlay;
	}

	// シーン遷移条件を満たしていなかったら今のポインタを返す
	return mIsSceneTag;
}