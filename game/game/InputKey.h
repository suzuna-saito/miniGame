#pragma once
#include "DxLib.h"
#include <vector>
#include <map>

/*
* ���͊֌W�̏���
*/
class InputKey
{
private:
	// �R���X�g���N�^
	InputKey();
	// �f�X�g���N�^
	~InputKey() {};

public:
	// ���͏��
	enum class InputState :unsigned char
	{
		eNone,			// �����ĂȂ�
		ePushMoment,	// �������u��
		ePushing,		// �����Ă�
	};

	// �C���X�^���X���쐬����
	static void CreateInstance();
	// �C���X�^���X���폜����
	static void DeleteInstance();

	// �t���[�����̏���(tmp�̍X�V)
	static void TmpKeyUpdate();

	/// <summary>
	/// ���͏�Ԃ𒲂ׂ�
	/// </summary>
	/// <param name="_key">���͏�Ԃ𒲂ׂ����L�[</param>
	/// <returns>���͏�Ԃ�Ԃ�</returns>
	static InputState CheckInput(int _key);

private:
	static InputKey* mInputKey;	// InputKey�̎���

	std::vector<int> mUseKey;	// �Q�[�����g�p�����L�[
	std::map<int, int> mTmp;	// �Q�[�����Ɏg�p�����L�[�̓��͏�Ԃ�ێ�
};