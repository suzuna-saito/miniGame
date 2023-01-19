#include "game.h"

// 性的メンバ変数の初期化
const int game::MWidth = 1920;  // 画面の幅
const int game::MHeight = 1080; // 画面の高さ

game::game()
	: mFps(nullptr)
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
	// @@
	// 生成
	Area* mArea = new Area();
	new Goal();
	std::vector<Obstacle*> mObstacles;
	for (int i = 0; i < 3; ++i)
	{
		mObstacles.emplace_back(new Obstacle(i));
	}

	Player* mPlayer = new Player(mObstacles);

	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// 更新処理
		UpdateGame();
		// 描画処理
		DrawGame();
	}

	// オブジェクトの解放
	ObjectManager::DeleteObject();
}

void game::Termination()
{
	// クラスの解放処理
	delete mFps;

	// ＤＸライブラリの後始末
	DxLib_End();
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