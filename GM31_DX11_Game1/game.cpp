#include "main.h"
#include "scene.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "polygon.h"
#include "camera.h"
#include "field.h"
#include "model.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "explosion.h"
#include "title.h"
#include "result.h"
#include "game.h"
#include <list>
#include <typeinfo>
#include <vector>


void CGame::Init() {

	CBullet::LoadModel();
	CEnemy::LoadModel();

	//初期化の順番は描画の順番となります。

	AddGameObject<CCamera>(0);
	AddGameObject<CPlayer>(1);
	AddGameObject<CEnemy>(1);
	AddGameObject<CEnemy>(1);
	AddGameObject<CEnemy>(1);
	AddGameObject<CEnemy>(1);
	AddGameObject<CEnemy>(1);
	AddGameObject<CEnemy>(1);
	AddGameObject<CEnemy>(1);
	AddGameObject<CField>(1);
}


void CGame::Uninit() {

	CScene::Uninit();

	CBullet::UnloadModel();
	CEnemy::UnloadModel();
}


void CGame::Update() {

	CScene::Update();

	CPlayer* player = CScene::GetGameObject<CPlayer>(1);
	

	if (player->isDead) {

		CManager::SetScene<CResult>();

	}


}