#include <iostream>
#include "linkedlistimp.cpp"

using namespace std;

int main()
{
	Linkedlist list;

	// Inserting nodes
	list.insertNode(1);
	list.insertNode(2);
	list.insertNode(3);
	list.insertNode(4);

	cout << "Elements of the list are: ";

	// Print the list
	list.printList();
cout << endl;
}