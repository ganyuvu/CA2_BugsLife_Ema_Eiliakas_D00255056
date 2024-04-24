#include "Hopper.h"

Hopper::Hopper(char type, int id, const pair<int, int> &position, Direction direction, int size, bool isAlive,
               const list<pair<int, int>> &path, int hopLength) :
               Bug(type, id, position, direction, size, isAlive,path), hopLength(hopLength) {

    this-> type = type;
    this->id = id;
}

void Hopper::move() {
    pair<int, int> newPos = getPosition();

    // This will keep looping until the path isnt blocked
    while (isWayBlocked()) {
        //this will set a random direction the bug will face
        direction = static_cast<Direction>(1 + (rand() % 4));
    }

    // we then update the position based on direction
    switch (direction) {
        case Direction::North:
            newPos.second -= hopLength;
            if (newPos.second < 0) newPos.second = 0;
            break;
        case Direction::East:
            newPos.first += hopLength;
            if (newPos.first > 9) newPos.first = 9;
            break;
        case Direction::South:
            newPos.second += hopLength;
            if (newPos.second > 9) newPos.second = 9;
            break;
        case Direction::West:
            newPos.first -= hopLength;
            if (newPos.first < 0) newPos.first = 0;
            break;
        default:
            break;
    }

    setPosition(newPos);
        getPath().push_back(newPos);
}

Hopper::~Hopper() {
    cout << "Destructor called.\n";
}




