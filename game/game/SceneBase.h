#pragma once

/* 
* �V�[���̊��N���X
*/
class SceneBase
{
public:
	// �V�[���̃^�O�i��ށj
	enum class Scene :unsigned char
	{
		eInit,    // �������
		eTitle,   // �^�C�g��
		ePlay,    // �v���C
		eResult,  // ���U���g
	};

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_nowScene">���݂̃V�[��</param>
	SceneBase(Scene _nowScene);
	// �f�X�g���N�^
	~SceneBase() {};

	/// <summary>
	/// �V�[���̍X�V����
	/// </summary>
	/// <returns>���ɐ�������V�[���̃^�O</returns>
	virtual SceneBase::Scene Update() = 0;

	static Scene mIsSceneTag; // ���݂̃V�[���^�O

protected:
	bool mSceneTransitionFlag;// ���̃V�[���ɑJ�ڂ��邩
};