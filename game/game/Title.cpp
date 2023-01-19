#include "Title.h"

Title::Title()
	: SceneBase(SceneBase::Scene::eTitle)
{
	new Text();
}

Title::~Title()
{
}

SceneBase::Scene Title::Update()
{
	// スペースボタンが押されたらシーンを遷移する
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		return Scene::ePlay;
	}

	// シーン遷移条件を満たしていなかったら今のタグを返す
	return mIsSceneTag;
}