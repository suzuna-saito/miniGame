#include "game.h"

// 性的メンバ変数の初期化
const int game::MWidth = 1920;  // 画面の幅
const int game::MHeight = 1080; // 画面の高さ

game::game()
	: mFps(nullptr)
	, mNowScene(new Title)
	, mReturnSceneTag(SceneBase::mIsSceneTag)
{
}

bool game::Init()
{
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return false;	// エラーが起きたら直ちに終了
	}

	// 画面モードのセット
	SetGraphMode(MWidth, MHeight, 16);
	ChangeWindowMode(TRUE);

	// 使用するフォントを変更する
	ChangeFont("Malgun Gothic");
	// 画面に描画するフォントのサイズ
	SetFontSize(60);
	// フォントの描画を綺麗にする
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);

	// Fps管理クラスの初期化
	mFps = new Fps();

	// 実態を一つしか持たないクラスの作成
	ObjectManager::CreateInstance();	// ObjectManagerクラス

	return true;
}

void game::GameLoop()
{
	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// 現在のシーンの更新処理
		mReturnSceneTag = mNowScene->Update();
		// シーンタグの切り替えが発生したら
		if (mReturnSceneTag != SceneBase::mIsSceneTag)
		{
			// 現在のシーンの解放
			delete mNowScene;
			// オブジェクトを削除する
			ObjectManager::DeleteObject();

			// 新しいシーンを生成
			NewScene();
		}

		// 更新処理
		UpdateGame();
		// 描画処理
		DrawGame();
	}
}

void game::NewScene()
{
	// 返り値で返ってきたタグがタイトルだったら
	if (mReturnSceneTag == SceneBase::Scene::eTitle)
	{
		mNowScene = new Title();   // タイトルを生成
	}
	// 返り値で返ってきたタグがプレイだったら
	else if (mReturnSceneTag == SceneBase::Scene::ePlay)
	{
		mNowScene = new Play();    // プレイを生成
	}
}

void game::UpdateGame()
{
	// デルタタイムを更新
	float deltaTime = mFps->GetDeltaTime();

	// 各オブジェクトを更新
	ObjectManager::UpdateObject(deltaTime);

	// FPSの更新処理
	mFps->Update();
}

void game::DrawGame()
{
	// 画面を初期化する
	ClearDrawScreen();

	// 各オブジェクトを描画
	ObjectManager::DrawObject();

	// 裏画面の内容を表画面に反映させる
	ScreenFlip();
}

void game::Termination()
{
	// 実体を一つしか持たないクラスの解放処理
	ObjectManager::DeleteObject();	// オブジェクトの解放

	// クラスの解放処理
	delete mNowScene;
	delete mFps;

	// ＤＸライブラリの後始末
	DxLib_End();
}