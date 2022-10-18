#include "Stage.h"
#include "Novice.h"
#include "Calc.h"
#include "InputDevice.h.h"
#include "Resource.h"


Stage::Stage() {
	Init();

}
Stage::~Stage() {

}

// �X�V����
void Stage::Updatetyutorial() {
	StagetyutorialInit();
}

	// �X�V����
void Stage::Update() {

}

// ����������
void Stage::Init() {

}

// �`�揈��
void Stage::Draw() {
	Novice::DrawSprite(0, 0, Image::sky, 1.0f, 1.0f, 0.0f, WHITE);
	stageDraw();
}

//�u���b�N������
void Stage::Block_Ini(Ract* b) //�|�C���^�擾
{
	b->x = 0;   //x���W�@�@�@�@//�Q�Ɠn��
	b->y = 0;   //y���W
	b->w = 0;   //��
	b->t = e_Type::e_��;   //����
	b->k = 0;   //���
	b->r = 0.;   //��]�p�x

	for (int i = 0; i < e_Ani::e_Ani_Total; i = i + 1)
	{
		b->p[i].p = 0;    //�ʐ^�̃n���h��
		b->p[i].w = 0;    //�ʐ^�̕�
		b->p[i].t = 0;    //�ʐ^�̌���
	}

	b->a = e_Ani::e_Normal;  //�A�j���[�V����
	b->d = FALSE;  //����
	b->j = 0;  //�W�����v�J�E���^
	b->c = FALSE;  //�L�����N�^�[���ۂ�(�������ۂ�)
}

//�X�e�[�W����
void Stage::StagetyutorialInit() {

	//�t�@�C���擾
	char name[] = { "./picter/stage/tyutorial.txt" };
	FILE* fp = NULL;
	errno_t error = fopen_s(&fp, name, "r");

	if (error == NULL && fp != NULL)
	{
		fscanf_s(fp, "%d\n", &STAGE_TOTAL);
		fscanf_s(fp, "%d\n", &STAGE_WIDTH);
		fscanf_s(fp, "%d\n", &STAGE_HEIGHT);

		stagemake = new Text * [STAGE_WIDTH];
		for (int i = 0; i < STAGE_WIDTH; i = i + 1)
		{
			stagemake[i] = new Text[STAGE_HEIGHT];
		}

		for (int y = 0; y < STAGE_HEIGHT; y = y + 1)
		{
			for (int x = 0; x < STAGE_WIDTH; x = x + 1)
			{
				fscanf_s(fp, "%d\n", &stagemake[x][y].k);
				stagemake[x][y].x = x;
				stagemake[x][y].y = y;
			}
		}

		//�t�@�C�������
		fclose(fp);
	}


	//�������m��
	Block = new Ract[STAGE_TOTAL];
	//Text����Ract�ɕϊ��A�e�L�X�g�̏����ꎟ���z��Ɋi�[
	int i = 0;
	for (int y = 0; y < STAGE_HEIGHT; y = y + 1)
	{
		for (int x = 0; x < STAGE_WIDTH; x = x + 1)
		{
			//�u���b�N�����̂Ƃ�
			if (stagemake[x][y].k == e_Type::e_��)
			{
				//�u���b�N������
				Block_Ini(&Block[i]);
			}
			else
			{
				switch (stagemake[x][y].k)

				{
				case e_Type::e_�n��:

					Block[i].p[0].p = Image::stageBlock;

					//����
					Block[i].d = FALSE;
					//�L�������ۂ�
					Block[i].c = FALSE;

					break;

				case e_Type::e_���Ƃ���:
					Block[i].p[0].p = Image::stageBlock;
					/*Block[i].p0 = ;*/

					Block[i].d = FALSE;
					Block[i].c = FALSE;

					break;
				case e_Type::e_�������Ȃ�:
					Block[i].p[0].p = Image::stageBlock;
					/*Block[i].p0 = ;*/

					Block[i].d = FALSE;
					Block[i].c = FALSE;

					break;
				case e_Type::e_�j:
					Block[i].p[0].p = Image::stageBlock;
					/*Block[i].p0 = ;*/

					Block[i].d = FALSE;
					Block[i].c = FALSE;

					break;
				case e_Type::e_�R�C��:
					Block[i].p[0].p = Image::stageBlock;
					/*Block[i].p0 = ;*/

					Block[i].d = FALSE;
					Block[i].c = FALSE;

					break;

				case e_Type::e_�G�l�~�[:
					Block[i].p[0].p = Image::stageBlock;
					/*Block[i].p0 = ;*/

					Block[i].d = FALSE;
					Block[i].c = FALSE;

					break;

				case e_Type::e_�v���C���[:
					Block[i].p[0].p = Image::stageBlock;
					/*Block[i].p0 = ;*/

					Block[i].d = FALSE;
					Block[i].c = TRUE;

					break;
				case e_Type::e_�A�[��:
					Block[i].p[0].p = Image::stageBlock;
					/*Block[i].p0 = ;*/

					Block[i].d = FALSE;
					Block[i].c = TRUE;

					break;

				/*case e_Type::e_:

					Block[i].p[e_Ani::e_Normal].p = LoadGraph("./supermario/mario.png");
					Block[i].p[e_Ani::e_Walk1].p = LoadGraph("./supermario/mariowalk.png");
					Block[i].p[e_Ani::e_Walk2].p = LoadGraph("./supermario/mariowalk2.png");
					Block[i].p[e_Ani::e_Jump].p = LoadGraph("./supermario/mariozyanpu.png");
					Block[i].p[e_Ani::e_End].p = LoadGraph("./supermario/sky.png");


					Block[i].d = FALSE;

					Block[i].c = TRUE;

					break;*/
				}

				////�u���b�N�ʐ^������݂ƕ��擾
				//GetGraphSize(Block[i].p[0].p, &Block[i].p[0].w, &Block[i].p[0].t);
				////�u���b�N�̕��ƌ��݂���
				//Block[i].w = Block[i].p[0].w;
				//Block[i].t = Block[i].p[0].t;
				
				Block[i].w = 32/*(int)chipSize::CELLX*/;
				Block[i].t = 32/*(int)chipSize::CELLY*/;

				//�u���b�N�̍��W.���.��]�p�x.�W�����v�J�E���^����
				Block[i].x = stagemake[x][y].x * 50;
				Block[i].y = stagemake[x][y].y * 50;
				Block[i].k = stagemake[x][y].k;
				Block[i].r = 0;
				Block[i].j = 0;
				Block[i].a = e_Ani::e_Normal;
			}

			//���[�v�J�E���^
			i = i + 1;
		}
	}

	//���������(Text�^�@Stage)
	for (int i = 0; i < STAGE_WIDTH; i = i + 1)
	{
		delete[] stagemake[i];
	}
	delete[] stagemake;


	//�W�����v���̕ϐ�������
	Jump = e_Jump::�n�ʂɒ��n;

	//�J�E���^
	Cou = 0;

}

//�Q�[���`��
void Stage::stageDraw()
{
	/*int pic = 0;
	for (int x = 0; x < (int)chipSize::STAGE_MAX_X; x = x + 1)
	{
		for (int y = 0; y < (int)chipSize::STAGE_MAX_Y; y = y + 1)
		{
			switch (Typ[x][y])
			{
			case 0:
				
				break;
			case 1:
				pic = Image::stageBlock;
				break;
			case 2:
				pic = Image::makeblock;
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			}
			Novice::DrawSprite((int)chipSize::CELLX * x, (int)chipSize::CELLX * y, pic, 1.0f, 1.0f, 0.0f, WHITE);
		}
	}*/

	//�u���b�N�`��
	for (int i = 0; i < STAGE_TOTAL; i = i + 1)
	{

		//�}���I�`��
		if (Block[i].k == e_Type::e_�v���C���[)
		{

			switch (Player->d)
			{
			case FALSE: //�E����������


				break;

			case TRUE: //������������


				break;
			}
		}

		//�}���I�ȊO�̕`��
		else if (Block[i].k != e_Type::e_��)
		{
			switch (Block[i].d)
			{
			case FALSE: //�E����������
				Novice::DrawSprite(Block[i].x, Block[i].y, Block[i].p[0].p, 1.0f, 1.0f, 0.0f, WHITE);
				
				break;
				//������������
			case TRUE:
				Novice::DrawSprite(Block[i].x, Block[i].y, Block[i].p[0].p, 1.0f, 1.0f, 0.0f, WHITE);
				
				break;
			}
		}
	}
}
	





	

//�Q�[���I�����̏������s���֐�
//void Stage::Game_End()
//{
//	//���������(Block)
//	delete[] Block;
//
//	//�Q�[��������
//	StagetyutorialInit();
//}


