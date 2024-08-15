#pragma once


// *** Stack LIFO (후입선출)

// Stack In -> [1] [2] [3] [4] -> Out
// In:  1->2->3->4
// Out: 4->3->2->1

// 활용에시 : ctrl + z , Game Scene Manager 

// Core Function
// top() , pop()

// vector, linked list를 활용해서 만들 수 있음.

// stack은 기본적으로 iterator를 제공하지 않으나, 
// 내부에 구현된 컨테이너에 따라 iterator가 포함되어있을 수 있음.

template <typename T, class Container = std::deque<T>>
class MyStack
{
public:
	MyStack() {}
	~MyStack() {}

	int32 size() { return m_container.size(); }
	bool empty() { return m_container.empty(); }
	void push_back(const T& value) { m_container.push_back(value); }
	void pop() {  m_container.pop_back(); }
	const T& top() { return m_container.back(); }
private:
	Container m_container;

};

