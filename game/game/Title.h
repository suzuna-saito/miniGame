#pragma once
#include "SceneBase.h"

/* 
* �^�C�g���V�[�� 
*/
class Title :public SceneBase
{
public:
	// �R���X�g���N�^
	Title();
	// �f�X�g���N�^
	~Title();

	/// <summary>
	/// �V�[���̍X�V����
	/// </summary>
	/// <returns>���݂̃V�[���̃|�C���^</returns>
	SceneBase::Scene Update()override;
};