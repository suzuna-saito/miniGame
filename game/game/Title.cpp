#include "Title.h"

Title::Title()
	: SceneBase(SceneBase::Scene::eTitle)
{
	// 現在のゲームタイプをプレイに更新
	mNowGameType = NowGameType::eGamePlay;

	new Text("これはタイトルです");
}

Title::~Title()
{
}

SceneBase::Scene Title::Update()
{
	// スペースボタンが押された瞬間だったらシーンを遷移する
	if (InputKey::CheckInput(KEY_INPUT_SPACE) == InputKey::InputState::ePushMoment)
	{
		return Scene::ePlay;
	}

	// シーン遷移条件を満たしていなかったら今のタグを返す
	return mIsSceneTag;
}