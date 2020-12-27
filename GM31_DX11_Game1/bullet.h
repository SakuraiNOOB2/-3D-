#pragma once


#include "gameObject.h"

class CBullet:public CGameObject{

private:

	static class CModel* m_Model;

public:

	static void LoadModel();
	static void UnloadModel();

	void Init();
	void Uninit();
	void Update();
	void Draw();

};

