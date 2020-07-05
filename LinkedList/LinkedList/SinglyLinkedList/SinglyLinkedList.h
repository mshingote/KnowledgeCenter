#ifndef SINGLY_LINKEDLIST_H
#define SINGLY_LINKEDLIST_H

#include <memory>
#include <iostream>

namespace LinkedList
{
	using std::shared_ptr;
	using std::cout;
	using std::cerr;
	using std::endl;
	using std::weak_ptr;
	using std::make_shared;

	template<typename T> struct Node
	{
		T data;
		shared_ptr<struct Node> next;
	};
	template<typename T> using ListNode = struct Node<T>;

	template <typename T> class SinglyLinkedList
	{
	public:
		void DisplaySinglyLinkedList()
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
			auto itr = m_head;
			while (itr != nullptr)
			{
				cout << itr.get()->data << ' ';
				itr = itr->next;
			}
			cout << "<- Tail";
			cout << "\n---------------------\n";
		}

		bool InsertNodeAtBegin(T data)
		{
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
				temp->next = m_head;
				m_head = temp;
			}
			++m_size;
			return true;
		}

		bool InsertNodeAtEnd(T data)
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

		bool InsertNodeAtPosition(size_t position, T data)
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
				shared_ptr< ListNode<T> > itr = m_head;
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

	private:
		int __get_size()
		{
			return m_size;
		}
		
		shared_ptr< ListNode<T> > __get_node()
		{
			shared_ptr< ListNode<T> > temp(new(std::nothrow) ListNode<T>);
			if (temp == nullptr)
			{
				cerr << "Unable to allocate memory for new node in singly linked list." << endl;
			}
			temp.get()->next = nullptr;
			return temp;
		}

		shared_ptr< ListNode<T> > __get_node(T data)
		{
			shared_ptr< ListNode<T> > temp = __get_node();
			if (temp != nullptr)
			{
				temp.get()->data = data;
			}
			return temp;
		}
		
	private:
		size_t m_size = 0;
		shared_ptr< ListNode<T> > m_head = nullptr;
		shared_ptr< ListNode<T> > m_tail = nullptr;
	};
}
#endif SINGLY_LINKEDLIST_H