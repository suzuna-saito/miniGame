#include "SceneBase.h"

// �ÓI�����o�ϐ��̏�����
SceneBase::Scene SceneBase::mIsSceneTag = Scene::eInit;						// ���݂̃V�[���̏�����
SceneBase::NowGameType SceneBase::mNowGameType = NowGameType::eGamePlay;	// ���݂̃Q�[���^�C�v

SceneBase::SceneBase(Scene _nowScene)
	: mSceneTransitionFlag(false)
{
	// ���݂̃V�[���^�O���X�V
	mIsSceneTag = _nowScene;
	// ���݂̃Q�[���^�C�v���v���C�ɍX�V
	mNowGameType = NowGameType::eGamePlay;
}