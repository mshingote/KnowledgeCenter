#ifndef SINGLY_LINKEDLIST_H
#define SINGLY_LINKEDLIST_H

#include <memory>

namespace LinkedList
{
	using std::shared_ptr;

	class SinglyLinkedList
	{
	public:
		void DisplaySinglyLinkedList();
		bool InsertNodeAtBegin(int data);
		bool InsertNodeAtEnd(int data);
		bool InsertNodeAtPosition(size_t position, int data);

	private:
		int __get_size();
		shared_ptr<SinglyLinkedList> __get_node();
		shared_ptr<SinglyLinkedList> __get_node(int data);

	private:
		int m_data = 0;
		size_t m_size = 0;
		shared_ptr<SinglyLinkedList> m_head = nullptr;
		shared_ptr<SinglyLinkedList> m_tail = nullptr;
		shared_ptr<SinglyLinkedList> next = nullptr;
	};
}
#endif SINGLY_LINKEDLIST_H