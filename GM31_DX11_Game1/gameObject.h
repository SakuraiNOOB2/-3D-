#pragma once

#include "main.h"
#include "manager.h"
#include "renderer.h"

class CGameObject {

	//アクセス指定子
protected:		

	D3DXVECTOR3 m_Position;
	D3DXVECTOR3 m_Rotation;
	D3DXVECTOR3 m_Scale;
	
	bool m_Destroy = false;

	//アクセス指定子
public:

	CGameObject() {};		//コンストラクタ
	virtual ~CGameObject(){}		//デストラクタ

	virtual void Init() = 0;	//仮想関数
	virtual void Uninit() = 0;	//純粋仮想関数
	virtual void Update() = 0;
	virtual void Draw() = 0;

	D3DXVECTOR3 GetPosition() { return m_Position; }
	D3DXVECTOR3 GetRotation() { return m_Rotation; }
	D3DXVECTOR3 GetScale() { return m_Scale; }
	D3DXVECTOR3 GetForward() {

		D3DXMATRIX rot;
		D3DXMatrixRotationYawPitchRoll(&rot, m_Rotation.y, m_Rotation.x, m_Rotation.z);

		D3DXVECTOR3 forward;
		forward.x = rot._31;
		forward.y = rot._32;
		forward.z = rot._33;

		return forward;
	}



	void SetPosition(D3DXVECTOR3 position) { m_Position = position; }
	void SetRotation(D3DXVECTOR3 rotation) { m_Rotation = rotation; }
	void SetScale(D3DXVECTOR3 scale) { m_Scale = scale; }


	void SetDestroy() { m_Destroy = true; }
	void Reset() { m_Destroy = false; }

	bool Destroy() {

		if (m_Destroy) {

			Uninit();
			delete this;
			return true;
		}
		else {

			return false;
		}


	}

protected:

	bool alphaOut;
	bool isFade;
	float alpha = 0.0f;
	float addAlpha;

public:

	void FadeUpdate(){
		if (!isFade) {

			return;
		}

		alpha += addAlpha;

		if (alphaOut) {

			if (alpha >= 1.0f) {

				alpha = 1.0f;
				isFade = false;
			}

		}
		else {
			if (alpha <= 0.0f) {

				alpha = 1.0f;
				isFade = false;
			}
		}
	}

	void FadeStart(bool fadeOut, int frame){

		alphaOut = fadeOut;
		addAlpha = 1.0f / frame;
		isFade = true;

		if (alphaOut) {

			alpha = 0.0f;
		}
		else {

			alpha = 1.0f;
			addAlpha = -addAlpha;
		}
	}

};