#include "main.h"
#include "manager.h"
#include "input.h"
#include "renderer.h"
#include "result.h"
#include "title.h"
#include "game.h"
#include "resultBackground.h"


void CResult::Init() {

	AddGameObject<CresultBackground>(0);

	CresultBackground* background = CScene::GetGameObject<CresultBackground>(0);
	background->FadeStart(true, 60);
}

void CResult::Update() {

	CScene::Update();

	if (CInput::GetKeyTrigger(VK_RETURN)) {

		CManager::SetScene<CTitle>();

	}

}

void CResult::Uninit() {

	

}