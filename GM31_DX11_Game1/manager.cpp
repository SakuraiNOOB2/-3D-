
#include "main.h"
#include "manager.h"
#include "renderer.h"
#include "input.h"
#include "polygon.h"
#include "camera.h"
#include "field.h"
#include "model.h"
#include "player.h"
#include "scene.h"
#include "title.h"
#include "game.h"

#include <list>

CScene* CManager::m_Scene;

void CManager::Init()
{

	CRenderer::Init();
	CInput::Init();

	////m_Scene = new CScene();

	//m_Scene = new CGame();
	//m_Scene->Init();

	SetScene<CTitle>();

}

void CManager::Uninit()
{

	m_Scene->Uninit();
	delete m_Scene;

	CInput::Uninit();

	CRenderer::Uninit();

}

void CManager::Update()
{
	CInput::Update();

	m_Scene->Update();

}

void CManager::Draw()
{

	CRenderer::Begin();

	LIGHT light;
	light.Enable = true;
	light.Direction = D3DXVECTOR4(1.0f, -1.0f, 1.0f, 0.0f);
	D3DXVec4Normalize(&light.Direction, &light.Direction);
	light.Ambient = D3DXCOLOR(0.1f, 0.1f, 0.1f, 1.0f);
	light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.f, 1.0f);
	CRenderer::SetLight(light);

	m_Scene->Draw();

	light.Enable = false;
	CRenderer::SetLight(light);

	CRenderer::End();

}
