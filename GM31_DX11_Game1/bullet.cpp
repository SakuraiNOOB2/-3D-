#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "model.h"
#include "bullet.h"
#include "enemy.h"
#include "scene.h"
#include "explosion.h"

CModel* CBullet::m_Model;

void CBullet::LoadModel() {

	m_Model = new CModel();
	m_Model->Load("asset\\model\\rocket.obj");

}

void CBullet::UnloadModel() {

	m_Model->Unload();
	delete m_Model;

}


void CBullet::Init() {

	m_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
}

void CBullet::Uninit() {

	

}

void CBullet::Update() {


	CScene* scene = CManager::GetScene();
	std::vector<CEnemy*> enemyList = scene->GetMultipleGameObjects<CEnemy>();

	m_Position.z += 0.1f;

	if (m_Position.z > 10.0f) {

		scene->AddGameObject<CExplosion>(1)->SetPosition(m_Position);

		SetDestroy();
		return;
	}

	for (CEnemy* enemy : enemyList) {

		D3DXVECTOR3 enemyPosition = enemy->GetPosition();

		D3DXVECTOR3 direction = m_Position - enemyPosition;
		float length = D3DXVec3Length(&direction);

		if (length < 4.0f) {

			scene->AddGameObject<CExplosion>(1)->SetPosition(m_Position);

			enemy->SetDestroy();
			SetDestroy();

			scene->AddGameObject<CEnemy>(1);

			return;
		}

	}


}

void CBullet::Draw() {

	//マトリクス設定
	D3DXMATRIX world, scale, rot, trans;

	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);

	world = scale * rot*trans;

	CRenderer::SetWorldMatrix(&world);

	m_Model->Draw();

}