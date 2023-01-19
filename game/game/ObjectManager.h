#pragma once
#include <vector>
#include "Object.h"

/*
* �S�ẴI�u�W�F�N�g�̊Ǘ�������N���X(���̂��ЂƂ��������Ȃ��N���X)
*/
class ObjectManager
{
private:
	// �R���X�g���N�^
	ObjectManager();
	// �f�X�g���N�^
	~ObjectManager() {};
public:
	// �C���X�^���X���쐬����
	static void CreateInstance();
	// �C���X�^���X���폜����
	static void DeleteInstance();

	/// <summary>
	/// �R���e�i�ɃI�u�W�F�N�g��ǉ�
	/// </summary>
	/// <param name="_actor">�ǉ�����I�u�W�F�N�g�N���X�̃|�C���^</param>
	static void AddObject(class Object* _object);
	/// <summary>
	/// �R���e�i����I�u�W�F�N�g�̍폜
	/// </summary>
	/// <param name="_actor">�폜����I�u�W�F�N�g�N���X�̃|�C���^</param>
	static void RemovalObject(class Object* _object);
	/// <summary>
	/// �I�u�W�F�N�g�����
	/// </summary>
	static void DeleteObject();
	/// <summary>
	/// �I�u�W�F�N�g�̍X�V����
	/// </summary>
	/// <param name="_deltaTime">�Ō�̃t���[������������̂ɗv��������</param>
	static void UpdateObject(float _deltaTime);
	/// <summary>
	/// �I�u�W�F�N�g�̕`��
	/// </summary>
	static void DrawObject();

private:
	static ObjectManager* mObjectManager;	// ObjectManager�̎���

	std::vector<Object*>mObjects;			// �S�ẴI�u�W�F�N�g���i�[����R���e�i
};