#pragma once
#include <vector>
#include "game.h"
#include "Object.h"
#include "Obstacle.h"
#include "Area.h"
#include "HP.h"

/*
* �v���C���[����/����/�`��
*/
class Player :public Object
{
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="_obstacle">��Q���N���X�̃|�C���^</param>
    Player(std::vector<class Obstacle*> _obstacle);
    // �f�X�g���N�^
    ~Player();

    /// <summary>
    /// ���͂̍X�V����
    /// </summary>
    void InputUpdate()override;
    /// <summary>
    /// �X�V����
    /// </summary>
    void Update(float _deltaTime)override;
    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw()override;

private:
    std::vector<class Obstacle*>mObstacles; // ��Q���N���X�̃|�C���^

    const int MMaxHitTime;  // ��Q���ɓ��������Ƃ��̍ő�o�ߎ��ԁi���G���ԁj
    int mHitCount;          // ��Q���ɓ������Ă���o�߂�������
    bool mHitFlag;	        // ��Q���ɓ����������ǂ��� true�F��������

    Vector2 mInitPos;       // �v���C���[�̏����|�W�V����

public: // getter/setter
    // ��Q���ɓ����������ǂ������擾
    const bool GetHitFlag() const { return mHitFlag; }
};