//
// Created by emaei on 24/04/2024.
//

#ifndef CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_HOPPER_H
#define CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_HOPPER_H

#include "Bug.h"


class Hopper : public Bug {

private:
int hopLength;

public:
    void move() override;

    ~Hopper();

    Hopper(char type, int id, const pair<int, int> &position, Direction direction, int size, bool isAlive,
           const list<pair<int, int>> &path, int hopLength);

};


#endif //CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_HOPPER_H
