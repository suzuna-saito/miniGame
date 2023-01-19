#pragma once
#include "SceneBase.h"

/* 
* タイトルシーン 
*/
class Title :public SceneBase
{
public:
	// コンストラクタ
	Title();
	// デストラクタ
	~Title();

	/// <summary>
	/// シーンの更新処理
	/// </summary>
	/// <returns>現在のシーンのポインタ</returns>
	SceneBase::Scene Update()override;
};