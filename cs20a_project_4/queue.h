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
	/*   TODO   */

}


template<typename Type>
void Queue<Type>::dequeue() {
	/*   TODO   */

}


template<typename Type>
bool Queue<Type>::empty() const {
	/*   TODO   */
	return false;
}


template<typename Type>
Type Queue<Type>::peek() const {
	/*   TODO   */
	Type retval{};
	return retval;
}


template<typename Type>
void Queue<Type>::print() const {
	/*   TODO   */
}




























#endif //QUEUE_H_X_XMMXX 