#pragma once

#include "gameObject.h"

class CMenu :public CGameObject {

private:

	ID3D11Buffer* m_VertexBuffer = NULL;
	ID3D11ShaderResourceView* m_Texture = NULL;


public:

	void Init();
	void Uninit();
	void Update();
	void Draw();



};