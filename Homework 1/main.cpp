#include <iostream>
#include <string>
#include <cassert>
#include "LinkedList.h"
using namespace std;

int main()
{
	LinkedList e1;
	e1.insertToFront("A");
	e1.insertToFront("B");
	e1.insertToFront("C");
	e1.insertToFront("D");
	LinkedList e2;
	e2.insertToFront("X");
	e2.insertToFront("Y");
	e2.insertToFront("Z");

	LinkedList e3 = e1;

	e1.printList();
	e2.printList();
	e3.printList();

	e1 = e2;
	e1.printList();

	string s = "test";
	e1.get(4,s);
	assert(e1.get(4, s) == 0 && s == "test");
	assert(e1.get(2, s) == 1 && s == "X");

	e1 = e3;
	e1.printList();

	e1.reverseList();
	e1.printList();
	e3.printReverse();

	e1.append(e2);
	e1.printList();
	e1.append(e1);
	e1.printList();

	e1.swap(e3);
	e1.printList();
	e3.printList();

	LinkedList ls;
	ls.insertToFront("Hawkeye");
	ls.insertToFront("Thor");
	ls.insertToFront("Hulk");
	ls.insertToFront("Black Widow");
	ls.insertToFront("Iron Man");
	ls.insertToFront("Captain America");

	for (int k = 0; k < ls.size(); k++)
	{
		string x;
		ls.get(k, x);
		cout << x << endl;
	}

	LinkedList ls1;
	ls1.insertToFront("The Mandalorian");
	ls1.insertToFront("Baby Yoda");
	ls1.insertToFront("Cara Dune");
	ls1.insertToFront("Greef Karga");

	ls1.printList();
	ls1.printReverse();

	LinkedList t1;
	t1.insertToFront("Athos");
	t1.insertToFront("Porthos");
	t1.insertToFront("Aramis");
	LinkedList t2;
	t2.insertToFront("Robin");
	t2.insertToFront("Batman");
	t1.append(t2);  // adds contents of e2 to the end of e1 
	string st;
	assert(t1.size() == 5 && t1.get(3, st) && st == "Batman");
	assert(t2.size() == 2 && t2.get(1, st) && st == "Robin");

	LinkedList t3;
	t3.insertToFront("Jim");
	t3.insertToFront("Oz");
	t3.insertToFront("Paul");
	t3.insertToFront("Kevin");
	t3.reverseList();  // reverses the contents of e1 
	string st1;
	assert(t3.size() == 4 && t3.get(0, st1) && st1 == "Jim");

	LinkedList t4;
	t4.insertToFront("A");
	t4.insertToFront("B");
	t4.insertToFront("C");
	t4.insertToFront("D");
	LinkedList t5;
	t5.insertToFront("X");
	t5.insertToFront("Y");
	t5.insertToFront("Z");
	t4.swap(t5);  // exchange contents of e1 and e2 
	string st2;
	assert(t4.size() == 3 && t4.get(0, st2) && st2 == "Z");
	assert(t5.size() == 4 && t5.get(2, st2) && st2 == "B");

	t5.printList();
	cout << "delete" << endl;
	t5.deleteList();
	t5.printList();
	cout << "deleted" << endl;

	cout << "all tests completed"<<'\n';
}