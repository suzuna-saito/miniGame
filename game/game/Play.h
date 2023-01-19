#pragma once
#include "SceneBase.h"

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
};