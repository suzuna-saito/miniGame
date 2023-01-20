#include "ObjectManager.h"

// 自身のインスタンスの初期化
ObjectManager* ObjectManager::mObjectManager = nullptr;

ObjectManager::ObjectManager()
{
}

void ObjectManager::CreateInstance()
{
	// マネージャーを生成していなかったら
	if (mObjectManager == nullptr)
	{
		mObjectManager = new ObjectManager();  // インスタンスを生成
	}
}

void ObjectManager::DeleteInstance()
{
	if (mObjectManager != nullptr)
	{
		delete mObjectManager;                // 削除
		mObjectManager = nullptr;
	}
}

void ObjectManager::AddObject(Object* _object)
{
	// 追加されたオブジェクトを格納
	mObjectManager->mObjects.emplace_back(_object);
}

void ObjectManager::RemovalObject(class Object* _object)
{
	// コンテナの中から対象のオブジェクトを探す
	auto iter = std::find(mObjectManager->mObjects.begin(), mObjectManager->mObjects.end(), _object);
	if (iter != mObjectManager->mObjects.end())
	{
		// コンテナの最初の要素と最後の要素を入れ替える
		std::iter_swap(iter, mObjectManager->mObjects.end() - 1);
		// 末尾要素を削除する
		mObjectManager->mObjects.pop_back();
	}
}

void ObjectManager::DeleteObject()
{
	// コンテナが空じゃなかったら
	while (!mObjectManager->mObjects.empty())
	{
		// 末尾要素から削除
		delete mObjectManager->mObjects.back();
	}

	mObjectManager->mObjects.clear();
}

void ObjectManager::UpdateObject(float _deltaTime)
{
	// 各オブジェクトを更新
	for (auto obj : mObjectManager->mObjects)
	{
		// 先に入力処理の更新をする
		obj->InputUpdate();
		obj->Update(_deltaTime);
	}
}

void ObjectManager::DrawObject()
{
	// 各オブジェクトを描画
	for (auto obj : mObjectManager->mObjects)
	{
		obj->Draw();
	}
}