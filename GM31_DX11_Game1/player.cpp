#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "model.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "explosion.h"
#include "scene.h"
#include "result.h"

void CPlayer::Init() {

	m_Model = new CModel();
	m_Model->Load("asset\\model\\Arc170.obj");

	m_Position = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	//m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

	isDead = false;

	D3DXQuaternionIdentity(&m_Quaternion);

}

void CPlayer::Uninit() {

	m_Model->Unload();
	delete m_Model;

}

void CPlayer::Update() {

	if (CInput::GetKeyPress('A')) {

		m_Position.x -= 0.1f;

		D3DXQUATERNION quat;
		D3DXQuaternionRotationAxis(&quat, &D3DXVECTOR3(0.0f, 0.0f, 1.0f), 0.1f);

		//Quaternionの合成
		m_Quaternion *= quat;	//m_Rotation.z+=0.1f;

		/*m_Rotation.y -= 0.05f;*/
	}
	if (CInput::GetKeyPress('D')) {

		m_Position.x += 0.1f;

		D3DXQUATERNION quat;
		D3DXQuaternionRotationAxis(&quat, &D3DXVECTOR3(0.0f, 0.0f, 1.0f), -0.1f);

		//Quaternionの合成
		m_Quaternion *= quat;	//m_Rotation.z+=0.1f;

		/*m_Rotation.y += 0.05f;*/
	}

	D3DXVECTOR3 forward = GetForward();//前方向ベクトル

	if (CInput::GetKeyPress('W')) {

		m_Position += forward * 0.1f;
	}
	if (CInput::GetKeyPress('S')) {

		m_Position -= forward * 0.1f;
	}

	if (m_Position.z > 5.0f) {

		m_Position.z = 5.0f;

	}
	if (m_Position.z < -5.0f) {

		m_Position.z = -5.0f;

	}
	if (m_Position.x > 5.0f) {

		m_Position.x = 5.0f;

	}
	if (m_Position.x < -5.0f) {

		m_Position.x = -5.0f;

	}




	if (CInput::GetKeyTrigger(VK_SPACE)) {

		CScene* scene = CManager::GetScene();
		scene->AddGameObject<CBullet>(1)->SetPosition(m_Position);

	}



}

void CPlayer::Draw() {

	//マトリクス設定
	D3DXMATRIX world, scale, rot, trans;

	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);

	//D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixRotationQuaternion(&rot, &m_Quaternion);

	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);

	world = scale * rot*trans;

	CRenderer::SetWorldMatrix(&world);

	m_Model->Draw();

}