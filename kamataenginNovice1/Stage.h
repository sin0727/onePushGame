#pragma once

#include "Enum.h"
#include "Resource.h"

// �X�e�[�W�N���X
class Stage {
public:
	int selctStage = 0;

	enum e_Type
	{
		e_��,
		e_�n��,
		e_���Ƃ���,
		e_�������Ȃ�,
		e_�j,
		e_�R�C��,
		e_�G�l�~�[,
		e_�v���C���[,
		e_�A�[��,
	};


	enum e_Ani
	{
		e_Normal,
		e_Walk1,
		e_Walk2,
		e_Jump,
		e_End,
		e_Ani_Total,
	};


	////�W�����v��Ԃ̗񋓑̒�`
	enum e_Jump
	{
		�n�ʂɒ��n,
		�W�����v��,
		������,
	};

	struct Pic
	{
		int p;
		int w;
		int t;
	};


	struct Ract
	{
		int x;
		int y;
		int w;
		int t;
		int k;
		double r;
		Pic p[e_Ani::e_Ani_Total];
		int a;
		bool d;
		int j;
		bool c;
	};


	struct Text
	{
		int k;
		int x;
		int y;
	};

	//�u���b�N�񎟌��z��
	Text** stagemake;


	int STAGE_TOTAL;
	int STAGE_WIDTH;
	int STAGE_HEIGHT;


	//�ꎟ���z��
	Ract* Block;

	//�v���C���[�̃A�h���X
	Ract* Player;

	//�A�[���̃A�h���X
	Ract* arme;

	/*int Typ[(int)chipSize::STAGE_MAX_X][(int)chipSize::STAGE_MAX_Y];
	int Typ_fd[(int)WindowSize::POS_MAX_X][(int)WindowSize::POS_MAX_Y];*/



	//�W�����v�t���O
	int Jump;

	//�W�����v�J�n����y���W�L�^
	int Jump_Ymem;

	//�J�E���^
	int Cou;

public:
	Stage();
	~Stage();

	// �X�V����
	void Update();

	// �X�V����
	void Updatetyutorial();

	// ����������
	void Init();

	// �`�揈��
	void Draw();
	
	//�X�e�[�W����
	void StagetyutorialInit();

	//�Q�[���G���h����
	void Game_End();

	//�Q�[���`��
	void stageDraw(/*int* PosX*/);

	//�u���b�N������
	void Block_Ini(Ract* b);
};