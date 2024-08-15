#pragma once

namespace MyIterator { template<class T> class MyListIter; };

template<typename T>
struct Node
{
public:
	explicit Node()
		: data(-1), prev(nullptr), next(nullptr) {}
	explicit Node(const T& value)
		: data(value), prev(nullptr), next(nullptr) {}

	explicit Node(const T& value, Node<T>* prev, Node<T>* next)
		: data(value), prev(prev), next(next) {}
	~Node() {}

	// for print node object
	friend ostream& operator<<(ostream& os, const Node<T>& rhs)
	{
		os << rhs.data;
		return os;
	}

	T& operator*() { return data; }
private:
	T data;
	Node* prev;
	Node* next;

	template <typename T>
	friend class MyIterator::MyListIter;
	
	template <typename T, class Iterator>
	friend class MyList;
};




//{
//	auto&& __range = range_expression;
//	for (auto __begin = begin_expr,
//		__end = end_expr;
//		__begin != __end; ++__begin) {
//		range_declaration = *__begin;
//		loop_statement
//	}
//}

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

		MyListIter& operator+(const int32& offset)
		{
			for (int32 i = 0; i < offset; ++i) node = node->next;
			return *this;
		}

		MyListIter& operator-(const int32& offset)
		{
			for (int32 i = 0; i < offset; ++i) node = node->prev;
			return *this;
		}

		Node<T>& operator*() { return *node; }
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