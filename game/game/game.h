#pragma once
#include "DxLib.h"
#include "Fps.h"
#include "InputKey.h"
#include "ObjectManager.h"
#include "SceneBase.h"
#include "Title.h"
#include "Play.h"
#include "Result.h"

/*
* �Q�[�����[�v�������s���N���X
*/
class game
{
public:
    // �R���X�g���N�^
    game();
    // �f�X�g���N�^
    ~game() {};

    // ����������
    // <returns>true: ����������</returns>
    bool Init();
    // �Q�[�����[�v
    void GameLoop();
    // �I������
    void Termination();

    static const int MWidth;    // ��ʂ̕�
    static const int MHeight;   // ��ʂ̍���

private:
    // mReturnSceneTag���Q�l�ɐV�����V�[���𐶐�����
    void NewScene();
    // �X�V����
    void UpdateGame();
    // �`�揈��
    void DrawGame();

    class Fps* mFps;            // FPS�v���N���X

    class SceneBase* mNowScene;         // ���݂̃V�[��
    SceneBase::Scene mReturnSceneTag;   // update�ŕԂ��Ă����V�[���̃^�O
};