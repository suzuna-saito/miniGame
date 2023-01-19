#include "game.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// gemeクラス
	game game;
	// 初期化処理
	if (game.Init())
	{
		// ゲームの更新処理
		game.GameLoop();
	}

	// ゲームクラスの終了処理
	game.Termination();

	// ソフトの終了
	return 0;
}