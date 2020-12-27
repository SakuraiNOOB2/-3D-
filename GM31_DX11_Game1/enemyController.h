#pragma once

#include "gameObject.h"

class CEnemyController :public CGameObject {

private:
	static int timer;

public:

	void Init();
	void Uninit();
	void Update();
	void Draw();

	void Reset();

};