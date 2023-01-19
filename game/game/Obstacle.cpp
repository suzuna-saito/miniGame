#include "Obstacle.h"
#include "Area.h"

Obstacle::Obstacle(const int _num)
{
    // ���N���X�ϐ��̐ݒ�
    mSize = { 50.0f , 50.0f };                                // �T�C�Y
    mPos = { Area::mHitPos.x , 300.0f + (200.0f * _num) };    // �|�W�V����(�G���A�̍��͂�)
    mMoveSpeed = 700.0f;                                      // �ړ��X�s�[�h

    // �����i���o�[�����������|�W�V�����ƈړ��l���t�ɂ���
    if (_num % 2)
    {
        mPos.x = Area::mHitSize.x - mSize.x;
        mMoveSpeed *= -1;
    }
}

Obstacle::~Obstacle()
{
}

void Obstacle::Update(float _deltaTime)
{
    // �|�W�V���������Ɉړ�������
    mPos.x += mMoveSpeed* _deltaTime;

    // �G���A�ɓ���������ړ��������t�ɂ���
    if (AreaHitCheck(this))
    {
        mMoveSpeed *= -1;
    }
}

void Obstacle::Draw()
{
    // ��Q���̕`��
    DrawBoxAA(mPos.x, mPos.y, mPos.x + mSize.x, mPos.y + mSize.y, GetColor(255, 150, 50), FALSE);
}