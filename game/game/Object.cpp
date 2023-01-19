#include "Object.h"
#include "Area.h"

Object::Object()
	: mPos({ 0.0f })
	, mSize({ 0.0f })
	, mMovePos({ 0.0f })
    , mMoveSpeed(0.0f)
{
	// オブジェクトを格納
	ObjectManager::AddObject(this);
}

Object::~Object()
{
	// オブジェクトを削除
	ObjectManager::RemovalObject(this);
}

bool Object::HitCheck(const Object* _obj1, const Object* _obj2)
{
	// obj1(自分)がobj2(相手)に当たったら
	if (_obj1->GetPos().x <= _obj2->GetPos().x + _obj2->GetSize().x &&
		_obj1->GetPos().x + _obj1->GetSize().x >= _obj2->GetPos().x &&
		_obj1->GetPos().y <= _obj2->GetPos().y + _obj2->GetSize().y &&
		_obj1->GetPos().y + _obj1->GetSize().y >= _obj2->GetPos().y)
	{
		return true;
	}

	return false;
}

bool Object::AreaHitCheck(Object* _obj)
{
	// 対象のオブジェクトがエリアに当たったら
	if (_obj->GetPos().x <= Area::mHitPos.x ||
		_obj->GetPos().x >= Area::mHitSize.x - _obj->GetSize().x ||
		_obj->GetPos().y <= Area::mHitPos.y ||
		_obj->GetPos().y >= Area::mHitSize.y - _obj->GetSize().y)
	{
		Vector2 setPos = _obj->GetPos();

		// ポジションの押し戻し処理(エリアの外側に行かないようにする)
		// 左
		if (_obj->GetPos().x <= Area::mHitPos.x)
		{
			setPos.x = Area::mHitPos.x;
		}
		// 右
		else if (_obj->GetPos().x >= Area::mHitSize.x - _obj->GetSize().x)
		{
			setPos.x = Area::mHitSize.x - _obj->GetSize().x;
		}
		// 上
		if (_obj->GetPos().y <= Area::mHitPos.y)
		{
			setPos.y = Area::mHitPos.y;
		}
		// 下
		else if (_obj->GetPos().y >= Area::mHitSize.y - _obj->GetSize().y)
		{
			setPos.y = Area::mHitSize.y - _obj->GetSize().y;
		}

		// 押し戻しをしたポジションを対象のオブジェクトに新しくセット
		_obj->SetPos(setPos);

		return true;
	}

	return false;
}