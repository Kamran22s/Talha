#include<iostream>
#include "array.h"
using namespace std;

bool Array::isValidIndex(int index) const
{
	return (index >= 0 && index < capacity);
}
Array::Array(int argCount, ...)
{
	if (argCount <= 0)
	{
		capacity = 0;
		data = nullptr;
		return;

	}
	capacity = argCount;
	va_list argList;
	__crt_va_start(argList, argCount);
	data = new int[argCount];
	for (int i = 0; i < argCount; i++)
	{
		data[i] = __crt_va_arg(argList, int);

	}
	__crt_va_end(argList);
}

Array::Array(const Array & ref)
{
	if (!ref.data)
	{
		data = nullptr;
		capacity = 0;
		return;
	}
	capacity = ref.capacity;
	data = new int[capacity];
	memCpy(data, ref.data, capacity);

}


Array::~Array()
{
	if (data)
		delete[] data;
	data = nullptr;
	capacity = 0;
}
int Array::getCapacity()
{
	return capacity;
}
int & Array::  operator[](int index)
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	exit(0);
}
int Array::get(int index)
{
	return data[index];
}
/*
const int & Array:: operator[](int index) const
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	exit(0);
}
*/
void Array::reSize(int newCap)
{
	if (newCap <= 0)
	{
		this-> ~Array();
		return;
	}
	int * ptr = new int[newCap];
	memcpy(ptr, data, (newCap < capacity ? newCap : capacity) * sizeof(int));
	this->~Array();
	capacity = newCap;
	data = ptr;

}

void Array::display()
{
	cout << "{ ";
	for (int i = 0; i < this->capacity; i++)
	{
		cout << this->operator[](i) << " ";

	}
	cout << "}\n";
}


void Array::memCpy(void * dest, const void * src, int noOfByt)
{
	int *d = (int*)dest;
	int *s = (int*)src;
	for (int i = 0; i < noOfByt; i++)
	{
		d[i] = s[i];
	}

}



