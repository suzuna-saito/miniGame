#pragma once
#include "Object.h"

/*
* ��Q������/����/�`��
*/
class Obstacle :public Object
{
public:
    // �R���X�g���N�^
    Obstacle(const int _num);
    // �f�X�g���N�^
    ~Obstacle();

    /// <summary>
    /// �X�V����
    /// </summary>
    void Update(float _deltaTime)override;
    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw()override;
};