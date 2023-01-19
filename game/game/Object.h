#pragma once
#include "DxLib.h"
#include "ObjectManager.h"

/*
* オブジェクトの基底クラス
*/
class Object
{
public:
    // コンストラクタ
    Object();
    // デストラクタ
    virtual ~Object();

    /// <summary>
    /// 入力の更新処理
    /// </summary>
    virtual void InputUpdate() {};
    /// <summary>
    /// 更新処理
    /// </summary>
    /// <param name="_deltaTime">最後のフレームを完了するのに要した時間</param>
    virtual void Update(float _deltaTime){};
    /// <summary>
    /// 描画処理
    /// </summary>
    virtual void Draw(){};

protected:
    // 構造体
    // 2次元ベクトル
    struct Vector2
    {
        float x;
        float y;
    };

    /// <summary>
    /// オブジェクト同士の当たり判定
    /// </summary>
    /// <param name="_obj1">対象のオブジェクト（自分）</param>
    /// <param name="_obj2">対象のオブジェクト（相手）</param>
    /// <returns>true : 当たった</returns>
    bool HitCheck(const class Object* _obj1,const class Object* _obj2);
    /// <summary>
    /// エリアとオブジェクトの当たり判定(押し戻しも同時に行う)
    /// </summary>
    /// <param name="_obj">対象のオブジェクト</param>
    /// <returns>true : 当たった</returns>
    bool AreaHitCheck(class Object* _obj);

    Vector2 mPos;       // ポジション
    Vector2 mSize;      // サイズ
    Vector2 mMovePos;   // 移動位置
    float mMoveSpeed;   // 移動速度

    ///// <summary>
    ///// Vector2同士の足し算（+＝）
    ///// </summary>
    ///// <param name="_vec2">足す値（Vector2）</param>
    ///// <returns>_vec2を足した値</returns>
    //Object::Vector2& operator+=(const Object::Vector2& _vec2)
    //{
    //    mPos.x += _vec2.x;
    //    mPos.y += _vec2.y;
    //    return mPos;
    //}

public: // getter/setter
    // ポジションを取得
    const Vector2 GetPos() const { return mPos; }
    // サイズを取得
    const Vector2 GetSize() const { return mSize; }

    // ポジションをセット
    void SetPos(const Vector2 _pos) { mPos = _pos; }
};