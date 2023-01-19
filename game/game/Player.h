#pragma once
#include <vector>
#include "game.h"
#include "Object.h"
#include "Obstacle.h"
#include "Area.h"
#include "HP.h"

/*
* プレイヤー生成/処理/描画
*/
class Player :public Object
{
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="_obstacle">障害物クラスのポインタ</param>
    Player(std::vector<class Obstacle*> _obstacle);
    // デストラクタ
    ~Player();

    /// <summary>
    /// 入力の更新処理
    /// </summary>
    void InputUpdate()override;
    /// <summary>
    /// 更新処理
    /// </summary>
    void Update(float _deltaTime)override;
    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw()override;

private:
    std::vector<class Obstacle*>mObstacles; // 障害物クラスのポインタ

    const int MMaxHitTime;  // 障害物に当たったときの最大経過時間（無敵時間）
    int mHitCount;          // 障害物に当たってから経過した時間
    bool mHitFlag;	        // 障害物に当たったかどうか true：当たった

    Vector2 mInitPos;       // プレイヤーの初期ポジション

public: // getter/setter
    // 障害物に当たったかどうかを取得
    const bool GetHitFlag() const { return mHitFlag; }
};