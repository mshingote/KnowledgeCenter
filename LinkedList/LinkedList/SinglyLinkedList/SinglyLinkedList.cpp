#include "SinglyLinkedList.h"
#include <iostream>

namespace LinkedList 
{
	using std::cout;
	using std::cerr;
	using std::endl;
	using std::weak_ptr;
	using std::make_shared;

	void SinglyLinkedList::DisplaySinglyLinkedList()
	{
		if (m_size == 0)
		{
			cerr << "Singly Linked List is empty." << endl;
			return;
		}
		cout << "\n---------------------\n";
		cout << "Displaying Singly Linked List" << endl;
		cout << "---------------------\n";
		cout << "Head -> ";
		auto& itr = m_head;
		while (itr != nullptr)
		{
			cout << itr->m_data << ' ';
			itr = itr->next;
		}
		cout << "<- Tail";
		cout << "\n---------------------\n";
	}
	bool SinglyLinkedList::InsertNodeAtBegin(int data)
	{
		auto temp = __get_node(data);
		if (temp == nullptr)
		{
			return false;
		}
		if (m_head == nullptr)
		{
			m_head = m_tail =(temp);
		}
		else
		{
			temp->next = m_head;
			m_head = temp;
		}
		++m_size;
		return true;
	}
	bool SinglyLinkedList::InsertNodeAtEnd(int data)
	{
		auto temp = __get_node(data);
		if (temp == nullptr)
		{
			return false;
		}
		if (m_tail == nullptr)
		{
			m_head = m_tail = temp;
		}
		else
		{
			m_tail->next = temp;
			m_tail = temp;
		}
		++m_size;
		return true;
	}
	bool SinglyLinkedList::InsertNodeAtPosition(size_t position, int data)
	{
		if (position == 1)
		{
			return InsertNodeAtBegin(data);
		}
		else if (position < 1 || position > m_size)
		{
			cerr << "Invalid position given to insert data in singly linked list" << endl;
			return false;
		}
		else if (position == m_size)
		{
			return InsertNodeAtEnd(data);
		}
		auto temp = __get_node(data);
		if (temp == nullptr)
		{
			return false;
		}
		if (m_head == nullptr)
		{
			m_head = m_tail = temp;
		}
		else
		{
			shared_ptr<SinglyLinkedList> itr = m_head;
			while (position > 0)
			{
				--position;
				itr = itr->next;
			}
			temp->next = itr->next;
			itr->next = temp;
		}
		++m_size;
		return true;
	}

	int SinglyLinkedList::__get_size()
	{
		return m_size;
	}
	shared_ptr<SinglyLinkedList> SinglyLinkedList::__get_node()
	{
		shared_ptr<SinglyLinkedList> temp(new SinglyLinkedList);
		if (temp == nullptr)
		{
			cerr << "Unable to allocate memory for new node in singly linked list." << endl;
		}
		return temp;
	}
	shared_ptr<SinglyLinkedList> SinglyLinkedList::__get_node(int data)
	{
		auto temp = __get_node();
		if (temp != nullptr)
		{
			temp->m_data = data;
		}
		return temp;
	}
}