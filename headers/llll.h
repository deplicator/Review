#ifndef _LLLL_H_
#define _LLLL_H_

void createNodes(Node* &head, int n);
void populateNodes(Node* head, int n, int m = 0);
void insertNodeValue(Node* head, int position, int value);
void insertNewNode(Node* &head, int index, int value = 0);
void printNodeValues(Node* head);
void printNodeValuesRecursive(Node* head, int first = 0);
void printNodeValuesReverse(Node* head, int last = 0);
void removeNode(Node* &head, int index);
void cleanupNodes(Node* head);

#endif
