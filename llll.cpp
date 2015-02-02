/*
 * A Lame Linked List Library (hence the llll) by James.
 * Treat linked list numbers like array elements.
 */
#include <algorithm>
#include <ctime>
#include <iostream>
#include "headers/Node.h"
#include "headers/llll.h"



/*
 * Create n linked Nodes with values of zero.
 * @param head		Pointer to beginning of linked list.
 * @param n			Number of Nodes to create.
 */
void createNodes(Node* &head, int n) {
    Node* temp;
    head = new Node;
    temp = head;
	for(int i = 0; i < n; i++) {
		temp->value = 0;
		temp->next = new Node;
		temp = temp->next;
	}
	temp->next = NULL;
}


/*
 * Replace all values in Nodes with random number between min and max (including min and max).
 * @param head		Pointer to beginning of linked list.
 * @param max		Maximum random number value.
 * @param [min]		Minimum random number value, defaults to zero.
 */
void populateNodes(Node* head, int max, int min) {
	srand(time(NULL));
	if(min > max) {
		std::swap(min, max);
	}
	while(head->next != NULL) {
		head->value = rand()%(max-min+1) + min;
		head = head->next;
	}
}


/*
 * Replace value of specific Node at index
 * @param head		Pointer to beginning of linked list.
 * @param index		Position of value to change, starts with 0th element (like array).
 * @param value		Value to insert.
 */
void insertNodeValue(Node* head, int index, int value) {
	int current = 0;
	while(head->next != NULL && current < index) {
		head = head->next;
		current++;
	}
	head->value = value;
}


/*
 * Insert a Node into linked list at index.
 * @param head		Pointer to beginning of linked list.
 * @param index		Position of value to change, starts with 0th element (like array).
 * @param [value]	Optional value, without it the new Node value will be zero.
 */
void insertNewNode(Node* &head, int index, int value) {
	//Setup Node to be inserted.
	Node* insert = new Node;
	insert->value = value;
	insert->next = NULL;

	//Special case for zero-th element, requires head to be passed by reference.
	if(index == 0) {
		insert->next = head->next;
		head = insert;

	//Any other index can transverse the linked list and insert the new Node.
	} else {
		Node* temp;
		temp = head;
		int current = 1;
		while(temp->next != NULL && current < index) {
			temp = temp->next;
			current++;
		}
		insert->next = temp->next;
		temp->next = insert;
	}
}


/*
 * Print out values from linked list in order and with pretty curly braces.
 * @param head		Pointer to beginning of linked list.
 */
void printNodeValues(Node* head) {
	std::cout << "{" ;
	while(head->next != NULL) {
		std::cout << head->value << ", ";
		head = head->next;
	}
	//I can't believe this works http://stackoverflow.com/a/3745914/2219970
	std::cout << "\b" << "\b" << "}" << std::endl;
}


/*
 * Uses recursion to print out values from linked list in order with pretty curly braces.
 * @param head		Pointer to beginning of linked list.
 * @param [first]	Only passed to mark recursive calls so the function knows when to print "}".
 */
void printNodeValuesRecursive(Node* head, int first) {
	if(first == 0) {
		std::cout << "{";
	}
	if(head->next != NULL) {
		std::cout << head->value << ", ";
		printNodeValuesRecursive(head->next, 1);
	} else {
		std::cout << "\b" << "\b" << "}" << std::endl;
	}
}


/*
 * Uses recursion to print out values from linked list in reverse order (still with pretty curly 
 * braces, but that was a little harder than I expected).
 * @param head		Pointer to beginning of linked list.
 * @param [last]	Only passed to mark recursive calls so the function knows when to print "}".
 */
void printNodeValuesReverse(Node* head, int last) {
	if(head->next != NULL) {
		printNodeValuesReverse(head->next, 1);
		std::cout << head->value << ", ";
	} else {
		std::cout << "{";
	}
	if(last == 0) {
		std::cout << "\b" << "\b" << "}" << std::endl;
	}
}


/*
 * Removes Node from linked list at index. If index is higher than number of Nodes in linked list
 * this will remove the last Node.
 * @param head		Pointer to beginning of linked list.
 * @param index		Position of value to change, starts with 0th element (like array).
 */
void removeNode(Node* &head, int index) {
	Node* temp;
	temp = head;
	//Special case for zero-th element, requires head to be passed by reference.
	if(index == 0) {
		head = head->next;
		delete temp;

	} else {
		Node* remove;
		int current = 1;
		while(temp->next != NULL && current < index) {
			temp = temp->next;
			current++;
		}
		remove = temp->next;
		temp->next = remove->next;
		delete remove;
	}
}


/*
 * Remove Nodes from memory.
 * @param head		Pointer to beginning of linked list.
 */
void cleanupNodes(Node* head) {
	Node* temp;
	do {
		temp = head;
		head = head->next;
		delete temp;
	} while (head->next != NULL);
}
