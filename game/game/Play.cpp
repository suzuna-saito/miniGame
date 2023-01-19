#include "Play.h"

Play::Play()
    : SceneBase(SceneBase::Scene::ePlay)
{
	// ����
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
	// ���݂̃Q�[���^�C�v���N���A�ɂȂ�����
	if (/*mSceneTransitionFlag*/mNowGameType == NowGameType::eGameClear)
	{
		// ���U���g�V�[���^�O��Ԃ�
		return Scene::eResult;
	}
	// ���݂̃Q�[���^�C�v���I�[�o�[�ɂȂ�����
	else if (/*mSceneTransitionFlag*/mNowGameType == NowGameType::eGameOver)
	{
		// �^�C�g���V�[���^�O��Ԃ�
		return Scene::eTitle;
	}

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃^�O��Ԃ�
	return mIsSceneTag;
}
