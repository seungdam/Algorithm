#pragma once
#include <type_traits>
#include <array>
// *** Queue FIFO first in first out

// [front] < ---- > [back]
// ���� �����͸� ������ ���� �� �ִ� list, deque�� �����ϴ� ���� �� ���ƺ��δ�.

// what if using array?


// [][front][][][back][]
// �̷������� index�� ������ range�ν� Ȱ���ϴ� ����� ����.
// front ~ back == m_size


// container compare�� ���� template-meta-programming
// template�� ��ġ �Լ�ó�� �����ϵ��� ���α׷��� �ϴ� ��

template<class T>
class has_func_pop_front
{
	using no = char[1];
	using yes = char[2];

	// SFINAE ��Ģ�� ���ؼ� pop_front �Լ��� ������ no�� ��ȯ�մϴ�.
	template<class C>
	static yes& check(decltype(&C::pop_front));  // Container::pop_front() �Լ��� �����͸� ��Ÿ��
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

	// template meta function�� ����� Container Type�� ���� ������ �ٸ� ����� ������ �� �ֵ����Ѵ�.
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
			m_back = (m_back + 1) % m_container.size(); // front�� back ����ؼ� ��ȯ�ϵ��� ������ ����
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