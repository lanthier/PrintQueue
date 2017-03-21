<pre>
/* An object used to build a queue that holds string data
 */	 
#include "Node.h"
#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;
Node::Node(string i, Node *n) {s = i; next = n;}
Node::~Node() { delete next; }
void Node::ENQUEUE() {}
void Node::DEQUEUE() {}
Node*Node::getNext() { return next; }
void Node::setNext(Node *i) { next = i; }

string Node::gets() { return s; }
</pre>