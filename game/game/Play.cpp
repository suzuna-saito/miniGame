#include "Play.h"

Play::Play()
    : SceneBase(SceneBase::Scene::ePlay)
{
	// 生成
	new Area();
	Goal*mGoal = new Goal();
	std::vector<Obstacle*> mObstacles;
	for (int i = 0; i < 3; ++i)
	{
		mObstacles.emplace_back(new Obstacle(i));
	}
	
	mPlayer = new Player(mObstacles, mGoal);
}

Play::~Play()
{
}

SceneBase::Scene Play::Update()
{
	// 現在のゲームタイプがクリアになったら
	if (/*mSceneTransitionFlag*/mNowGameType == NowGameType::eGameClear)
	{
		// リザルトシーンタグを返す
		return Scene::eResult;
	}
	// 現在のゲームタイプがオーバーになったら
	else if (/*mSceneTransitionFlag*/mNowGameType == NowGameType::eGameOver)
	{
		// タイトルシーンタグを返す
		return Scene::eTitle;
	}

	// シーン遷移条件を満たしていなかったら今のタグを返す
	return mIsSceneTag;
}
