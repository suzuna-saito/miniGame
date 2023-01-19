#pragma once
#include "Object.h"
#include "game.h"

/*
* �S�[���𐶐�/����/�`��
*/
class Goal :public Object
{
public:
    // �R���X�g���N�^
    Goal();
    // �f�X�g���N�^
    ~Goal();

    /// <summary>
    /// �X�V����
    /// </summary>
    void Update(float _deltaTime)override;
    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw()override;

private:
    const int MMaxAlpha;    // ���l�̍ő�l
    const int MMinAlpha;    // ���l�̍ŏ��l
    int mNowAlpha;          // ���݂̃��l
    int mAddAlpha;          // ���l�̑����l
};