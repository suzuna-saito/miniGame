#pragma once
#include "Object.h"
#include "Player.h"
#include "Area.h"

/*
* �v���C���[��HP
*/
class HP :public Object
{
public:
	// �R���X�g���N�^
	HP(class Player* _owner);
	// �f�X�g���N�^
	~HP();

    /// <summary>
    /// �X�V����
    /// </summary>
    void Update(float _deltaTime)override;
    /// <summary>
    /// �`�揈��
    /// </summary>
    void Draw()override;

private:
    class Player* mPlayer;  // �v���C���[�N���X�̃|�C���^
    
    const int MFontHandle;  // �`��Ɏg�p����t�H���g�f�[�^
    const int MDrawDistance;// �`�悷��Ƃ���HP���m�̋�����
    int mHP;                // �c�@
};