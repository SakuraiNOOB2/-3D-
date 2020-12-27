#pragma once

#include "main.h"
#include "gameObject.h"
#include <list>
#include <typeinfo>
#include <vector>


class CScene {

protected:

	std::list<CGameObject*> m_gameObject[3];	//STL���X�g�\��

public:

	CScene(){}
	virtual ~CScene(){}

	virtual void Init() = 0;

	virtual void Uninit() {

		for (int i = 0; i < 3; i++) {

			for (CGameObject* object : m_gameObject[i]) {

				object->Uninit();
				delete object;
			}

			m_gameObject[i].clear();	//���X�g�̃N���A


		//delete[] g_gameObject;	//���߁I

		}

	}

	virtual void Update() {

		for (int i = 0; i < 3; i++) {

			for (CGameObject* object : m_gameObject[i]) {

				object->Update();		//���Ԑ�(�|�����[�t�B�Y��)
			}

			m_gameObject[i].remove_if(
				[](CGameObject* object) {
				return object->Destroy(); }
			);
			//�����_��

		}
	}

	virtual void Draw() {

		for (int i = 0; i < 3; i++) {

			for (CGameObject* object : m_gameObject[i]) {

				object->Draw();

			}

		}

	}

	//cpp�ɏ����Ȃ����ƁI�I�I
	template <typename T>
	T* AddGameObject(int layer) {

		T* gameObject = new T();
		m_gameObject[layer].push_back(gameObject);
		gameObject->Init();

		return gameObject;

	}

	template <typename T>
	T* GetGameObject(int layer) {

		for (CGameObject* object : m_gameObject[layer]) {

			//�^�𒲂ׂ�
			if (typeid(*object) == typeid(T)) {

				return (T*)object;

			}
		}

		return NULL;

	}

	template <typename T>
	std::vector<T*> GetMultipleGameObjects() {

		std::vector<T*> objects;	//STL�̔z��

		for (int i = 0; i < 3; i++) {

			for (CGameObject* object : m_gameObject[i]) {

				if (typeid(*object) == typeid(T)) {

					objects.push_back((T*)object);

				}

			}

		}
		return objects;
	}

	


};
