#pragma once
#include <vector>
#include "DxLib.h"
#include "Fps.h"
#include "ObjectManager.h"
#include "Area.h"
#include "Goal.h"
#include "Obstacle.h"
#include "Player.h"

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
    // �X�V����
    void UpdateGame();
    // �`�揈��
    void DrawGame();

    class Fps* mFps;            // FPS�v���N���X
};