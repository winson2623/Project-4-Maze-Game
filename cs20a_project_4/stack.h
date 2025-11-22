#ifndef STACK_H_
#define STACK_H_

#include"dllist.h"

// Stack ADT using linked list as primary data structure.
// 
template<typename Type>
class Stack {
public:

	Stack();

	// Basic stack operations
	void	push(Type item);
	void	pop();
	Type	peek() const; 

	// Check to see if there is anything on the stack
	bool	empty() const;

	// Use to see what is in the stack for debugging
	void	print() const;

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif

	DLList<Type> list;
};

// Stack Implementation
//

// Stack() Default constrcutor:
//		Call the defualt constructor for its List.
//		Already implemented.
template<typename Type>
Stack<Type>::Stack():list() {}


template<typename Type>
void Stack<Type>::push(Type item) {
	list.add_front(item);
}


template<typename Type>
void Stack<Type>::pop() {
	if (!list.empty()) {
		list.remove_front();
	}
}

template<typename Type>
bool Stack<Type>::empty() const {
	return list.empty();
}


template<typename Type>
Type Stack<Type>::peek() const {
	return list.front();
}


template<typename Type>
void Stack<Type>::print() const {
	list.print();

}




























#endif//STACK_H__X_XMMXX