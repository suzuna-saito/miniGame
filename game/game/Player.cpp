#include "Player.h"

Player::Player(std::vector<class Obstacle*> _obstacles , class Goal* _goal)
    : Object()
	, mObstacles(_obstacles)
	, mGoal(_goal)
	, MMaxHitTime(80)
	, mHitCount(0)
	, mHitFlag(false)
{
    // ���N���X�ϐ��̐ݒ�
	mSize = { 70.0f,70.0f };	// �T�C�Y
	mPos = { game::MWidth / 2.0f - mSize.x / 2.0f ,Area::mHitSize.y - mSize.y - 30.0f }; // �|�W�V�����i��ʐ^�񒆉��ɂ���)
    mMoveSpeed = 500.0f;		// �ړ����x

	// �����|�W�V�����̐ݒ�
	mInitPos = mPos;

	// �c�@�̐���
	new HP(this);
}

Player::~Player()
{
}

void Player::InputUpdate()
{
	// mMovePos�i�ړ��ʒu�j��0�ɖ߂��B
	mMovePos = { 0.0f };

	// �v���C���[���_�Œ��i�������Ă����莞�Ԍo�߂��Ă��Ȃ�������j�ʂ���
	if (mHitCount != 0)
	{
		return;
	}

	// ��
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		mMovePos.x = mMoveSpeed;
	}
	// �E
	else if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		mMovePos.x = -mMoveSpeed;
	}
	// ��
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		mMovePos.y = -mMoveSpeed;
	}
	// ��
	else if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		mMovePos.y = mMoveSpeed;
	}
}

void Player::Update(float _deltaTime)
{
	// �|�W�V�����̍X�V
	// @@ Vector2��+=�̉��Z�q�̃I�[�o�[���C�h��肽��
	mPos.x += mMovePos.x * _deltaTime;
	mPos.y += mMovePos.y * _deltaTime;

	// �G���A�Ƃ̓����蔻�肩�A�����߂�����
	AreaHitCheck(this);

	// �����蔻��
	// ���G���Ԃ���Ȃ����A��Q���ɓ������Ă�����t���O��true�ɂ���
	if (mHitCount == 0)
	{
		for (auto obstacle : mObstacles)
		{
			if (HitCheck(this, obstacle))
			{
				mHitFlag = true;
				mPos = mInitPos;
				break;
			}
		}
	}
	else
	{
		// ��Q���ɓ������Ă��Ȃ�
		mHitFlag = false;
	}

	// ���������u�Ԃ܂��͖��G���Ԓ���������
	if (mHitFlag || mHitCount != 0)
	{
		// ��Q���ɓ������Ă���̎��Ԃ��J�E���g
		++mHitCount;

		// �J�E���g���ő�o�ߎ��Ԃ𒴂�����J�E���g��0�ɖ߂�
		if (mHitCount > MMaxHitTime)
		{
			mHitCount = 0;
		}
	}

	// �S�[���܂ł��ǂ�����猻�݂̃Q�[���^�C�v���N���A�ɂ���
	if (HitCheck(this, mGoal))
	{
		SceneBase::mNowGameType = SceneBase::NowGameType::eGameClear;
	}
}

void Player::Draw()
{
	// �v���C���[�̕`��
	// ��Q���ɓ����������͓_�ł�����
	if (mHitCount % 2 == 0)
	{
		DrawBoxAA(mPos.x, mPos.y, mPos.x + mSize.x, mPos.y + mSize.y, GetColor(50, 150, 255), TRUE);
	}
}
