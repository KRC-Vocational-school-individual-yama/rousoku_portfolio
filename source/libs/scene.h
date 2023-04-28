#pragma once
#include<list>

class Object;

class Scene {
public:
	Scene();
	virtual ~Scene();
	virtual void Update();
	virtual void Draw();

	template<class C>
	Object* Create() {
		C* tempObject= new C(this);
		objectList.emplace_back(tempObject);
		return tempObject;
	}
	template<class C>
	C* Invoke() {
		for (auto it = objectList.begin(); it != objectList.end(); it++) {
			C* obj = dynamic_cast<C*>(*it);
			if (obj != nullptr) {
				return obj;
			}

		}
		return nullptr;
	}
	template<class C>
	void Destroy() {
		//for (auto it = objectList.begin(); it != objectList.end(); it++) {
		//	C& obj = *it;//�Q�ƌ^�@�Z����Ⴄ�@�^�𕡐��݂����Ȋ���
		//	C* deleteisObject;
		//	if (obj == deleteisObject) {
		//		delete obj;
		//		objectList.erase(it);
		//		return;
		//	}
		//
		//}
		for (auto it = objectList.begin(); it != objectList.end(); it++) {
			C* obj = dynamic_cast<C*>(*it);
			if (obj != nullptr) {
				delete obj;
				objectList.erase(it);
				return;
			}

		}
	}

private:
	void AllDestroy();

	std::list<Object*>objectList;

};
