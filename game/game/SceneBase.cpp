#include "SceneBase.h"

// 静的メンバ変数の初期化
SceneBase::Scene SceneBase::mIsSceneTag = Scene::eInit;						// 現在のシーンの初期化
SceneBase::NowGameType SceneBase::mNowGameType = NowGameType::eGamePlay;	// 現在のゲームタイプ

SceneBase::SceneBase(Scene _nowScene)
	: mSceneTransitionFlag(false)
{
	// 現在のシーンタグを更新
	mIsSceneTag = _nowScene;
	// 現在のゲームタイプをプレイに更新
	mNowGameType = NowGameType::eGamePlay;
}