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
		e_�v���C���[,
		e_�A�[��,
		e_�R�C��,
		e_�j,
		e_�G�l�~�[,
		
	};


	enum e_Ani
	{
		e_Normal,
		e_Walk1,
		e_Walk2,
		e_Jump,
		e_End,
		e_dfg,
		e_df,
		e_Ani_Total,
	};


	////�W�����v��Ԃ̗񋓑̒�`
	enum e_Jump
	{
		�n�ʂɒ��n,
		�W�����v��,
		������,
	};

	struct
	{
		int Typ[(int)chipSize::STAGE_MAX_X][(int)chipSize::STAGE_MAX_Y];
		int Typ_Exp[(int)WindowSize::POS_MAX_X][(int)WindowSize::POS_MAX_Y];

	}Blo;

	

	int STAGE_TOTAL;
	int STAGE_WIDTH;
	int STAGE_HEIGHT;


	bool change = false;
	int changecount = 2;

	//�v���C���[

	struct
	{
		struct
		{
			int x = 210;
			int y = (int)WindowSize::POS_MAX_Y - 5 * (int)chipSize::CELLX;
			int prex = 0;
			int prey = 0;
			int Yin = (int)WindowSize::POS_MAX_Y - 3 * (int)chipSize::CELLY;
			int X_Sta;
		}Pos;

		struct
		{
			int le_up = 0;
			int ri_up = 0;
			int le_do = 0;

			int ri_do = 0;
		}In;

		struct
		{
			int le_up = 0;
			int ri_up = 0;
			int le_do = 0;
			int ri_do = 0;
		}Out;

	}Player;

	//�v���C���[�ړ�
	const int Movx = (int)chipSize::CELLX / 10;
	int Movy = 0;
	const int Movy_max = (int)chipSize::CELLY * 2;

	int Sta_PosX = 0;


	struct
	{
		bool Xpl = 0;
		bool Xmi = 0;
		bool Jum = 0;
		bool Rev = 0;
	}Fla;


	int cou = 0;
	double T = 0.0;
	const double T_k = 10.0;


	//�A�[��
	struct
	{
		struct
		{
			int x = 790;
			int y = (int)WindowSize::POS_MAX_Y - 20 * (int)chipSize::CELLY;
			int prex = 0;
			int prey = 0;
			int Yin = (int)WindowSize::POS_MAX_Y - 3 * (int)chipSize::CELLY;
			int X_Sta;
		}Pos;

		struct
		{
			int le_up = 0;
			int ri_up = 0;
			int le_do = 0;

			int ri_do = 0;
		}In;

		struct
		{
			int le_up = 0;
			int ri_up = 0;
			int le_do = 0;
			int ri_do = 0;
		}Out;

	}Arme;

	//�A�[���ړ�
	const int Movx2 = (int)chipSize::CELLX / 8;

	//�߂�
	const int Movx3 = (int)chipSize::CELLX / 11;
	//���ړ�
	const int Movy2 = (int)chipSize::CELLY / 10;
	const int Movy3 = (int)chipSize::CELLY / 12;

	int Sta_PosX2 = 0;

	struct
	{
		bool Xpl = 0;
		bool Xmi = 0;
		bool Ydw = 0;
		bool Yup = 0;
	}Fla2;


	int cou2 = 0;
	double T2 = 0.0;
	const double T_k2 = 10.0;

	bool arme = true;
	bool rturn = false;
	bool rterunback = false;
	bool armecath = false;
	bool armecathmove = false;
	bool armelost = false;
	int backmovecount = 0;
	int armecount = 240;

	//�{�b�N�X
	int boxx = 590;
	int boxy = (int)WindowSize::POS_MAX_Y - 5 * (int)chipSize::CELLY;

	int ArmeSize = 96;
	int boxx2 = 590;
	int boxy2 = (int)WindowSize::POS_MAX_Y - 6 * (int)chipSize::CELLY;
	int boxx2pre = 0;
	int boxy2pre = 0;
	int boxx2cath = 0;
	int boxy2cath = 0;
	bool dust = true;
	//�R�C��
	int coinx = 800;
	int coiny = (int)WindowSize::POS_MAX_Y - 5 * (int)chipSize::CELLY;

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
	/*void Game_End();*/

	//�Q�[���`��
	void stageDraw();

	//�Q�[���A�N�V�����o��
	void gameOut();

	//�A�N�V�����v�Z
	void gameCal();

	//�v���C���[����я���������
	void cha();
};

Stage stage;