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

            // assigning the tokens to variables and pushing them it into the vector
            char type = tokens[0][0]; // Assuming type is the first token and a single character

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
            }
            //catch error
            catch (const std::exception& e) {
                cout << "Can't parse bug info: " << e.what() << endl;
            }
        }

        file.close();

        // adds bugs to the grid
        // goes through the bug vector and adds them to the board
        for (const auto& bug : bug_vector) {
            addBugsToGrid(*bug);
        }
    }

//referencing Bug class, directly working with the original object
void Board::addBugsToGrid(const Bug& bug){
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
}

void Board::displayGrid(){
    for(int i = 0; i < 10; ++i)//prints out the row
    {
        for(int j = 0; j < 10; ++j)//prints out the columns
        {
            cout << grid[i][j] << "  "; // outputs the entire grid with spacing between each char
        }
        cout << endl;//moves to next line
    }
}

void Board::findBugByID(const vector<Bug*> & bug_vector) {
    int idInput;

    cout << "Enter bug ID to locate it: ";
    cin >> idInput; //gets id from user and stores it in idInput

    bool bugFound = false;

    for (const Bug *bug: bug_vector) { //loops through bugs

        //checks if the bug id matches the users input
        if (bug->getId() == idInput) {

            cout << "\nBug found" << endl;

            printf("=================================================================\n");
            printf("%-8s %-4s %-10s %-12s %-8s %-4s %12s\n", "Type", "ID", "Position", "Direction", "Size", "Alive",
                   "Hop Length");
            printf("=================================================================\n");

            for (const Bug *bug: bug_vector) { //loops through bugs

                //we then check if the bug id matches input
                if (bug->getId() == idInput) {

                    // displays the defualt bug data
                    printf("%-8c %-4d (%-2d,%-2d) %9s %8d %10s"
                            , bug->getType(), bug->getId(), bug->getPosition().first, bug->getPosition().second
                            , bug->directionToString().c_str(), bug->getSize(), (bug->isAlive1() ? "Yes" : "No"));

                    // checking if the bug is a hopper so we can display its hop length
                    //dynamic_cast checks if bug class points to hopper class, if it does we can access hopper
                    //and hopper will be assigned a hopper pointer
                    if (const Hopper *hopper = dynamic_cast<const Hopper *>(bug)) {
                        printf("%10d\n", hopper->getHopLength());
                    }
                    //if the bug in the vector isn't a hopper it will just print -
                    else {
                        printf("%10s\n", "-");
                    }

                    //will stop loop
                    bugFound = true;
                    break;
                }
            }
        }

        if (!bugFound) {
            cout << "Bug with ID: " << idInput << " not found" << endl;
        }
    }
}

void Board::tapBugBoard(const vector<Bug *> &bug_vector) {
//goes through each bug
    for (Bug* bug : bug_vector) {
        bug->move(); // calls move()
    }
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



