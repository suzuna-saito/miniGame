#pragma once
#include "DxLib.h"

/* 
* �t���[���ɂ����������Ԃ��v���������݂���N���X
*/
class Fps
{
public:
	// �R���X�g���N�^
	Fps();
	// �f�X�g���N�^
	~Fps() {};

	// �t���[�����̏���
	void Update();

private:
	// FPS���ݒ�l���傫���Ȃ�Ȃ��悤�ɐ���
	void Wait();

	const int MSetFps;             // �t���[�����[�g�̍ō��l
	const int MOneFrameTickCount;  // 1�t���[���ɂ����鎞��

	int mBeforeTickCount;     // �O�̃t���[���̂�����������
	float mDeltaTime;         // ���݂̃t���[���̂�����������

public:   // �Q�b�^�[�A�Z�b�^�[
	// ���݂̃t���[���ɂ�����������(float�^)
	float GetDeltaTime() { return mDeltaTime; }
};

