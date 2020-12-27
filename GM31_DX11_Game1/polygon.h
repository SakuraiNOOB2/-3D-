#pragma once

#include "gameObject.h"

#define MENU_BACKGROUND "asset/texture/spaceMenu.png"
#define TUTORIAL_BACKGROUND "asset/texture/spaceTutorial.png"
#define RESULT_BACKGROUND "asset/texture/spaceResult.png"

class CPolygon:public CGameObject{

private:

	ID3D11Buffer* m_VertexBuffer = NULL;
	ID3D11ShaderResourceView* m_Texture = NULL;

	LPCSTR texture = NULL;

public:

	void Init();
	void Uninit();
	void Update();
	void Draw();

	void SetTexture(LPCSTR textureFile) { texture = textureFile; };
};