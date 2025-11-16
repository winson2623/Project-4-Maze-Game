#ifndef ROOM_H
#define ROOM_H
#include<ostream>

// Rooms on 2d grid
class Room {
	// Overloaded operators for convenience.  You must be careful with
	// friend functions if abused you can easily violate encapsulation.  
	// Functions that can be made friends are tightly related to concept
	// of the object. 
	friend std::ostream & operator<<(std::ostream &os, const Room& p);
	friend Room operator+ (const Room &lhs, const Room &rhs);
	friend Room operator- (const Room &lhs, const Room &rhs);

public:
	Room();

	Room(int x, int y);
	
	// Will make use of implicit copy constructor and assignment operators
	// for shallow copy, which is fine since there is no dynamically
	// allocated memory.

	int x() const;
	int y() const;
	Room read() const;
	void write(int x, int y);

	bool adjacent(const Room &p);

	// overloaded comparison operator, two rooms are equal
	// if both their elements are equal
	bool operator==(const Room &other);
	bool operator==(const Room &other) const;
	bool operator!=(const Room &other);
	bool operator!=(const Room &other) const;
private:
	int m_x, m_y;
};

#endif//ROOM_H