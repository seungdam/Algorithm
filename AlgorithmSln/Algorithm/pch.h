#pragma once

#include <vector>
#include <list>
#include <stack>
#include <random>
#include <iostream>

using namespace std;

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;

using uint8 =  unsigned  __int8;
using uint16 = unsigned  __int16;
using uint32 = unsigned  __int32;
using uint64 = unsigned  __int64;


// binary linked list
template<typename TypeName>
struct Node
{
public:
	explicit Node()
		: data(TypeName()), prev(nullptr), next(nullptr) {}
	explicit Node(const TypeName& value)
		: data(value), prev(nullptr), next(nullptr) {}

	explicit Node(const TypeName& value, Node<TypeName>* prev, Node<TypeName>* next)
		: data(value), prev(prev), next(next) {}
	~Node() {}

	TypeName data;
	Node* prev;
	Node* next;
};


namespace MyIterator
{
	template<typename T>
	class MyListIter
	{
	public:
		explicit MyListIter() : node(nullptr) {}
		explicit MyListIter(Node<T>* arg = nullptr) : node(arg) {}

		~MyListIter() {}
		MyListIter& operator++()
		{
			node = node->next;
			return *this;
		}
		MyListIter& operator--()
		{
			node = node->prev;
			return *this;
		}

		T& operator*() { return node->data; }
		bool operator==(const MyListIter& rhs) const { return node == rhs.node; }
		bool operator!=(const MyListIter& rhs) const { return node != rhs.node; }
	private:
		Node<T>* node;
	};

	template<typename T>
	class MyVectorIter
	{
	public:
		explicit MyVectorIter() : elm(nullptr) {}
		explicit MyVectorIter(T* arg = nullptr) : elm(arg) {}

		~MyVectorIter() {}
		MyVectorIter& operator++()
		{
			elm = ++elm;
			return *this;
		}
		MyVectorIter& operator--()
		{
			elm = --elm;
			return *this;
		}

		T& operator*() { return *elm; }
		bool operator==(const MyVectorIter& rhs) const { return elm == rhs.elm; }
		bool operator!=(const MyVectorIter& rhs) const { return elm != rhs.elm; }
	private:
		T* elm;
	};
}