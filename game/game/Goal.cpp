#include "Goal.h"

Goal::Goal()
    : Object()
    , MMaxAlpha(255)
    , MMinAlpha(150)
    , mNowAlpha(255)
    , mAddAlpha(2)
{
    // ���N���X�ϐ��̐ݒ�
    mSize = { 70.0f,70.0f };	// �T�C�Y
    mPos = { game::MWidth / 2.0f - mSize.x / 2.0f ,Area::mHitPos.y + 30.0f };			// �|�W�V�����i��ʐ^�񒆂ɂ���)
}

Goal::~Goal()
{
}

void Goal::Update(float _deltaTime)
{
    // ���݂̃��l���ő�l���傫���Ȃ邩�A�ŏ��l��菬�����Ȃ�����
    if (mNowAlpha >= MMaxAlpha || mNowAlpha <= MMinAlpha)
    {
        // �����l�̕����𔽑΂ɂ���
        mAddAlpha *= -1;
    }

    mNowAlpha += mAddAlpha;
}

void Goal::Draw()
{
    // �`��u�����h���[�h�����u�����h�ɂ���
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, mNowAlpha);
    DrawBoxAA(mPos.x, mPos.y, mPos.x + mSize.x, mPos.y + mSize.y, GetColor(50, 150, 255), TRUE);

    // �`��u�����h���[�h���m�[�u�����h�ɂ���
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
