#include"shark.h"
#include"maze.h"
#include"player.h"

Shark::Shark(Maze* maze, Room p, std::string name, char sprite):
	Entity(maze, p, name, sprite){
}
void Shark::update() {

	// Pick a random direction
	int dir = maze()->randInt(0, 3);
	// Get a copy of sharks current position
	Room p  = room();

	int rows = maze()->rows();
	int cols = maze()->cols();
	int x    = p.x();
	int y    = p.y();

	// Check to see if desired direction is inbounds.
	// Accounting for the Walls and one space to allow
	// movement in that direction. Update the x,y
	// coordinates or do nothing
	switch (dir) {
	case 0:  if (y <= 2)      return; else y--; break;
	case 1:  if (y >= rows-3) return; else y++; break;
	case 2:  if (x <= 2)      return; else x--; break;
	case 3:  if (x >= cols-3) return; else x++; break;
	default: return;
	}

	// Check to see if new position is an open cell
	p.write(x, y);
	if (!maze()->open(p)) 
		return;

	move(p); // move there
}

void Shark::say() {
	switch (interact()) {
	case Interact::ATTACK:
		std::cout << name() << ": OM NOM!";
		break;
	case Interact::ALONE:
		std::cout << name() << ": I'm hungry";
		break;
	case Interact::GREET:
		std::cout << name() << ": Hey Buddy";
		break;
	default:
		std::cout << name() << ":A - hee - ahee ha - hee!";
	}
}