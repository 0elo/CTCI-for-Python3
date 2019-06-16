#ifndef NODE_H
#define NODE_H

/* Node class is a linked list data structure
 * Used in Chapter(s) 2
 */
class Node {

public:
	
	Node(int d) : data{ d }, next{ nullptr } {}

	int data;
	Node * next;

private:
};

#endif // NODE_H