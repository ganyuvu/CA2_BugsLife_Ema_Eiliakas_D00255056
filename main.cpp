#include <iostream>
#include <list>
#include <utility>
#include <vector>

using namespace std;

enum class Direction {North,East,South,West};

class Bug{
protected:
    char type;
    int id;
    pair<int,int> position;
    Direction direction;
    int size;
    bool isAlive;
    list<pair<int,int>> path;

public:
    // Constructor to initialize variables
    Bug(char _type, int _id, pair<int,int> _position, Direction _direction, int _size, bool _isAlive, list<pair<int,int>> _path) :
            type(_type), id(_id), position(_position), direction(_direction), size(_size), isAlive(_isAlive), path(_path) {}

    void display(){

    }
};


int main() {

    vector<Bug> bugs;

    int input;

    //Menu here
    cout << "8. Exit" << endl;
    cin >> input;



    return 0;
}
