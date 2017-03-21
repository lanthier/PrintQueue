/* The include file for Queue.cpp
 */

#ifndef _Queue_
#define _Queue_
using namespace std;
#include <string>

class Node;
class Queue {
private:
	Node * head;
	Node * tail;

public:
	Queue();
	~Queue();
	void ENQUEUE(string s);
	string DEQUEUE();
	bool Queue::ISEMPTY();

};

#endif
