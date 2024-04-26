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
    vector<vector<char>> grid; //vector for storing grid size
    vector<Bug*> bug_vector; // vector that points at bug

public:
    Board();
    void displayAllBugs();
    void findBugByID(const vector<Bug *> &bug_vector);
    void tapBugBoard(const vector<Bug*> & bug_vector);
    Direction intToDirection(int value);
    void getBugsFromFile(const string &fileName);
    void displayLifeHistory();
    void displayAllCells();
    void startFight();
    bool isGameOver();
    void runSimulation();

    // method to get the bug vector (using it in main)
    vector<Bug*>& getBugVector() {
        return bug_vector;
    }
};

#endif //CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_BOARD_H
