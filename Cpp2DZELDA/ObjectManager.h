#pragma once
#include "Object.h"

class ObjectManager
{
	DECLARE_SINGLE(ObjectManager);
public:

	void Add(Object* object);
	void Remove(Object* object);
	void Clear();

	const vector<Object*>& GetObjects() { return this->_objects; }

	template <typename T>
	T* CreateObject()
	{
		static_assert(is_convertible_v<T*, Object*>);
		T* object = new T();
		object->Init();

		return object;
	}
private:
	vector<Object*> _objects;
};

