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

};


#endif //CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_HOPPER_H
