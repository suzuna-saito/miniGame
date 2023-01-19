#include "Object.h"
#include "Area.h"

Object::Object()
	: mPos({ 0.0f })
	, mSize({ 0.0f })
	, mMovePos({ 0.0f })
    , mMoveSpeed(0.0f)
{
	// �I�u�W�F�N�g���i�[
	ObjectManager::AddObject(this);
}

Object::~Object()
{
	// �I�u�W�F�N�g���폜
	ObjectManager::RemovalObject(this);
}

bool Object::HitCheck(const Object* _obj1, const Object* _obj2)
{
	// obj1(����)��obj2(����)�ɓ���������
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
	// �Ώۂ̃I�u�W�F�N�g���G���A�ɓ���������
	if (_obj->GetPos().x <= Area::mHitPos.x ||
		_obj->GetPos().x >= Area::mHitSize.x - _obj->GetSize().x ||
		_obj->GetPos().y <= Area::mHitPos.y ||
		_obj->GetPos().y >= Area::mHitSize.y - _obj->GetSize().y)
	{
		Vector2 setPos = _obj->GetPos();

		// �|�W�V�����̉����߂�����(�G���A�̊O���ɍs���Ȃ��悤�ɂ���)
		// ��
		if (_obj->GetPos().x <= Area::mHitPos.x)
		{
			setPos.x = Area::mHitPos.x;
		}
		// �E
		else if (_obj->GetPos().x >= Area::mHitSize.x - _obj->GetSize().x)
		{
			setPos.x = Area::mHitSize.x - _obj->GetSize().x;
		}
		// ��
		if (_obj->GetPos().y <= Area::mHitPos.y)
		{
			setPos.y = Area::mHitPos.y;
		}
		// ��
		else if (_obj->GetPos().y >= Area::mHitSize.y - _obj->GetSize().y)
		{
			setPos.y = Area::mHitSize.y - _obj->GetSize().y;
		}

		// �����߂��������|�W�V������Ώۂ̃I�u�W�F�N�g�ɐV�����Z�b�g
		_obj->SetPos(setPos);

		return true;
	}

	return false;
}