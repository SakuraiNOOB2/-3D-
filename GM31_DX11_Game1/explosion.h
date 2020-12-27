#pragma once

#include "gameObject.h"

class CExplosion :public CGameObject {

private:

	int m_Count;

	ID3D11Buffer* m_VertexBuffer = NULL;
	ID3D11ShaderResourceView* m_Texture = NULL;


public:

	CExplosion() {}
	~CExplosion() {}

	void Init();
	void Uninit();
	void Update();
	void Draw();


};