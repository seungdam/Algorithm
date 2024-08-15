#pragma once
#include <type_traits>
#include <array>
// *** Queue FIFO first in first out

// [front] < ---- > [back]
// 앞의 데이터를 빠르게 꺼낼 수 있는 list, deque로 구현하는 것이 더 좋아보인다.

// what if using array?


// [][front][][][back][]
// 이런식으로 index의 개념을 range로써 활용하는 방법이 있음.
// front ~ back == m_size


// container compare를 위한 template-meta-programming
// template을 마치 함수처럼 동작하도록 프로그래밍 하는 것

template<class T>
class has_func_pop_front
{
	using no = char[1];
	using yes = char[2];

	// SFINAE 규칙에 의해서 pop_front 함수가 없으면 no를 반환합니다.
	template<class C>
	static yes& check(decltype(&C::pop_front));  // Container::pop_front() 함수의 포인터를 나타냄
	template<class C>
	static no& check(...);
public:
	static const bool value = sizeof(check<T>(nullptr)) == sizeof(yes);
};

template<typename T, typename Container = deque<T>>
class MyQueue
{
private:
	Container m_container;

	// for vector, array container;
	int m_size;
	int m_front;
	int m_back;

public:	
	explicit MyQueue() : m_front(0), m_back(0), m_size(0) {};
	~MyQueue() {};

	// template meta function을 사용해 Container Type에 따라 동일한 다른 기능을 수행할 수 있도록한다.
	void push(const T& value)
	{
		if (has_func_pop_front<Container>::value)
		{
			if (m_size == m_container.size())
			{
				int32 new_size = ::max(1, m_size * 2);
				Container new_container;
				new_container.resize(new_size);

				for (int32 idx = 0; idx < m_size; ++idx)
				{
					new_container[idx] = m_container[(m_front + idx) % m_container.size())];
				}
				m_container.swap(new_container);
			}
			m_container[m_back] = value;
			// [front|value][back];
			m_back = (m_back + 1) % m_container.size(); // front와 back 계속해서 순환하도록 나머지 연산
			++m_size;
		}
		else
		{
			m_container.push_back(value);
		}
	};
	
	void pop()
	{
		if (!has_func_pop_front<Container>::value)
		{
			m_front = (m_front + 1) % m_container.size();
			--m_size;
		}
		else m_container.pop_front();
	};
	
	T& front()
	{
		if (has_func_pop_front<Container>::value)
		{
			return m_container.front();
		}
		else
		{
			return m_container[m_front];
		}
	};
	
	T& back()
	{
		return m_container.back();
	};
};