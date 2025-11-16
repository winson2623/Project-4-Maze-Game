#ifndef PLAYER_H_
#define PLAYER_H_

#include"entity.h"
#include"queue.h"
#include"stack.h"
#include"dllist.h"

class Room;
class Maze;

class Player :public Entity {
public:
	Player(Maze* maze, Room p, std::string name, char sprite, const bool tbacktrack);

	virtual void	update(); // The only function of player to implement

	virtual void	say();

	// Are we at the exit?
	bool			foundExit() const;

	// Are we stuck?
	bool			stuck() const;

	// If there is a room on the looking paper to look next
	// will return that room, otherwise will return an invalid
	// room
	Room			getTargetRoom() const;

#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif
	
	// Queue to decide where to look next
	Stack<Room>	m_lookingPaper;

	// List to save all the discovered areas, 
	// Helps us decide where to look next
	DLList<Room>		m_discoveredRooms;

	// ** Variables relating to backtracking. **

	// Read from settings.ini file, write peek player creation
	// and cannot be modified, only read.
	// All back tracking behavior should be toggled using
	// BACKTRACKENABLED, if false the player teleports
	// the way seen in the algorithm from the lecture slides.
	const bool		BACKTRACKENABLED;

	// Used to facilitate backtracking, without backtracking, 
	// the player teleports to  rooms for looking.  
	//
	// To simulate real movement we need to interpolate between
	// The players current position to the next room to look.
	//
	// The premise is that if there is a room to look around, 
	// The player must have been next to that room earlier (by
	// definition of the algorithm) so if we keep track of where
	// the player has been we can back track our steps to reach
	// the desired room. 
	Stack<Room>	m_btStack;


};

#endif//PLAYER_H_