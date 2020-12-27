#pragma once

#include "gameObject.h"
#include "model.h"

class CField:public CGameObject{

private:

	CModel* m_Model;

public:

	CField(){}
	~CField(){}

	void Init();
	void Uninit();
	void Update();
	void Draw();



};

