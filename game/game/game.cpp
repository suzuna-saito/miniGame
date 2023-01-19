#include "game.h"

// ���I�����o�ϐ��̏�����
const int game::MWidth = 1920;  // ��ʂ̕�
const int game::MHeight = 1080; // ��ʂ̍���

game::game()
	: mFps(nullptr)
	, mNowScene(new Title)
	, mReturnSceneTag(SceneBase::mIsSceneTag)
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
	// �G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ���݂̃V�[���̍X�V����
		mReturnSceneTag = mNowScene->Update();
		// �V�[���^�O�̐؂�ւ�������������
		if (mReturnSceneTag != SceneBase::mIsSceneTag)
		{
			// ���݂̃V�[���̉��
			delete mNowScene;
			// �I�u�W�F�N�g���폜����
			ObjectManager::DeleteObject();

			// �V�����V�[���𐶐�
			NewScene();
		}

		// �X�V����
		UpdateGame();
		// �`�揈��
		DrawGame();
	}
}

void game::NewScene()
{
	// �Ԃ�l�ŕԂ��Ă����^�O���^�C�g����������
	if (mReturnSceneTag == SceneBase::Scene::eTitle)
	{
		mNowScene = new Title();   // �^�C�g���𐶐�
	}
	// �Ԃ�l�ŕԂ��Ă����^�O���v���C��������
	else if (mReturnSceneTag == SceneBase::Scene::ePlay)
	{
		mNowScene = new Play();    // �v���C�𐶐�
	}
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

void game::Termination()
{
	// ���̂�����������Ȃ��N���X�̉������
	ObjectManager::DeleteObject();	// �I�u�W�F�N�g�̉��

	// �N���X�̉������
	delete mNowScene;
	delete mFps;

	// �c�w���C�u�����̌�n��
	DxLib_End();
}