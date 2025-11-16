#include"room.h"

Room::Room():m_x(0), m_y(0) {}

Room::Room(int x, int y): m_x(x), m_y(y) {}

int Room::x() const {
	return m_x;
}

int Room::y() const {
	return m_y;
}
Room Room::read() const {
	return Room(m_x, m_y);
}
void Room::write(int x, int y) {
	m_x = x;
	m_y = y;
}
bool Room::adjacent(const Room &p) {
	double x0 = m_x;
	double x1 = p.m_x;
	double y0 = m_y;
	double y1 = p.m_y;
	//If we dont care about the actual distance 
	//then we dont need the square root
	double sqrdist = (x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1);
	return sqrdist <= 1;
}
bool Room::operator==(const Room& other) {
	return (m_x == other.m_x && m_y == other.m_y);
}
bool Room::operator==(const Room& other) const {
	return (m_x == other.m_x && m_y == other.m_y);
}

bool Room::operator!=(const Room& other) {
	return !operator==(other);
}

bool Room::operator!=(const Room& other) const {
	return !operator==(other);
}


std::ostream & operator<<(std::ostream &os, const Room& p) {
	return os << "(" << p.m_x <<","<<p.m_y<<")";
}

Room operator+ (const Room &lhs, const Room &rhs) {
	Room p(lhs.m_x + rhs.m_x, lhs.m_y + rhs.m_y);
	return p;
}
Room operator- (const Room &lhs, const Room &rhs) {
	Room p(lhs.m_x - rhs.m_x, lhs.m_y - rhs.m_y);
	return p;
}

