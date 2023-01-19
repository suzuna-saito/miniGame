#pragma once
#include "SceneBase.h"

/* 
* リザルトシーン
*/
class Result :public SceneBase
{
public:
	// コンストラクタ
	Result();
	// デストラクタ
	~Result();

	/// <summary>
	/// シーンの更新処理
	/// </summary>
	/// <returns>現在のシーンのポインタ</returns>
	SceneBase::Scene Update()override;
};