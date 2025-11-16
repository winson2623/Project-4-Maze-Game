#include"entity.h"
#include"room.h"
#include"maze.h"
#include<string>							
Entity::Entity(Maze* maze, Room p, std::string name, char sprite)
	:m_maze(maze), m_currRoom(p),m_name(name),
	m_sprite(sprite), m_state(State::LOOK), m_interact(Interact::ALONE) {
}
Entity::~Entity() {}
void Entity::move(Room p) {
	m_currRoom = p;
}
Room Entity::room() const {
	return m_currRoom;
}
void Entity::state(State s) {
	m_state = s;
}
State  Entity::state() const {
	return m_state;
}
char Entity::draw() const {
	return m_sprite;
}
Maze* Entity::maze() const {
	return m_maze;
}
std::string Entity::name() {
	return m_name;
}

void Entity::interact(Interact i) {
	m_interact = i;
}
Interact Entity::interact() const {
	return m_interact;
}