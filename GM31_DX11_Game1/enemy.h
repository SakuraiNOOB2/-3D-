#pragma once

#include "gameObject.h"


class CEnemy :public CGameObject {

private:
	static CModel* m_Model;

public:

	static void LoadModel();
	static void UnloadModel();

	void Init();
	void Uninit();
	void Update();
	void Draw();

	void ResetPosition();

};
