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
	// �J�ڃt���O���オ���Ă�����
	if (mSceneTransitionFlag)
	{
		// �����𖞂����Ă�����v���C�V�[���𐶐����Ă��̃|�C���^��Ԃ�
		return Scene::ePlay;
	}

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃|�C���^��Ԃ�
	return mIsSceneTag;
}