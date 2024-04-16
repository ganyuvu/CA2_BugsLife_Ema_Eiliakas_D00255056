#ifndef CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_BUG_H
#define CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_BUG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <utility>
#include <vector>
#include "Direction.h"

using namespace std;

class Bug {

protected:
    char type;//the bugs type (H = Hopper, C = Crawler)
    int id;//bugs id
    pair<int,int> position;//position of bug
    Direction direction;//direction the bug is facing
    int size;//bugs size
    bool isAlive;//is the bug alive or not
    list<pair<int,int>> path;//path taken by bug

public:
    // Constructor to initialize variables
    Bug(char _type, int _id, pair<int,int> _position, Direction _direction, int _size, bool _isAlive, list<pair<int,int>> _path) :
            type(_type), id(_id), position(_position), direction(_direction), size(_size), isAlive(_isAlive), path(_path) {}

    //converts the enum into a corresponding string
    string directionToString() const {
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

    //method for displaying all the bugs info
    void display() const {
        printf("%-8c %-4d (%-2d,%-2d) %10s %7d %10s\n"
                , type, id, position.first, position.second,directionToString().c_str(), size, (isAlive ? "Yes" : "No"));
    }

    char getType() const {
        return type;
    }

    int getId() const {
        return id;
    }

    const pair<int, int> &getPosition() const {
        return position;
    }

    Direction getDirection() const {
        return direction;
    }

    int getSize() const {
        return size;
    }

    bool isAlive1() const {
        return isAlive;
    }

    const list<pair<int, int>> &getPath() const {
        return path;
    }
};


#endif //CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_BUG_H
