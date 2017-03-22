#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T> class list
{
public:
	T* data;
	int length;

public:
	list();
	list(int N);
	~list();
	int size();
	T get(int i);
	void add(T new_data);
};

template <class T> list<T>::list()
{
	this->data = (T*) malloc(sizeof(T));
	this->length = 0;
}

template <class T> list<T>::list(int N)
{
	this->data = (T*) malloc(sizeof(T)*N);
	this->length = N;
}

template <class T> list<T>::~list()
{
	
}

template <class T> int list<T>::size()
{
	return this->length;
}

template <class T> T list<T>::get(int i)
{
	return this->data[i];
}

template <class T> void list<T>::add(T new_data)
{
	this->length++;
	this->data = (T*) realloc(this->data,sizeof(T)*(this->length));
	this->data[this->length - 1] = new_data;
}

template <class T> ostream &operator<<(ostream &os, list<T> &l)
{
	os << "[ ";
	for(int i = 0;i<l.size();i++)
		os << l.get(i) << " ";
	os << "]";
	os << endl;
}