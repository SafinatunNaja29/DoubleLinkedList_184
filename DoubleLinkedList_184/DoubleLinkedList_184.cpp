#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int NoMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student : ";
	cin >> nim;
	cout << "\nEnter the name of the student : ";
	cin >> nm;
	Node* newNode = new Node();		//step 1
	newNode->NoMhs = nim;			//step2
	newNode->name = nm;				//step 2

	/*insert a node in the beginning of a doubly - linked list*/
	if (START == NULL || nim <= START->NoMhs) {
		if (START != NULL && nim == START->NoMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START;		//step 3
		if (START != NULL)
			START->prev = newNode;	//step 4
		newNode->prev = NULL;		//step 5
		START = newNode;			//step 6
		return;
	}

	/*Inserting a Node Between Two Nodes in the List*/
	Node* current = START;			//step 1.a
	Node* previous = NULL;			//step 1.b
	while (current->next != NULL && current->next->NoMhs < nim)
	{
		previous = current;			//step 1.d
		current = current->next;	//step 1.e
	}

	if (current->next != NULL && nim == current->next->NoMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next;	//step 4
	newNode->prev = current;		//step 5
	if (current->next != NULL)
		current->next->prev = newNode;	//step 6
	current->next = newNode;		//step 7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = NULL;				//step 1.a
	*current = START;				//step 1.b
	while (*current != NULL && (*current)->NoMhs != rollNo) {	//step 1.c
		*previous = *current;		//step 1.d
		*current = (*current)->next;	//step 1.e
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, *current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;	//step 2
	if (previous != NULL)
		previous->next = current->next;	//step 3
	else
		START = current->next;

	delete current;	//step4
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedList::traverse() {
	if (listEmpty())
		cout << "\nList is Empty" << endl;
	else {
		cout << "\nRecord is ascending order of roll number are : " << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->NoMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedList::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is Empty" << endl;
	}

	else {
		cout << "\nRecord in descending order of roll number are : " << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;
		while (currentNode != NULL) {
			cout << currentNode->NoMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;

		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is Empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be deleted : ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number" << rollNo << "deleted" << endl;
}
void DoubleLinkedList::searchData() {
	if (listEmpty() == true) {
		cout << "\nList is Empty" << endl;

	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search : ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number : " << curr->NoMhs << endl;
		cout << "\nName : " << curr->name << endl;
	}
}

int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record form the list" << endl;
			cout << "3. View all records in the ascending order of roll numbers" << endl;
			cout << "4. View all records in the descending order of roll number" << endl;
			cout << "5. Search for a record in the list" << endl;
			cout << "6. Exit" << endl;
			cout << "\nEnter yout choice (1-6) : ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1':
				obj.addNode();
				break;
			case '2':
				obj.hapus();
				break;
			case '3':
				obj.traverse();
				break;
			case '4':
				obj.revtraverse();
				break;
			case '5':
			obj.searchData();
				break;
			case '6':
				return 0;
			default:
				cout << "\nInvalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << "Check for the values entered." << endl;
		}
	}
}