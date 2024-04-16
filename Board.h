//
// Created by emaei on 16/04/2024.
//

#ifndef CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_BOARD_H
#define CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_BOARD_H


#include <fstream>
#include <sstream>
#include <list>
#include <utility>
#include <vector>
#include "Bug.h"

using namespace std;

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

    void findBugByID(const vector<Bug>& bugs){
        int idInput;

        cout << "Enter bug ID to locate it: ";
        cin >> idInput; //gets id from user and stores it in idInput

        bool bugFound = false;

        for (const Bug& bug : bugs) { //loops through bugs
            //checks if the bug id matches the users input
            if(bug.getId() == idInput){
                cout << "Bug found." << endl;

                printf("======================================================\n");
                printf("%-8s %-4s %-10s %-12s %-8s %6s\n"
                        , "Type", "ID", "Position", "Direction", "Size", "Alive");
                printf("======================================================\n");

                bug.display();
                bugFound = true;
                break;
            }
        }
        if(!bugFound){
            cout << "Bug not found.";
        }
    }

};



#endif //CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_BOARD_H
