#pragma once
#include <vector>
#include "DxLib.h"
#include "Fps.h"
#include "ObjectManager.h"
#include "Area.h"
#include "Goal.h"
#include "Obstacle.h"
#include "Player.h"

/*
* ゲームループ処理を行うクラス
*/
class game
{
public:
    // コンストラクタ
    game();
    // デストラクタ
    ~game() {};

    // 初期化処理
    // <returns>true: 初期化成功</returns>
    bool Init();
    // ゲームループ
    void GameLoop();
    // 終了処理
    void Termination();

    static const int MWidth;    // 画面の幅
    static const int MHeight;   // 画面の高さ

private:
    // 更新処理
    void UpdateGame();
    // 描画処理
    void DrawGame();

    class Fps* mFps;            // FPS計測クラス
};