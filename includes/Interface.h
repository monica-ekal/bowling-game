
#ifndef BOWLINGGAME_INTERFACE_H
#define BOWLINGGAME_INTERFACE_H

#include "BowlingGame.h"

/*
 * This class deals with requesting form the user the number of pins knocked down, and makes sure that it is valid.
 * It also displays the score after each roll
 */
class Interface{

    int rollNumber;
    int prevRoll;

public:
    Interface(): rollNumber{1},prevRoll{0}{};

    int nextRoll(const BowlingGame& game);

    void prepareNextRoll(const BowlingGame& game);

    int getRollNumber () const;

    void getScore(const BowlingGame& game) const;

    bool checkVector(int index, std::vector <int> vec);

    void displayScore(const BowlingGame& game);
};

#endif //BOWLINGGAME_INTERFACE_H
