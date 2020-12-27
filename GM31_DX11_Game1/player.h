#pragma once

#include "gameObject.h"
#include "model.h"

class CPlayer:public CGameObject{	//�p��(�C���w���^���X)

private:

	CModel* m_Model;

	D3DXQUATERNION m_Quaternion;

	

public:
	bool isDead = false;

	CPlayer(){}
	~CPlayer(){}

	void Init();
	void Uninit();
	void Update();
	void Draw();

	void SetDead() { isDead = true; }
};