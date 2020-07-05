#include "SinglyLinkedList.h"
#include <iostream>
#include <iomanip>

using namespace LinkedList;
using namespace std;

#define MAXSIZE 3
#define MEMORYSTATUS

#ifdef MEMORYSTATUS
int allocatedSize = 0;
int deallocatedSize = 0;
void* operator new(size_t size)
{
	allocatedSize += size;
	return malloc(size);
}
void operator delete(void* p, size_t size)
{
	deallocatedSize += size;
	free(p);
}
void CheckMemoryStatus()
{
	cout << "allocatedSize: " << allocatedSize << endl;
	cout << "deallocatedSize: " << deallocatedSize << endl;
}
#endif

typedef int mytype;

void Test_InsertNodeAtBegin(SinglyLinkedList<mytype>& ssl)
{
	cout << __func__ << endl;
	for (size_t i = 0; i < MAXSIZE; ++i)
	{
		ssl.InsertNodeAtBegin(i);
	}
}

void Test_InsertNodeAtEnd(SinglyLinkedList<mytype>& ssl)
{
	cout << __func__ << endl;
	for (size_t i = 0; i < MAXSIZE; ++i)
	{
		ssl.InsertNodeAtEnd(i);
	}
}

void Test_InsertNodeAtPosition(SinglyLinkedList<mytype>& ssl)
{
	cout << __func__ << endl;
	for (size_t i = 0; i < MAXSIZE; ++i)
	{
		ssl.InsertNodeAtPosition(1, i);
	}
}

void Test_DisplaySinglyLinkedList(SinglyLinkedList<mytype>& ssl)
{
	cout << __func__ << endl;
	ssl.DisplaySinglyLinkedList();
}

int main()
{
	{
		SinglyLinkedList<mytype> ssl;
		Test_InsertNodeAtBegin(ssl);
		Test_InsertNodeAtEnd(ssl);
		Test_InsertNodeAtPosition(ssl);
		Test_DisplaySinglyLinkedList(ssl);
	}

#ifdef MEMORYSTATUS
	CheckMemoryStatus();
#endif
	return 0;
}