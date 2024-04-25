#include <iostream>
#include "Board.h"

using namespace std;

int main() {
    Board board;
    int input;
    bool running = true;
    bool boardInitialized = false;

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

        //checks if board was made and if input isnt 1
        if (!boardInitialized && input != 1) {
            cout << "Must initialize the bug board first!" << endl;
            continue;
        }

        switch (input) {
            case 1:
                board.getBugsFromFile("Bugs.txt");

                //cout << "\n==========BUG BOARD=========\n";
                //board.displayGrid();
                cout << "Board initialized";
                boardInitialized = true;
                break;
            case 2:
                // displays all the bug info
                board.displayAllBugs();
                break;
            case 3:
                board.findBugByID(board.getBugVector());
                break;
            case 4:
                board.tapBugBoard(board.getBugVector());
                break;
            case 5:
                board.displayLifeHistory();
                break;
            case 6:
                board.displayAllCells();
                break;
            case 7:
                break;
            case 8:
                running = false; // Exit the loop
                break;
            default:
                cerr << "Invalid Option, please try again" << endl;
                break;
        }
    }

    return 0;
}

