#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <utility>
#include <vector>

using namespace std;

enum class Direction {North, East, South, West};

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

    //getter for bug position
    const pair<int, int> &getPosition() const {
        return position;
    }

    //getter for bug type
    char getType() const {
        return type;
    }
};

class Board {
protected:
    vector<vector<char>> grid; //vector for creating grid

public:
    //creating the 10x10 grid
    Board(){
        grid.assign(10, vector<char>(10, '*'));
    }

    //referencing Bug class, directly working with the original object
    void addBugsToGrid(const Bug& bug){
        pair<int, int> position = bug.getPosition(); //getting the bugs position

        //checking if the bug is inbound of the grid
        if (position.first >= 0 && position.first < grid.size() &&
            position.second >= 0 && position.second < grid[0].size()) {
            //adding bug to the grid and replaces the * with the bug type (C/H)
            grid[position.first][position.second] = bug.getType();
        }
        else{
            cout << "Position of bug not inbound" << endl;
        }
    };

    void displayGrid(){
        for(int i = 0; i < 10; ++i)//prints out the row
        {
            for(int j = 0; j < 10; ++j)//prints out the columns
            {
                cout << grid[i][j] << "  "; // outputs the entire grid with spacing between each char
            }
            cout << endl;//moves to next line
        }
    }

};

// Function to convert integer direction to Direction enum
Direction intToDirection(int value) {
    switch(value) {
        case 1:
            return Direction::North;
        case 2:
            return Direction::East;
        case 3:
            return Direction::South;
        case 4:
            return Direction::West;
        default:
            return Direction::North; // Default to North if unknown direction
    }
}

int main() {
    vector<Bug> bugs;//vector to hold bugs
    Board board;
    int input;//users input

    //Menu
    cout << "====Menu====" << endl;
    cout << "1. Initialize Bug Board" << endl;
    cout << "2. Display All Bugs" << endl;
    cout << "3. Find By ID" << endl;
    cout << "4. Shake Board" << endl;
    cout << "5. Display Life History" << endl;
    cout << "6. Display all Cells" << endl;
    cout << "7. PLAY" << endl;
    cout << "8. Exit" << endl;
    cin >> input;

    ifstream file("Bugs.txt");

    if(!file.is_open()){
        cout << "Unable to open file!" << endl;
        return 1;
    }

    string line;
    //loop for reading the file
    while(getline(file,line)){
        vector<string> tokens;
        stringstream ss(line);
        string token;

        //loop to store tokens in vector using a delimiter
        while(getline(ss, token, ';')){
            tokens.push_back(token);
        }

        //assigning the tokens to variables
        char type = tokens[0][0]; //Assuming type is the first token and a single character
        int id = stoi(tokens[1]);//Converting string to integer
        pair<int, int> position = make_pair(stoi(tokens[2]), stoi(tokens[3])); //Converting strings to integers and creating pair
        Direction direction = intToDirection(stoi(tokens[4])); //Converting string to integer and then to Direction enum
        int size = stoi(tokens[5]); //Converting string to integer
        bool isAlive = true;

        //Bug object and push it into the vector
        Bug bug(type, id, position, direction, size, isAlive, list<pair<int,int>>());
        bugs.push_back(bug);

    }
    // Close the file
    file.close();

    //adds bug to the board
    for(const auto& bug: bugs)//goes through the bug vector and adds them to the board
    {
        board.addBugsToGrid(bug);
    }

    switch (input) {
        case 1:
            cout << "\n==========BUG BOARD=========\n";
            board.displayGrid();
            break;
        case 2:
            printf("======================================================\n");
            printf("%-8s %-4s %-10s %-12s %-8s %6s\n"
                    , "Type", "ID", "Position", "Direction", "Size", "Alive");
            printf("======================================================\n");
            // Display the bug details
            for(Bug bug : bugs){
                bug.display();
            }
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            return 0;
        default:
            cerr << "Invalid Option!" << endl;
            break;
    }

    return 0;
}
