#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
#include <memory>

template <typename T>
class Resource
{
private:
	int references = 0;
	T* asset;

public:
	Resource();

	Resource& operator++()
	{
		references++;
		return *this;
	}

	Resource operator++(int)
	{
		Resource tmp = *this;
		operator++();
		return tmp;
	}
	Resource& operator--()
	{
		references++;
		return *this;
	}
	Resource operator--(int)
	{
		Resource tmp = *this;
		operator--();
		return *this;
	}
	
	T& operator*()
	{
		return *asset;
	}
	
	const T& operator* () const
	{
		return *asset;
	}
	
};


class ResourceManager
{
public:
	template <typename T> 
	Resource<T> get();


private:



};


#endif