#include "Bug.h"


Bug::~Bug() {

}
char Bug::getType() const {
    return type;
}

int Bug::getId() const {
    return id;
}

const pair<int, int> &Bug::getPosition() const {
    return position;
}

void Bug::setPosition(const pair<int, int> &position) {
    Bug::position = position;
}

Direction Bug::getDirection() const {
    return direction;
}

void Bug::setDirection(Direction direction) {
    Bug::direction = direction;
}

int Bug::getSize() const {
    return size;
}

void Bug::setSize(int size) {
    Bug::size = size;
}

bool Bug::isAlive1() const {
    return isAlive;
}

void Bug::setIsAlive(bool isAlive) {
    Bug::isAlive = isAlive;
}

const list<pair<int, int>> &Bug::getPath() const {
    return path;
}

void Bug::setPath(const list<pair<int, int>> &path) {
    Bug::path = path;
}

void Bug::display() const  {
    printf("%-8c %-4d (%-2d,%-2d) %10s %7d %10s\n"
            , type, id, position.first, position.second,directionToString().c_str(), size, (isAlive ? "Yes" : "No"));
}

Bug::Bug(char _type, int _id, pair<int, int> _position, Direction _direction, int _size, bool _isAlive,
         list<pair<int, int>> _path)  :
        type(_type), id(_id), position(_position), direction(_direction), size(_size), isAlive(_isAlive), path(_path) {}

//converts the enum into a corresponding string
string Bug::directionToString() const {
    switch (direction) {
        case Direction::North:
            return "North";
        case Direction::East:
            return "East";
        case Direction::South:
            return "South";
        case Direction::West:
            return "West";
        default:
            return "Unknown";
    }
}

