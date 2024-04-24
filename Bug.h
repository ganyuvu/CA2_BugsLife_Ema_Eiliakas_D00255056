#ifndef CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_BUG_H
#define CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_BUG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <utility>
#include <vector>

using namespace std;

enum Direction{North,East,South,West};

class Bug {

protected:
    char type;                          //the bugs type (H = Hopper, C = Crawler)
    int id;                             //bugs id
    pair<int,int> position;             //position of bug
    Direction direction;                //direction the bug is facing
    int size;                           //bugs size
    bool isAlive;                       //is the bug alive or not
    list<pair<int,int>> path;           //path taken by bug

public:

    virtual void move() = 0;
    virtual ~Bug();

    // Constructor to initialize variables
    Bug(char _type, int _id, pair<int,int> _position, Direction _direction, int _size, bool _isAlive, list<pair<int,int>> _path);

    string directionToString() const;
    //method for displaying all the bugs info
    void display() const;

    char getType() const;

    int getId() const;

    const pair<int, int> &getPosition() const;

    void setPosition(const pair<int, int> &position);

    Direction getDirection() const;

    void setDirection(Direction direction);

    int getSize() const;

    void setSize(int size);

    bool isAlive1() const;

    void setIsAlive(bool isAlive);

    const list<pair<int, int>> &getPath() const;

    void setPath(const list<pair<int, int>> &path);
};


#endif //CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_BUG_H
