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
	// �V�[���J�ڏ���(�G���^�[�������ƑJ�ځi���j)
	if (mSceneTransitionFlag)
	{
		// �����𖞂����Ă����烊�U���g�V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return Scene::eResult;
	}

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
	return mIsSceneTag;
}
