#pragma once
template<class Type>
class MyVector
{
private:
	Type* m_data;
	__int32 m_size;
	__int32 m_capacity;
public:
	MyVector() {}
	~MyVector()
	{
		if (m_data)
		{
			delete[] m_data;
		}
	}
	void reserve(const int& capacity)
	{
			if (m_capacity >= capacity)
			{
				return;
			}

			Type* datas = new Type[capacity];

			for (int idx = 0; idx < m_capacity; ++idx)
			{
				datas[idx] = m_data[idx];
			}

			m_capacity = capacity;

			if (m_data)
			{
				delete[] m_data;
			}
			m_data = datas;
	}
	void push_back(const Type& value)
	{
		if (m_size == m_capacity)
		{
			__int32 new_capacity = static_cast<int>(m_capacity * 1.5);
			if (new_capacity == m_capacity)
			{
				new_capacity += 1;
			}
			reserve(new_capacity);
		}
		m_data[m_size++] = value;
	}
	void resize(int nSize)
	{
		if (nSize > m_capacity)
		{
			m_capacity = nSize;
			reserve(nSize);
		}

		for (int i = nSize; nSize < m_capacity; ++i)
		{
			m_data[i] = 0;
		}
	}
	void clear() 
	{
		if (m_data) delete[] m_data;
		m_data = new Type[m_capacity]{0,};
		m_size = 0;
	}
	__int32 size() { return m_size; }
	__int32 capacity() { return m_capacity; }
public:
	Type& operator[](int index) { return m_data[index]; }

};

