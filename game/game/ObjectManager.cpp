#include "ObjectManager.h"

// ���g�̃C���X�^���X�̏�����
ObjectManager* ObjectManager::mObjectManager = nullptr;

ObjectManager::ObjectManager()
{
}

void ObjectManager::CreateInstance()
{
	// �}�l�[�W���[�𐶐����Ă��Ȃ�������
	if (mObjectManager == nullptr)
	{
		mObjectManager = new ObjectManager();  // �C���X�^���X�𐶐�
	}
}

void ObjectManager::DeleteInstance()
{
	if (mObjectManager != nullptr)
	{
		delete mObjectManager;                // �폜
		mObjectManager = nullptr;
	}
}

void ObjectManager::AddObject(Object* _object)
{
	// �ǉ����ꂽ�I�u�W�F�N�g���i�[
	mObjectManager->mObjects.emplace_back(_object);
}

void ObjectManager::RemovalObject(class Object* _object)
{
	// �R���e�i�̒�����Ώۂ̃I�u�W�F�N�g��T��
	auto iter = std::find(mObjectManager->mObjects.begin(), mObjectManager->mObjects.end(), _object);
	if (iter != mObjectManager->mObjects.end())
	{
		// �R���e�i�̍ŏ��̗v�f�ƍŌ�̗v�f�����ւ���
		std::iter_swap(iter, mObjectManager->mObjects.end() - 1);
		// �����v�f���폜����
		mObjectManager->mObjects.pop_back();
	}
}

void ObjectManager::DeleteObject()
{
	// �R���e�i���󂶂�Ȃ�������
	while (!mObjectManager->mObjects.empty())
	{
		// �����v�f����폜
		delete mObjectManager->mObjects.back();
	}

	mObjectManager->mObjects.clear();
}

void ObjectManager::UpdateObject(float _deltaTime)
{
	// �e�I�u�W�F�N�g���X�V
	for (auto obj : mObjectManager->mObjects)
	{
		// ��ɓ��͏����̍X�V������
		obj->InputUpdate();
		obj->Update(_deltaTime);
	}
}

void ObjectManager::DrawObject()
{
	// �e�I�u�W�F�N�g��`��
	for (auto obj : mObjectManager->mObjects)
	{
		obj->Draw();
	}
}