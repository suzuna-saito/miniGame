#include "Title.h"

Title::Title()
	: SceneBase(SceneBase::Scene::eTitle)
{
	// ���݂̃Q�[���^�C�v���v���C�ɍX�V
	mNowGameType = NowGameType::eGamePlay;

	new Text("����̓^�C�g���ł�");
}

Title::~Title()
{
}

SceneBase::Scene Title::Update()
{
	// �X�y�[�X�{�^���������ꂽ�u�Ԃ�������V�[����J�ڂ���
	if (InputKey::CheckInput(KEY_INPUT_SPACE) == InputKey::InputState::ePushMoment)
	{
		return Scene::ePlay;
	}

	// �V�[���J�ڏ����𖞂����Ă��Ȃ������獡�̃^�O��Ԃ�
	return mIsSceneTag;
}