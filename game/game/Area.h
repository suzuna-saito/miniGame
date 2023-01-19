#pragma once
#include "Object.h"
#include "game.h"

/*
* �v���C���[���s���ł���G���A����/����/�`��
*/
class Area :public Object
{
public:
    // �R���X�g���N�^
    Area();
    // �f�X�g���N�^
    ~Area();

    /// <summary>
    /// �X�V����
    /// </summary>
    void Update(float _deltaTime)override;
    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw()override;

    static Vector2 mHitPos;        // �G���A�̓����蔻��|�W�V����
    static Vector2 mHitSize;       // �G���A�̓����蔻��T�C�Y

private:
    const int MAreaAdjustedDistance; // �G���A�Ƃ̉����߂��̍ۂɏ����������J���邽�߂̒l
};