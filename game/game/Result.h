#pragma once
#include "SceneBase.h"

/* 
* ���U���g�V�[��
*/
class Result :public SceneBase
{
public:
	// �R���X�g���N�^
	Result();
	// �f�X�g���N�^
	~Result();

	/// <summary>
	/// �V�[���̍X�V����
	/// </summary>
	/// <returns>���݂̃V�[���̃|�C���^</returns>
	SceneBase::Scene Update()override;
};