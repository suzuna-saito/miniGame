#include "InputKey.h"

// ���g�̃C���X�^���X�̏�����
InputKey* InputKey::mInputKey = nullptr;

InputKey::InputKey()
{
}

void InputKey::CreateInstance()
{
    // InputKey�𐶐����Ă��Ȃ�������
    if (mInputKey == nullptr)
    {
        mInputKey = new InputKey();  // �C���X�^���X�𐶐�
    }
}

void InputKey::DeleteInstance()
{
    if (mInputKey != nullptr)
    {
        delete mInputKey;                // �폜
        mInputKey = nullptr;
    }
}

void InputKey::TmpKeyUpdate()
{
    // �Q�[�����Ɏg�p�����L�[���ׂĒ��ׂ�
    for (auto key : mInputKey->mUseKey)
    {
        // ����̃L�[��������Ă�����1�A������ĂȂ����0������
        mInputKey->mTmp[key] = CheckHitKey(key);
    }
}

InputKey::InputState InputKey::CheckInput(int _key)
{
    // �����̃L�[�̌��݂̓��͏�Ԃ𒲂ׂ�
    int nowHitKey = CheckHitKey(_key);

    if (nowHitKey == 1)
    {
        printf("");
    }

    // �R���e�i�̒��ɑΏۂ̃L�[�����邩��T��
    auto iter = std::find(mInputKey->mUseKey.begin(), mInputKey->mUseKey.end(), _key);
    // �Ώۂ̃L�[���������
    if (iter == mInputKey->mUseKey.end())
    {
        // �R���e�i�ɑΏۂ̃L�[��ǉ�
        mInputKey->mUseKey.emplace_back(_key);
        // �L�[��������Ă�����
        if (nowHitKey == 1)
        {
            // �X�e�[�g���������u�Ԃɂ���
            return InputState::ePushMoment;

        }
    }
    // �Ώۂ̃L�[�������
    else
    {
        // �Ώۂ̃L�[���O�t���[���ŉ�����ĂȂ���΂��A���݉����Ă����
        if (mInputKey->mTmp[_key] == 0 && nowHitKey == 1)
        {
            // �X�e�[�g���������u�Ԃɂ���
            return InputState::ePushMoment;
        }
        // �Ώۂ̃L�[���O�t���[���ŉ�����Ă��Ă��A���݉����Ă����
        else if(mInputKey->mTmp[_key] == 1 && nowHitKey == 1)
        {
            // �X�e�[�g�������Ă�ɂ���
            return InputState::ePushing;
        }
        else
        {
            // �X�e�[�g�������Ă��Ȃ��ɂ���
            return InputState::eNone;
        }
    }
}
