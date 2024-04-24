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
    Board();
    //referencing Bug class, directly working with the original object
    void addBugsToGrid(const Bug& bug);
    void displayGrid();
    void findBugByID(const vector<Bug *> &bug_vector);
};

#endif //CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_BOARD_H
