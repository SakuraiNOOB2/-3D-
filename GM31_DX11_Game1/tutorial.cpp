#include "main.h"
#include "manager.h"
#include "input.h"
#include "renderer.h"
#include "game.h"
#include "tutorial.h"
#include "tutorialBackground.h"


void CTutorial::Init() {

	AddGameObject<CtutorialBackground>(0);

	CtutorialBackground* background = CScene::GetGameObject<CtutorialBackground>(0);
	background->FadeStart(true, 60);

}

void CTutorial::Update() {

	CScene::Update();

	if (CInput::GetKeyTrigger(VK_RETURN)) {

		CManager::SetScene<CGame>();

	}

}

void CTutorial::Uninit() {

	/*CScene::Uninit();*/

}