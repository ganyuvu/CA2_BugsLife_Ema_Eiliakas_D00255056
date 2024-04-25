
#include "Beatle.h"

Beatle::Beatle(char type, int id, const pair<int, int> &position, Direction direction, int size, bool isAlive,
               const list<pair<int, int>> &path) :
        Bug(type, id, position, direction, size, isAlive,path) {

    this-> type = type;
    this->id = id;

}

//will edit this later
void Beatle::move() {
    pair<int, int> newPos = getPosition();

    // This will keep looping until the path isnt blocked
    while (isWayBlocked()) {
        //this will set a random direction the bug will face
        direction = static_cast<Direction>(1 + (rand() % 4));
    }

    // we then update the position based on direction
    switch (direction) {
        case Direction::North:
            newPos.second--;
            break;
        case Direction::East:
            newPos.first++;
            break;
        case Direction::South:
            newPos.second++;
            break;
        case Direction::West:
            newPos.first--;
            break;
        default:
            break;
    }

    setPosition(newPos);
    getPath().push_back(newPos);
}

Beatle::~Beatle() {
    cout << "Destructor called.\n";
}

bool Beatle::isSkipTurn() const {
    return skipTurn;
}



