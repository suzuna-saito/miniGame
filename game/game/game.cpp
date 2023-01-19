#include "game.h"

// ���I�����o�ϐ��̏�����
const int game::MWidth = 1920;  // ��ʂ̕�
const int game::MHeight = 1080; // ��ʂ̍���

game::game()
	: mFps(nullptr)
{
}

bool game::Init()
{
	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return false;	// �G���[���N�����璼���ɏI��
	}

	// ��ʃ��[�h�̃Z�b�g
	SetGraphMode(MWidth, MHeight, 16);
	ChangeWindowMode(TRUE);

	// �g�p����t�H���g��ύX����
	ChangeFont("Malgun Gothic");
	// ��ʂɕ`�悷��t�H���g�̃T�C�Y
	SetFontSize(60);
	// �t�H���g�̕`����Y��ɂ���
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);

	// Fps�Ǘ��N���X�̏�����
	mFps = new Fps();

	// ���Ԃ�����������Ȃ��N���X�̍쐬
	ObjectManager::CreateInstance();	// ObjectManager�N���X

	return true;
}

void game::GameLoop()
{
	// @@
	// ����
	Area* mArea = new Area();
	new Goal();
	std::vector<Obstacle*> mObstacles;
	for (int i = 0; i < 3; ++i)
	{
		mObstacles.emplace_back(new Obstacle(i));
	}

	Player* mPlayer = new Player(mObstacles);

	// �G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// �X�V����
		UpdateGame();
		// �`�揈��
		DrawGame();
	}

	// �I�u�W�F�N�g�̉��
	ObjectManager::DeleteObject();
}

void game::Termination()
{
	// �N���X�̉������
	delete mFps;

	// �c�w���C�u�����̌�n��
	DxLib_End();
}

void game::UpdateGame()
{
	// �f���^�^�C�����X�V
	float deltaTime = mFps->GetDeltaTime();

	// �e�I�u�W�F�N�g���X�V
	ObjectManager::UpdateObject(deltaTime);

	// FPS�̍X�V����
	mFps->Update();
}

void game::DrawGame()
{
	// ��ʂ�����������
	ClearDrawScreen();

	// �e�I�u�W�F�N�g��`��
	ObjectManager::DrawObject();

	// ����ʂ̓��e��\��ʂɔ��f������
	ScreenFlip();
}