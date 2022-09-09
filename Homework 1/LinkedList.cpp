#include <iostream>
#include <string>
#include "LinkedList.h"

struct Node;

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::LinkedList(const LinkedList& rhs)
{
	if (rhs.head == nullptr)
	{
		head = nullptr;
	}

	//creates head node
	Node* cp = new Node();
	cp->value = rhs.head->value;
	cp->next = nullptr;  
	head = cp;

	Node* og = rhs.head->next;

	while ( og != nullptr)//iterate until end of linked list
	{
		cp->next = new Node();//points prev node of cp to a new node
		cp = cp->next;//cp is now the new node
		cp->value = og->value;//copy value of the next node of rhs into new node in this
		og = og->next;//og now points to next node of rhs
		cp->next = nullptr;
	}
}

LinkedList::~LinkedList()
{
	Node* n1 = head;
	while (n1 != nullptr)
	{
		Node* n2 = n1->next;
		delete n1;
		n1 = n2;
	}
}

const LinkedList& LinkedList::operator = (const LinkedList& rhs)
{
	if (&rhs == this)
	{
		return rhs;
	}

	if (rhs.head == nullptr)
	{
		head = nullptr;
	}

	//deletes nodes of this
	Node* n1 = head;
	while (n1 != nullptr)
	{
		Node* n2 = n1->next;
		delete n1;
		n1 = n2;
	}
	head = nullptr;

	//creates head node
	Node* cp = new Node();
	cp->value = rhs.head->value;
	cp->next = nullptr;
	head = cp;

	Node* og = rhs.head->next;

	while (og != nullptr)//iterate until end of linked list
	{
		cp->next = new Node();//points prev node of cp to a new node
		cp = cp->next;//cp is now the new node
		cp->value = og->value;//copy value of the next node of rhs into new node in this
		og = og->next;//og now points to next node of rhs
		cp->next = nullptr;
	}

	return *this;
}

void LinkedList::insertToFront(const ItemType& val)
{
	Node* p;
	p = new Node;
	p->value = val;
	p->next = head;
	head = p;
}

void LinkedList::printList() const
{
	Node* p;
	p = head;
	while (p != nullptr)
	{
		std::cout << p->value << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

bool LinkedList::get(int i, ItemType& item) const
{
	//ewturn false if i not in range
	if (i<0 || i>size() - 1)
	{
		return false;
	}

	Node* p;
	p = head;
	for (int j = 0; j < i; j++)
	{
		p = p->next;
	}

	item = p->value;
	return true;
}

void LinkedList::reverseList()
{
	Node* current;
	Node* previous;
	Node* next;
	if (head->next != nullptr)
	{
		current = head->next;//current is 2nd node
		previous = head;//previous is head
		previous->next = nullptr;//head points to nullptr
		next = current->next;//next points to third node
		while (next != nullptr)//iterate until current is the last ndoe
		{
			current->next = previous;//point current to previous node

			//iterate previous, current, and next, up one node
			previous = current;
			current = next;
			next = current->next;
		}
		//point last node to previous node, and set as head
		current->next = previous;
		head = current;
	}
}

void LinkedList::printReverse() const
{
	//loop starting from last node, print reverse
	for (int k = this->size() - 1; k > -1; k--)
	{
		std::string x;
		this->get(k, x);
		std::cout << x << " ";
	}
	std::cout << std::endl;
}

void LinkedList::append(const LinkedList& other)
{
	if (this == nullptr)
	{
		*this = other;
	}

	//create temp LinkedList to prevent infinite loop when appending to itself
	LinkedList* temp = new LinkedList();
	*temp = other;
	Node* p;
	p = head;
	Node* oth;
	oth = temp->head;

	//loop to end of LinkedList this
	while (p->next != nullptr)
	{
		p = p->next;
	}

	//creates new nodes for this, using nodes from LinkedList other
	while (oth != nullptr)
	{
		p->next = new Node();//points prev node of p to a new node
		p = p->next;//p is now the new node
		p->value = oth->value;//copy value of the next node of other into new node in this
		p->next = nullptr;
		oth = oth->next;//oth now points to next node of other
	}

	//cleanup
	delete temp;
}

void LinkedList::swap(LinkedList& other)
{
	//temp store other
	LinkedList* temp = new LinkedList();
	*temp = other;

	//swap
	other = *this;	
	*this = *temp;

	//cleanup
	delete temp;
}

int LinkedList::size() const
{
	Node* p;
	p = head;
	int count = 0;
	while (p != nullptr)
	{
		count++;
		p = p->next;
	}
	return count;
}

void LinkedList::deleteList()
{
	if (head == nullptr)
	{
		return;
	}
	Node* next = head->next;
	delete head;
	head = next;
	deleteList();
}