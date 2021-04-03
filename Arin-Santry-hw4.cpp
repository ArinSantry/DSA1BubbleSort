/*
This code is used to submit your assignment #4.

You need to do the following:

	1. implement another version of Bubble sort algorithm that works
	by swapping the pointers instead of swapping the data inside the nodes.

	2. implement a function that reverses the list.

	3. implement a function that checks if two linked lists are identical.


You are not allowed to modify the LinkedList Class, only complete class implementation.

Complete the missing functions, test your code, and then submit your answers.

Methods to be completed:
	 sortBySwappingPointers()

*/

#include <iostream>
#include <string>

using namespace std;

class LinkedList {

private:
	struct Node {
		int data;
		Node* next;
	};

	Node* head;
	Node* tail;

public:
	LinkedList();
	void insertAtBeginning(const int addData);
	void bSortList();
	void sortBySwappingPointers();
	void reverseList();
	bool checkIfIdentical(LinkedList l2);
	int getSize();
	Node* swap(Node* head);

	// we will overload << operator to print linked lists :)
	friend ostream& operator<<(ostream& os, const LinkedList& ll);

};

// initialize head and tail pointers to nullptr
LinkedList::LinkedList() {

	head = nullptr;
	tail = nullptr;
}

int LinkedList::getSize()
{
	Node* curr = head;
	int size = 0;
	while (curr != NULL)
		size++;
	return size;
}

// to add a node at the beginning, we have two cases:
// 1. Empty list and 2. Non-empty list.
// if the list is empty we need to update both pointers head and tail.

void LinkedList::insertAtBeginning(const int addData) {

	Node* newNode = new Node;
	newNode->data = addData;
	newNode->next = nullptr;

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}

}


// sort using bubble sort -- swapping contents
void LinkedList::bSortList()
{
	Node *i, *j;
	int tempInt;

	for (i = head; i != NULL; i = i->next)
		for (j = head; j->next != NULL; j = j->next) {
			if (j->data > j->next->data) {

				// swap contents of the nodes
				tempInt = j->data;
				j->data = j->next->data;
				j->next->data = tempInt;
			}
		}
}

// another version of Bubble sort algorithm
void LinkedList::sortBySwappingPointers() {
	Node* cur;
	Node* next;
	bool unsorted = true;
	while (unsorted)
	{
		unsorted = false;
		cur = head;
		while (cur != nullptr)
		{
			next = cur->next;
			if (next->data < cur->data)
			{
				swap(cur);
				unsorted = true;
			}
			cur = cur->next;
		}
	}
}

LinkedList::Node* LinkedList::swap(Node* head)
{
	// Base Case: The list is empty or has only one node 
	if (head == NULL || head->next == NULL)
		return head;

	// Store head of list after two nodes 
	Node* remaing = head->next->next;

	// Change head 
	Node* newhead = head->next;

	// Change next of second node 
	head->next->next = head;

	// Recur for remaining list and change next of head 
	head->next = swap(remaing);

	// Return new head of modified list 
	return newhead;
}

// reverse the nodes order of a linked list
void LinkedList::reverseList() {
	Node* current = head;
	Node *prev = NULL, *next = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

// check if two lists are identical
bool LinkedList::checkIfIdentical(LinkedList l2) {
	Node* a = head;
	Node* b = l2.head;
	while (a != NULL && b != NULL)
	{
		if (a->data != b->data)
			return false;
		a = a->next;
		b = b->next;
	}

	// If linked lists are identical, then  
	// 'a' and 'b' must be NULL at this point. 
	return (a == NULL && b == NULL);
}


// overloading << operator to print a linked list
// os variable is output stream
ostream& operator<<(ostream& os, const LinkedList& ll)
{
	// Node structure is defined inside LinkedList class, we need
	// to use the resolution operator :: to access it.
	// Thats why we defined this function as a friend function, so
	// we can access the Node struct and all private members.

	LinkedList::Node* curr = ll.head;

	while (curr != nullptr) {
		os << "(" << curr->data << ") -> ";
		curr = curr->next;
	}
	os << "00" << endl;

	return os;
}


int main() {

	LinkedList myList1, myList2;
	
	// testing checkIfIdentical function with two empty lists
	cout << "List 1: " << myList1; // using the overloaded operator
	cout << "List 2: " << myList2;
	cout << "Test 1: checking identical lists" << endl;
	if (myList1.checkIfIdentical(myList2)) {
		cout << "Empty lists are identical ..." << endl;
	}
	else {
		cout << "Empty lists are NOT identical !!!" << endl;
	}
	

	myList1.insertAtBeginning(20);
	myList1.insertAtBeginning(10);
	myList1.insertAtBeginning(25);

	myList2.insertAtBeginning(20);
	myList2.insertAtBeginning(10);
	myList2.insertAtBeginning(25);

	
	// testing checkIfIdentical function
	cout << "List 1: " << myList1;
	cout << "List 2: " << myList2;
	cout << "Test 2: checking identical lists" << endl;
	if (myList1.checkIfIdentical(myList2)) {
		cout << "Lists are identical ..." << endl;
	}
	else {
		cout << "Lists are NOT identical ..." << endl;
	}
	

	myList2.insertAtBeginning(101);

	
	// testing checkIfIdentical function
	cout << "List 1: " << myList1;
	cout << "List 2: " << myList2;
	cout << "Test 3: checking identical lists" << endl;
	if (myList1.checkIfIdentical(myList2)) {
		cout << "Lists are identical ..." << endl;
	}
	else {
		cout << "Lists are NOT identical ..." << endl;
	}
	

	// testing reverseList function
	cout << "Test 4: checking reversal function" << endl;
	cout << "List 1 before reversal ..." << endl;
	cout << "List 1: " << myList1;
	myList1.reverseList();
	cout << "List 1 after reversal ..." << endl;
	cout << "List 1: " << myList1;

	
	//testing soring function
	cout << "Test 5: checking sorting function" << endl;
	cout << "List 1 before sorting ..." << endl;
	cout << "List 1: " << myList1;
	myList1.sortBySwappingPointers();
	cout << "List 1 after sorting ..." << endl;
	cout << "List 1: " << myList1;
	
	do
	{
		cout << '\n' << "Press a key to continue...";
	} while (cin.get() != '\n');

	return 0; 

	return 0;
}
