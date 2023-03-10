#include "SceneBase.h"

// 現在のシーンの初期化
SceneBase::Scene SceneBase::mIsSceneTag = Scene::eInit;

SceneBase::SceneBase(Scene _nowScene)
	: mSceneTransitionFlag(false)
{
	// 現在のシーンタグを更新
	mIsSceneTag = _nowScene;
}