/*   	 The include file for Node.cpp
 */

#ifndef _Node_
#define _Node_
#include <string>
#include <iostream>
using namespace std;
class Node {
private:
	Node * next;
	string s;
public:
	Node::Node(string i, Node *n);
	Node::~Node();
	void ENQUEUE();
	void DEQUEUE();
	Node * getNext();
	void setNext(Node *i);
	string gets();
};
#endif
