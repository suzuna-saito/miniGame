#pragma once
#include "SceneBase.h"

/* 
* �v���C�V�[��
*/
class Play :public SceneBase
{
public:
	// �R���X�g���N�^
	Play();
	// �f�X�g���N�^
	~Play();

	/// <summary>
	/// �V�[���̍X�V����
	/// </summary>
	/// <returns>���݂̃V�[���̃|�C���^</returns>
	SceneBase::Scene Update()override;
};