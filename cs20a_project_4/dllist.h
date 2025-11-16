#ifndef FA23_CS20A_LlST_H
#define FA23_CS20A_LlST_H

#include<iostream>
#include<assert.h>
// Linked DLList object that maintains both head and tail pointers
// and the count of the list.  Note that you have to keep the head,
// tail and count consistent with the intended state of the DLList 
// otherwise very bad things happen. 
template<typename Item>
class DLList {
public:

	DLList();

	DLList(const DLList<Item>& other);

	DLList<Item>& operator=(const DLList<Item>& other);

	~DLList();

	void	print() const;
	bool	empty() const;

	void	add_front(const Item &itm);
	void	add_rear(const Item &itm);
	void	add(int idx, const Item &itm);

	// Note that the user must head ensure the list is not empty
	// prior to calling these functions. 
	Item	front() const;
	Item	rear() const;
	Item	peek(int idx) const;

	int		size() const;
	int		items(const Item &itm) const;

	int		search(const Item &itm) const;

	bool	remove_front();
	bool	remove_rear();
	bool	remove_index(int idx);
	int		remove_item(const Item &itm);


	bool	sub_list(const DLList<Item>& sub);

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif
	// Forward declare the nodes for our DLList.
	// Will be implemented along with list
	// member functions
	class Node;

	// We'll have both head and tail points for 
	// Fast insertion/deletion from both ends.
	Node*	head;
	Node*	tail;

	// Keep track of number of nodes in the list
	int		count;
};


/* DLList Implementation
//
//  Since DLList is a template class (which is not an actual
//  class yet, not until we actually instantiate the list)
//  we need to keep the implementation together with
//  the definition.  There are ways to simulate having
//  separate "implementation/definition" with templates,
//  but they aren't necessary and can be confusing.
*/

/* Node definition
//		Already implemented, nothing to do here but to use it.
*/
template<typename Item>
class DLList<Item>::Node {
public:
	Node() :next(nullptr), prev(nullptr) {}
	Node(Item i, Node* p, Node* n) : item(i), next(n), prev(p) {}

	Node * nxt() const { return next; }
	void nxt(Node *n) { next = n; }

	Node * prv() const { return prev; }
	void prv(Node *p) { prev = p; }

	Item itm() const { return item; }
	void itm(const Item &i) { item = i; }

private:
	Item  item;
	Node * next;
	Node * prev;
};



/* DLList default constructor
//		Already implemented, nothing to do.
*/
template<typename Item>
DLList<Item>::DLList() :head(nullptr), tail(nullptr), count(0) {
}


/* Copy constructor
*/
template<typename Item>
DLList<Item>::DLList(const DLList<Item>& other) {

	if (other.head == nullptr) {
		head = nullptr;
		tail = nullptr;
		count = 0;
		return;
	}

	head = new Node(other.head->itm(), nullptr, nullptr);
	Node* currThis = head;
	Node* otherCurr = other.head->nxt();
	count = 1;

	while (otherCurr != nullptr) {
		Node* currNext = new Node(otherCurr->itm(), currThis, nullptr);
		currThis->nxt(currNext);
		currThis = currNext;
		otherCurr = otherCurr->nxt();
		count++;
	}
	tail = currThis;
}
/* Overloaded assignment operator
*/
template<typename Item>
DLList<Item>& DLList<Item>::operator=(const DLList<Item>& other) {
	
	if (this == &other) { return *this; }
	
	while (head != nullptr) {	//delete existing linked list
		Node* temp = head;
		head = head->nxt();
		delete temp;
	}
	tail = nullptr;
	count = 0;

	//handle empty list
	if (other.head == nullptr) {
		head = nullptr;
		tail = nullptr;
		count = 0;
		return *this;
	}

	//COPY CONSTRUCTOR
	head = new Node(other.head->itm(), nullptr, nullptr);
	Node* currThis = head;
	Node* otherCurr = other.head->nxt();
	count = 1;

	while (otherCurr != nullptr) {
		Node* currNext = new Node(otherCurr->itm(), currThis, nullptr);	
		currThis->nxt(currNext);
		currThis = currNext;
		otherCurr = otherCurr->nxt();
		count++;
	}
	tail = currThis;

	return *this;
}


/* DLList destructor
*/
template<typename Item>
DLList<Item>::~DLList() {


	Node* p = head;
	while (p != nullptr) {
		Node* n = p->nxt();
		delete p;
		p = n;
	}
	head = nullptr;
	tail = nullptr;
	count = 0;
}

/* DLList print
*/

template<typename Item>
void DLList<Item>::print() const {

	Node* p = head;
	while (p != nullptr) {
		std::cout << p->itm()<<" ";
		p = p->nxt();
	}
}

/* DLList empty
*/
template<typename Item>
bool DLList<Item>::empty() const {


	bool retval = false;
	if (count == 0) {
		retval = true;
	}
	else {
		retval = false;
	}
	return retval;
}


/* DLList add_front
*/
template<typename Item>
void DLList<Item>::add_front(const Item &itm) {


	Node* p = new Node(itm, nullptr, head);	//(item, previous pointer, next pointer)
	
	if (head != nullptr) {
		head->prv(p);
	}
	else {
		tail = p;	// empty list, p is both head and tail
	}
	head = p;
	count++;
}

/* DLList add_rear
*/
template<typename Item>
void DLList<Item>::add_rear(const Item &itm) {

	Node* p = new Node(itm, tail, nullptr);

	if (tail != nullptr) {
		tail->nxt(p);
	}
	else {
		head = p;
	}
	tail = p;
	count++;
}

/* DLList add
*/
template<typename Item>
void DLList<Item>::add(int idx, const Item &itm) {

	if (idx <= 0) { 
		add_front(itm); 
		return;
	}
	else if (idx >= count) {
		add_rear(itm);
		return;
	}
	else {
		Node* p = head;
		for (int i = 0; i < idx; i++) {
			p = p->nxt();
		}
		Node* n = new Node(itm, p->prv(), p);
		p->prv()->nxt(n);
		p->prv(n);

		count++;
	}
}

/*  DLList front
*/
template<typename Item>
Item DLList<Item>::front() const {
	// Force check that the head is pointing to a Node
	// Typical solution for deployement code is to throw
	// exceptions, but since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	assert(head != nullptr);


	Item retval=head->itm();
	return retval;
}

/* DLList rear
*/
template<typename Item>
Item DLList<Item>::rear() const {

	// Force check that the tail is pointing to a Node
	// Typical solution for deployement code is to throw
	// exceptions, since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	assert(tail != nullptr);


	Item retval=tail->itm();
	return retval;

}

/* DLList peek
*/
template<typename Item>
Item DLList<Item>::peek(int idx) const {

	// Force index to be correct before getting the Item
	// Typical solution for deployement code is to throw
	// exceptions, since we haven't covered that yet
	// we'll make due with assert, which is used for testing
	assert(idx >= 0 && idx < count);

	Node* p = head;
	for (int i = 0; i < idx; i++) {
		p = p->nxt();
	}
	Item retval = p->itm();
	return retval;
}

/* DLList size
*/
template<typename Item>
int DLList<Item>::size() const {

	int retval = count;
	return retval;
}

template<typename Item>
int DLList<Item>::items(const Item &itm) const {

	int count = 0;
	Node* p = head;
	while (p != nullptr) {
		if (p->itm() == itm) {
			count++;
		}
		p = p->nxt();
	}
	int retval = count;
	return retval;

}
/* DLList search
*/
template<typename Item>
int DLList<Item>::search(const Item &itm) const {

	int retval = -42;

	Node* p = head;
	int i = 0;
	while (p != nullptr) {
		if (p->itm() == itm) {
			retval = i;
			break;
		}
		p = p->nxt();
		i++;
	}
	return retval;
}

/* DLList remove_front
*/
template<typename Item>
bool DLList<Item>::remove_front() {


	bool retval = false;
	if (head == nullptr) { return false; }
	
	Node* temp = head;
	head = head->nxt();

	if (head != nullptr) { 
		head->prv(nullptr);
	}
	else {
		tail = nullptr;	//if head->nxt() is empty, then tail should also be emptied to prevent dangling pointer
	}
	delete temp;
	count--;
	retval = true;
	
	return retval;
}
/* DLList remove_rear
*/
template<typename Item>
bool DLList<Item>::remove_rear() {


	bool retval = false;
	if (tail == nullptr) { return false; }

	Node* temp = tail;
	tail = tail->prv();

	if (tail != nullptr) {
		tail->nxt(nullptr);
	}
	else {
		head = nullptr;
	}
	delete temp;
	count--;
	retval = true;

	return retval;
}

/* DLList remove_index
*/
template<typename Item>
bool DLList<Item>::remove_index(int idx) {

	bool retval = false;
	Node* p = head;

	if (idx < 0 || idx >= count) { 
		retval = false; 
		return retval;
	}

	for (int i = 0; i < idx; i++) {
		p = p->nxt();
	}
		
	if (p->prv() != nullptr) {	//updates previous node or head if previous is null
		p->prv()->nxt(p->nxt());
	}
	else {
		head = p->nxt();
	}

	if (p->nxt() != nullptr) {	//updates next node or tail if next is null
		p->nxt()->prv(p->prv());
	}
	else {
		tail = p->prv();
	}

	delete p;
	count--;
	retval = true;
	return retval;

}

/* DLList remove_item
*/
template<typename Item>
int DLList<Item>::remove_item(const Item &itm) {

	int retval = -42;
	int i = 0;
	Node* p = head;

	while (p != nullptr) {
		if (p->itm() == itm) {
			
			if (p->prv() != nullptr) {	//updates previous node or head if previous is null
				p->prv()->nxt(p->nxt());
			}
			else {
				head = p->nxt();
			}

			if (p->nxt() != nullptr) {	//updates next node or tail if next is null
				p->nxt()->prv(p->prv());
			}
			else {
				tail = p->prv();
			}
			delete p;
			count--;
			retval = i;
			break;
		}
		p = p->nxt();
		i++;
	}
	return retval;

}

/* DLList sub_list
*/
template<typename Item>
bool DLList<Item>::sub_list(const DLList<Item>& sub) {
	
	bool retval = false;

	if (sub.head == nullptr) { retval = true; }
	Node* mainPtr = head;

	while (mainPtr != nullptr) {
		Node* subPtr = sub.head;
		Node* tempPtr = mainPtr;

		while (subPtr != nullptr && tempPtr != nullptr) {
			if (tempPtr->itm() != subPtr->itm()) {
				break;	//no match stop comparing
			}
			tempPtr = tempPtr->nxt();
			subPtr = subPtr->nxt();
		}

		if (subPtr == nullptr) {
			retval = true;	//sublist matched
			break;	//end of sublist
		}

		mainPtr = mainPtr->nxt();	//search next if temp != sub
	}

	return retval;
}

#endif



























































































// _X_XMMXXI