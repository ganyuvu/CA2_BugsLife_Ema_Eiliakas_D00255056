#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <utility>
#include <vector>
#include "Board.h"
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Beatle.h"

using namespace std;

Board::Board() {
    grid.assign(10, vector<char>(10, '*'));
}

    void Board::getBugsFromFile(const std::string &fileName) {

        ifstream file(fileName);

        if (!file.is_open()) {
            cout << "Unable to open file: " << fileName << endl;
            return;
        }

        string line;

        // loop for reading the file
        while (getline(file, line)) {
            vector<string> tokens;
            stringstream ss(line);
            string token;

            // loop to store tokens in vector using a delimiter
            while (getline(ss, token, ';')) {
                tokens.push_back(token);
            }

            // assigning the tokens to variables and pushing them into the vector
            char type = tokens[0][0]; // Assuming type is the first token [0][0] will turn string to char

            try {
                if (type == 'C') {
                    int id = stoi(tokens[1]); // Converting string to integer
                    pair<int, int> position = make_pair(stoi(tokens[2]), stoi(tokens[3])); // Converting strings to integers and creating pair
                    Direction direction = intToDirection(stoi(tokens[4])); // Converting string to integer and then to Direction enum
                    int size = stoi(tokens[5]); // Converting string to integer
                    bool isAlive = true;

                    Crawler* crawler = new Crawler(type, id, position, direction, size, isAlive, list<pair<int,int>>());
                    bug_vector.push_back(crawler);
                }
                else if (type == 'H') {
                    int id = stoi(tokens[1]); // Converting string to integer
                    pair<int, int> position = make_pair(stoi(tokens[2]), stoi(tokens[3])); // Converting strings to integers and creating pair
                    Direction direction = intToDirection(stoi(tokens[4])); // Converting string to integer and then to Direction enum
                    int size = stoi(tokens[5]); // Converting string to integer
                    bool isAlive = true;
                    int hopLength = stoi(tokens[6]);

                    Hopper* hopper = new Hopper(type, id, position, direction, size, isAlive, list<pair<int,int>>(), hopLength);
                    bug_vector.push_back(hopper);
                }
                else if (type == 'B') {
                    int id = stoi(tokens[1]); // Converting string to integer
                    pair<int, int> position = make_pair(stoi(tokens[2]), stoi(tokens[3])); // Converting strings to integers and creating pair
                    Direction direction = intToDirection(stoi(tokens[4])); // Converting string to integer and then to Direction enum
                    int size = stoi(tokens[5]); // Converting string to integer
                    bool isAlive = true;

                    Beatle* beatle = new Beatle(type, id, position, direction, size, isAlive, list<pair<int,int>>());
                    bug_vector.push_back(beatle);
                }
            }
            //catch error
            catch (const std::exception& e) {
                cout << "Can't parse bug info: " << e.what() << endl;
            }
        }

        file.close();
    }

void Board::findBugByID(const vector<Bug*> & bug_vector) {
    int idInput;

    cout << "Enter bug ID to locate it: ";
    cin >> idInput; //gets id from user and stores it in idInput

    bool bugFound = false;

    for (const Bug *bug: bug_vector) { //loops through bugs

        //checks if the bug id matches the users input
        if (bug->getId() == idInput) {
            bugFound = true;
            cout << "\nBug found" << endl;

            printf("=================================================================\n");
            printf("%-8s %-4s %-10s %-12s %-8s %-4s %12s\n", "Type", "ID", "Position", "Direction", "Size", "Alive",
                   "Hop Length");
            printf("=================================================================\n");

            // displays the default bug data
            printf("%-8c %-4d (%-2d,%-2d) %9s %8d %10s"
                    , bug->getType(), bug->getId(), bug->getPosition().first, bug->getPosition().second
                    , bug->directionToString().c_str(), bug->getSize(), (bug->isAlive1() ? "Yes" : "No"));

            // checking if the bug is a hopper so we can display its hop length
            // dynamic_cast checks if bug class points to hopper class, if it does we can access hopper
            // and hopper will be assigned a hopper pointer
            if (const Hopper *hopper = dynamic_cast<const Hopper *>(bug)) {
                printf("%10d\n", hopper->getHopLength());
            }
            //if the bug in the vector isn't a hopper it will just print -
            else {
                printf("%10s\n", "-");
            }
            break; // Exit the loop after bug is found
        }
    }

    if (!bugFound) {
        cout << "Bug with ID: " << idInput << " not found" << endl;
    }
}

void Board::startFight() {

    //loops through all bugs in vector
    for (int i = 0; i < bug_vector.size(); ++i) {
        // looping through bugs again, added +1 so it skips bug1
        for (int j = i + 1; j < bug_vector.size(); ++j) {
            bug_vector[i]->fight(bug_vector[j]); // start fight between bug 1 and 2
        }
    }
}

void Board::tapBugBoard(const vector<Bug *> &bug_vector) {
//goes through each bug
    for (Bug* bug : bug_vector) {

        if (bug->isAlive1()) {  // check if bug is alive
            bug->move();  // calls move()
        }
    }
    startFight();
}

// Function to convert integer direction to Direction enum
Direction Board::intToDirection(int value) {
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

void Board::displayAllBugs() {
    printf("=================================================================\n");
    printf("%-8s %-4s %-10s %-12s %-8s %-4s %12s\n"
            , "Type", "ID", "Position", "Direction", "Size", "Alive", "Hop Length");
    printf("=================================================================\n");

    for (const Bug* bug : bug_vector) {

        // displays defualt bug data
        printf("%-8c %-4d (%-2d,%-2d) %9s %8d %10s"
                , bug->getType(), bug->getId(), bug->getPosition().first, bug->getPosition().second
                , bug->directionToString().c_str(), bug->getSize(), (bug->isAlive1() ? "Yes" : "No"));

        // checking if the bug is a hopper so we can display its hop length
        //dynamic_cast checks if bug class points to hopper class, if it does we can access hopper
        //and hopper will be assigned a hopper pointer
        if (const Hopper* hopper = dynamic_cast<const Hopper*>(bug)) {
            printf("%10d\n", hopper->getHopLength());
        }
        //if the bug in the vector isn't a hopper it will just print -
        else {
            printf("%10s\n", "-");
        }
    }

}

//to do: implement display for bug getting eaten
//to do:  write to a file
void Board::displayLifeHistory() {
    cout << "====Bug Life History====" << endl;

    //loops through all bugs
    for (const auto& bug : bug_vector) {

        //displaying bug ID buy type and path
        cout << "\n"<<bug->getId() << " " << bug->getType() << " Path: ";
        const list<pair<int, int>>& path = bug->getPath(); //displays the bugs path

        //if path list isnt empty we loop through it using an iterator that will point at each position
        if (!path.empty()) {
            for (auto i = path.begin(); i != path.end(); ++i) {

                //making sure comma is only printed after the first path
                if (i != path.begin()) {
                    cout << ",";
                }
                cout << "(" << i->first << "," << i->second << ")";
            }
        }
        else {
            cout << "No path taken";
        }

        // Then we finally display if the bug is alive or not
        cout << ", " << (bug->isAlive1() ? "Alive" : "Dead") << endl;
    }
}

void Board::displayAllCells() {
    //displaying all cells in grid
        for (int i = 0; i < grid.size(); ++i) {

            for (int j = 0; j < grid[i].size(); ++j) {

                //storing and printing the cells
                pair<int, int> cell(i, j);
                cout << "\n(" << cell.first << "," << cell.second << "): ";

                // Checking if a bug occupies a cell
                bool cellOccupied = false;

                for (Bug* bug : bug_vector) {
                    //if bug position matches the cell, we print it out
                    if (bug->getPosition() == cell) {
                        cout << bug->getType() << ", " << bug->getId();
                        cellOccupied = true;
                    }
                }
                if (!cellOccupied) {
                    cout << "Empty";
                }
            }
        }
}

bool Board::isGameOver() {
    int bugsAlive = bug_vector.size(); //when game starts, all bugs are alive, so we get their count

    //we loop through bug vector
    for (Bug* bug : bug_vector) {
        //check if bug isnt alive and decrement if a bug dies
        if (!bug->isAlive1()) {
            bugsAlive--;
        }
        //if bugsAlive equals to 1 then the game is over
        if (bugsAlive == 1) {
            return true;
        }
    }
    // otherwise game continues
    return false;
}

void Board::runSimulation() {
    int round = 1; // start at round 1

    //loop while game isnt over
    while (!isGameOver()) {
        //display the round and the bugs
        cout << "\nROUND " << round << ":\n";
        tapBugBoard(bug_vector);
        displayAllBugs();

        round++;
    }

    //getting the winner bug
    Bug* winner = nullptr; //pointing to nothing for now

    for (Bug* bug : bug_vector) {
        //check if bug is alive  and sets it as winner
        if (bug->isAlive1()) {
            winner = bug;
            break;
        }
    }
    //displaying the winner
    cout << "\nGame Over... " << "Winner is: " << winner->getType() << ", " << winner->getId() <<endl;
}

