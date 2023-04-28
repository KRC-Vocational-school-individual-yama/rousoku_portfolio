#pragma once
#include<DxLib.h>


namespace DxLib {
	template<typename T>
	struct Vec2 {
		T x, y;

		template<typename CT>
		Vec2<CT> Cast() {
			return Vec2<CT>{
				static_cast<CT>(this->x),
					static_cast<CT>(this->y)
			};
		}

	};

	template<typename T>
	Vec2<T>operator +(const Vec2<T>& b, const Vec2<T>& c) {
		Vec2<T>ans;
		ans.x= b.x + c.x;
		ans.y= b.y + c.y;
		 return ans;
	}
	template<typename T>
	Vec2<T> operator +=(Vec2<T>& b, const Vec2<T>& c) {
		b.x += c.x;
		b.y += c.y;
		 return b;
	}
	template<typename T>
	Vec2<T> operator -(const Vec2<T>& b, const Vec2<T>& c) {
		Vec2<T>ans;
		ans.x= b.x - c.x;
		ans.y= b.y - c.y;
		 return ans;
	}
	template<typename T>
	Vec2<T> operator -=(Vec2<T>& b, const Vec2<T>& c) {
		b.x -= c.x;
		b.y -= c.y;
		return b;
	}
	template<typename T>
	Vec2<T> operator *(const Vec2<T>& b, const Vec2<T>& c) {
		Vec2<T>ans;
		ans.x= b.x * c.x;
		ans.y= b.y * c.y;
		 return ans;
	}
	template<typename T>
	Vec2<T> operator *=(Vec2<T>& b, const Vec2<T>& c) {
		b.x *= c.x;
		b.y *= c.y;
		return b;
	}
	template<typename T>
	Vec2<T> operator /(const Vec2<T>& b, const Vec2<T>& c) {
		Vec2<T>ans;
		ans.x = b.x / c.x;
		ans.y = b.y / c.y;
		return ans;
	}
	template<typename T>
	Vec2<T> operator /=(Vec2<T>& b, const Vec2<T>& c) {
		b.x /= c.x;
		b.y /= c.y;
		return b;
	}
	template<typename T>
	Vec2<T> operator %(const Vec2<T>& b, const Vec2<T>& c) {
		Vec2<T>ans;
		ans.x = b.x % c.x;
		ans.y = b.y % c.y;
		return ans;
	}
	template<typename T>
	Vec2<T> operator %=(Vec2<T>& b, const Vec2<T>& c) {
		b.x %= c.x;
		b.y %= c.y;
		return b;
	}

}