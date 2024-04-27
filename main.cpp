#include <iostream>
#include "Board.h"
#include <SFML/Graphics.hpp>

void runSFML(Board& board);

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
        cout << "7. Run Simulation (with SFML)" << endl;
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

                cout << "\nBoard initialized";
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
                //since I used stringStream it doesnt output like cout, so i called the method using cout
                cout << "====Bug Life History====" << endl;
                cout << board.displayLifeHistory() << endl;
                break;
            case 6:
                board.displayAllCells();
                break;
            case 7:
                runSFML(board);
                break;
            case 8:
                board.lifeHistoryToFile("bugs_life_history_data_time.out");
                running = false; // Exit the loop
                break;
            default:
                cerr << "Invalid Option, please try again" << endl;
                break;
        }
    }

    return 0;
}

//used notes from moodle and SFML website to help me with any sfml code
//https://www.sfml-dev.org/tutorials/2.6/
void runSFML(Board& board){

    //render window 480 x 480
    sf::RenderWindow window(sf::VideoMode(740, 500), "BUGS LIFE");

    // drawing the initial state of the board
    board.draw(window);
    board.drawButton(window);
    window.display();

    while (window.isOpen())
    {
        //checking for event e.g closing the window
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            //when a mouse is clicked it will run the simulation
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                //this method will take in window and it will keep updating the window
                board.runSimulation(window);

            }
        }
    }
}

