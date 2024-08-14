#pragma once






//[head] <-> ....[][][][][] <-> [tail]
template<typename T, class Iterator = MyIterator::MyListIter<T>>
class MyList
{
public:
	MyList() : m_size(0)
	{
		// make dummy header
		m_head = new Node<T>();
		m_tail = new Node<T>();

		m_head->next = m_tail;
		m_head->prev = m_tail;
		m_tail->next = m_head;
		m_tail->prev = m_head;
	}
	~MyList() {}

	void push_front(const T& value)
	{
		add_node(m_head->next, value);
	}
	void push_back(const T& value)
	{
		add_node(m_tail, value);
	}

	void pop_front()
	{
		rm_node(m_head);

	}
	void pop_back()
	{
		rm_node(m_tail);
	}

	//           [prev] <-> [before]
	//		[prev] <-> [new node] <-> [before]
	Node<T>* add_node(Node<T>* before, const T& value)
	{
		auto new_node = new Node<T>(value, before->prev, before);
		auto prev_node = before->prev;

		prev_node->next = new_node;
		before->prev = new_node;

		++m_size;
		return new_node;
	}

	//  [prev] <-> [node] <-> [next]
	//	 [prev] <-> [next]
	Node<T>* rm_node(Node<T>* node)
	{
		auto prev_node = node->prev;
		auto next_node = node->next;

		next_node->prev = prev_node;
		prev_node->next = next_node;
		delete node;

		--m_size;
		return next_node;
	}

	int32 size() { return m_size; }
	

	// 2024-08-14 
	// make my list to use in range for-loop
	Iterator begin()  const  { return Iterator(m_head->next); }
	Iterator end()    const  { return Iterator(m_tail); }
	Iterator insert(Iterator iter, const T& value)
	{
		Node<T> node = add_node(iter->prev, value);
		return Iterator(node);
	}
private:
	Node<T>* m_head;
	Node<T>* m_tail;
	int32	 m_size;
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