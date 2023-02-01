#include "Result.h"

Result::Result()
    : SceneBase(SceneBase::Scene::eResult)
{
	const char* text = "";

	if (SceneBase::mNowGameType == SceneBase::NowGameType::eGameClear)
	{
		text = "ゲームクリアです";
	}
	else if (SceneBase::mNowGameType == SceneBase::NowGameType::eGameOver)
	{
		text = "ゲームオーバーです";
	}

	new Text(text);
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
