// DEFINE YOUR RUN
//#define RUN00

#ifdef RUN00
#include"studentinfo.h"
#include<string>
using std::string;
#include"stack.h"
#include"queue.h"

int main() {



	Stack<std::string> stack;
	Queue<std::string> queue;

	stack.push(StudentInfo::Name());
	stack.push("Feynman");
	stack.push("Turing");
	stack.push("Einstein");
	stack.push("Bohr");
	stack.push("Sanchez");

	stack.print();

	queue.enqueue(stack.peek());
	stack.pop();

	queue.enqueue(stack.peek());
	stack.pop();

	queue.enqueue(stack.peek());
	stack.pop();

	queue.enqueue(stack.peek());
	stack.pop();

	queue.dequeue();
	queue.dequeue();

	queue.print();

	return 0;
}

#else

#include"game.h"

int main() {



	//Setup game
	Game g("settings.ini");

	//Exectute game loop
	g.run();

	return 0;
}

#endif