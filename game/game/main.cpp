#include "game.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// geme�N���X
	game game;
	// ����������
	if (game.Init())
	{
		// �Q�[���̍X�V����
		game.GameLoop();
	}

	// �Q�[���N���X�̏I������
	game.Termination();

	// �\�t�g�̏I��
	return 0;
}