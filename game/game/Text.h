#pragma once
#include "Object.h"
#include "SceneBase.h"

class Text :public Object
{
public:
    // �R���X�g���N�^
    Text();
    // �f�X�g���N�^
    ~Text();

    /// <summary>
    /// �X�V����
    /// </summary>
    void Update(float _deltaTime)override;
    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw()override;

private:
    const char* mText;
};