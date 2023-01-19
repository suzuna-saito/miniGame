#pragma once
#include <vector>
#include "Object.h"

/*
* 全てのオブジェクトの管理をするクラス(実体をひとつしか持たないクラス)
*/
class ObjectManager
{
private:
	// コンストラクタ
	ObjectManager();
	// デストラクタ
	~ObjectManager() {};
public:
	// インスタンスを作成する
	static void CreateInstance();
	// インスタンスを削除する
	static void DeleteInstance();

	/// <summary>
	/// コンテナにオブジェクトを追加
	/// </summary>
	/// <param name="_actor">追加するオブジェクトクラスのポインタ</param>
	static void AddObject(class Object* _object);
	/// <summary>
	/// コンテナからオブジェクトの削除
	/// </summary>
	/// <param name="_actor">削除するオブジェクトクラスのポインタ</param>
	static void RemovalObject(class Object* _object);
	/// <summary>
	/// オブジェクトを解放
	/// </summary>
	static void DeleteObject();
	/// <summary>
	/// オブジェクトの更新処理
	/// </summary>
	/// <param name="_deltaTime">最後のフレームを完了するのに要した時間</param>
	static void UpdateObject(float _deltaTime);
	/// <summary>
	/// オブジェクトの描画
	/// </summary>
	static void DrawObject();

private:
	static ObjectManager* mObjectManager;	// ObjectManagerの実体

	std::vector<Object*>mObjects;			// 全てのオブジェクトを格納するコンテナ
};