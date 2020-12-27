#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "camera.h"
#include "scene.h"
#include "player.h"


void CCamera::Init() {

	m_Position = D3DXVECTOR3(0.0f, 2.0, -5.0f);
	m_Target = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

}

void CCamera::Uninit() {


}

void CCamera::Update() {

	CPlayer* player = CManager::GetScene()->GetGameObject<CPlayer>(1);
	m_Target = player->GetPosition();

	//トップビュー
	m_Position = m_Target + D3DXVECTOR3(0.0f, 20.0f, -10.0f);

}

void CCamera::Draw() {

	//ピューマトリクス設定
	D3DXMatrixLookAtLH(&m_viewMatrix, &m_Position, &m_Target,
		&D3DXVECTOR3(0.0f, 1.0f, 0.0f));

	CRenderer::SetViewMatrix(&m_viewMatrix);

	//プロジェクションマトリクス設定
	D3DXMatrixPerspectiveFovLH(&m_projectionMatrix, 1.0f,
		(float)SCREEN_WIDTH / SCREEN_HEIGHT, 1.0f, 1000.0f);

	CRenderer::SetProjectionMatrix(&m_projectionMatrix);

}