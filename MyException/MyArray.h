#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<typeinfo>
#include<exception>
#include<iomanip>
#include"Exception.h"

using namespace std;

template<class T>
class MyArray
{
private:
	int size = 0;
	T* array = nullptr;

public:
	explicit MyArray(int size);
	MyArray(const MyArray<T>& obj);
	MyArray& operator = (const MyArray& obj);
	T& operator [] (int index);

	void FillArray();

	int GetSize() { return size; }

	~MyArray();

	

	template<class T>
	friend ostream& operator<<(ostream& out, const MyArray<T>& obj);
	//template<class T>
	//friend ifstream& operator>>(ifstream& in, const MyArray<T>& obj);
};

template<class T>
inline MyArray<T>::MyArray(int size)
{
	if (size < 0)
	{
		cout << "Размер массива указан неверно: ";
	    throw size;
	}

	// используем класс exception
	if (size == 0)
	{		
		throw exception ("Был создан массив с кол-вом элементов 0");
	}

	this->size = size;
	array = new T[size];	
}

template<class T>
inline MyArray<T>::MyArray(const MyArray<T>& obj)
{
	this->size = obj.size;
	
	for (size_t i = 0; i < obj.size; i++)
	{
		this->array[i] = obj.array[i];
	}
}

template<class T>
inline MyArray<T>& MyArray<T>::operator=(const MyArray<T>& obj)

{
	if (this == &obj)
	{
		return *this;
	}

	if (array != nullptr)
	{
		delete[] array;
	}

	size = obj.size;

	array = new T[size];

	for (size_t i = 0; i < size; i++)
	{
		array[i] = obj.array[i];
	}

	return *this;
}

template<class T>
inline T& MyArray<T>::operator[](int index)
{
	if (index < 0 || index >= size)
	{
		if (index < 0)
		{
			cout << "Указанный индекс массива < 0: ";
			throw index;
		}

		/*cout << "Указанный индекс массива >= size: ";
		throw index;*/	

		//бросаем свой класс MyException
		throw MyException("Указанный индекс массива >= size", index);
	}

	else
		return array[index];
}

template<class T>
inline void MyArray<T>::FillArray()
{
	for (size_t i = 0; i < size; i++)
	{
		if (typeid(T).name() == (string)"int")
			array[i] = rand() % 10;
		else if (typeid(T).name() == (string)"double")
			array[i] = (rand() % 1000) / 10.;
		else if (typeid(T).name() == (string)"char")
			array[i] = ('a' + rand() % ('z' - 'a'));

		else 
		{
			throw exception ("Указанный тип переменной не поддерживает генерацию значений\n");
		}
	}
}



template<class T>
inline MyArray<T>::~MyArray()
{
	delete[] array;
}

template<class T>
inline ostream& operator<<(ostream& out, const MyArray<T>& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		out << obj.array[i] << " ";
	}
	
	cout << endl;
	return out;
}

//template<class T>
//inline ifstream& operator>>(ifstream& in, const MyArray<T>& obj)
//{
//	for (size_t i = 0; i < obj.size; i++)
//	{
//		in >> obj.array[i] >> " ";
//	}
//
//	cout << endl;
//	return in;
//}
