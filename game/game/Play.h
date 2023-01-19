#pragma once
#include <vector>
#include "SceneBase.h"
#include "Area.h"
#include "Goal.h"
#include "Obstacle.h"
#include "Player.h"

/* 
* プレイシーン
*/
class Play :public SceneBase
{
public:
	// コンストラクタ
	Play();
	// デストラクタ
	~Play();

	/// <summary>
	/// シーンの更新処理
	/// </summary>
	/// <returns>現在のシーンのポインタ</returns>
	SceneBase::Scene Update()override;

private:
	// クラスのポインタ変数
	class Player* mPlayer;	// プレイヤー
};