#pragma once
#include <vector>
#include "SceneBase.h"
#include "Area.h"
#include "Goal.h"
#include "Obstacle.h"
#include "Player.h"

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

private:
	// �N���X�̃|�C���^�ϐ�
	class Player* mPlayer;	// �v���C���[
};