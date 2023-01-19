#pragma once
#include "Object.h"
#include "Player.h"
#include "Area.h"

/*
* プレイヤーのHP
*/
class HP :public Object
{
public:
	// コンストラクタ
	HP(class Player* _owner);
	// デストラクタ
	~HP();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update(float _deltaTime)override;
    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw()override;

private:
    class Player* mPlayer;  // プレイヤークラスのポインタ
    
    const int MFontHandle;  // 描画に使用するフォントデータ
    const int MDrawDistance;// 描画するときのHP同士の距離感
    int mHP;                // 残機
};