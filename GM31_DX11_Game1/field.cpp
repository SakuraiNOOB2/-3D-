#include "main.h"
#include "renderer.h"
#include "field.h"
#include "player.h"
#include "scene.h"

void CField::Init() {

	m_Model = new CModel();
	m_Model->Load("asset\\model\\skydome.obj");
	
	m_Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 45.0f, 0.0f);
	m_Scale = D3DXVECTOR3(-100.0f, -100.0f, -100.0f);

}


void CField::Uninit() {

	m_Model->Unload();
	delete m_Model;

}


void CField::Update() {

	CPlayer* player = CManager::GetScene()->GetGameObject<CPlayer>(1);
	m_Position = player->GetPosition();

}


void CField::Draw() {

	//マトリクス設定
	D3DXMATRIX world, scale, rot, trans;

	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);

	world = scale * rot*trans;

	CRenderer::SetWorldMatrix(&world);

	m_Model->Draw();

}



