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
	// �X�y�[�X�{�^���������ꂽ��V�[����J�ڂ���
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		return Scene::eTitle;
	}

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃^�O��Ԃ�
	return mIsSceneTag;
}
