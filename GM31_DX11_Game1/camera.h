#pragma once

#include "gameObject.h"

class CCamera:public CGameObject{

private:

	D3DXVECTOR3 m_Target;
	D3DXMATRIX m_viewMatrix;
	D3DXMATRIX m_projectionMatrix;

public:

	void Init();
	void Uninit();
	void Update();
	void Draw();

	D3DXMATRIX GetViewMatrix() { return m_viewMatrix; };


};

