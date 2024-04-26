#include "Bug.h"

Bug::Bug(char _type, int _id, pair<int, int> _position, Direction _direction, int _size, bool _isAlive,
         list<pair<int, int>> _path)  :
        type(_type), id(_id), position(_position), direction(_direction), size(_size), isAlive(_isAlive), path(_path) {}

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

list<pair<int, int>>& Bug::getPath() {
    return path;
}

void Bug::setPath(const list<pair<int, int>> &path) {
    Bug::path = path;
}

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

bool Bug::isWayBlocked() {
    switch (direction) {
        case Direction::North:
            return (position.second == 0);          //y axis = 0 the bug is at the top edge
        case Direction::East:
            return (position.first == 9);           //x axis = 9 the bug is at the right edge
        case Direction::South:
            return (position.second == 9);          //y axis = 9 the bug is at the bottom edge
        case Direction::West:
            return (position.first == 0);           //x axis = 0 the bug is at the lef edge
        default:
            return true; //will return true, meaning the path is blocked
    }
}

void Bug::fight(Bug *otherBug) {
    // Checking if both bugs are in the same cell and if they are alive
    if (this->getPosition() == otherBug->getPosition() && this->isAlive && otherBug->isAlive) {

        // if first bug is larger in size, it will eat the otherBug
        if (this->getSize() > otherBug->getSize()) {

            this->setSize(this->getSize() + otherBug->getSize()); //adding the bugs sizes to simulate eat function
            otherBug->setIsAlive(false); // Setting otherBug status as dead
        }

        //if Other bug is larger in size, it will eat the otherBug
        else if (this->getSize() < otherBug->getSize()) {

            otherBug->setSize(this->getSize() + otherBug->getSize()); //Adding the bugs sizes to simulate eat function
            this->setIsAlive(false); // setting bug as dead
        }

        // if both bugs are equal in size we randomize the winner
        else {
            //50/50 chance to win
            if (rand() % 2 == 0) {
                this->setSize(this->getSize() + otherBug->getSize());
                otherBug->setIsAlive(false);
            }
            else {
                otherBug->setSize(this->getSize() + otherBug->getSize());
                this->setIsAlive(false);
            }
        }
    }
}

Bug::~Bug() {
    cout << "Destructor called.\n";
}




