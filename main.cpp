#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <utility>
#include <vector>
#include "Bug.h"
#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"

using namespace std;

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


void tapBugBoard(vector<Bug*>& bug_vector) {

    //goes through each bug
    for (Bug* bug : bug_vector) {
        bug->move(); // call move() for each bug
    }
}

int main() {
    vector<Bug*> bug_vector; // vector that points at bug
    Board board;
    int input;
    bool running = true;


    ifstream file("Bugs.txt");

    if (!file.is_open()) {
        cout << "Unable to open file!" << endl;
        return 1;
    }

    while (running) {
        // Menu
        cout << "\n====Menu====" << endl;
        cout << "1. Initialize Bug Board" << endl;
        cout << "2. Display All Bugs" << endl;
        cout << "3. Find By ID" << endl;
        cout << "4. Shake Board" << endl;
        cout << "5. Display Life History" << endl;
        cout << "6. Display all Cells" << endl;
        cout << "7. PLAY" << endl;
        cout << "8. Exit" << endl;
        cin >> input;

        string line;
        // loop for reading the file
        while (getline(file,line)) {
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
                if(type == 'C'){
                    int id = stoi(tokens[1]); // Converting string to integer
                    pair<int, int> position = make_pair(stoi(tokens[2]), stoi(tokens[3])); // Converting strings to integers and creating pair
                    Direction direction = intToDirection(stoi(tokens[4])); // Converting string to integer and then to Direction enum
                    int size = stoi(tokens[5]); // Converting string to integer
                    bool isAlive = true;

                    Crawler* crawler = new Crawler{type, id, position, direction, size, isAlive, list<pair<int,int>>()};
                    bug_vector.push_back(crawler);
                }
                else if(type == 'H'){
                    int id = stoi(tokens[1]); // Converting string to integer
                    pair<int, int> position = make_pair(stoi(tokens[2]), stoi(tokens[3])); // Converting strings to integers and creating pair
                    Direction direction = intToDirection(stoi(tokens[4])); // Converting string to integer and then to Direction enum
                    int size = stoi(tokens[5]); // Converting string to integer
                    bool isAlive = true;
                    int hopLength = stoi(tokens[6]);

                    Hopper* hopper = new Hopper{type, id, position, direction, size, isAlive, list<pair<int,int>>(), hopLength};
                    bug_vector.push_back(hopper);
                }

            }

            //catch any errors
            catch (const std::exception& e) {
                cout << e.what() << endl;
            }
        }
        // Close the file
        file.close();

        // adds bug to the board
        for (const auto& bug : bug_vector) // goes through the bug vector and adds them to the board
        {
            board.addBugsToGrid(*bug);
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
                for (Bug* bug : bug_vector) {
                    bug->display();
                }
                break;
            case 3:
                board.findBugByID(bug_vector); // calling method to find a specific bug out of all bugs
                break;
            case 4:
                tapBugBoard(bug_vector); //calling method to move all bugs
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                running = false; // Exit the loop
                break;
            default:
                cerr << "Invalid Option!" << endl;
                break;
        }
    }

    return 0;
}

