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
	if (InputKey::CheckInput(KEY_INPUT_SPACE) == InputKey::InputState::ePushMoment)
	{
		return Scene::eTitle;
	}

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃^�O��Ԃ�
	return mIsSceneTag;
}
