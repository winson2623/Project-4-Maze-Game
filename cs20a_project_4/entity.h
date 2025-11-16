#ifndef ENTITY_H
#define ENTITY_H

#include"room.h"
#include<string>

// An Entity can have certain States that describe 
// What they are doing
enum class State { LOOK, NOEXIT, BACKTRACK, EXIT };

// Interactions between Entities
enum class Interact { GREET, ATTACK, ALONE };

class Maze;

class Entity {
public:

	Entity(Maze* maze, Room p, std::string, char sprite);
	virtual ~Entity();
	// Pure virtual functions: Entity is an ABC
	// Derived classes must implement
	virtual	void	update() = 0;
	virtual	void	say() = 0;

	// Maybe overriden in derived class
	// Otherwise just returns the char
	// representing the Entity
	virtual	char	draw() const;

	// Setters and Getters for common attributes
	std::string		name();

	void			move(Room p);
	Room			room() const;

	void			state(State s);
	State			state() const;

	void			interact(Interact i);
	Interact		interact() const;

	Maze*			maze() const;

private:
	Room		m_currRoom;		//Current position

	State		m_state;
	Interact    m_interact;

	char		m_sprite;
	Maze*		m_maze;		//Pointer to the maze
							//Entity does not allocate
							//Just points to it.
	std::string m_name;
};

#endif//ACTOR_H