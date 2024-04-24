
#ifndef CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_CRAWLER_H
#define CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_CRAWLER_H

#include "Bug.h"

class Crawler : public Bug {
private:

public:
    void move() override; //implementation of move

    ~Crawler();

    Crawler(char type, int id, const pair<int, int> &position, Direction direction, int size, bool isAlive,
            const list<pair<int, int>> &path);

};

#endif //CA2_BUGSLIFE_EMA_EILIAKAS_D00255056_CRAWLER_H
