#ifndef WORLD_H
#define WORLD_H

#include"dllist.h"
#include"room.h"


const int MAX_ACTORS = 50;
class Player;
class Entity;

class Maze {
public:
	// Constructor: create the maze from file.
	// file must not have any white space after last
	// col and must have one newline after last row.
	// Creates the player, sets the starting and end 
	// rooms
	Maze(std::string filename, const bool tbacktrack);
	~Maze();

	int		rows() const;	// Get the count of the maze
	int		cols() const;

	int		numOpenRooms() const;
	bool	open(Room p) const;

	bool	foundExit(Room p) const;

	Player*	player() const;	// Get the player from the maze
	int		addBaddies();

	double  getPlayerUpdateRunTime(); //Time it takes for the player to make their move

	void	update();		// Update the maze by one step
	void	interact();		// Update the Entities' interactions
	void	draw() const;	// Draw the maze with entities

	int randInt(int min, int max);
private:
	

	DLList<Room> m_openRooms;	// Store all the cells entities can move to

	int		m_rows;				// Extents of the maze
	int		m_cols;

	Room	m_start;			// Start of the maze
	Room	m_end;				// End room of the maze

	char**	m_tmaze;			// maze template created from file
	char**	m_renderedMaze;	// Copy of maze with entities drawn

	Player*	m_player;			// Dynamically allocated player

	Entity*	m_entities[MAX_ACTORS]; // Polymorphic array of entities
								  // The player is always the 0th element
	int		m_nEntities;

	double  m_duration;		// How long Player::update takes to execute

	
};

#endif//WORLD_H