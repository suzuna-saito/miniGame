#include "SceneBase.h"

// ���݂̃V�[���̏�����
SceneBase::Scene SceneBase::mIsSceneTag = Scene::eInit;

SceneBase::SceneBase(Scene _nowScene)
	: mSceneTransitionFlag(false)
{
	// ���݂̃V�[���^�O���X�V
	mIsSceneTag = _nowScene;
}