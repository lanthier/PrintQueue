/* A class that creates a queue of Nodes containing strings
 */
#include "Queue.h"
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;
#define NULL 0
Queue::Queue() {
	head = NULL;
	tail = NULL;
}
Queue::~Queue () {delete head; }
void Queue::ENQUEUE(string s) {
	if (head) {
		Node*i=new Node(s,NULL);
		tail->setNext(i);
		tail = tail->getNext();
	}
	else tail = head = new Node(s,NULL);
}
string  Queue:: DEQUEUE() {
	if (!head) { abort(); }
	string a = head->gets(); //returns a
	Node *n = head; //for memory
	head = head->getNext();
	n->setNext(NULL); //for memory
	delete n; //for memory
	return a;
}
bool Queue::ISEMPTY() { return !head; }
