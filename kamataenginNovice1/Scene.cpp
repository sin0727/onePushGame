#include "Scene.h"
#include <Novice.h>
#include "Calc.h"
#include "InputDevice.h.h"

Scene::Scene() {

}
Scene::~Scene() {
	/*if (stage != nullptr) delete stage;*/
}

int sinn = 1;

void Scene::Update() {
	switch (scene)
	{
	case (int)SceneType::title:
		UpdateTitle();
		break;
	case (int)SceneType::menu:
		UpdateMenu();
		break;
	case (int)SceneType::game:
		switch (/*stage->selctStage*/1)
		{
		case (int)StageType::tutorial1:
			/*stage->Updatetyutorial();*/
			break;
		case (int)StageType::game_stage1:
			/*stage->Update();*/
			/*if (stage->is_game_clear == true) {
			scene = (int)SceneType::goal;
		}
		if (stage->is_game_over == true) {
			scene = (int)SceneType::game_over;
		}*/
			break;
		}
		break;

		/*case (int)SceneType::goal:
			Updatecrear();*/
			//	break;
			///*case (int)SceneType::game_over:
			//	Updategameover();*/
			//	break;
	}
}

void Scene::Draw() {
	switch (scene)
	{
	case (int)SceneType::title:
		DrawTitle();
		break;
	case (int)SceneType::menu:
		DrawMenu();
		break;
	case (int)SceneType::game:
		switch (/*stage->selctStage*/1)
		{
		case (int)StageType::tutorial1:
			/*stage->Draw();*/
		
			break;
		case (int)StageType::game_stage1:
			/*stage->Draw();*/
			break;
		}

		break;

		
		
		//case (int)SceneType::goal:
		//	Drawcrear();
		//	break;
		///*case (int)SceneType::game_over:
		//	Drawgameover();*/
		//	break;
	}
}

// titleの更新処理
void Scene::UpdateTitle() {

	if (Keyboard::pre_Keys[DIK_SPACE] == 0 && Keyboard::keys[DIK_SPACE] != 0) {
		scene = (int)SceneType::menu;
	}
}

// titleの更新処理
void Scene::UpdateMenu() {

	if (Keyboard::keys[DIK_A] == 0 && Keyboard::pre_Keys[DIK_A] != 0) {
		curx = tyutorialx;
		cury = tyutorialy + 100;
		select = 0;
	}

	if (Keyboard::keys[DIK_D] == 0 && Keyboard::pre_Keys[DIK_D] != 0) {
		curx = stage1x;
		cury = stage1y + 100;
		select = 1;
	}


	switch (select)
	{
	case (int)SelectType::tutorial:
		if (Keyboard::pre_Keys[DIK_SPACE] == 0 && Keyboard::keys[DIK_SPACE] != 0)
		{
			scene = (int)SceneType::game;
			/*stage->selctStage = 0;*/
		}
		break;

	case (int)SelectType::stage1:
		if (Keyboard::pre_Keys[DIK_SPACE] == 0 && Keyboard::keys[DIK_SPACE] != 0)
		{
			scene = (int)SceneType::game;
			/*stage->selctStage = 1;*/
		}
		break;
	}

	
}


void Scene::Updatecrear() {
	//crearframe++;
	//if (crearframe >= 160)
	//{
	//	is_reset = true;
	//	stage->startcount = 10;
	//}

}


void Scene::Updategameover() {
	/*gameoverframe++;
	if (gameoverframe >= 100) {
		is_reset = true;
		stage->startcount = 10;
	}*/

}
// タイトルの描画
void Scene::DrawTitle() {
	Novice::DrawSprite(0, 0, Image::title, 1.0f, 1.0f, 0.0f, WHITE);
	/*Novice::DrawSprite(0, 0, Image::start_button[animation_index1], 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, 0, Image::tutorial_button[animation_index2], 1.0f, 1.0f, 0.0f, WHITE);*/

}

// メニューの描画
void Scene::DrawMenu() {
	
	Novice::DrawSprite(0, 0, Image::menu, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(stage1x, stage1y, Image::stage_1, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(tyutorialx, tyutorialy, Image::tyutorial, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(curx, cury, Image::cursol, 1.0f, 1.0f, 0.0f, WHITE);
}

void Scene::Drawcrear() {

	/*Novice::DrawSprite(0, 0, Image::crear, 1.0f, 1.0f, 0.0f, WHITE);
	Calc::DrawNum(stage->sec_timer * 120, 1000, 400, 220, 0.7, 0.7, 0.0, WHITE);*/
}

void Scene::Drawgameover() {
	/*Novice::DrawSprite(0, 0, Image::gameover, 1.0f, 1.0f, 0.0f, WHITE);

	Novice::ScreenPrintf(0, 0, "%d", crearframe);*/
}

void Scene::startcount() {
	/*Calc::DrawNum(stage->startcount, (int)WindowSize::width * 0.45f, (int)WindowSize::height * 0.1f, 220, 0.7, 0.7, 0.0, 0xFFFFFFaa);*/
}