#pragma once

#include"myDxLib.h"
#include<string>
#include<vector>
#include<list>
#include<assert.h>
class Scene;

class Object {
public:
	Object(Scene* sc):myScene(sc) ,init(true){}
	virtual ~Object()=default;
	virtual void Init()		=0;
	virtual void Update()	=0;
	virtual void Draw()		=0;

	static inline bool CircleCollision(Vec2<float>_pos, float _rad, Vec2<float>_pos2, float _rad2) {
		float a, b, c;
		a = _pos2.x - _pos.x;
		b = _pos2.y - _pos.y;
		c = _rad + _rad2;
		if (a * a + b * b < c * c) {
			return true;
		}
		return false;
	}
	static inline bool SquareCollision(Vec2<float> _pos, Vec2<float>_size, Vec2<float> _pos2, Vec2<float>_size2) {
		bool up=false,down=false,left=false,right=false;
		up = _pos.y<_pos2.y+_size2.y;
		down = _pos.y+_size.y>_pos2.y;
		left = _pos.x<_pos2.x+_size2.x;
		right = _pos.x+_size.x>_pos2.x;
		if (up && down && left && right)
			return true;
		return false;
	}

	Scene* GetScene() {return myScene;}
	bool GetInitFlag() { return init; }
	void SetInitFlag(bool _flag) { init = _flag; }
private:
	Scene* myScene;
	bool init;
};
