#include "Result.h"

Result::Result()
    : SceneBase(SceneBase::Scene::eResult)
{
	new Text();
}

Result::~Result()
{
}

SceneBase::Scene Result::Update()
{
	// スペースボタンが押されたらシーンを遷移する
	if (InputKey::CheckInput(KEY_INPUT_SPACE) == InputKey::InputState::ePushMoment)
	{
		return Scene::eTitle;
	}

	// シーン遷移条件を満たしていなかったら今のタグを返す
	return mIsSceneTag;
}
