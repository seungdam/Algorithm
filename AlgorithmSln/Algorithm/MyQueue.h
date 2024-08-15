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

template<typename T>
class has_member_pop_front
{
	using no = char[1];
	using yes = char[2];

	// SFINAE ��Ģ�� ���ؼ� pop_front �Լ��� ������ no�� ��ȯ�մϴ�.
	template<typename C>
	static yes& check(decltype(&C::pop_front));  // Container::pop_front() �Լ��� �����͸� ��Ÿ��
	template<typename C>
	static no& check(...);
public:
	static const bool value = sizeof(check<T>(nullptr)) == sizeof(yes);
};

template<typename V,template<typename,typename> typename C, typename A = std::allocator<V>>
class MyQueue
{
	using Container = C<V, A>;
private:
	Container m_container;

	// for vector, array container;
	int32 m_size;
	int32 m_front;
	int32 m_back;

public:	
	explicit MyQueue() : m_front(0), m_back(0), m_size(0) {};
	~MyQueue() {};

	void push(const V& value)
	{
		if (!has_member_pop_front<Container>::value)
		{
			if (m_size == m_container.size())
			{
				int32 new_size = max(1, m_size * 2);
				Container new_container;
				new_container.resize(new_size);
				for (int32 idx = 0; idx < m_size; ++idx)
				{
					auto pidx = (m_front + idx) % m_container.size();
					new_container[idx] = m_container[pidx];
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
		if (!has_member_pop_front<Container>::value)
		{
			m_front = (m_front + 1) % m_container.size();
			--m_size;
		}
		else
		{
			m_container.pop_front();
		}
	};
	
	V& front()
	{
		if (has_member_pop_front<Container>::value)
		{
			return m_container.front();
		}
		else
		{
			return m_container[m_front];
		}
	};
	
	V& back()
	{
		return m_container.back();
	};

	int32 empty() 
	{
		if (!has_member_pop_front<Container>::value)
		{
			return m_size == 0;
		}
		else
		{
			return m_container.size() == 0;
		}
	}
};