#include "Area.h"

// �ÓI�����o�ϐ��̏�����
Object::Vector2 Area::mHitPos = { 0.0f };   // �G���A�̓����蔻��|�W�V����
Object::Vector2 Area::mHitSize = { 0.0f };  // �G���A�̓����蔻��

Area::Area()
    : Object()
    , MAreaAdjustedDistance(10.0f)
{
    // ���N���X�ϐ��̐ݒ�
    mPos = { 300.0f,50.0f };                                     // �G���A�̍��㒸�_�|�W�V����
    mSize = { game::MWidth - mPos.x,game::MHeight - mPos.y };    // �G���A�̃T�C�Y

    mHitPos = { mPos.x + MAreaAdjustedDistance,mPos.y + MAreaAdjustedDistance };
    mHitSize = { mSize.x - MAreaAdjustedDistance,mSize.y - MAreaAdjustedDistance };
}

Area::~Area()
{
}

void Area::Update(float _deltaTime)
{
}

void Area::Draw()
{
    // �G���A�̕`��
    DrawBox(mPos.x, mPos.y, mSize.x, mSize.y, GetColor(40, 40, 40), TRUE);      // �D�F�̓h��Ԃ��G���A
    DrawBox(mPos.x, mPos.y, mSize.x, mSize.y, GetColor(255, 255, 255), FALSE);  // �G���A���������Ă��锒����

    mHitPos = { mPos.x + MAreaAdjustedDistance,mPos.y + MAreaAdjustedDistance };
    mHitSize = { mSize.x - MAreaAdjustedDistance,mSize.y - MAreaAdjustedDistance };
}