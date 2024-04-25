
#ifndef CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_BEATLE_H
#define CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_BEATLE_H

#include "Bug.h"

class Beatle : public Bug{

private:
    bool skipTurn;

public:
    void move() override;

    ~Beatle();

    Beatle(char type, int id, const pair<int, int> &position, Direction direction, int size, bool isAlive,
           const list<pair<int, int>> &path);

    bool isSkipTurn() const;

};


#endif //CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_BEATLE_H
