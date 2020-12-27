#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "model.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "explosion.h"
#include "scene.h"
#include "result.h"
#include <random>

CModel* CEnemy::m_Model;

void CEnemy::LoadModel() {

	m_Model = new CModel();
	m_Model->Load("asset\\model\\enemy.obj");

}


void CEnemy::UnloadModel() {

	m_Model->Unload();
	delete m_Model;

}


void CEnemy::Init() {

	std::random_device rnd;     // �ǛQ���Ĥ������������ǥ��`�����əC������
	std::mt19937 mt(rnd()); //  ��륻��̥ĥ������`��32�ӥåȰ桢�����ϳ��ڥ��`��
	std::uniform_int_distribution<> rand(-8, 8);     // [-8, -8] �����һ������

	m_Position = D3DXVECTOR3((float)rand(mt), 1.0f, 8.0f);
	m_Rotation = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

}

void CEnemy::Uninit() {

	

}

void CEnemy::Update() {

	m_Position.z -= 0.05f;

	CPlayer* player = CManager::GetScene()->GetGameObject<CPlayer>(1);

	D3DXVECTOR3 playerPosition = player->GetPosition();

	D3DXVECTOR3 direction = m_Position - playerPosition;
	float length = D3DXVec3Length(&direction);

	if (length < 1.0f) {

		player->SetDead();

		return;
	}

	if (m_Position.z < -8.0f) {

		ResetPosition();
		return;
	}

}

void CEnemy::Draw() {

	//�}�g���N�X�ݒ�
	D3DXMATRIX world, scale, rot, trans;

	D3DXMatrixScaling(&scale, m_Scale.x, m_Scale.y, m_Scale.z);
	D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);
	D3DXMatrixTranslation(&trans, m_Position.x, m_Position.y, m_Position.z);

	world = scale * rot*trans;

	CRenderer::SetWorldMatrix(&world);

	m_Model->Draw();

}

void CEnemy::ResetPosition() {

	std::random_device rnd;     // �ǛQ���Ĥ������������ǥ��`�����əC������
	std::mt19937 mt(rnd()); //  ��륻��̥ĥ������`��32�ӥåȰ桢�����ϳ��ڥ��`��
	std::uniform_int_distribution<> rand(-8, 8);     // [-8, -8] �����һ������

	m_Position = D3DXVECTOR3((float)rand(mt), 1.0f, 8.0f);

}