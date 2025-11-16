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
	/*   TODO   */
}


template<typename Type>
void Stack<Type>::pop() {
	/*   TODO   */
}

template<typename Type>
bool Stack<Type>::empty() const {
	/*   TODO   */
	return false;
}


template<typename Type>
Type Stack<Type>::peek() const {
	/*   TODO   */
	Type retval{};
	return retval;
}


template<typename Type>
void Stack<Type>::print() const {
	/*   TODO   */

}




























#endif//STACK_H__X_XMMXX