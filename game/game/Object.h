#pragma once
#include "DxLib.h"
#include "ObjectManager.h"

/*
* �I�u�W�F�N�g�̊��N���X
*/
class Object
{
public:
    // �R���X�g���N�^
    Object();
    // �f�X�g���N�^
    virtual ~Object();

    /// <summary>
    /// ���͂̍X�V����
    /// </summary>
    virtual void InputUpdate() {};
    /// <summary>
    /// �X�V����
    /// </summary>
    /// <param name="_deltaTime">�Ō�̃t���[������������̂ɗv��������</param>
    virtual void Update(float _deltaTime){};
    /// <summary>
    /// �`�揈��
    /// </summary>
    virtual void Draw(){};

protected:
    // �\����
    // 2�����x�N�g��
    struct Vector2
    {
        float x;
        float y;
    };

    /// <summary>
    /// �I�u�W�F�N�g���m�̓����蔻��
    /// </summary>
    /// <param name="_obj1">�Ώۂ̃I�u�W�F�N�g�i�����j</param>
    /// <param name="_obj2">�Ώۂ̃I�u�W�F�N�g�i����j</param>
    /// <returns>true : ��������</returns>
    bool HitCheck(const class Object* _obj1,const class Object* _obj2);
    /// <summary>
    /// �G���A�ƃI�u�W�F�N�g�̓����蔻��(�����߂��������ɍs��)
    /// </summary>
    /// <param name="_obj">�Ώۂ̃I�u�W�F�N�g</param>
    /// <returns>true : ��������</returns>
    bool AreaHitCheck(class Object* _obj);

    Vector2 mPos;       // �|�W�V����
    Vector2 mSize;      // �T�C�Y
    Vector2 mMovePos;   // �ړ��ʒu
    float mMoveSpeed;   // �ړ����x

    ///// <summary>
    ///// Vector2���m�̑����Z�i+���j
    ///// </summary>
    ///// <param name="_vec2">�����l�iVector2�j</param>
    ///// <returns>_vec2�𑫂����l</returns>
    //Object::Vector2& operator+=(const Object::Vector2& _vec2)
    //{
    //    mPos.x += _vec2.x;
    //    mPos.y += _vec2.y;
    //    return mPos;
    //}

public: // getter/setter
    // �|�W�V�������擾
    const Vector2 GetPos() const { return mPos; }
    // �T�C�Y���擾
    const Vector2 GetSize() const { return mSize; }

    // �|�W�V�������Z�b�g
    void SetPos(const Vector2 _pos) { mPos = _pos; }
};