#include "pch.h"
#include "ObjectManager.h"

void ObjectManager::Add(Object* object)
{
	if (object == nullptr)
	{
		return;
	}

	auto findIt = std::find(this->_objects.begin(), this->_objects.end(), object);

	if (findIt == this->_objects.end())
	{
		this->_objects.push_back(object);
	}
}

void ObjectManager::Remove(Object* object)
{
	if (object == nullptr)
	{
		return;
	}

	auto findIt = std::find(this->_objects.begin(), this->_objects.end(), object);
	if (findIt != this->_objects.end())
	{
		this->_objects.erase(findIt);
		delete object;
	}
}

void ObjectManager::Clear()
{
	for (auto object : this->_objects)
	{
		delete object;
	}

	this->_objects.clear();
}
