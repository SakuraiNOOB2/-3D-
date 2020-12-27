#include "main.h"
#include "manager.h"
#include "input.h"
#include "renderer.h"
#include "title.h"
#include "game.h"
#include "tutorial.h"
#include "menu.h"


void CTitle::Init() {

	AddGameObject<CMenu>(0);

	CMenu* menu = CScene::GetGameObject<CMenu>(0);
	menu->FadeStart(true, 60);
}

void CTitle::Update() {

	CScene::Update();

	if (CInput::GetKeyTrigger(VK_RETURN)) {

		CManager::SetScene<CTutorial>();

	}

}

void CTitle::Uninit() {

	

}