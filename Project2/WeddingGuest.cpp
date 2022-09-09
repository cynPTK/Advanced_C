#include "WeddingGuest.h"
#include "string"
//#include <iostream>//for dump()

WeddingGuest::WeddingGuest()
{
	head = nullptr;
	tail = nullptr;
}

WeddingGuest::WeddingGuest(const WeddingGuest& rhs)
{
	//return if list is empty
	int flag = 0;
	if (rhs.head == nullptr)
	{
		head = nullptr;
		flag = 1;
	}
	if (rhs.tail == nullptr)
	{
		tail = nullptr;
		flag = 1;
	}

	if (flag == 1)
		return;

	//creates head node
	Node* cp = new Node();
	cp->m_firstName = rhs.head->m_firstName;
	cp->m_lastName = rhs.head->m_lastName;
	cp->m_value = rhs.head->m_value;
	cp->next = nullptr;
	cp->prev = nullptr;
	head = cp;
	tail = cp;
	Node* n_prev = head;

	Node* og = rhs.head->next;

	while (og != nullptr)//iterate until end of linked list
	{
		cp->next = new Node();//points prev node of cp to a new node
		cp = cp->next;//cp is now the new node
		cp->prev = n_prev;//cp prev points to previous node

		// copy values of the next node of rhs into new node in this
		cp->m_firstName = og->m_firstName;
		cp->m_lastName = og->m_lastName;
		cp->m_value = og->m_value;

		og = og->next;//og now points to next node of rhs
		n_prev = n_prev->next;//iterate previous node forward

		cp->next = nullptr;
		tail = cp;
	}
}

 WeddingGuest& WeddingGuest::operator=( const WeddingGuest& rhs)
{
	//return *this if rhs and this is the same linked list
	if (&rhs == this)
	{
		return *this;
	}

	//return this if rhs is empty
	int flag = 0;
	if (rhs.head == nullptr)
	{
		head = nullptr;
		flag = 1;
	}
	if (rhs.tail == nullptr)
	{
		tail = nullptr;
		flag = 1;
	}

	if (flag == 1)
		return *this;

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
	cp->m_firstName = rhs.head->m_firstName;
	cp->m_lastName = rhs.head->m_lastName;
	cp->m_value = rhs.head->m_value;
	cp->next = nullptr;
	cp->prev = nullptr;
	head = cp;
	Node* n_prev = head;

	Node* og = rhs.head->next;

	while (og != nullptr)//iterate until end of linked list
	{
		cp->next = new Node();//points prev node of cp to a new node
		cp = cp->next;//cp is now the new node
		cp->prev = n_prev;//cp prev points to previous node

		// copy values of the next node of rhs into new node in this
		cp->m_firstName = og->m_firstName;
		cp->m_lastName = og->m_lastName;
		cp->m_value = og->m_value;

		og = og->next;//og now points to next node of rhs
		n_prev = n_prev->next;//iterate previous node forward

		cp->next = nullptr;
		tail = cp;
	}

	return *this;
}

WeddingGuest::~WeddingGuest()
{
	Node* n1 = head;
	while (n1 != nullptr)//iterate through every node
	{
		Node* n2 = n1->next;
		delete n1;//delete node in iteration
		n1 = n2;//iterate to next item
	}
}

bool WeddingGuest::noGuests() const
{
	//return true if guestCount is 0
	if (guestCount() == 0)
		return true;
	return false;
}

int WeddingGuest::guestCount() const
{
	int count = 0;
	Node* p = head;
	while (p != nullptr)//iterate through every node
	{
		count++;//count number of nodes
		p = p->next;
	}
	return count;
}

bool WeddingGuest::inviteGuest(const std::string& firstName, const std::string&
	lastName, const GuestType& value)
{
	Node* p = head;

	//return false is name is already in list
	while (p != nullptr)
	{
		if (p->m_firstName == firstName && p->m_lastName == lastName)
		{
			return false;
		}
		p = p->next;
	}

	p = head;

	if (head == nullptr)//insertToFront if list is empty
	{
		insertToFront(firstName, lastName, value);
		return true;
	}
	else if (lastName.std::string::compare(head->m_lastName) < 0 || (lastName.std::string::compare(head->m_lastName) == 0 && firstName.std::string::compare(head->m_firstName) < 0))//insertToFront if guest is first alphabetically in list
	{
		insertToFront(firstName, lastName, value);
		return true;
	}
	else if ((lastName.std::string::compare(tail->m_lastName) > 0 || (lastName.std::string::compare(tail->m_lastName) == 0 && firstName.std::string::compare(tail->m_firstName) > 0)))//insert to rear if guest is last alphabeticaly in list
	{
		Node* latest = new Node();

		//initiate latest values
		latest->m_value = value;
		latest->m_firstName = firstName;
		latest->m_lastName = lastName;

		tail->next = latest;
		latest->prev = tail;
		tail = latest;
		return true;

	}
	while (p->next != nullptr)//insert in center alphabetically
	{
		if (lastName.std::string::compare(p->m_lastName) < 0 || (lastName.std::string::compare(p->m_lastName) == 0 && firstName.std::string::compare(p->m_firstName) < 0))
			break;
		p = p->next;
	}
	if (p->prev != nullptr)
		p = p->prev;//go to node above latest
	Node* latest = new Node();

	//initiate latest values
	latest->m_value = value;
	latest->m_firstName = firstName;
	latest->m_lastName = lastName;

	//latest points to correct nodes
	latest->next = p->next;
	latest->prev = p;

	//node before latest points to latest
	p->next = latest;

	//makes sure node after latest points to latest
	p = p->next;
	latest = latest->next;
	latest->prev = p;

	return true;
}

bool WeddingGuest::alterGuest(const std::string& firstName, const std::string&
	lastName, const GuestType& value)
{
	Node* p = head;
	while (p != nullptr)//iterate through every node
	{
		if (p->m_firstName == firstName && p->m_lastName == lastName)//if find first and last name match, change the guest's value to value in parameter
		{
			p->m_value = value;
			return true;
		}
		p = p->next;
	}

	return false;
}

bool WeddingGuest::inviteOrAlter(const std::string& firstName, const
	std::string& lastName, const GuestType& value)
{
	Node* p = head;
	while (p != nullptr)//iterate through every node
	{
		if (p->m_firstName == firstName && p->m_lastName == lastName)//if find first and last name match, change the guest's value to value in parameter
		{
			p->m_value = value;
			return true;
		}
		p = p->next;
	}
	p = head;

	if (head == nullptr)//insertToFront if list is empty
	{
		insertToFront(firstName, lastName, value);
		return true;
	}
	else if (lastName.std::string::compare(head->m_lastName) < 0 || (lastName.std::string::compare(head->m_lastName) == 0 && firstName.std::string::compare(head->m_firstName) < 0))//insertToFront if guest is first alphabetically in list
	{
		insertToFront(firstName, lastName, value);
		return true;
	}
	else if ((lastName.std::string::compare(tail->m_lastName) > 0 || (lastName.std::string::compare(tail->m_lastName) == 0 && firstName.std::string::compare(tail->m_firstName) > 0)))//insert to rear if guest is last alphabeticaly in list
	{
		Node* latest = new Node();

		//initiate latest values
		latest->m_value = value;
		latest->m_firstName = firstName;
		latest->m_lastName = lastName;

		tail->next = latest;
		latest->prev = tail;
		tail = latest;
		return true;

	}

	while (p->next != nullptr)//insert in center alphabetically
	{
		if (lastName.std::string::compare(p->m_lastName) < 0 || (lastName.std::string::compare(p->m_lastName) == 0 && firstName.std::string::compare(p->m_firstName) < 0))
			break;
		p = p->next;
	}
	if (p->prev != nullptr)
		p = p->prev;//go to node above latest
	Node* latest = new Node();

	//initiate latest values
	latest->m_value = value;
	latest->m_firstName = firstName;
	latest->m_lastName = lastName;

	//latest points to correct nodes
	latest->next = p->next;
	latest->prev = p;

	//node before latest points to latest
	p->next = latest;

	if (latest->next != nullptr)
	{
		//makes sure node after latest points to latest
		p = p->next;
		latest = latest->next;
		latest->prev = p;
	}
	else
	{
		//if latest->next is nullptr, then latest is the tail
		tail = latest;
	}

	return true;
}

bool WeddingGuest::crossGuestOff(const std::string& firstName, const
	std::string& lastName)
{
	Node* p = head;
	if (head == nullptr)//list is empty
	{
		return false;
	}
	if (head->m_firstName == firstName && head->m_lastName == lastName)//head is guest to be crossed off 
	{
		Node* killMe = head;
		head = killMe->next;//head is now node after original head
		if (head != nullptr)
			head->prev = nullptr;//set head->prev as nullptr
		delete killMe;
		return true;
	}
	else if (tail->m_firstName == firstName && tail->m_lastName == lastName)//tail is guest to be crossed off
	{
		Node* killMe = tail;
		tail = killMe->prev;//tail is now node before original tail
		if (tail != nullptr)
			tail->next = nullptr;//set tail->next as nullptr
		delete killMe;
		return true;
	}
	
	//guest to be crossed off is in the middle
	while (p != nullptr)
	{
		if (p->next != nullptr && p->next->m_firstName == firstName && p->next->m_lastName == lastName)//breaks one node before node we want to delete
		{
			break;
		}
		p = p->next;
	}
	if (p != nullptr)//if name is not on list, p == nullptr
	{
		Node* killMe = p->next;
		p->next = killMe->next;//next for node before killMe is set to what killMe points to next
		p = p->next;//iterate to node after killMe
		p->prev = killMe->prev;//node after killMe points to what killMe points to previously
		delete killMe;
		return true;
	}

	return false;
}

bool WeddingGuest::invitedToTheWedding(const std::string& firstName, const
	std::string& lastName) const
{
	Node* p = head;
	while (p != nullptr)//iterate through every node
	{
		if (p->m_firstName == firstName && p->m_lastName == lastName)//returns true if name is found
		{
			return true;
		}
		p = p->next;
	}
	return false;
}

bool WeddingGuest::matchInvitedGuest(const std::string& firstName, const
	std::string& lastName, GuestType& value) const
{
	Node* p = head;
	while (p != nullptr)//iterate through every node
	{
		if (p->m_firstName == firstName && p->m_lastName == lastName)//name is found
		{
			value = p->m_value;//value of third param is now value of node
			return true;
		}
		p = p->next;
	}

	return false;
}

bool WeddingGuest::verifyGuestOnTheList(int i, std::string& firstName,
	std::string& lastName, GuestType& value) const
{
	if (0 <= i && i < guestCount())//make sure i is within number of nodes
	{
		Node* p;
		p = head;

		for (int j = 0; j < i; j++)//iterate until ith value
		{
			p = p->next;
		}

		//set other three params to values in node
		firstName = p->m_firstName;
		lastName = p->m_lastName;
		value = p->m_value;
		return true;
	}
	return false;
}

void WeddingGuest::swapWeddingGuests(WeddingGuest& other)
{
	//temp store other
	WeddingGuest temp = other;

	//swap
	other = *this;
	*this = temp;
}

void WeddingGuest::insertToFront(const std::string first,const std::string last, const GuestType& val)
{
	Node* p = new Node();//create new node with values of pararm
	p->m_value = val;
	p->m_firstName = first;
	p->m_lastName = last;
	//set next and prev adresses
	p->next = head;
	p->prev = nullptr;
	//set p as new head
	head = p;

	if (p->next != nullptr)
	{
		p = p->next;
		p->prev = head;//set prev of next node as head
	}
	else
		tail = head;
}

//void WeddingGuest::dump() const
//{
//	Node* p = head;
//	std::cerr << "head = " << head << std::endl;
//	std::cerr << "tail = " << tail << std::endl;
//
//	while(p!=nullptr)
//	{
//		std::cerr << p->m_firstName << " "
//			<< p->m_lastName << " "
//			<< p->m_value <<
//			" next: " << p->next <<
//			" this: " << p <<
//			" prev: " << p->prev << std::endl;
//		p = p->next;
//	}
//	std::cerr << std::endl;
//}

bool joinGuests(const WeddingGuest& odOne, const WeddingGuest& odTwo, WeddingGuest& odJoined)
{
	std::string first;
	std::string last;
	GuestType value;
	WeddingGuest joined;
	int flag = 0;
	
	for (int i = 0; i < odOne.guestCount(); i++)//invite all guests on odOne
	{
		odOne.verifyGuestOnTheList(i, first, last, value);
		joined.inviteGuest(first, last, value);
	}
	for (int i = 0; i < odTwo.guestCount(); i++)//invite guests on odTwo
	{
		odTwo.verifyGuestOnTheList(i, first, last, value);
		if (!joined.inviteGuest(first, last, value))//if invite failed bc name is already in joined
		{
			GuestType odOneVal;
			odOne.matchInvitedGuest(first, last, odOneVal);
			if (value != odOneVal)//if values are different for the name
			{
				odJoined.crossGuestOff(first, last);//cross guest off
				flag = 1;//flag to return false
			}
		}
	}
	odJoined = joined;//copy joined into odJoined
	if (flag == 1)
		return false;
	return true;
}

void attestGuests(const std::string& fsearch, const std::string& lsearch, const WeddingGuest& odOne, WeddingGuest& odResult)
{
	std::string first;
	std::string last;
	GuestType value;
	WeddingGuest Result;

	for (int i = 0; i < odOne.guestCount(); i++)
	{
		if (fsearch == "*" && lsearch == "*")//Results is entire list od odOne if first and last are both wild
		{
			Result = odOne;
		}
		else if (fsearch == "*")//if first is wild
		{
			odOne.verifyGuestOnTheList(i, first, last, value);//Results include all matches of lastname
			if (last == lsearch)
				Result.inviteGuest(first, last, value);
		}
		else if (lsearch == "*")//if last is wild
		{
			odOne.verifyGuestOnTheList(i, first, last, value);//Results include all matches of firstname
			if (first == fsearch)
				Result.inviteGuest(first, last, value);
		}
		else
		{
			odOne.verifyGuestOnTheList(i, first, last, value);//Results include only matches of both first and last name
			if (first == fsearch && last == lsearch)
				Result.inviteGuest(first, last, value);
		}
	}
	odResult = Result;//copy Result into odResult
}