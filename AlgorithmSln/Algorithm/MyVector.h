#pragma once
template<class T, class Iterator = MyIterator::MyVectorIter<T>>
class MyVector
{
private:
	T* m_data;
	int32 m_size;
	int32 m_capacity;
public:
	MyVector() : m_size(0), m_capacity(0), m_data(nullptr) {}
	~MyVector()
	{
		if (m_data)
		{
			delete[] m_data;
		}
	}
	void reserve(const int32& r_capacity)
	{
			if (m_capacity >= r_capacity)
			{
				return;
			}

			T* datas = new T[r_capacity + 1];

			for (int idx = 0; idx < m_capacity; ++idx)
			{
				datas[idx] = m_data[idx];
			}

			m_capacity = r_capacity;

			if (m_data)
			{
				delete[] m_data;
			}
			m_data = datas;
	}
	void push_back(const T& value)
	{
		if (m_size == m_capacity)
		{
			int32 new_capacity = static_cast<int>(m_capacity * 1.5);
			if (new_capacity == m_capacity)
			{
				new_capacity += 1;
			}
			reserve(new_capacity);
		}
		m_data[m_size++] = value;
	}
	void resize(int32 new_capacity)
	{
		if (new_capacity > m_capacity)
		{
			m_capacity = new_capacity;
			reserve(new_capacity);
		}

		for (int i = new_capacity; new_capacity < m_capacity; ++i)
		{
			m_data[i] = 0;
		}
	}
	void clear() 
	{
		if (m_data) delete[] m_data;
		m_data = new T[m_capacity]{0,};
		m_size = 0;
	}
	int32 size() { return m_size; }
	int32 capacity() { return m_capacity; }
	Iterator begin() { return Iterator(m_data); }
	Iterator end()   { return Iterator(m_data + m_capacity);}
public:
	T& operator[](uint32 index) { return m_data[index]; }

};

