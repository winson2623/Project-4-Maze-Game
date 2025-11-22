#ifndef QUEUE_H_
#define QUEUE_H_

#include"dllist.h"

// Queue ADT using linked list as primary data structure.
// 
template<typename Type>
class Queue {
public:

	Queue();

	// Basic queue operations
	void	enqueue(Type item);
	void	dequeue();
	Type	peek() const;

	// Check to see if there is anything on the queue
	bool	empty() const;

	// Use to see what is in the queue for debugging
	void	print() const;

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif
	DLList<Type> list;
};


// Queue Implementation
//

// Queue() Default constrcutor:
//		Call the defualt constructor for its List.
//		Already implemented.
template<typename Type>
Queue<Type>::Queue() :list() {}


template<typename Type>
void Queue<Type>::enqueue(Type item) {
	list.add_front(item);

}


template<typename Type>
void Queue<Type>::dequeue() {
	if (!list.empty()) {
		list.remove_rear();
	}

}


template<typename Type>
bool Queue<Type>::empty() const {

	return list.empty();
}


template<typename Type>
Type Queue<Type>::peek() const {
	
	
	return list.rear();
}


template<typename Type>
void Queue<Type>::print() const {
	list.print();
}




























#endif //QUEUE_H_X_XMMXX 