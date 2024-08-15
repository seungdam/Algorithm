#pragma once


// *** Stack LIFO (���Լ���)

// Stack In -> [1] [2] [3] [4] -> Out
// In:  1->2->3->4
// Out: 4->3->2->1

// Ȱ�뿡�� : ctrl + z , Game Scene Manager 

// Core Function
// top() , pop()

// vector, linked list�� Ȱ���ؼ� ���� �� ����.

// stack�� �⺻������ iterator�� �������� ������, 
// ���ο� ������ �����̳ʿ� ���� iterator�� ���ԵǾ����� �� ����.

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

