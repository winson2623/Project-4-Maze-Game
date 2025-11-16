#ifndef SHARK_H
#define SHARK_H
#include"entity.h"
// Shark NPC's that roam the maze and bite peek Nemo
class Shark : public Entity {
public:
	Shark(Maze* maze, Room p, std::string name, char sprite);
	virtual void update();	// Sharks move randomly in the world in search of prey
	virtual void say();		// What does the shark say? 
private:
};

#endif//SHARK_H